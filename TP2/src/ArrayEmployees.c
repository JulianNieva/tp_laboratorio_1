/*
 * ArrayEmployees.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"

void InitEmployees(eEmployees listOfEmployees[])
{
	int i;

	for(i = 0; i < LIMIT; i++)
	{
		listOfEmployees[i].isEmpty = EMPTY;
	}
}

int AddEmployees(eEmployees listOfEmployees[])
{
	int i;

	i = FindEmpty(listOfEmployees);

	if(i != -1)
	{
		listOfEmployees[i].id = i+1;
		GetString("Ingrese el nombre del empleado: ", listOfEmployees[i].name);
		GetString("Ingrese el apellido del empleado: ", listOfEmployees[i].lastName);
		listOfEmployees[i].salary = GetFloat("Ingrese el salario del empleado: ");
		listOfEmployees[i].sector = GetInt("Ingrese el id del sector del empleado: ");
		listOfEmployees[i].isEmpty = NOT_EMPTY;
	}

	return i;
}

int RemoveEmployees(eEmployees listOfEmployees[])
{
	int id;
	int posicionId;
	int retorno;
	int opcion;

	retorno = -1;

	id = GetInt("Ingrese el ID del empleado: ");

	posicionId = FindEmployeeById(listOfEmployees,id);

	if(posicionId != -1)
	{
		retorno = 0;

		opcion = GetInt("Esta seguro que desea dar de baja este empleado?\n(Ingrese 1 para aceptar, 0 para cancelar):  ");
		if(opcion == 1)
		{
			retorno = 1;
			listOfEmployees[posicionId].isEmpty = EMPTY;
		}
	}

	return retorno;
}

int FindEmpty(eEmployees listOfEmployees[])
{
	int i;
	int index;
	index = -1;

	for(i = 0; i < LIMIT; i++)
	{
		if(listOfEmployees[i].isEmpty == EMPTY)
		{
			index = i;
			break;
		}
	}

	return index;
}

int FindEmployeeById(eEmployees listOfEmployees[], int id)
{
	int i;
	int index;
	index = -1;

	for(i = 0; i < LIMIT; i++)
	{
		if(id == listOfEmployees[i].id)
		{
			index = i;
			break;
		}
	}

	return index;
}
