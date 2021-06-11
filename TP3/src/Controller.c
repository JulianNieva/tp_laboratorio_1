#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"
#include "parser.h"
#include "Menu.h"
#include "Controller.h"

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
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile;

		pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
			{
				retorno = 0;
			}
		}

		fclose(pFile);
	}

    return retorno;
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
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile;

		pFile = fopen(path,"rb");

		if(pFile != NULL)
		{
			if(!parser_EmployeeFromBinary(pFile ,pArrayListEmployee))
			{
				retorno = 0;
			}
		}

		fclose(pFile);
	}

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idMaximo)
{
	int retorno = -1;
	Employee* aux;
	char auxNombre[128];
	char auxHoras[50];
	char auxSueldo[50];
	char idAux[20];

	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		itoa(*idMaximo,idAux,10);	//Convierto un entero (int) a cadena
		utn_getString("Ingrese el nombre del empleado: ", "Error. Ingrese un nombre valido", 128, 6, auxNombre);
		getString("Ingrese el horario de trabajo del empleado: ",auxHoras,50);
		getString("Ingrese el sueldo del empleado: ",auxSueldo,50);

		aux = employee_newParametros(idAux,auxNombre,auxHoras,auxSueldo);

		if(aux != NULL)
		{
			*idMaximo = *idMaximo + 1;
			if(!ll_add(pArrayListEmployee, aux))
			{
				retorno = 0;
			}
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
	int index;
	int idAEliminar;
	char respuesta[4];
	Employee* aux;

	if(pArrayListEmployee != NULL)
	{
		getInt(&idAEliminar,"Ingrese el ID del empleado que desea modificar: ");

		index = FindEmployeeById(pArrayListEmployee,idAEliminar);

		if(index != -1)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, index);
			utn_getString("Estas seguro que desea modificar este empleado?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida", 4, 6, respuesta);

			if(stricmp(respuesta,"si") == 0)
			{
				retorno = 0;
				do
				{
					switch(SubMenuModificar())
					{
						case 1:
							utn_getString("Ingrese el nuevo nombre del empleado: ", "Error. Ingrese un nombre valido", 128, 6, aux->nombre);
							break;
						case 2:
							utn_getInt("Ingrese el nuevo horario laboral del empleado: ","Error. Ingrese un horario valido", 70, 350, 6, &aux->horasTrabajadas);
							break;
						case 3:	//Utilizar gets
							utn_getInt("Ingrese el nuevo sueldo del empleado", "Error. Ingrese un sueldo valido", 10000, 400000, 6, &aux->sueldo);
							break;
					}

					utn_getString("Desea seguir modificando?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida", 4, 6, respuesta);

				}while(stricmp(respuesta, "si") == 0);
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
	int index;
	int idAEliminar;
	char respuesta[4];

	if(pArrayListEmployee != NULL)
	{
		getInt(&idAEliminar,"Ingrese el ID del empleado que desea eliminar: ");

		index = FindEmployeeById(pArrayListEmployee,idAEliminar);

		if(index != -1)
		{
			utn_getString("Estas seguro que desea eliminar este empleado?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida", 4, 6, respuesta);

			if(stricmp(respuesta,"si") == 0)
			{
				if(!ll_remove(pArrayListEmployee,index))
				{
					retorno = 0;
				}
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
	int retorno = -1;
	Employee* aux = NULL;
	int lenght;

	if(pArrayListEmployee != NULL)
	{
		retorno = EXITO;

		lenght = ll_len(pArrayListEmployee);

	    printf("|         |                 	|                 	   |            |\n");
	    printf("|  ID  	  | Nombre       	|  Horas Trabajadas    	   |   Sueldo   |\n");
	    printf("|_________|_____________________|__________________________|____________|\n");

		for(int i = 0; i < lenght; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);

			if(!employee_showOneEmployee(aux))
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
		printf("|_________|_____________________|__________________________|____________|\n");
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

		switch(SubMenuCriterioOrdenamiento())
		{
		case 1:
			ll_sort(pArrayListEmployee,employee_compareByName, orden);
			break;
		case 2:
			ll_sort(pArrayListEmployee,employee_compareByHours, orden);
			break;
		case 3:
			ll_sort(pArrayListEmployee,employee_compareBySalary, orden);
			break;
		case 4:
			ll_sort(pArrayListEmployee,employee_compareById, orden);
			break;
		}
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
	FILE* pFile;
	Employee* aux;
	int lenght;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");//Imprimo el encabezado en la lista

			lenght = ll_len(pArrayListEmployee);

			for(int i = 0; i < lenght; i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);

				if(!employee_getId(aux,&auxId) && !employee_getNombre(aux,auxNombre) &&
				   !employee_getHorasTrabajadas(aux,&auxHoras) && !employee_getSueldo(aux,&auxSueldo))	//Get para cada caso
				{
					fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
					retorno = 0;
				}
				else
				{
					retorno = -1;
					break;
				}
			}
		}
	}

	fclose(pFile);

    return retorno;
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
	FILE* pFile;
	Employee* aux;
	int lenght;
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{

		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			lenght = ll_len(pArrayListEmployee);

			for(int i = 0; i < lenght; i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);

				if(fwrite(aux,sizeof(Employee),1,pFile) == 1)
				{
					retorno = 0;
				}
				else
				{
					retorno = -1;
					break;
				}
			}
		}
	}

	fclose(pFile);

    return retorno;
}

void InitalizeMaxId(char* path, int* idMaximo)
{
	FILE* pArchivoId;

    pArchivoId = fopen(path,"r");

    if(pArchivoId != NULL)
    {
    	fscanf(pArchivoId,"%d\n", idMaximo);
    }

    fclose(pArchivoId);
}

void WriteMaxId(char* path, int* idMaximo)
{
    FILE* pArchivoId;

	pArchivoId= fopen(path,"w");

    if(pArchivoId != NULL)
    {
    	fprintf(pArchivoId,"%d",*idMaximo);
    }

    fclose(pArchivoId);
}

int FindEmployeeById(LinkedList* pArrayListEmployee, int idAEliminar)
{
	int index = -1;
	int idAux;
	int lenght;
	Employee* aux;

	if(pArrayListEmployee != NULL)
	{
		lenght = ll_len(pArrayListEmployee);

		for(int i = 0; i < lenght; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);

			employee_getId(aux,&idAux);
			if(idAux == idAEliminar)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
