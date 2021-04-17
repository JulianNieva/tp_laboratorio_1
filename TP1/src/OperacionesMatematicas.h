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
 * @fn float CalcularSuma(float, float)
 * @brief Realiza la suma entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la suma
 */
float CalcularSuma (float, float);

/**
 * @fn float CalcularResta(float, float)
 * @brief Realiza la resta entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la resta
 */
float CalcularResta (float, float);

/**
 * @fn float CalcularDivision(float, float)
 * @brief Realiza la division entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la division
 */
float CalcularDivision (float, float);

/**
 * @fn float CalcularMultiplicacion(float, float)
 * @brief Realiza la multiplicacion entre x e y
 *
 * @param Recibe el primer operando (x)
 * @param Recibe el segundo operando (y)
 * @return Devuelve el resultado de la multiplicacion
 */
float CalcularMultiplicacion (float, float);

/**
 * @fn unsigned long int CalcularFactorial(float)
 * @brief Se calcula el factorial del numero
 *
 * @param Recibe el numero (x o y)
 * @return Devuelve el resultado de la factorizacion
 */
unsigned long long int CalcularFactorial (float);

#endif /* OPERACIONESMATEMATICAS_H_ */
