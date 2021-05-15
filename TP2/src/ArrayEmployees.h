/*
 * ArrayEmployees.h
 *
 *  Created on: 23 abr. 2021
 *      Author: Julian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define EMPTY 0
#define NOT_EMPTY 1

#define LIMIT 10

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployees;

/**
 * @fn int ShowMenu(void)
 * @brief Shows the menu option for the user
 *
 * @return Return the selected option
 */
int ShowMenu(void);

/**
 * @fn int InitEmployees(eEmployees[], int)
 * @brief Initializes the array to indicate that it is empty
 *
 * @param listOfEmployees[] array of employees
 * @param lenght Lenght of the array
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), 0 if okay
 */
int InitEmployees(eEmployees[], int);

/**
 * @fn void IncreaseIdAutomatically(int*)
 * @brief Increaes the id for the employee automatically
 *
 * @param id Pointer to idAutoIncrease
 */
void IncreaseIdAutomatically(int*);

/**
 * @fn int AskForData(eEmployees[], int, int*)
 * @brief Ask the user for the data they wish to add to an employee
 *
 * @param employees[] array of employees
 * @param lenght Lenght of the array
 * @param id Pointer to idAutoIncrease
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), 0 if okay
 */
int AskForData(eEmployees[], int, int*);

/**
 * @fn int AddEmployee(eEmployees[], int, int, char[], char[], float, int, int)
 * @brief Adds an employee to the position received by value
 *
 * @param employee Pointer of the employee to add the data
 * @param lenght Lenght of the array
 * @param id Id of the employee to add
 * @param name[] Name of tye employee to add
 * @param lastName[] Last name of the to add
 * @param salary Salary of the employee to add
 * @param sector Sector of the employee to add
 * @return -1 if error (listOfEmployees == NULL, invalid id, name == NULL, lastName == NULL,invalid salary,invalid sector, invalid lenght), 0 if okay
 */
int AddEmployee(eEmployees*, int, int, char[], char[], float, int);

/**
 * @fn int RemoveEmployees(eEmployees[], int, int)
 * @brief Remove a Employee by Id (put isEmpty Flag in 0)
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @param id Id of the employee to remove
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), 0 if okay
 */
int RemoveEmployees(eEmployees[], int, int);

/**
 * @fn int InitModifyProccess(eEmployees[], int)
 * @brief Initializes the proccess of modifying an employee
 *
 * @param employees[] Array of employees
 * @param lenght Lenght of the array
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), 0 if okay
 */
int InitModifyProccess(eEmployees[], int);

/**
 * @fn void ModifyEmployee(eEmployees*)
 * @brief Modifies the employee
 *
 * @param employee* Pointer of the specific employee
 */
void ModifyEmployee(eEmployees *);

/**
 * @fn int FindEmpty(eEmployees[], int)
 * @brief Finds an empty flag in the array and return the position
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), or the position of "empty" space
 */
int FindEmpty(eEmployees[], int);

/**
 * @fn int FindEmployeeById(eEmployees[], int, int)
 * @brief Find an employee by an id that the user entered, and return the position of the emplyee in the array
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @param id Id the user entered to find a certain employee
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), or the position of the employee
 */
int FindEmployeeById(eEmployees[], int,int);

/**
 * @fn int PrintEmployees(eEmployees[], int)
 * @brief Prints the employees that were added by the user
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), 0 if okay
 */
int PrintEmployees(eEmployees[], int);

/**
 * @fn void PrintOneEmployee(eEmployees)
 * @brief Prints one employee
 *
 * @param employee The employee to print
 */
void PrintOneEmployee(eEmployees);

/**
 * @fn int ShowInformSubMenu(eEmployees[], int)
 * @brief It shows a submenu to the user to interact
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @return -1 if error (listOfEmployees == NULL or invalid lenght), 0 if okay
 */
int ShowInformSubMenu(eEmployees[], int);

/**
 * @fn void CalculateTotalOfSalary(eEmployees[], int)
 * @brief It calculates the salary of every employee added
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @return -1 if error (listOfEmployees == NULL, invalid average ,invalid lenght), 0 if okay
 */
int CalculateTotalOfSalary(eEmployees[], int);

/**
 * @fn int PrintEmployeeWhoExceedTheAverageSalary(eEmployees[], int, float)
 * @brief It prints those employees who exceed the average salary
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @param average The average of all salaries
 * @return -1 if error (listOfEmployees == NULL, invalid average ,invalid lenght), 0 if okay
 */
int PrintEmployeeWhoExceedTheAverageSalary(eEmployees[], int, float);

/**
 * @fn int SortEmployees(eEmployees[], int, int)
 * @brief Sort the employees, the argument order
			indicate UP or DOWN order
 *
 * @param listOfEmployees[] Array of employees
 * @param lenght Lenght of the array
 * @param order The way the user wishes to see the list
 * @return -1 if error (listOfEmployees == NULL, invalid sort ,invalid lenght), 0 if okay
 */
int SortEmployees(eEmployees[], int, int);

#endif /* ARRAYEMPLOYEES_H_ */
