#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief Reserva espacio en memoria para un empleado
 *
 * @return NULL si no hay mas espacio en memoria, si no el puntero a la memoria en el heap
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Crea un nuevo empleado con los parametros recibidos
 *
 * @param idStr Id del empleado
 * @param nombreStr Nombre del empleado
 * @param horasTrabajadasStr Horas trabajadas del empleado
 * @param sueldoStr Sueldo del empleado
 * @return NULL si se produjo un error, si no el puntero el empleado creado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/**
 * @fn void employee_delete(Employee*)
 * @brief Borra en memoria al empleado recibido
 *
 * @param Empleado a eliminar de memoria
 */
void employee_delete(Employee*);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief setea el id del empleado
 *
 * @param this El empleado
 * @param id Id a setear al empleado
 * @return -1 si this == NULL, 0 si no hubo problema
 */
int employee_setId(Employee* this,int id);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Obtengo el id del empleado
 *
 * @param this El empleado que voy a obtener su id
 * @param id Guardo el id del empleado
 * @return -1 si this == NULL e id == NULL, 0 si no hubo problema
 */
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Setea el nombre al empleado recibido
 *
 * @param this El empleado
 * @param nombre Nombre a setear al empleado
 * @return -1 si this == NULL y nombre == NULL, 0 si no hubo problema
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Obtengo el nombre del empleado recibido
 *
 * @param this El empleado que voy a obtener su nombre
 * @param nombre Guardo el nombre del empleado
 * @return -1 si this == NULL y nombre == NULL, 0 si no hubo problema
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Seteo las horas al empleado recibido
 *
 * @param this El Empleado
 * @param horasTrabajadas Horas a setear al empleado
 * @return -1 si this == NULL, 0 si no hubo problema
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief  Obtengo las horas trabajadas del empleado
 *
 * @param this El empleado que voy a obtener su horas trabajadas
 * @param horasTrabajadas Guardo las horas del empleado
 * @return -1 si this == NULL y horasTrabajadas == NULL, 0 si no hubo problema
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief  Seteo el sueldo al empleado recibido
 *
 * @param this El empleado
 * @param sueldo Sueldo a setear al empleado
 * @return -1 si this == NULL, 0 si no hubo problema
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Obtengo el sueldo del empleado
 *
 * @param this El empleado que voy a obtener su sueldo
 * @param sueldo Guardo el sueldo del empleado
 * @return -1 si this == NULL y sueldo == NULL, 0 si no hubo problema
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @fn int employee_showOneEmployee(Employee*)
 * @brief Muestro un empleado
 *
 * @param Employee* Empleado a mostrar
 * @return -1 si Employee == NULL, 0 si no hubo problema
 */
int employee_showOneEmployee(Employee*);

/**
 * @fn int employee_compareByName(void*, void*)
 * @brief Comparacion entre 2 empleados por nombre
 *
 * @param Primer empleado
 * @param Segundo empleado
 * @return Devuelvo el valor de la comparacion
 */
int employee_compareByName(void*,void*);

/**
 * @fn int employee_compareBySalary(void*, void*)
 * @brief Comparacion entre 2 empleados por salario
 *
 * @param Primer empleado
 * @param Segundo empleado
 * @return Devuelvo el valor de la comparacion
 */
int employee_compareBySalary(void*,void*);

/**
 * @fn int employee_compareByHours(void*, void*)
 * @brief Comparacion entre 2 empleados por Horario trabajado
 *
 * @param Primer empleado
 * @param Segundo empleado
 * @return Devuelvo el valor de la comparacion
 */
int employee_compareByHours(void*,void*);

/**
 * @fn int employee_compareById(void*, void*)
 * @brief Comparacion entre 2 empleados por Id
 *
 * @param Primer empleado
 * @param Segundo empleado
 * @return Devuelvo el valor de la comparacion
 */
int employee_compareById(void*,void*);

#endif // employee_H_INCLUDED
