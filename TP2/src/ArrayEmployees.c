/*
 * ArrayEmployees.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"

int InitEmployees(eEmployees listOfEmployees[], int lenght)
{
	int i;
	int value = -1;

	if(listOfEmployees != NULL || lenght > 0)
	{
		for(i = 0; i < lenght; i++)
		{
			listOfEmployees[i].isEmpty = EMPTY;
		}
		value = 0;
	}

	return value;
}

int RemoveEmployees(eEmployees listOfEmployees[], int lenght, int id)
{
	int positionId;
	int value;
	int option;

	value = -1;

	positionId = FindEmployeeById(listOfEmployees, lenght, id);

	if(positionId != -1)
	{
		value = 0;

		option = GetInt("Are you sure you want to remove this employee?\n(Enter 1 if you accept, 0 to cancel the operation):  ");
		if(option == 1)
		{
			value = 1;
			listOfEmployees[positionId].isEmpty = EMPTY;
		}
	}

	return value;
}

int InitModifyProccess(eEmployees employees[], int lenght)
{
	int value = -1;
	int id;
	int positionId;
	int answer;

	if(employees != NULL || lenght < 0)
	{
		value = 0;

		id = GetInt("Enter the ID of the employee you wish to modify: ");

		positionId = FindEmployeeById(employees,lenght,id);

		if(positionId != -1)
		{
			printf("This is the employee found");
			PrintOneEmployee(employees[positionId]);

			answer = GetInt("Are you sure you want to modify this employee? \n (Enter 1 to accept, 0 to cancel)");

			if(answer == 1)
			{
				ModifyEmployee(&employees[positionId]);
			}
			else
			{
				printf("You cancelled the operation...");
			}
		}
	}

	return value;
}

void ModifyEmployee(eEmployees* employee)
{
	int option;
	int answer = 1;


	if(employee != NULL)
	{
		do
		{
			printf("1. Modify name");
			printf("2. Modify last name");
			printf("3. Modify salary");
			printf("4. Modify sector");
			printf("5. Exit");
			option = GetInt("Please select one of the options above: ");

			switch(option)
			{
			case 1:
				GetString("Please enter the new name of the employee: ",employee->name);
				printf("You have successfully changed the name!");
				break;
			case 2:
				GetString("Please enter the new last name of the employee: ",employee->lastName);
				printf("You have successfully changed the last name!");
				break;
			case 3:
				employee->salary = GetFloat("Please enter the new salary of the employee: ");
				printf("You have successfully changed the salary!");
				break;
			case 4:
				employee->sector = GetInt("Please enter the new sector of the employee: ");
				printf("You have successfully changed the sector!");
				break;
			case 5:
				answer = GetInt("Are you sure you want to exit?\n(Type 1 to accept, 0 to exit)");
				break;
			}

		}while(answer != 0);
	}
}

int FindEmpty(eEmployees listOfEmployees[], int lenght)
{
	int i;
	int index;
	index = -1;

	for(i = 0; i < lenght; i++)
	{
		if(listOfEmployees[i].isEmpty == EMPTY)
		{
			index = i;
			break;
		}
	}

	return index;
}

int FindEmployeeById(eEmployees listOfEmployees[], int lenght,int id)
{
	int i;
	int index;
	index = -1;

	for(i = 0; i < lenght; i++)
	{
		if(id == listOfEmployees[i].id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int PrintEmployees(eEmployees employees[], int lenght)
{
	int i;
	int value = -1;

	if(employees != NULL || lenght > 0)
	{
		printf("ID \t Name \t Last Name \t Salary \t Sector");
		for(i = 0; i < lenght; i++)
		{
			if(employees[i].isEmpty != EMPTY)
			{
				PrintOneEmployee(employees[i]);
			}
		}
		value = 0;
	}

	return value;
}

void PrintOneEmployee(eEmployees employee)
{
	printf("%d %s %s %.2f %d",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
}
