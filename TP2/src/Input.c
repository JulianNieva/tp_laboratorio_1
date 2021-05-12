/*
 * Input.c
 *
 *  Created on: 1 may. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int GetInt(char mensaje[])
{
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}

float GetFloat(char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}

char GetChar(char mensaje[])
{
	char letra;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &letra);

	return letra;
}

void GetString(char mensaje[], char text[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", text);
}
