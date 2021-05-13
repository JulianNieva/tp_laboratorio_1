/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"

#define NOT_ENTERED 0
#define ENTERED 1

int main(void)
{
	eEmployees employeeList[LIMIT];
	int option;
	int index;
	int id;
	int flagEmployee = NOT_ENTERED;

	setbuf(stdout, NULL);

	InitEmployees(employeeList,LIMIT);

	do
	{
		puts("1. Add an employee");
		puts("2. Modify an employee");
		puts("3. Remove an employee");
		puts("4. Inform");
		puts("5. Exit");
		option = GetInt("Choose an option:  ");

		switch (option)
		{
		case 1:
			if(index != -1)
			{
				puts("The employee has been succesfully added!");
			}
			else
			{
				puts("There is no more space to add another employee..");
			}
			flagEmployee = ENTERED;
			break;
		case 2:
			if(flagEmployee == ENTERED)
			{
				PrintEmployees(employeeList,LIMIT);
				index = InitModifyProccess(employeeList,LIMIT);
				if(index == -1)
				{
					puts("The employee id could not be found");
				}
			}
			else
			{
				puts("Be sure to add at least one employee before you modify one");
			}
			break;
		case 3:
			if(flagEmployee == ENTERED)
			{
				PrintEmployees(employeeList,LIMIT);
				id = GetInt("Enter the id of the employee you wish to remove: ");
				index = RemoveEmployees(employeeList, LIMIT, id);
				if(index == -1)
				{
					puts("The employee id could not be found");
				}
				else
				{
					if(index == 0)
					{
						puts("You cancelled the operation...");
					}
					else
					{
						puts("The employee has been succesfully removed!");
					}
				}
			}
			else
			{
				puts("Be sure to add at least one employee before you remove one");
			}
			break;
		case 4:
			if(flagEmployee == ENTERED)
			{
				puts("I will be able to inform something soon...");
				PrintEmployees(employeeList,LIMIT);
			}
			else
			{
				puts("Be sure to add at least one employee before you can see a report");
			}
			break;
		case 5:
			puts("Thank you for using our service!");
			break;
		}
	}while(option != 5);
}
