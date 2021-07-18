#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"
#include "Input.h"

#define SE_REALIZO 1
#define NO_SE_REALIZO 0

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
	int idMaximo = 1001;
	int opcionCarga;
	int flagCargaTexto = NO_SE_REALIZO;
	int flagCargaBinario = NO_SE_REALIZO;
    LinkedList* listaEmpleados = ll_newLinkedList();

    setbuf(stdout,NULL);

    do{
        switch(MenuPrincipal())
        {
            case 1:
            	if(ll_isEmpty(listaEmpleados) || (flagCargaTexto == NO_SE_REALIZO && flagCargaBinario == NO_SE_REALIZO))
            	{
            		utn_getInt("Cual archivo desea cargar?\n1. Archivo Original\n2. Archivo Guardado\nElija una opcion: ", "Error. Ingrese una opcion valida ", 1, 2, 6, &opcionCarga);
            		if(opcionCarga == 1)
            		{
            			if(!controller_loadFromText("data.csv",listaEmpleados))
            			{
            				flagCargaTexto = SE_REALIZO;
            				printf("Se cargo el archivo con exito!\n");
            			}
            			else
            			{
            				printf("Se produjo un error en la carga del archivo\n");
            			}
            		}
            		else
            		{
            			if(opcionCarga == 2)
            			{
							if(!controller_loadFromText("data2.csv",listaEmpleados))
							{
								printf("Se cargo el archivo con exito!\n");
								flagCargaTexto = SE_REALIZO;
							}
							else
							{
								printf("Se produjo un error en la carga del archivo\n");
							}
            			}
            		}
            	}
            	else
            	{
            		printf("No puede cargar un archivo dos veces\n");
            	}
                break;
            case 2:
            	if(ll_isEmpty(listaEmpleados) || (flagCargaTexto == NO_SE_REALIZO && flagCargaBinario == NO_SE_REALIZO))
				{
            		if(!controller_loadFromBinary("data.bin", listaEmpleados))
            		{
            			flagCargaBinario = SE_REALIZO;
        				printf("Se cargo el archivo con exito!\n");
        			}
        			else
        			{
        				printf("Se produjo un error en la carga del archivo\n");
        			}
				}
            	else
            	{
            		printf("No puede cargar un archivo dos veces\n");
            	}
            	break;
            case 3:
				if(!controller_addEmployee(listaEmpleados, &idMaximo))
				{
					printf("Se dio de alta al empleado con exito!\n");
					WriteMaxId("idMaximo.csv",&idMaximo);
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
            		if(!controller_ListEmployee(listaEmpleados))
            		{

            		}
            		else
            		{
            			printf("Se produjo un error al mostrar un empleado\n");
            		}
            	}
            	else
				{
					printf("No hay elementos cargados en la lista.\n");
				}
            	break;
            case 7:
            	if(ll_len(listaEmpleados) != 0)
            	{
					if(!controller_sortEmployee(listaEmpleados))
					{
						printf("Se ordenaron los empleado con el critero especificado\n");
					}
					else
					{
						printf("Hubo un error,\n");
					}
            	}
            	else
				{
					printf("No hay elementos cargados en la lista.\n");
				}
            	break;
            case 8:
            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
					if(!controller_saveAsText("data2.csv",listaEmpleados))
					{
						printf("Se guardaron los datos de los empleados (modo texto)\n");
					}
					else
					{
						printf("Hubo un error al guardar los empleados\n");
					}
        		}
            	else
				{
					printf("No hay elementos cargados para guardar.\n");
				}
            	break;
            case 9:
            	if(ll_isEmpty(listaEmpleados) == 0)
            	{
					if(!controller_saveAsBinary("data.bin",listaEmpleados))
					{
						printf("Se guardaron los datos de los empleados (modo binario)\n");
					}
					else
					{
						printf("Hubo un error al guardar los empleados\n");
					}
				}
				else
				{
					printf("No hay elementos cargados para guardar.\n");
				}
            	break;
            case 10:
				utn_getInt("Estas seguro que desea salir?\n(Escriba 1 para salir, 0 para cancelar) ", "Error. Por favor escriba una respuesta valida\n", 0, 1, 6, &salir);
            	break;
        }
    }while(!salir);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

