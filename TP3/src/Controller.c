#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"
#include "parser.h"
#include "Menu.h"

#define ERROR -1
#define EXITO 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	if(path == NULL && pArrayListEmployee == NULL)
	{
		return ERROR;
	}

	FILE* pFile;

	pFile = fopen(path,"r");

	if(pFile != NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
	}

	fclose(pFile);

    return EXITO;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	if(path == NULL && pArrayListEmployee == NULL)
	{
		return ERROR;
	}

	FILE* pFile;

	pFile = fopen(path,"rb");

	if(pFile != NULL)
	{
		parser_EmployeeFromBinary(pFile ,pArrayListEmployee);
	}

	fclose(pFile);

    return EXITO;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* aux;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL)
	{
		utn_getString("Ingrese el nombre del empleado: ", "Error. Ingrese un nombre valido", 128, 6, auxNombre);
		utn_getInt("Ingrese las horas que trabaja el empleado: ", "Error. Ingrese un horario valido", 70, 350, 6, &auxHoras);
		utn_getInt("Ingrese el sueldo del empleado: ", "Error. Ingrese un sueldo valido", 10000, 400000, 6, &auxSueldo);

		aux = employee_newParametros(1,auxNombre,auxHoras,auxSueldo);

		if(aux != NULL)
		{
			retorno = 0;

			ll_add(pArrayListEmployee, aux);

			printf("Se dio de alta el empleado\n");
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int index = -1;
	int idAux;
	int lenght;
	char respuesta[4];
	Employee* aux;

	if(pArrayListEmployee != NULL)
	{
		printf("Ingrese el ID del empleado que desea eliminar: ");
		getInt(&idAux);

		lenght = ll_len(pArrayListEmployee);

		for(int i = 0; i < lenght; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);

			if(aux->id == idAux)
			{
				retorno = 0;
				index = i;
				break;
			}
		}

		if(index != -1)
		{
			utn_getString("Estas seguro que desea modificar este empleado?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida", 4, 6, respuesta);

			if(stricmp(respuesta,"si") == 0)
			{
				do
				{
					switch(SubMenuModificar())
					{
						case 1:
							utn_getString("Ingrese el nuevo nombre del empleado: ", "Error. Ingrese un nombre valido", 128, 6, aux->nombre);
							break;
						case 2:
							utn_getInt("Ingrese el nuevo horario laboral del empleado: ", "Error. Ingrese un horario valido", 70, 350, 6, &aux->horasTrabajadas);
							break;
						case 3:
							utn_getInt("Ingrese el nuevo sueldo del empleado", "Error. Ingrese un sueldo valido", 10000, 400000, 6, &aux->sueldo);
							break;
					}

					utn_getString("Desea seguir modificando?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida", 4, 6, respuesta);

				}while(stricmp(respuesta, "si") == 0);

				//ll_set(pArrayListEmployee, index,aux);
			}
		}
	}

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idAux;
	int lenght;
	char respuesta[4];
	Employee* aux;

	if(pArrayListEmployee != NULL)
	{
		printf("Ingrese el ID del empleado que desea eliminar: ");
		getInt(&idAux);

		lenght = ll_len(pArrayListEmployee);

		for(int i = 0; i < lenght; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);

			if(aux->id == idAux)
			{
				retorno = 0;

				utn_getString("Estas seguro que desea eliminar este empleado?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida", 4, 6, respuesta);

				if(stricmp(respuesta,"si") == 0)
				{
					ll_remove(pArrayListEmployee,i);
					printf("Se elimino al empleado exitosamente!\n");
				}
				else
				{
					printf("Usted cancelo la operacion....\n");
				}
				break;
			}
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	Employee* aux = NULL;
	int lenght;
	//Node* nodoActual;

	if(pArrayListEmployee != NULL)
	{
		retorno = EXITO;

		lenght = ll_len(pArrayListEmployee);

		for(int i = 0; i < lenght; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);

			employee_showOneEmployee(aux);
		}

		/*nodoActual = pArrayListEmployee->pFirstNode;

		while(nodoActual != NULL)
		{
			aux = (Employee*)nodoActual->pElement;

			employee_showOneEmployee(aux);

			nodoActual = nodoActual->pNextNode;
		}*/
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int orden;

	if(pArrayListEmployee != NULL)
	{
		utn_getInt("Ingrese el orden deseado\n(1 para ascendente, 0 para descendente):  ", "Error. Ingrese un orden valido ", 0, 1, 6, &orden);

		ll_sort(pArrayListEmployee,employee_compareByName, orden);
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

