/*
 * Input.c
 *
 *  Created on: 1 may. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int GetInt(char message[])
{
	int number;

	printf("%s", message);
	scanf("%d", &number);

	return number;
}

float GetFloat(char message[])
{
	float number;

	printf("%s", message);
	scanf("%f", &number);

	return number;
}

char GetChar(char message[])
{
	char letter;

	printf("%s", message);
	fflush(stdin);
	scanf("%c", &letter);

	return letter;
}

void GetString(char mensaje[], char text[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", text);
}
