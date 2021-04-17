/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Luca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);
		char opcion;
		char a = '~';
		char b = '~';
		char salir ='n';

		int x;
		int y;
		int flagA=0;
		int flagB=0;
		int flagC=0;
		int flagD=0;
		int suma;
		int resta;
		int multiplicacion;
		float division;
		int factorialA;
		int factorialB;


		do{
			system("cls");
			printf("\n                      ~~~~~~~~~~Menu de opciones~~~~~~~~~~                   \n\n");

			if(flagA==0)
			{
				printf("1- Ingrese el primer operando: (A = %c)\n",a);
			}
			else
			{
				printf("1- Ingrese el primer operando: (A = %d)\n",x);
			}

			if(flagB==0)
			{
				printf("2- Ingrese el segundo operando: (B = %c)\n",b);
			}
			else
			{
				printf("2- Ingrese el segundo operando: (B = %d)\n",y);
			}
			printf("3- Calcular todas las operaciones. \n");
			printf("4- Informar resultados. \n");
			printf("5- Salir. \n");

			utn_getChar(&opcion,"Ingrese opcion\n","error,vuelva a intentarlo\n",'1','5', 2);

			switch (opcion)
			{
				case '1':
					utn_getNumero(&x,"Ingrese el primer operando: \n","error, intente nuevamente: \n",-1000,1000,2);
					flagA=1;
					flagC=0;
					system("pause");
					break;
				case '2':
					utn_getNumero(&y,"Ingrese el segundo operando: \n","error, intente nuevamente: \n",-1000,1000,2);
					flagB=1;
					flagC=0;
					system("pause");
					break;
				case '3':
					flagC=flagA+flagB;
					if(flagC!=2){
						printf("Ingrese dos operandos para realizar la operacion. \n");
					}
					if(flagD==1){
						printf("Ya se realizo el calculo de las operaciones \n");
					}
					else
					{
						sumar(x,y,&suma);
						restar(x,y,&resta);
						dividir(x,y,&division);
						multiplicar(x,y,&multiplicacion);
						calcularFactorial(x,&factorialA);
						calcularFactorial(y,&factorialB);
						flagD=1;

						printf("Se realizaron las operaciones. \n\n");
					}
					flagC=3;
					system("pause");
					break;
				case '4':
					if(flagC!=3){
						printf("Realice las operaciones para mostrar los resultados\n\n");
					}
					else
					{
						printf("El resultado de %d+%d es: %d\n",x,y,suma);
						printf("El resultado de %d-%d es: %d\n",x,y,resta);
						printf("El resultado de %d/%d es: %5.2f\n",x,y,division);
						printf("El resultado de %d*%d es: %d\n",x,y,multiplicacion);
						printf("El factorial de %d es: %d\n",x,factorialA);
						printf("El factorial de %d es: %d\n",y,factorialB);
					}
					system("pause");
					break;
				case '5':
					utn_getChar(&salir, "Desea salir? Aprete s/n.\n", "Error\n",'a','z', 1);
					while(salir != 'n' && salir != 's'){
						utn_getChar(&salir, "Desea salir? Aprete s/n.\n\n", "Error\n",'a','z', 1);
					}
					system("pause");
					break;

				default:
					printf("Opcion incorrecta. \n\n");
					system("pause");
			}

		}while(salir=='n');

	return EXIT_SUCCESS;
}
