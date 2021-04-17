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

	resultado = 0;

	if(segundoNumero == 0)
	{
		resultado = -1;
	}
	else
	{
		resultado = (float)primerNumero / segundoNumero;
	}

	return resultado;
}

float CalcularMultiplicacion (float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;
}


unsigned long long int CalcularFactorial (int numero)
{
	float i;
	unsigned long long int factorial;

	factorial = 1;

	if(numero < 0)
	{
		factorial = -1;
	}
	else
	{
		for(i = numero ;i > 0; i--)
		{
			factorial = factorial * i;
		}
	}

	return factorial;
}

