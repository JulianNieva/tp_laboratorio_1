#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
#include "Input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
	int salir = 0;
	int idMaximo = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    setbuf(stdout,NULL);

    InitalizeMaxId("idMaximo.csv", &idMaximo);

    do{
        switch(MenuPrincipal())
        {
            case 1:
            	ll_clear(listaEmpleados);
				if(!controller_loadFromText("data.csv",listaEmpleados))
				{
					printf("Se cargaron los datos del texto con exito!\n");
				}
				else
				{
					printf("Hubo un error al cargar el archivo...\n");
				}
                break;
            case 2:
            	ll_clear(listaEmpleados);
				if(!controller_loadFromBinary("data.bin",listaEmpleados))
				{
					printf("Se cargaron los datos del archivo binario con exito!\n");
				}
				else
				{
					printf("Hubo un error al cargar el archivo...\n");
				}
            	break;
            case 3:
				if(!controller_addEmployee(listaEmpleados, &idMaximo))
				{
					printf("Se dio de alta al empleado con exito!\n");
				}
				else
				{
					printf("Error.\n");
				}
            	break;
            case 4:
            	if(ll_len(listaEmpleados) != 0)
            	{
            		controller_ListEmployee(listaEmpleados);
					if(!controller_editEmployee(listaEmpleados))
					{
						printf("Se modifico al empleado con exito!\n");
					}
					else
					{
						printf("Error. No se encontro al empleado\n");
					}
            	}
            	else
            	{
            		printf("No hay elementos cargados en la lista.\n");
            	}
            	break;
            case 5:
            	if(ll_len(listaEmpleados) != 0)
            	{
					controller_ListEmployee(listaEmpleados);
					if(!controller_removeEmployee(listaEmpleados))
					{
						printf("Se dio de baja al empleado con exito!\n");
					}
					else
					{
						printf("Error. No se encontro al empleado\n");
					}
            	}
            	else
				{
					printf("No hay elementos cargados en la lista.\n");
				}
            	break;
            case 6:
            	if(ll_len(listaEmpleados) != 0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
				{
					printf("No hay elementos cargados en la lista.\n");
				}
            	break;
            case 7:
            	if(ll_len(listaEmpleados) != 0)
            	{
					controller_sortEmployee(listaEmpleados);
					controller_ListEmployee(listaEmpleados);
            	}
            	else
				{
					printf("No hay elementos cargados en la lista.\n");
				}
            	break;
            case 8:
				if(!controller_saveAsText("data.csv",listaEmpleados))
				{
					printf("Se guardaron los datos de los empleados (modo texto)\n");
				}
				else
				{
					printf("Hubo un error al guardar los empleados\n");
				}
            	break;
            case 9:
				if(!controller_saveAsBinary("data.bin",listaEmpleados))
				{
					printf("Se guardaron los datos de los empleados (modo binario)\n");
				}
				else
				{
					printf("Hubo un error al guardar los empleados\n");
				}
            	break;
            case 10:
				utn_getInt("Estas seguro que desea salir?\n(Escriba 1 para salir, 0 para cancelar) ", "Error. Por favor escriba una respuesta valida\n", 0, 1, 6, &salir);
            	break;
        }
    }while(!salir);

    WriteMaxId("idMaximo.csv", &idMaximo);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

