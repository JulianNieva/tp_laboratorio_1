/*
 * PedirNumeros.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Julian
 */

#include "PedirNumeros.h"

float PedirPrimerOperando(void)
{
	float x;

	printf("Ingrese el primer operando (A): ");
	scanf("%f", & x);

	return x;
}

float PedirSegundoOperando(void)
{
	float y;

	printf("Ingrese el segundo operando (B): ");
	scanf("%f", & y);

	return y;
}
