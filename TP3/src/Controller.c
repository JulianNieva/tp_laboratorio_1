#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"

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
	Employee* auxiliar;

	char buffferId[20];
	char buffferNombre[100];
	char buffferHoras[20];
	char buffferSueldo[20];

	pFile = fopen(path,"r");

	if(pFile == NULL)
	{
		return ERROR;
	}

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffferId,buffferNombre,buffferHoras,buffferSueldo);

	while(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffferId,buffferNombre,buffferHoras,buffferSueldo) == 4)
	{
		auxiliar = employee_newParametrosTXT(buffferId,buffferNombre,buffferHoras,buffferSueldo);

		ll_add(pArrayListEmployee, auxiliar);
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
	Employee* auxiliar = NULL;
	char buffferId[20];
	char buffferNombre[128];
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
		auxiliar = employee_newParametrosTXT(buffferId,buffferNombre,buffferHoras,buffferSueldo);

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
	int retorno = -1;
	Employee* aux;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL)
	{
		utn_getString("Ingrese el nombre del empleado", "Error. Ingrese un nombre valido", 128, 6, auxNombre);
		utn_getInt("Ingrese las horas que trabaja el empleado", "Error. Ingrese un horario valido", 70, 350, 6, &auxHoras);
		utn_getInt("Ingrese el sueldo del empleado", "Error. Ingrese un sueldo valido", 10000, 400000, 6, &auxSueldo);

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

