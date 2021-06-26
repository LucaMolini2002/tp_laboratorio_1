/*
 * Parser.c
 *
 *  Created on: 26 jun. 2021
 *      Author: Luk
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna la cant de empleados que se cargaron
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pAuxEmployee;
	char idStr[50],nombre[128],horasTrabajadasStr[50],sueldoStr[50];
	int id;
	int horasTrabajadas;
	int sueldo;
	int idMax=0;

	if(pFile !=NULL)
	{
		do
		{

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,horasTrabajadasStr,sueldoStr)==4){
				id=atoi(idStr);
				sueldo=atoi(sueldoStr);
				horasTrabajadas=atoi(horasTrabajadasStr);
				if(id>idMax)
				{
					idMax=id;
				}
			}
			else
			{
				break;
			}
			pAuxEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			if(pAuxEmployee!=NULL)
			{
				ll_add(pArrayListEmployee, pAuxEmployee);
			}
		}while(!feof(pFile));
			retorno = idMax;
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna la cant de empleados que se cargaron
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int contador = 0;
	int cantidad = 0;
	Employee* auxEmpleado = NULL;

	if(pFile == NULL || pArrayListEmployee == NULL)
	{
		printf("El archivo no existe o no se pudo conseguir memoria.\n");
	}


	while(!feof(pFile))
	{
		auxEmpleado = employee_new();

		if(auxEmpleado == NULL)
		{
			break;
		}
		cantidad = fread((Employee*)auxEmpleado, sizeof(Employee), 1, pFile);
		if(cantidad  < 1)
		{
			break;
		}
		else if(ll_len(pArrayListEmployee) < 2000 && !ll_add(pArrayListEmployee, (Employee*)auxEmpleado))
		{
			contador++;
		}
	}
	return contador;
}

