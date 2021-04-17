/*
 ============================================================================
 Name        : TP1.c
 Author      : Nieva Julian Leandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesMatematicas.h"
#include "PedirNumeros.h"

#define SE_INGRESO 1
#define NO_SE_INGRESO 0

#define NO_SE_REALIZO 0
#define SE_REALIZO 1

int main(void)
{
		int opcionIngresada;
		int banderaDivision;
		int banderaSegundoOperando;
		int banderaPrimerOperando;
		int banderaCalculos;

		float x;
		float y;
		float resultadoSuma;
		float resultadoResta;
		float resultadoDivision;
		float resultadoMultiplicacion;
		unsigned long long int resultadoFactorialDeX;
		unsigned long long int resultadoFactorialDeY;

		banderaDivision = NO_SE_REALIZO;
		banderaSegundoOperando = NO_SE_INGRESO;
		banderaPrimerOperando = NO_SE_INGRESO;
		banderaCalculos = NO_SE_REALIZO;

		setbuf(stdout, NULL);

		do
		{
			system("@cls||clear");
			printf("Estudiante: Julian Leandro Nieva \t Curso: 1 C\n");

			if(banderaPrimerOperando == NO_SE_INGRESO)	//Si no se ingreso el primer operando se muestra el mensaje correspondiente
			{
				printf("1. Ingresar primer operando A \n");
			}
			else	//En caso de que se ingreso, se muestra el valor actual cargado
			{
				printf("1. Ingresar primer operando (A = %.2f) \n", x);
			}

			if(banderaSegundoOperando == NO_SE_INGRESO)	//Si no se ingreso el segundo operando se muestra el mensaje correspondiente
			{
				printf("2. Ingresar segundo operando B \n");
			}
			else	//En caso de que se ingreso, se muestra el valor actual cargado
			{
				printf("2. Ingresar segundo operando (B = %.2f) \n", y);
			}
			printf("3. Calcular todas las operaciones \n");
			printf("\t a)Calcular la suma (A+B)\n");
			printf("\t b)Calcular la resta (A-B)\n");
			printf("\t c)Calcular la division (A/B)\n");
			printf("\t d)Calcular la multiplicacion (A*B)\n");
			printf("\t e)Calcular el factorial (A!)\n");
			printf("\t f)Calcular el factorial (B!)\n");
			printf("4. Informar resultados \n");
			printf("5. Salir \n");
			printf("Elija una opcion: ");
			scanf("%d", &opcionIngresada);

			switch(opcionIngresada)
			{
				case 1:		//Si ingreso 1, llama a la funcion para tomar el primer operando x
					system("@cls||clear");
					x = PedirPrimerOperando();
					banderaPrimerOperando = SE_INGRESO;
					printf("Se ingreso el primer operando con exito!\n");
					system("pause");
					break;
				case 2:		//Si ingreso 2, llama a la funcion para tomar el segundo operando y
					system("@cls||clear");
					y = PedirSegundoOperando();
					banderaSegundoOperando = SE_INGRESO;
					printf("Se ingreso el segundo operando con exito!\n");
					system("pause");
					break;
				case 3:	//Si el usuario ingreso 3, se realizan los calculos siempre y cuando se cumpla la condicion
					system("@cls||clear");
					if(banderaSegundoOperando == SE_INGRESO && banderaPrimerOperando == SE_INGRESO)	//Se cumple la condicion si se ingreso aunque sea un operando
					{
						banderaCalculos = SE_REALIZO;
						resultadoSuma = CalcularSuma(x,y);
						resultadoResta = CalcularResta(x,y);
						resultadoMultiplicacion = CalcularMultiplicacion(x,y);
						if(y == 0)
						{
							banderaDivision = NO_SE_REALIZO;
						}
						else
						{
							resultadoDivision = CalcularDivision(x,y);
							banderaDivision = SE_REALIZO;
						}

						resultadoFactorialDeX = CalcularFactorial(x);
						resultadoFactorialDeY = CalcularFactorial(y);

						if(banderaDivision == SE_REALIZO && resultadoFactorialDeX != -1 && resultadoFactorialDeY != -1)//Valida si se puedieron realizar todas las operaciones
						{
							printf("Se realizo todas las operaciones con exito!\n");
						}
						else	//En caso de que no se realizo algunas de las operaciones, muestra este mensaje
						{
							printf("Hubo errores en el procesamiento de algun calculo, se realizaron las posibles operaciones\n");
						}
					}
					else	//Si no se ingreso ningun sea un operando, se muestra este mensaje
					{
						printf("Asegurese de ingresar los dos operandos para poder realizar las operaciones\n");
					}
					system("pause");
					break;
				case 4:	//En caso de que ingreso la opcion 4, y se realizaron los calculos, se muestran los resultados
					system("@cls||clear");
					if(banderaCalculos == SE_REALIZO)
					{
						printf("Primer operando (A = %.2f)\t Segundo Operando (B = %.2f)\n", x, y);
						printf("\na)El resultado de A + B es: %.2f \n",resultadoSuma);
						printf("b)El resultado de A - B es: %.2f \n",resultadoResta);
						if(banderaDivision == SE_REALIZO)
						{
							printf("c)El resultado de A / B es: %.2f \n",resultadoDivision);
						}
						else
						{
							printf("c)No se pudo realizar la division\n");
						}
						printf("d)El resultado de A * B es: %.2f \n",resultadoMultiplicacion);
						if(resultadoFactorialDeX != -1)
						{
							printf("e)El factorial de A! es: %I64u \n",resultadoFactorialDeX);
						}
						else
						{
							printf("e)No se pudo realizar el factorial (A)\n");
						}

						if(resultadoFactorialDeY != -1)
						{
							printf("f)El factorial de B! es: %I64u \n",resultadoFactorialDeY);
						}
						else
						{
							printf("f)No se pudo realizar el factorial (B)\n");
						}
					}
					else
					{
						printf("Asegurese de realizar los calculos primero\n");
					}
					system("pause");
					break;
				case 5:
					printf("Gracias por utilizar esta calculadora!");
					break;
				default:
					printf("Por favor, ingrese una opcion valida\n");
					system("pause");
					break;
			}//Fin del switch
		}while(opcionIngresada != 5);	//Fin del do-while
}//Fin de la funcion
