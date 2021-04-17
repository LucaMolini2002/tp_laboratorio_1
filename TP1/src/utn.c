/*
 * utn.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Luk
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* \brief funcion para obtener un numero y validarlo
 * \param int* pResultado: recibe el numero
 * \param char* mensaje: puntero que nos permite guardar un mensaje solicitando un numero
 * \param char* mensajeError: puntero que permite arrojar mensaje de error en caso de que se ingrese mal un dato
 * \param int minimo: permite poner un valor minimo que pueda ingresar un usuario
 * \param int maximo: permite poner un valor maximo que pueda ingresar un usuario
 * \param int* reintentos: indica la cantidad de intentos que tiene el usuario para fallar
 * \return int
 * */
int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",&bufferInt);

			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
/* \brief funcion para obtener una letra y validarlo
 * \param char* pLetra: recibe la letra
 * \param char* mensaje: puntero que nos permite guardar un mensaje solicitando una letra
 * \param char* mensajeError: puntero que permite arrojar mensaje de error en caso de que se ingrese mal un dato
 * \param int minimo: permite poner un valor minimo que pueda ingresar un usuario
 * \param int maximo: permite poner un valor maximo que pueda ingresar un usuario
 * \param int* reintentos: indica la cantidad de intentos que tiene el usuario para fallar
 * \return int
 * */
int utn_getChar(char* pLetra,char* pTexto,char* pError,char min,char max,int reintento){
	int retorno=-1;
	char buffer;
	do{
		printf("%s",pTexto);
		fflush(stdin);
		if(scanf("%c",&buffer)==1){
			if (buffer>=min && buffer<=max)
			{
				*pLetra = buffer;
				retorno= 0;
				break;
			}else{
				printf("%s",pError);
				reintento--;
			}
		}else{
			printf("%s",pError);
			reintento--;
		}
	}
	while(reintento>0);

	return retorno;
}
/* \brief funcion para sumar dos numeros
 * \param int operadorA: recibe el primer numero
 * \param int operadorB: recibe el segundo numero
 * \param int* resultado: puntero que guarda el valor del resultado
 * \return int
 * */
int sumar(int operadorA,int operadorB,int* resultado)
{
	*resultado=operadorA+operadorB;
	return 0;
}
/* \brief funcion para restar dos numeros
 * \param int operadorA: recibe el primer numero
 * \param int operadorB: recibe el segundo numero
 * \param int* resultado: puntero que guarda el valor del resultado
 * \return int
 * */
int restar(int operadorA,int operadorB,int* resultado)
{
	*resultado=operadorA-operadorB;
	return 0;
}
/* \brief funcion para multiplicar dos numeros
 * \param int operadorA: recibe el primer numero
 * \param int operadorB: recibe el segundo numero
 * \param int* resultado: puntero que guarda el valor del resultado
 * \return int
 * */
int multiplicar(int operadorA,int operadorB,int* resultado){
	*resultado=operadorA*operadorB;
	return 0;
}
/* \brief funcion para dividir dos numeros
 * \param int operadorA: recibe el primer numero
 * \param int operadorB: recibe el segundo numero
 * \param float* resultado: puntero que guarda el valor del resultado
 * \return int
 * */
int dividir(int operadorA,int operadorB,float* resultado){
	int retorno=-1;
	if(operadorB!=0)
	{
		*resultado=(float)operadorA/operadorB;
		retorno=0;
	}
	return retorno;
}
/* \brief funcion para calcular factorial de un numero
 * \param int operadorA: recibe el primer numero
 * \param int* resultado: puntero que guarda el valor del resultado, y en las proximas vueltas del for se utiliza para realizar la operacion
 * \param char* mensajeError: se imprime un mensaje de error en caso de que el usuario utilice numeros menores a 1
 * \return int
 * */
int calcularFactorial(int operador,int* resultado)
{
	*resultado = 1;
	if(operador>0)
	{
		for(int i=operador; i>0; i--)
		{
			*resultado *= i;
		}
	}
	else
	{
		*resultado=0;
	}
	return 0;
}
