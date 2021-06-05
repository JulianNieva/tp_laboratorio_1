/*
 * parser.h
 *
 *  Created on: 5 jun. 2021
 *      Author: Julian
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* SRC_PARSER_H_ */
