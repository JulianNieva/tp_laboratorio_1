/*
 * Menu.c
 *
 *  Created on: 2 jun. 2021
 *      Author: Julian
 */
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Input.h"

int MainMenu(void)
{
	int option;
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir \n");

	utn_getInt("Elija una opcion: ", "Error. Asegurese de ingresar una opcion valida", 1, 10, 6, &option);

	return option;
}

/*int SubMenu(void)
{
	int option;

	return option;
}*/
