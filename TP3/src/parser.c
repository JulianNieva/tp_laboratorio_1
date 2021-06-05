#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#define ERROR -1
#define EXITO 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxiliar;
	char bufferId[50];
	char bufferNombre[50];
	char bufferHoras[50];
	char bufferSueldo[50];

	if(pFile == NULL && pArrayListEmployee == NULL)
	{
		return ERROR;
	}

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);

	while(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo) == 4)
	{
		auxiliar = employee_newParametrosTXT(bufferId,bufferNombre,bufferHoras,bufferSueldo);

		ll_add(pArrayListEmployee, auxiliar);
	}

    return EXITO;
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
	Employee* auxiliar = NULL;
	char bufferId[20];
	char bufferNombre[128];
	char bufferHoras[20];
	char bufferSueldo[20];

	if(pFile == NULL && pArrayListEmployee == NULL)
	{
		return ERROR;
	}

	fread(auxiliar,sizeof(Employee),1,pFile);

	parser_EmployeeFromBinary(pFile, pArrayListEmployee);

	while(!feof(pFile))
	{
		fread(auxiliar,sizeof(Employee),1,pFile);
		auxiliar = employee_newParametrosTXT(bufferId,bufferNombre,bufferHoras,bufferSueldo);

		ll_add(pArrayListEmployee, auxiliar);
	}

	fclose(pFile);

    return 1;
}
