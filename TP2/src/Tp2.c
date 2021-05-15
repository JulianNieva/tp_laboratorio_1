/*
 ============================================================================
 Name        : Tp2.c
 Author      : Julian Leandro Nieva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Input.h"

#define NOT_ENTERED 0
#define ENTERED 1

int main(void)
{
	eEmployees employeeList[LIMIT];
	int value;
	int flagEmployee = NOT_ENTERED;
	int idAutoIncrease = 0;
	int auxId;
	char answer[4];

	setbuf(stdout, NULL);

	InitEmployees(employeeList,LIMIT);

	strcpy(answer,"no");

	do
	{
		switch (ShowMenu())
		{
		case 1:
			value = AskForData(employeeList,LIMIT, &idAutoIncrease);
			if(value != -1)
			{
				flagEmployee = ENTERED;
			}
			break;
		case 2:
			if(flagEmployee == ENTERED)
			{
				PrintEmployees(employeeList,LIMIT);
				InitModifyProccess(employeeList,LIMIT);
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
				utn_getInt("Please enter the id of the employee you wish to remove: ","Error, please enter a valid ID", 1,1000,4, &auxId);
				RemoveEmployees(employeeList, LIMIT, auxId);
			}
			else
			{
				puts("Be sure to add at least one employee before you remove one");
			}
			break;
		case 4:
			if(flagEmployee == ENTERED)
			{
				ShowInformSubMenu(employeeList,LIMIT);
			}
			else
			{
				puts("Be sure to add at least one employee before you can see a report");
			}
			break;
		case 5:
			utn_getString("Are you sure you want to exit this program?\n(Type yes to exit, no to stay)", "Error. Please type a valid answer",4,4,answer);
			break;
		}
	}while(stricmp(answer, "yes"));

	puts("Thank you for using this program!");
}
