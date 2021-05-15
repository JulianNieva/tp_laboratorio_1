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

int ShowMenu(void)
{
	int option;

	puts("1. Add an employee");
	puts("2. Modify an employee");
	puts("3. Remove an employee");
	puts("4. Inform");
	puts("5. Exit");
	utn_getInt("Please select an option: ", "\nError. Please enter a valid option\n", 1, 5, 4, &option);

	return option;
}

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

void IncreaseIdAutomatically(int* id)
{
	*id +=1;
}

int AskForData(eEmployees employees[], int lenght, int* id)
{
	int value = -1;
	int index;
	int idAux;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	if(employees != NULL && lenght > 0)
	{
		index = FindEmpty(employees, lenght);

		if(index != -1)
		{

			IncreaseIdAutomatically(id);
			idAux = *id;
			utn_getString("Please enter the name of the employee: ", "Please enter a valid name\n ",51,4, name);
			utn_getString("Please enter the last name of the employee: ", "Please enter a valid last name \n", 51, 4,lastName);
			utn_getFloat("Please enter the salary of the employee: ", "Error, please enter a valid salary (Between 1000 to 10000)\n", 1000, 10000, 4, &salary);
			utn_getInt("Please enter the sector ID\n(Enter a number between 1 to 4): ","Error, please enter a valid number\n", 1,4,4, &sector);

			AddEmployee(&employees[index], lenght, idAux, name, lastName, salary, sector);

			value = 0;
		}
		else
		{
			printf("There is no space left\n");
		}
	}

	return value;
}

int AddEmployee(eEmployees* employee, int lenght, int id, char name[], char lastName[], float salary, int sector)
{
	int value = -1;

	if(employee != NULL && lenght > 0 && name != NULL && lastName != NULL && id > 0 && salary > 0 && sector > 0)
	{
		value = 0;

		employee->id = id;
		employee->salary = salary;
		strcpy(employee->name, name);
		strcpy(employee->lastName, lastName);
		employee->sector = sector;
		employee->isEmpty = NOT_EMPTY;

		printf("The employee has been successfully added!\n");
	}

	return value;
}

int RemoveEmployees(eEmployees listOfEmployees[], int lenght, int id)
{
	int positionId;
	int value = -1;
	char answer[4];

	if(listOfEmployees != NULL && lenght > 0)
	{
		positionId = FindEmployeeById(listOfEmployees, lenght, id);
		if(positionId != -1)
		{
			utn_getString("Are you sure you want to remove this employee?\n(Type yes to accept, no to cancel): ","Error. Please type a valid option",4,4, answer);
			if(stricmp(answer, "yes") == 0)
			{
				listOfEmployees[positionId].isEmpty = EMPTY;
				printf("You successfully removed the employee!\n");
			}
			else
			{
				printf("You cancelled the operation\n");
			}
		}
		else
		{
			printf("Id of the employee not found...\n");
		}
		value = 0;
	}


	return value;
}

int InitModifyProccess(eEmployees employees[], int lenght)
{
	int value = -1;
	int id;
	int positionId;
	char answer[4];

	if(employees != NULL || lenght < 0)
	{
		value = 0;

		utn_getInt("Please enter the id of the employee you wish to modify: ","Error, please enter a valid ID\n", 1,1000,4, &id);

		positionId = FindEmployeeById(employees,lenght,id);

		if(positionId != -1)
		{
			printf("This is the employee found\n");
			PrintOneEmployee(employees[positionId]);

			utn_getString("Are you sure you want to modify this employee?\n(Type yes to accept, no to cancel)", "Error. please enter a valid answer\n", 4, 4, answer);

			if(stricmp(answer, "yes")==0)
			{
				ModifyEmployee(&employees[positionId]);
			}
			else
			{
				printf("You cancelled the operation...\n");
			}
		}
		else
		{
			printf("Employee ID not found...\n");
		}
	}

	return value;
}

void ModifyEmployee(eEmployees* employee)
{
	int option;
	char answer[4];

	strcpy(answer,"no");

	if(employee != NULL)
	{
		do
		{
			printf("MODIFICATION\n");
			printf("1. Modify name\n");
			printf("2. Modify last name\n");
			printf("3. Modify salary\n");
			printf("4. Modify sector\n");
			printf("5. Exit\n");
			utn_getInt("Please select an option\n", "Error. Please enter a valid option\n", 1, 5, 4, &option);

			switch(option)
			{
			case 1:
				utn_getString("Please enter the new name of the employee: ", "Please enter a valid name\n ",51,4, employee->name);
				printf("You have successfully changed the name!\n");
				break;
			case 2:
				utn_getString("Please enter the new last name of the employee: ", "Please enter a valid last name \n", 51, 4, employee->lastName);
				printf("You have successfully changed the last name!\n");
				break;
			case 3:
				utn_getFloat("Please enter the new salary of the employee: ", "Error, please enter a valid number\n", 1000, 10000, 4, &employee->salary);
				printf("You have successfully changed the salary!\n");
				break;
			case 4:
				utn_getInt("Please enter the new sector ID\n(Enter a number between 1 to 4): ","Error, please enter a valid number\n", 1,4,4, &employee->sector);
				printf("You have successfully changed the sector!\n");
				break;
			case 5:
				utn_getString("Are you sure you want to exit?\n(Type yes to accept, no to cancel)", "Error. please enter a valid answer\n", 4, 4, answer);
				break;
			}
		}while(stricmp(answer, "yes"));
	}
}

int FindEmpty(eEmployees listOfEmployees[], int lenght)
{
	int i;
	int index;
	index = -1;

	if(listOfEmployees != NULL && lenght > 0)
	{
		for(i = 0; i < lenght; i++)
		{
			if(listOfEmployees[i].isEmpty == EMPTY)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int FindEmployeeById(eEmployees listOfEmployees[], int lenght,int id)
{
	int i;
	int index;
	index = -1;

	if(listOfEmployees != NULL || lenght > 0)
	{
		for(i = 0; i < lenght; i++)
		{
			if(id == listOfEmployees[i].id && listOfEmployees[i].isEmpty != EMPTY)
			{
				index = i;
				break;
			}
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
	    printf("|         |                          |                 |            |\n");
	    printf("|     ID  | Name     Last Name       |  Salary         |   Sector   |\n");
	    printf("|_________|__________________________|_________________|____________|\n");
		for(i = 0; i < lenght; i++)
		{
			if(employees[i].isEmpty != EMPTY)
			{
				PrintOneEmployee(employees[i]);
			}
		}
		printf("|_________|__________________________|_________________|____________|\n");
		value = 0;
	}

	return value;
}

void PrintOneEmployee(eEmployees employee)
{
	printf("|      %d  | %-10s %s         | %.2f         |      %d     |\n",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
}

int ShowInformSubMenu(eEmployees employees[], int lenght)
{
	int option;
	int value = -1;
	int order;

	if(employees != NULL && lenght > 0)
	{
		value = 0;
		do
		{
			printf("1. List of the employees ordered by Last name and sector\n");
			printf("2. Average and total wages, and the employees who exceed the average\n");
			printf("3. Return\n");
			utn_getInt("Please enter one of the options above: " ,"Error. Please enter a valid option\n", 1, 3, 4, &option);

			switch (option)
			{
				case 1:
					utn_getInt("Please enter the order you wish to see the list of the employees\n(1 to show it in UP order, 0 DOWN order)","Error, please enter a valid option\n", 0,1,4,&order);
					SortEmployees(employees,lenght, order);
					break;
				case 2:
					CalculateTotalOfSalary(employees,lenght);
					break;
				case 3:
					break;
			}
		}while(option != 3);
	}

	return value;

}

int CalculateTotalOfSalary(eEmployees employees[], int lenght)
{
	int i;
	int value = -1;
	float average = 0;
	float acumulator = 0;
	int counter = 0;

	if(employees != NULL && lenght > 0)
	{
		value = 0;
		for(i = 0; i < lenght; i++)
		{
			if(employees[i].isEmpty != EMPTY)
			{
				acumulator = acumulator + employees[i].salary;
				counter++;
			}
		}

		if(acumulator > 0)
		{
			average = acumulator / counter;
		}
		printf(">>>>>The total of the employees salaries is: %.2f<<<<<\n",acumulator);
		printf(">>>>>The average salary of the employees is: %.2f<<<<<\n",average);

		PrintEmployeeWhoExceedTheAverageSalary(employees, lenght, average);

	}

	return value;

}

int PrintEmployeeWhoExceedTheAverageSalary(eEmployees employees[], int lenght, float average)
{
	int i;
	int value = -1;

	if(employees != NULL && lenght > 0 && average > 0)
	{
		printf("////These are the employees who exceed the average salary//// \n");
	    printf("|         |                          |                 |            |\n");
	    printf("|     ID  | Name     Last Name       |  Salary         |   Sector   |\n");
	    printf("|_________|__________________________|_________________|____________|\n");
		for(i = 0; i < lenght; i++)
		{
			if(employees[i].isEmpty != EMPTY && employees[i].salary > average)
			{
				PrintOneEmployee(employees[i]);
			}
		}
		value = 0;
	}

	return value;
}

int SortEmployees(eEmployees employees[], int lenght, int order)
{
	int value = -1;
	int i;
	int j;
	eEmployees aux;

	if(employees != NULL && lenght > 0 && (order == 0 || order == 1))
	{
		value = 0;

		if(order == 1)
		{
			// A-Z
			for(i = 0; i < lenght - 1; i++)
			{
				for(j = i + 1; j < lenght; j++)
				{
					if(employees[i].sector > employees[j].sector || (employees[i].sector == employees[j].sector && stricmp(employees[i].lastName,employees[j].lastName)>0) ||
					(employees[i].sector == employees[j].sector && stricmp(employees[i].lastName,employees[j].lastName)== 0 && stricmp(employees[i].name,employees[j].name) > 0))

					{
						aux = employees[i];
						employees[i] = employees[j];
						employees[j] = aux;
					}
				}
			}
		}
		else
		{
			//Z-A
			for(i = 0; i < lenght - 1; i++)
			{
				for(j = i + 1; j < lenght; j++)
				{
					if(employees[i].sector > employees[j].sector || (employees[i].sector == employees[j].sector && stricmp(employees[i].lastName,employees[j].lastName)<0) ||
					  (employees[i].sector == employees[j].sector && stricmp(employees[i].lastName,employees[j].lastName)== 0 && stricmp(employees[i].name,employees[j].name) < 0))

					{
						aux = employees[i];
						employees[i] = employees[j];
						employees[j] = aux;
					}
				}
			}
		}

		PrintEmployees(employees,lenght);
	}

	return value;
}
