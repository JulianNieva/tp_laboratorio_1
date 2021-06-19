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
	Employee auxiliar;

	int retorno = -1;

	char bufferId[20];
	char bufferHoras[20];
	char bufferSueldo[20];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(fread(&auxiliar,sizeof(Employee),1,pFile) == 1)
		{
			retorno = 0;

			itoa(auxiliar.id,bufferId,10);
			itoa(auxiliar.horasTrabajadas,bufferHoras,10);
			itoa(auxiliar.sueldo,bufferSueldo,10);

			Employee* aAgregar = employee_newParametros(bufferId,auxiliar.nombre,bufferHoras,bufferSueldo);

			if(ll_add(pArrayListEmployee, aAgregar) == -1) //Valido si se pudo agregar el nuevo empleado a la lista
			{
				retorno = -1;
				break;
			}
		}
	}

    return retorno;
}
