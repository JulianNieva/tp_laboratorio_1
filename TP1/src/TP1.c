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
				if(banderaSegundoOperando == 1 || banderaPrimerOperando == 1)
				{
					printf("1. Calcular la suma \n");
					printf("2. Calcular la resta \n");
					printf("3. Calcular la division \n");
					printf("4. Calcular la multiplicacion \n");
					printf("5. Calcular el factorial \n");
					printf("6. Para regresar \n");
					printf("Ingrese la operacion deseada a realizar : ");
					scanf("%d", &opcionIngresada);

					switch(opcionIngresada)
					{
					case 6:
						break;
					}
				}
				else
				{
					printf("No ingreso ningun operando\n");
				}
				break;
			case 4:
				printf("Idem 3\n");
				break;
		}
	}while(opcionIngresada != 5);
}
