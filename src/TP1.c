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

int main(void)
{
	int opcionIngresada;
	float x = 0;
	float y = 0;

	setbuf(stdout, NULL);
	do
	{
		if(x == 0)
		{
			printf("1. Ingresar primer operando (A) \n");
		}
		else
		{
			printf("Primer operando (A) = %.2f \n",x);
		}
		if(y == 0)
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
				break;
			case 2:
				printf("Ingrese el segundo operando (B): ");
				scanf("%f", &y);
				break;
			case 3:
				printf("No se llego todavia\n");
				break;
			case 4:
				printf("Idem 3\n");
				break;
		}
	}while(opcionIngresada != 5);
}
