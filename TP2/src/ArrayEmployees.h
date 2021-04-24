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

void InitEmployees(eEmployees[], int);

#endif /* ARRAYEMPLOYEES_H_ */
