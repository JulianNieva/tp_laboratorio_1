/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

int main(void)
{
	eEmployees employeeList[LIMIT];

	setbuf(stdout, NULL);

	InitEmployees(employeeList);

	int opcion;
	int index;

	do
		{
			puts("1. ALTAS");
			puts("2. MODIFICAR");
			puts("3. BAJA");
			puts("4. INFORMAR");
			puts("5. SALIR");
			opcion = GetInt("Ingrese una opcion: ");

			switch (opcion)
			{
			case 1:
				index = AddEmployees(employeeList);
				if(index != -1)
				{
					puts("Se dio de alta al empleado con exito!");
				}
				else
				{
					puts("No hay mas espacio para ingresar otro empleado");
				}
				break;
			case 2:
				puts("Podre modificar algo pronto");
				break;
			case 3:

				index = RemoveEmployees(employeeList);
				if(index == -1)
				{
					puts("No se encontro el id del empleado...");
				}
				else
				{
					if(index == 0)
					{
						puts("Se cancelo la operacion");
					}
					else
					{
						puts("Se dio de baja el empleado con exito!");
					}
				}
				break;
			case 4:
				break;
			case 5:
				puts("Gracias por utilizar este programa!");
				break;
			}
		}while(opcion != 5);
}
