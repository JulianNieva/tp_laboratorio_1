#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Input.h"

#define ERROR -1
#define EXITO 0

Employee* employee_new(void)	//Constructor
{
	Employee* aux;

	aux = (Employee*)malloc(sizeof(Employee));

	if(aux->nombre == NULL)
	{
		printf("Nombre es NULL");
	}

	return 	aux;	//Retorna el puntero a la entidad que reservo en memoria
}

Employee* employee_newParametrosTXT(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)	//Constructor con parametros (texto)
{
	Employee* this;
	int auxId;
	int auxHoras;
	int auxSueldo;

	auxId = atoi(idStr);
	auxHoras = atoi(horasTrabajadasStr);
	auxSueldo = atoi(sueldoStr);

	this = employee_new();

		//Valido de que las funciones me devuelvan todo ok
	if(employee_setId(this,auxId)== -1 || employee_setNombre(this,nombreStr) == -1|| employee_setHorasTrabajadas(this,auxHoras) == -1 || employee_setSueldo(this,auxSueldo) == -1)
	{
		employee_delete(this);	//Si no entro al if, llamo a la funcion para borrar al empleado
		this = NULL;	//Devuelvo NULL
	}

	return this;	//Si entro al if, devuelvo el empleado
}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)	//Constructor sin lectura de texto
{
	Employee* this;

	this = employee_new();

		//Valido de que las funciones me devuelvan todo ok
	if(employee_setId(this,id)== -1 || employee_setNombre(this,nombre) == -1|| employee_setHorasTrabajadas(this,horasTrabajadas) == -1 || employee_setSueldo(this,sueldo) == -1)
	{
		employee_delete(this);	//Si no entro al if, llamo a la funcion para borrar al empleado
		this = NULL;	//Devuelvo NULL
	}

	return this;	//Si entro al if, devuelvo el empleado
}

void employee_delete(Employee* this)	//Destructor
{
	free(this); //Se encarga de liberar la memoria reservada para el empleado
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	static int idMaximo = -1;

	if(this != NULL)
	{
		retorno = 0;
		if(id <= idMaximo)	//Primero me fijo si el id recibido es un numero negativo
		{
			//Si es negativo, lo calculo automaticamente con el idMaximo y lo guardo en la entidad
			idMaximo++;
			this->id = idMaximo;
		}
		else
		{
			if(id > idMaximo)	//Si no es un numero negativo, compruebo de la posibilidad de que sea un id mayor el establecido
			{
				//Si es mayor, actualizo su valor y guardi el id en la entidad
				idMaximo = id;
				this->id = idMaximo;
			}
		}
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombre,nombre);	//Si entro al if, guardo el nombre
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre,this->nombre);	//Copio en la variable nombre el nombre del empleado especificado
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;	//Guardo la hora solicitada
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
			retorno = 0;
			this->sueldo = sueldo;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}

	return retorno;
}

void employee_showOneEmployee(Employee* empleados)
{
	printf("%d--%s--%d--%d\n",empleados->id,empleados->nombre,empleados->horasTrabajadas,empleados->sueldo);
}

int employee_compareByName(Employee* firstEmployee, Employee* secondEmployee)
{
	int comparacion;

	if(firstEmployee != NULL && secondEmployee != NULL)
	{
		comparacion = stricmp(firstEmployee->nombre,secondEmployee->nombre);
	}

	return comparacion;
}
