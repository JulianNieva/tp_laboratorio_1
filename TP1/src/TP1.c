/*
 ============================================================================
 Name        : TP1.c
 Author      : Nieva Julian Leandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesMatematicas.h"


int main(void)
{
	int opcionIngresada;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	float x;
	float y;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialDeX;
	float resultadoFactorialDeY;

	x = 0;
	y = 0;

	banderaPrimerOperando = 0;
	banderaSegundoOperando = 0;

	setbuf(stdout, NULL);
	do
	{
		if(banderaPrimerOperando == 0)
		{
			printf("1. Ingresar primer operando (A) \n");
		}
		else
		{
			printf("Primer operando (A) = %.2f \n",x);
		}
		if(banderaSegundoOperando == 0)
		{
			printf("2. Ingresar el segundo operando (B) \n");
		}
		else
		{
			printf("Segundo operando (B) = %.2f \n",y);
		}

		if(banderaSegundoOperando == 1 && banderaPrimerOperando == 1)
		{
			printf("Si desea cambiar algunos de los valores, Ingrese 1 o 2 correspondientes a los operando \n");
		}

		printf("3. Calcular todas las operaciones \n");
		printf("4. Informar resultados \n");
		printf("5. Salir \n");
		printf("Elija una opcion: ");
		scanf("%d", &opcionIngresada);

		switch(opcionIngresada)
		{
			case 1:
				printf("Ingrese el primer operando (A): ");
				scanf("%f", &x);
				banderaPrimerOperando = 1;
				break;
			case 2:
				printf("Ingrese el segundo operando (B): ");
				scanf("%f", &y);
				banderaSegundoOperando = 1;
				break;
			case 3:
				if(banderaSegundoOperando == 1 || banderaPrimerOperando == 1)	//Se cumple la condicion si se ingreso aunque sea un operando
				{
					resultadoSuma = CalcularSuma(x,y);
					resultadoResta = CalcularResta(x,y);
					resultadoDivision = CalcularDivision(x,y);
					resultadoMultiplicacion = CalcularMultiplicacion(x,y);
					resultadoFactorialDeX = CalcularFactorialX(x);
					resultadoFactorialDeY = CalcularFactorialY(y);
					printf("Se realizo todas las operaciones con exito! \n");
				}
				else	//Si no se ingreso aunque sea un operando, se muestra este mensaje
				{
					printf("No se ingreso ningun operando\n");
				}
				break;
			case 4:
				printf("El resultado de %.2f + %2.f es: %.2f \n", x, y, resultadoSuma);
				printf("El resultado de %.2f - %2.f es: %.2f \n", x, y, resultadoResta);
				printf("El resultado de %.2f / %2.f es: %.2f \n", x, y, resultadoDivision);
				printf("El resultado de %.2f * %2.f es: %.2f \n", x, y, resultadoMultiplicacion);
				printf("El factorial de %.2f es: %.2f  Y el factorial de %.2f es: %.2f \n", x ,resultadoFactorialDeX, y , resultadoFactorialDeY);
				//programar volver al menu
				break;
		}
	}while(opcionIngresada != 5);
}
