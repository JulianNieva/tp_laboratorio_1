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

int MenuPrincipal(void)
{
	int option;
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
	printf("10. Salir \n");

	utn_getInt("Elija una opcion: ", "Error. Asegurese de ingresar una opcion valida", 1, 10, 6, &option);

	return option;
}

int SubMenuModificar(void)
{
	int option;

	printf("1. Modificar nombre\n");
	printf("2. Modificar horario de trabajo\n");
	printf("3. Modificar sueldo\n");

	utn_getInt("Elija una opcion: ", "Error. Asegurese de ingresar una opcion valida", 1, 3, 6, &option);

	return option;
}

int SubMenuCriterioOrdenamiento(void)
{
	int option;

	printf("1. Ordenar por nombre\n");
	printf("2. Ordenar por horario de trabajo\n");
	printf("3. Ordenar por sueldo\n");
	printf("4. Ordenar por ID\n");

	utn_getInt("Elija una opcion: ", "Error. Asegurese de ingresar una opcion valida", 1, 4, 6, &option);

	return option;
}
