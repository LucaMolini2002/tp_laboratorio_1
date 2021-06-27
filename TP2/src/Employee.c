/*
 * Employee.c
 *
 *  Created on: 12 may. 2021
 *      Author: Luk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"

/* * \brief  To indicate that all position in the array are empty,
 *           this function put the flag (isEmpty) is true in all
 *  \param list Employee* Pointer to array of employees
 *  \param len int array length
 *  \return int Return (-1) if error (invalid length or NULL pointer) - (0) if 0k
 */
int emp_initEmployees(Employee* list, int len)
{
	int retorno=-1;
	if(list!=NULL && len>0)
	{
		retorno=0;
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}
	}
	return retorno;
}
/* * \brief  add in existing list of employees the values received as parameters
 *           in the first empty position
 *  \param list Employee* Pointer to array of employees
 *  \param len int array length
 *  \param *id int
 *  \return int Return (-1) if error (invalid length or NULL pointer or without
 *           free space) - (0) if 0k
 */
int emp_addEmployees(Employee* list, int len, int* id)
{
	int retorno=-1;
	Employee bufferEmployees;
	int auxIndexEmp;

	auxIndexEmp = emp_getEmptyIndex(list, len);
	if(auxIndexEmp>=0)
	{
		if(list!=NULL && len>0 && auxIndexEmp<len && auxIndexEmp>=0 && list[auxIndexEmp].isEmpty==1)
		{
				if(utn_getNombre(bufferEmployees.name, NAME_LEN, "\nNombre:\n", "\nError\n", 2)==0 &&
				   utn_getNombre(bufferEmployees.lastName, LASTNAME_LEN,"\nApellido:\n", "\nError\n", 2)==0 &&
				   utn_getNumeroFloat(&bufferEmployees.salary,"\nSalario:\n", "\nError\n",0.0,500000.0, 2)==0 &&
				   utn_getNumero(&bufferEmployees.sector, "\nSector:\n", "\nError\n", 1, 100, 2)==0)
			{
				retorno=0;
				bufferEmployees.id= *id;
				bufferEmployees.isEmpty=0;
				list[auxIndexEmp]=bufferEmployees;
				(*id)++;
				printf("Los datos se cargaron con exito.\n");
			}
		}
	}
	else
	{
		printf("No hay mas espacios disponibles.\n");
	}
	return retorno;
}
/* * \brief  modify an employee only if he is registered
 *  \param list Employee* Pointer to array of employees
 *  \param len int array length
 *  \param index int
 *  \return int Return (-1) if error (invalid length or NULL pointer or without
 *           free space) - (0) if 0k
 */
int emp_modifyEmployees(Employee* list,int len, int index)
{
	int retorno=-1;
	Employee bufferEmployees;
	if(list!=NULL&&len>0&&index<len&&index>=0&&list[index].isEmpty==0)
	{
		if(utn_getNombre(bufferEmployees.name, NAME_LEN, "\nNombre:\n", "\nError\n", 2)==0 &&
		   utn_getNombre(bufferEmployees.lastName, LASTNAME_LEN,"\nApellido:\n", "\nError\n", 2)==0 &&
		   utn_getNumeroFloat(&bufferEmployees.salary,"\nSalario:\n", "\nError, ingrese salario como decimal.\n",0.0,999999.0, 2)==0 &&
		   utn_getNumero(&bufferEmployees.sector, "\nSector:\n", "\nError\n", 1, 100, 2)==0)
		{
			retorno=0;
			bufferEmployees.id=list[index].id;
			bufferEmployees.isEmpty=0;
			list[index]=bufferEmployees;
		}
	}
	return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *   pointer received or employee not found]
 */
int emp_findEmployeeById(Employee* list, int len, int id)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/* * \brief   Get a empty index in the array
 *  \param list Employee*
 *  \param len int
 *  \return int returns the index with the free position found in the array
 */
int emp_getEmptyIndex(Employee* list,int len)
{
	int retorno=-1;
	int i;
		if(list!=NULL&&len>0)
		{
			retorno=0;
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty==1)
				{
					retorno=i;
					break;
				}
			}
		}
	return retorno;
}

/* * \brief   Remove a Employee by Id (put isEmpty Flag in 1)
 *  \param list Employee*
 *  \param len int
 *  \param id int
 *  \return int Return (-1) if error (invalid length or NULL pointer or
 *    if can't find a employee) - (0) if 0k
 */
int emp_removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
	Employee buffer;
	if(list!=NULL&&len>0&&id<len&&id>=0&&list[id].isEmpty==0)
	{
		retorno=0;
		buffer.isEmpty=1;
		list[id] = buffer;
	}
	return retorno;
}

/* \brief Sort the elements in the array of employees, the argument order
 *        indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int emp_sortEmployee(Employee* list, int len)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Employee bufferEntidad;
	if(list!=NULL&&len>0)
	{
		do{
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(list[i].lastName,list[i+1].lastName,51)>0 ||
				  (strncmp(list[i].lastName,list[i+1].lastName,51)==0 &&
				   list[i].sector<list[i+1].sector))
				{
					flagSwap=1;
					bufferEntidad=list[i];
					list[i]=list[i+1];
					list[i+1]=bufferEntidad;
				}
				emp_printEmployees(list, len);
			}
			len--;
		}while(flagSwap);
	}
	return retorno;
}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int emp_print(Employee* pElement)
{
	int retorno=-1;
		if(pElement != NULL && pElement->isEmpty == 0)
		{
			retorno=0;
			printf("\nID: %d | Nombre: %s | Apellido: %s | Sector: %d | Salary: %2.f\n",pElement->id,pElement->name,pElement->lastName,pElement->sector,pElement->salary);
		}
	return retorno;
}
int emp_printEmployees(Employee* list, int len)
{
	int i;
	int retorno=-1;
	if(list != NULL && len > 0 )
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			emp_print(&list[i]);
		}
	}
	return retorno;
}
/** \brief Calculate average salary
 *
 * \param list Employee*
 * \param length int
 * \param average* float
 * \param aboveAverage* int
 * \return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int emp_calculateAverageSalary(Employee* list, int len, int index)
{
	int ret=-1;
	float AverageSalary=0;
	float auxAverageSalary=0;
	int employeesRate=0;
	if(list!=NULL && len>0 && index>0)
	{
		for(int i=0; i<=index-1;i++)
		{
			auxAverageSalary+=list[i].salary;
		}
		AverageSalary= auxAverageSalary/(index);
		if(emp_salaryExceeded(list, index, &employeesRate, AverageSalary)==0)
		{
			printf("\n\nEl promedio de salario es: %.2f. El numero de empleados que superan el promedio es: %d \n\n",AverageSalary,employeesRate);
			ret=0;
		}
	}
	return ret;
}
/** \brief Calculate above-average employees
 * \param list Employee*
 * \param index int
 * \param salaryAverage float
 * \param employeesAverage int*
 * \return int Return (-1) if Error - (0) if Ok
 */
int emp_salaryExceeded(Employee* list, int index, int* employeesAverage, float salaryAverage)
{
	int ret=-1;
	int auxEmployeesAverage=0;
	if(list!=NULL && index>0 && salaryAverage >= 0)
	{
		for(int i=0; i<index; i++)
		{
			if(list[i].salary > salaryAverage)
			{
				auxEmployeesAverage++;
				ret=0;
			}
		}
		ret=0;
		*employeesAverage=auxEmployeesAverage;
	}
	return ret;
}
