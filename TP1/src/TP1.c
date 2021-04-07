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
#include "PedirEnteros.h"

#define SE_INGRESO 1
#define NO_SE_INGRESO 0

int main(void)
{
	int opcionIngresada;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int x;
	int y;

	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	float resultadoFactorialDeX;
	float resultadoFactorialDeY;

	x = 0;
	y = 0;

	banderaPrimerOperando = NO_SE_INGRESO;
	banderaSegundoOperando = NO_SE_INGRESO;

	setbuf(stdout, NULL);

	do
	{
		if(banderaPrimerOperando == NO_SE_INGRESO)
		{
			printf("1. Ingresar primer operando (A) \n");
		}
		else
		{
			printf("Primer operando (A) = %d \n",x);
		}
		if(banderaSegundoOperando == NO_SE_INGRESO)
		{
			printf("2. Ingresar el segundo operando (B) \n");
		}
		else
		{
			printf("Segundo operando (B) = %d \n",y);
		}
		if(banderaSegundoOperando == SE_INGRESO && banderaPrimerOperando == SE_INGRESO)
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
				x = PedirPrimerOperando();
				banderaPrimerOperando = SE_INGRESO;
				break;
			case 2:
				y = PedirSegundoOperando();
				banderaSegundoOperando = SE_INGRESO;
				break;
			case 3:
				if(banderaSegundoOperando == SE_INGRESO || banderaPrimerOperando == SE_INGRESO)	//Se cumple la condicion si se ingreso aunque sea un operando
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
				printf("El resultado de %d + %d es: %d \n", x, y, resultadoSuma);
				printf("El resultado de %d - %d es: %d \n", x, y, resultadoResta);
				printf("El resultado de %d / %d es: %.2f \n", x, y, resultadoDivision);
				printf("El resultado de %d * %d es: %d \n", x, y, resultadoMultiplicacion);
				printf("El factorial de %d es: %.2f  Y el factorial de %d es: %.2f \n", x ,resultadoFactorialDeX, y , resultadoFactorialDeY);
				//programar volver al menu
				break;

		}//Fin del switch

	}while(opcionIngresada != 5);	//Fin del do-while
}//Fin de la funcion
