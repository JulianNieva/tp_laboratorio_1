/*
 * ArrayEmployees.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

void InitEmployees(eEmployees listOfEmployees[], int lenght)
{
	int i;

	for(i = 0; i < lenght; i++)
	{
		listOfEmployees[i].isEmpty = EMPTY;
	}
}
