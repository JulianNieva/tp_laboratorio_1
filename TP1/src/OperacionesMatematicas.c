/*
 * OperacionesMatematicas.c
 *
 *  Created on: 5 abr. 2021
 *      Author: Julian
 */

#include "OperacionesMatematicas.h"

int CalcularSuma (int primerNumero, int segundoNumero)
{
	int resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;

}

int CalcularResta (int primerNumero, int segundoNumero)
{
	int resultado;

	resultado = primerNumero - segundoNumero;


	return resultado;
}

float CalcularDivision (int primerNumero, int segundoNumero)
{
	float resultado;

	resultado = (float)primerNumero / segundoNumero;

	return resultado;
}

int CalcularMultiplicacion (int primerNumero, int segundoNumero)
{
	int resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;
}

float CalcularFactorialX (int primerNumero)
{
	int i;
	int factorial;

	factorial = 1;

	for(i = primerNumero ;i > 0; i--)
	{
		factorial = factorial * i;
	}

	return factorial;
}

float CalcularFactorialY (int segundoNumero)
{
	int i;
	int factorial;

	factorial = 1;

	for(i = segundoNumero ;i > 0; i--)
	{
		factorial = factorial * i;
	}

	return factorial;
}

