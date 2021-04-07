/*
 * OperacionesMatematicas.h
 *
 *  Created on: 5 abr. 2021
 *      Author: Julian
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/**
 * @fn int CalcularSuma(int, int)
 * @brief Realiza la suma entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la suma
 */
int CalcularSuma (int, int);

/**
 * @fn int CalcularResta(int, int)
 * @brief Realiza la resta entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la resta
 */
int CalcularResta (int, int);

/**
 * @fn float CalcularDivision(int, int)
 * @brief Realiza la division entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la division
 */
float CalcularDivision (int, int);

/**
 * @fn int CalcularMultiplicacion(int, int)
 * @brief Realiza la multiplicacion entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la multiplicacion
 */
int CalcularMultiplicacion (int, int);

/**
 * @fn float CalcularFactorialX(int)
 * @brief Se calcula el factorial del primer operando (x)
 *
 * @param Recibe el primer operando (x)
 * @return Devuelve el resultado del factorial x de tipo flotante
 */
float CalcularFactorialX (int);

/**
 * @fn float CalcularFactorialX(int)
 * @brief Se calcula el factorial del segundo operando (y)
 *
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado del factorial y de tipo flotante
 */
float CalcularFactorialY (int);

#endif /* OPERACIONESMATEMATICAS_H_ */
