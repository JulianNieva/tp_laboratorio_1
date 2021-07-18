#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxiliar;
	char bufferId[50];
	char bufferNombre[50];
	char bufferHoras[50];
	char bufferSueldo[50];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);	//Lee el encabezado

		while(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo) == 4)
		{
			auxiliar = employee_newParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);

			if(!ll_add(pArrayListEmployee, auxiliar))//Acordarse de validar si lo pudo agregar
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

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* aux = NULL;
	int retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			aux = employee_new();	//Creo en memoria un empleado

			if(aux != NULL)	//Me aseguro de que distinto de NULL
			{
				if(fread(aux,sizeof(Employee),1,pFile))	//Si pudo leer al empleado correctamente entra el if
				{
					ll_add(pArrayListEmployee,aux);	//Agrego el empleado leido a la lista
					retorno = 0;
				}
				else	//Si no, borro de memoria al empleado
				{
					employee_delete(aux);
				}
			}

		}while(!feof(pFile));
	}

    return retorno;
}
