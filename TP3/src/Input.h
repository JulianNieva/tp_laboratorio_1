/*
 * Input.h
 *
 *  Created on: 13 may. 2021
 *      Author: Julian
 */

#ifndef INPUT_H_
#define INPUT_H_

/**
 * @fn int isChar(char[])
 * @brief Valida si el string recibido es char
 *
 * @param string Cadena recibida
 * @return Devuelve -1 si no es un dato tipo char, 0 si es un char
 */
int isChar(char string[]);

/**
 * @fn int getString(char[], int)
 * @brief Se inserta el string respetando su tamaño
 *
 * @param input String recibido por referencia
 * @param tam Tamaño maximo de caracteres permitidos
 * @return Devuelve -1 si hay un error (Input == NULL o Tamaño invalido), 0 si esta bien
 */
int getString(char mensaje[],char input[], int tam);

/**
 * @fn int SizeString(char[])
 * @brief Agrega las mayusuclas y minusculas al string recibido (para los nombres)
 *
 * @param string Cadena recibida
 * @return Devuelve -1 si hay un error (string == NULL), 0 si esta bien
 */
int SizeString(char string[]);

/**
 * @fn int utn_getString(char[], char[], int, int, char[])
 * @brief Se inicia el proceso de solicitar un string
 *
 * @param mensaje Mensaje a mostrar al usuario
 * @param mensajeError Mensaje de error por si el usuario no ingreso lo deseado
 * @param tam tamaño maximo de caracteres
 * @param reintentos cantidad de reintentos posibles para el usuario
 * @param input string recibido por referencia
 * @return Devuelve -1 si hay un error (Input == NULL, mensajeError == NULL, mensaje == NULL , tamaño invalido o reintentos invalido), 0 si esta bien
 */
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);

/**
 * @fn int isInt(char[])
 * @brief Recibe un string que valida si se ingreso dato tipo int
 *
 * @param input Cadena recibida a validar
 * @return Devuelve -1 si hay una letra en el string, 0 si solo hay numeros
 */
int isInt(char input[]);

/**
 * @fn int getInt(int*)
 * @brief Se solicita que se escriba numeros en un string y los devuelve si se cumplen las condiciones
 *
 * @param input Puntero de la variable recibida por referencia
 * @param mensaje Mensaje a mostrar al usuario
 * @return Devuelve -1 si no se escribieron solo numeros, 0 si esta bien
 */
int getInt(int* input,char mensaje[]);

/**
 * @fn int utn_getInt(char[], char[], int, int, int, int*)
 * @brief Se incialializa el proceso de pedir un entero
 *
 * @param mensaje Mensaje a mostrar al usuario
 * @param mensajeError Mensaje de error por si el usuario no ingreso lo deseado
 * @param min Minimo requerido
 * @param max Maximo requerido
 * @param reintentos Cantidad de reintentos posibles para el usuario
 * @param input Variable que se desea agregar el valor ingresado por el usuario (Mediante referencia)
 * @return Devuelve -1 si hay un error (Input == NULL, mensajeError == NULL, mensaje == NULL ,min invalido, max invalido o reintentos invalido), 0 si esta bien
 */
int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input);

/**
 * @fn int isFloat(char[])
 * @brief Valida si el string recibido tiene numeros y .
 *
 * @param input Cadena recibida a validar
 * @return Devuelve -1 si hay una letra en el string, 0 si solo hay numeros
 */

int isFloat(char input[]);

/**
 * @fn int getFloat(float*)
 * @brief Se ingresa el un string, que si se cumple la validacion, se convierte a float
 *
 * @param input Puntero de la variable recibida por referencia
 * @return Devuelve -1 si no se escribieron solo numeros, 0 si esta bien
 */
int getFloat(char mensaje[],float* input);

/**
 * @fn int utn_getFloat(char[], char[], float, float, int, float*)
 * @brief Se incialializa el proceso de pedir un flotante
 *
 * @param mensaje Mensaje a mostrar al usuario
 * @param mensajeError Mensaje de error por si el usuario no ingreso lo deseado
 * @param min Minimo requerido
 * @param max Maximo requerido
 * @param reintentos Cantidad de reintentos posibles para el usuario
 * @param input Variable que se desea agregar el valor ingresado por el usuario (Mediante referencia)
 * @return Devuelve -1 si hay un error (Input == NULL, mensajeError == NULL, mensaje == NULL ,min invalido, max invalido o reintentos invalido), 0 si esta bien
 */
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);

#endif /* INPUT_H_ */
