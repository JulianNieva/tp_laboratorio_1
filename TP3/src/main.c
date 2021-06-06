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
    LinkedList* listaEmpleados = ll_newLinkedList();

    setbuf(stdout,NULL);

    do{
        switch(MenuPrincipal())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_ListEmployee(listaEmpleados);
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	printf("Se guardaron los datos de los empleados (modo texto)\n");
            	break;
            case 9:
            	controller_saveAsBinary("data.csv",listaEmpleados);
            	printf("Se guardaron los datos de los empleados (modo texto)\n");
            	break;
            case 10:
				utn_getInt("Estas seguro que desea salir?\n(Escriba 1 para salir, 0 para cancelar)", "Error. Por favor escriba una respuesta valida\n", 0, 1, 6, &salir);
            	break;
        }
    }while(!salir);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

