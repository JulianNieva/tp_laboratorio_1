/*
 * PedirEnteros.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Julian
 */

#include "PedirEnteros.h"

int PedirPrimerOperando(void)
{
	int x;

	printf("Ingrese el primer operando (A): ");
	scanf("%d", & x);

	return x;
}

int PedirSegundoOperando(void)
{
	int y;

	printf("Ingrese el segundo operando (B): ");
	scanf("%d", & y);

	return y;
}
