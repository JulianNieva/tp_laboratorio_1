#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"
#include "parser.h"
#include "Menu.h"
#include "Controller.h"

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

	int sueldo;
	int horasTrabajadas;
	char auxNombre[128];

	char horasStr[50];
	char sueldoStr[50];
	char idStr[20];

	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		ReadMaxId("idMaximo.csv",idMaximo);

		utn_getString("Ingrese el nombre del empleado: ", "Error. Ingrese un nombre valido ", 128, 6, auxNombre);
		utn_getInt("Ingrese el horario laboral del empleado: ","Error. Ingrese un horario valido ", 50, 400, 6, &horasTrabajadas);
		utn_getInt("Ingrese el sueldo del empleado: ", "Error. Ingrese un sueldo valido ", 10000, 500000, 6, &sueldo);

		itoa(horasTrabajadas,horasStr,10);
		itoa(*idMaximo,idStr,10);
		itoa(sueldo,sueldoStr,10);

		aux = employee_newParametros(idStr,auxNombre,horasStr,sueldoStr);

		if(aux != NULL)
		{
			if(!ll_add(pArrayListEmployee, aux))
			{
				*idMaximo = GetMaxId(pArrayListEmployee);
				*idMaximo = *idMaximo + 1;
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
	int idAModificar;
	char respuesta[4];

	int sueldoAux;
	int horasAux;
	char nombreAux[128];

	Employee* aux;

	if(pArrayListEmployee != NULL)
	{
		utn_getInt("Ingrese el ID del empleado que desea dar de baja: ","Error. Ingrese un ID valido ", 1, 10000, 6, &idAModificar);

		index = FindEmployeeById(pArrayListEmployee,idAModificar);

		if(index != -1)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, index);
			utn_getString("Estas seguro que desea modificar este empleado?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida ", 4, 6, respuesta);

			if(stricmp(respuesta,"si") == 0)
			{
				retorno = 0;
				do
				{
					switch(SubMenuModificar())
					{
						case 1:
							utn_getString("Ingrese el nuevo nombre del empleado: ", "Error. Ingrese un nombre valido ", 128, 6, nombreAux);
							employee_setNombre(aux,nombreAux);
							break;
						case 2:
							utn_getInt("Ingrese el nuevo horario laboral del empleado: ","Error. Ingrese un horario valido ", 70, 350, 6, &horasAux);
							employee_setHorasTrabajadas(aux,horasAux);
							break;
						case 3:
							utn_getInt("Ingrese el nuevo sueldo del empleado", "Error. Ingrese un sueldo valido ", 10000, 400000, 6, &sueldoAux);
							employee_setSueldo(aux,sueldoAux);
							break;
					}

					utn_getString("Desea seguir modificando?\n(Escriba SI para aceptar): ", "Error. Ingrese una respuesta valida ", 4, 6, respuesta);

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
		utn_getInt("Ingrese el ID del empleado que desea dar de baja: ","Error. Ingrese un ID valido ", 1, 10000, 6, &idAEliminar);

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
		retorno = 0;

		lenght = ll_len(pArrayListEmployee);

		printf(" _______________________________________________________________________\n");
	    printf("|  ID  	  | Nombre       	|  Horas Trabajadas    	   |   Sueldo   |\n");
	    printf("|_________|_____________________|__________________________|____________|\n");

		for(int i = 0; i < lenght; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);

			if(employee_showOneEmployee(aux) == -1)
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
		retorno = 0;

		utn_getInt("Ingrese el orden deseado\n(1 para ascendente, 0 para descendente):  ", "Error. Ingrese un orden valido ", 0, 1, 6, &orden);

		switch(SubMenuCriterioOrdenamiento())
		{
		case 1:
			if(ll_sort(pArrayListEmployee,employee_compareByName, orden) == -1)
			{
				retorno = -1;
			}
			break;
		case 2:
			if(ll_sort(pArrayListEmployee,employee_compareByHours, orden)== -1)
			{
				retorno = -1;
			}
			break;
		case 3:
			if(ll_sort(pArrayListEmployee,employee_compareBySalary, orden) == -1)
			{
				retorno = -1;
			}
			break;
		case 4:
			if(ll_sort(pArrayListEmployee,employee_compareById, orden) == -1)
			{
				retorno = -1;
			}
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

/**
 * @fn void ReadMaxId(char*, int*)
 * @brief Leo el proximo ID que se le asignara a un empleado
 *
 * @param path Nombre del archivo
 * @param idMaximo Puntero al idMaximo
 */
void ReadMaxId(char* path, int* idMaximo)
{
	FILE* pArchivoId;

    pArchivoId = fopen(path,"r");

    if(pArchivoId != NULL)
    {
    	fscanf(pArchivoId,"%d\n", idMaximo);
    }

    fclose(pArchivoId);
}

/**
 * @fn void WriteMaxId(char*, int*)
 * @brief Escribo el nuevo ID maximo en el archivo
 *
 * @param path Nombre del archivo
 * @param idMaximo Puntero al idMaximo
 */
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

/**
 * @fn int FindEmployeeById(LinkedList*, int)
 * @brief Busco un empleado por ID y devuelvo su posicion
 *
 * @param pArrayListEmployee Puntero a la lista de empleados
 * @param idABuscar ID a buscar
 * @return Devuelvo -1 si no se encontro al empleado, sino la posicion del empleado encontrado
 */
int FindEmployeeById(LinkedList* pArrayListEmployee, int idABuscar)
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
			if(idAux == idABuscar)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

/**
 * @fn int GetMaxId(LinkedList*)
 * @brief Obtengo el ID maximo y lo retorno
 *
 * @param pArrayListEmployee Puntero a la lista de empleados
 * @return Devuelvo el ID mayor
 */
int GetMaxId(LinkedList* pArrayListEmployee)
{
	int IdMayor;
	int id;
	int len;
	int i;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(aux,&id);

				if(i == 0 || (IdMayor<id))
				{
					IdMayor=id;
				}
			}
		}
	}

	return IdMayor;
}
