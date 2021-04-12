/*
 * OperacionesMatematicas.c
 *
 *  Created on: 5 abr. 2021
 *      Author: Julian
 */

#include "OperacionesMatematicas.h"

float CalcularSuma (float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;

}

float CalcularResta (float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero - segundoNumero;


	return resultado;
}

float CalcularDivision (float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = (float)primerNumero / segundoNumero;

	return resultado;
}

float CalcularMultiplicacion (float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;
}

float CalcularFactorialX (float primerNumero)
{
	float i;
	float factorial;

	factorial = 1;

	for(i = primerNumero ;i > 0; i--)
	{
		factorial = factorial * i;
	}

	return factorial;
}

float CalcularFactorialY (float segundoNumero)
{
	float i;
	float factorial;

	factorial = 1;

	for(i = segundoNumero ;i > 0; i--)
	{
		factorial = factorial * i;
	}

	return factorial;
}

