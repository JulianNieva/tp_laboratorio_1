/*
 * Input.h
 *
 *  Created on: 1 may. 2021
 *      Author: Julian
 */

#ifndef INPUT_H_
#define INPUT_H_

/**
 * @fn int GetInt(char[])
 * @brief Pido un entero y lo devuelvo
 *
 * @param mensaje Mensaje a mostrar al usuario sobre lo que deba ingresar
 * @return numero Retorna el entero ingresado
 */
int GetInt(char[]);

/**
 * @fn float GetFloat(char[])
 * @brief Pido un decimal y lo devuelvo
 *
 * @param mensaje Mensaje a mostrar al usuario sobre lo que deba ingresar
 * @return numero Retorna el decimal ingresado
 */
float GetFloat(char[]);

/**
 * @fn char GetChar(char[])
 * @brief Pido un caracter y lo devuelvo
 *
 * @param mensaje Mensaje a mostrar al usuario sobre lo que deba ingresar
 * @return letra Retorna la letra
 */
char GetChar(char[]);

/**
 * @fn void GetString(char[], char[])
 * @brief Pido que ingrese una palabra
 *
 * @param mensaje Mensaje a mostrar al usuario sobre lo que deba ingresar
 * @param text Texto que recibe y sera modificado en el momento
 */
void GetString(char[], char[]);

#endif /* INPUT_H_ */
