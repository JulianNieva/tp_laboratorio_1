/*
 * ArrayEmployees.h
 *
 *  Created on: 23 abr. 2021
 *      Author: Julian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define EMPTY 0
#define NOT_EMPTY 1

#define LIMIT 10

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployees;

int InitEmployees(eEmployees[], int);

int IncreaseIdAutomatically(void);

int RemoveEmployees(eEmployees[], int, int);

int InitModifyProccess(eEmployees[], int);

void ModifyEmployee(eEmployees *);

int FindEmpty(eEmployees[], int);

int FindEmployeeById(eEmployees[], int,int);

int PrintEmployees(eEmployees[], int);

void PrintOneEmployee(eEmployees);

#endif /* ARRAYEMPLOYEES_H_ */
