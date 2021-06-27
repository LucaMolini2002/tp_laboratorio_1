/*
 ============================================================================
 Name        : Tp2_Laboratorio_1.c
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
#include "Employee.h"

#define QTY_EMPLOYEES 1000

int main(void) {

	setbuf(stdout,NULL);

	Employee employees[QTY_EMPLOYEES];

	int opcion;
	int opcionInforme;
	int idEmployee=1;
	int auxIndexEmployees;
	int auxIdEmployees;
	int flag=0;
	int auxEmptyIndex;

	if(emp_initEmployees(employees, QTY_EMPLOYEES)==0)
	{
		printf("\n    ~ Menu de opciones: ~   \n\n");
	}

	do{
		if(!utn_getNumero(&opcion, "1-Dar de alta un empleado\n"
								   "2-Modificar un empleado\n"
								   "3-Dar de baja un empleado\n"
								   "4-Informes\n"
								   "5-Salir\n", "Error, ingrese una opcion valida.\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				emp_addEmployees(employees, QTY_EMPLOYEES, &idEmployee);
				flag=1;
				break;
			case 2:
				if(flag==1)
				{
					if(utn_getNumero(&auxIdEmployees, "Ingrese ID del cliente a modificar: \n", "ID no valido, vuelva a intentarlo.\n", 0, 100000, 3)==0)
					{
						auxIndexEmployees = emp_findEmployeeById(employees, QTY_EMPLOYEES, auxIdEmployees);
						if(auxIndexEmployees >= 0 && emp_modifyEmployees(employees, QTY_EMPLOYEES, auxIndexEmployees)==0)
						{
							printf("Modificacion realizada con exito. \n");
						}
					}
				}
				else
				{
					printf("Aun no hay empleados cargados para modificar.");
				}
				break;
			case 3:
				if(flag==1)
				{
					if(utn_getNumero(&auxIdEmployees, "Ingrese ID del cliente a dar de baja: \n", "ID no valido, vuelva a intentarlo.\n", 0, 100000, 3)==0)
					{
						auxIndexEmployees = emp_findEmployeeById(employees, QTY_EMPLOYEES, auxIdEmployees);
						if(auxIndexEmployees >= 0 && emp_removeEmployee(employees, QTY_EMPLOYEES, auxIndexEmployees)==0)
						{
							printf("Se dio de baja al cliente. \n");

						}
					}
				}
				else
				{
					printf("Aun no hay empleados cargados para dar de baja.");
				}
				break;
			case 4:
				if(!utn_getNumero(&opcionInforme,"1-Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n"
												 "2-Total y promedio de salarios, y cuantos empleados superan el salario promedio\n"
												,"Error, ingrese una opcion valida.\n", 1, 2, 2))
				{
					switch(opcionInforme)
					{
					case 1:
						emp_sortEmployee(employees, QTY_EMPLOYEES);
						emp_printEmployees(employees, QTY_EMPLOYEES);
						break;
					case 2:
						auxEmptyIndex = emp_getEmptyIndex(employees, QTY_EMPLOYEES);
						emp_calculateAverageSalary(employees, QTY_EMPLOYEES, auxEmptyIndex);
						break;
					}
				}
				break;
			}
		}
	}while(opcion<5);
	return EXIT_SUCCESS;
}
