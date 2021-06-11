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

	return 	aux;	//Retorna el puntero a la entidad que reservo en memoria
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)	//Constructor con parametros (texto)
{
	Employee* this;
	int auxId;
	int auxHoras;
	int auxSueldo;

	auxId = atoi(idStr);
	auxHoras = atoi(horasTrabajadasStr);
	auxSueldo = atoi(sueldoStr);

	this = employee_new();

	//Setter general para validar parametros

		//Valido de que las funciones me devuelvan todo ok
	if(employee_setId(this,auxId) == -1 || employee_setNombre(this,nombreStr) == -1|| employee_setHorasTrabajadas(this,auxHoras) == -1 || employee_setSueldo(this,auxSueldo) == -1)
	{
		employee_delete(this);	//Si entro al if, llamo a la funcion para borrar al empleado
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

	if(this != NULL)
	{
		retorno = 0;
		this->id = id;
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

int employee_showOneEmployee(Employee* empleados)
{
	int retorno = -1;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if(!employee_getId(empleados,&auxId) && !employee_getNombre(empleados,auxNombre) &&
	   !employee_getHorasTrabajadas(empleados,&auxHoras) && !employee_getSueldo(empleados,&auxSueldo))
	{
		printf("|%d \t  |%s \t    	|%d  \t\t 	   |%d   \t|\n",auxId,auxNombre,auxHoras,auxSueldo);
		retorno = 0;
	}

	return retorno;
}

int employee_compareByName(void* firstEmployee, void* secondEmployee)
{
	int comparacion;
	char primerNombre[128];
	char segundoNombre[128];

	if(firstEmployee != NULL && secondEmployee != NULL)
	{
		employee_getNombre((Employee*) firstEmployee,primerNombre);
		employee_getNombre((Employee*) secondEmployee,segundoNombre);

		comparacion = stricmp(primerNombre,segundoNombre);
	}

	return comparacion;
}

int employee_compareBySalary(void* firstEmployee,void* secondEmployee)
{
	int comparacion = -1;

	int primerSueldo;
	int segundoSueldo;

	employee_getSueldo((Employee*) firstEmployee,&primerSueldo);
	employee_getSueldo((Employee*) secondEmployee,&segundoSueldo);

	if(primerSueldo > segundoSueldo)
	{
		comparacion = 1;
	}
	else
	{
		if(primerSueldo == segundoSueldo)
		{
			comparacion = 0;
		}
	}

	return comparacion;
}

int employee_compareByHours(void* firstEmployee,void* secondEmployee)
{
	int comparacion = -1;

	int primerHorario;
	int segundoHorario;

	employee_getHorasTrabajadas((Employee*) firstEmployee,&primerHorario);
	employee_getHorasTrabajadas((Employee*) secondEmployee,&segundoHorario);

	if(primerHorario > segundoHorario)
	{
		comparacion = 1;
	}
	else
	{
		if(primerHorario == segundoHorario)
		{
			comparacion = 0;
		}
	}

	return comparacion;
}

int employee_compareById(void* firstEmployee,void* secondEmployee)
{
	int comparacion = -1;

	int primerId;
	int segundoId;

	employee_getId((Employee*) firstEmployee,&primerId);
	employee_getId((Employee*) secondEmployee,&segundoId);

	if(primerId > segundoId)
	{
		comparacion = 1;
	}
	else
	{
		if(primerId == segundoId)
		{
			comparacion = 0;
		}
	}

	return comparacion;
}
