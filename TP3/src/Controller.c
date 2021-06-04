#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

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

	printf("Hola1");

	FILE* pFile;
	Employee *auxiliar;

	char buffferId[20];
	char buffferNombre[100];
	char buffferHoras[20];
	char buffferSueldo[20];

	pFile = fopen(path,"r");

	if(pFile == NULL)
	{
		return ERROR;
	}

	printf("Hola2");

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffferId,buffferNombre,buffferHoras,buffferSueldo);

	while(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffferId,buffferNombre,buffferHoras,buffferSueldo) == 4)
	{
		printf("Hola4");
		auxiliar = employee_newParametros(buffferId,buffferNombre,buffferHoras,buffferSueldo);

		printf("Hola4");

		ll_add(pArrayListEmployee, auxiliar);
	}
	printf("Hola3");

	fclose(pFile);

	printf("\n\n\n%d\n\n\n", ll_len(pArrayListEmployee));

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
	Employee* auxiliar = NULL;
	char buffferId[20];
	char buffferNombre[20];
	char buffferHoras[20];
	char buffferSueldo[20];

	pFile = fopen(path,"rb");

	if(pFile == NULL)
	{
		return ERROR;
	}

	fread(auxiliar,sizeof(Employee),1,pFile);

	while(!feof(pFile))
	{
		fread(auxiliar,sizeof(Employee),1,pFile);
		auxiliar = employee_newParametros(buffferId,buffferNombre,buffferHoras,buffferSueldo);

		ll_add(pArrayListEmployee, auxiliar);
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
    return 1;
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
    return 1;
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
    return 1;
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
	Node* nodoActual;

	if(pArrayListEmployee != NULL)
	{
		retorno = EXITO;

		nodoActual = pArrayListEmployee->pFirstNode;

		while(nodoActual != NULL)
		{
			aux = (Employee*)nodoActual->pElement;

			employee_showOneEmployee(aux);

			nodoActual = nodoActual->pNextNode;
		}
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
    return 1;
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

