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
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	char respuesta[4];
    LinkedList* listaEmpleados = ll_newLinkedList();

    setbuf(stdout,NULL);

    strcpy(respuesta,"si");

    do{
        switch(MainMenu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	printf("Se cargaron los datos de los empleados (modo binario)\n");
            	controller_loadFromBinary("data.csv",listaEmpleados);
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	printf("Pronto podre dar de alta algo\n");
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	printf("Pronto podre modificar algun empleado\n");
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	printf("Pronto podre dar de baja un empleado\n");
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	printf("Pronto podre listar los empleados\n");
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	printf("Pronto podre ordenar los empleados\n");
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
            	utn_getString("Estas seguro que desea salir?\n(Escriba Si para salir, No para cancelar)", "Error. Por favor escriba una respuesta valida\n", 2, 6, respuesta);
            	break;
        }
    }while(stricmp(respuesta, "si") == 0);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

