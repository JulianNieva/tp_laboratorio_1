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
#include "Menu.h"

int main(void)
{
	eEmployees employeeList[LIMIT];

	setbuf(stdout, NULL);

	InitEmployees(employeeList);

	ShowcaseMenu(employeeList);
}
