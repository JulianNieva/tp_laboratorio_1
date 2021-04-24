/*
 * Menu.c
 *
 *  Created on: 23 abr. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void ShowcaseMenu(void)
{
	int opcion;

	do
	{
		puts("1. ALTAS");
		puts("2. MODIFICAR");
		puts("3. BAJA");
		puts("4. INFORMAR");
		puts("5. SALIR");
		printf("Elija una opcion deseada: ");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			puts("Voy a dar de alta algo pronto");
			break;
		case 2:
			puts("Voy a modificar algo pronto");
			break;
		case 3:
			puts("Voy a dar de baja algo pronto");
			break;
		case 4:
			puts("Pronto podre informar algo");
			break;
		case 5:
			puts("Gracias por utilizar este programa!");
			break;
		}
	}while(opcion != 5);

}
