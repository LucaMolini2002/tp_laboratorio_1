#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

static int funcionCriterio(void* emp1, void* emp2);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna la cantidad de empleados cargados
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int contador = 0;
	FILE* file = NULL;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		file = fopen(path, "r");

		if(file != NULL)
		{
			contador = parser_EmployeeFromText(file, pArrayListEmployee);
		}
	}

	fclose(file);

	return contador;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna la cantidad de empleados cargados
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int contador = 0;
	FILE* file = NULL;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		file = fopen(path, "rb");

		if(file != NULL)
		{
			contador = parser_EmployeeFromBinary(file, pArrayListEmployee);
		}
	}

	fclose(file);

	return contador;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* cantidadEmpleadosP)
{
	int retorno = -1;
	Employee* nuevoEmpleado = NULL;
	char nombre[128];
	int id;
	int horasTrabajadas;
	int sueldo;

	int largoArray = ll_len(pArrayListEmployee);

	if(largoArray >= 2000)
	{
		printf("\nNo hay mas espacio para cargar empleados.\n");
	}
	else if(largoArray == 0)
	{
		printf("\nPrimero debe cargar los empleados del archivo.\n");
	}
	else
	{
		id = (*cantidadEmpleadosP)+1;

		utn_getNombre(nombre, 128, "\nIngrese el nombre: ", "Error, Ingrese nuevamente un nombre.", 2);

		utn_getNumero(&horasTrabajadas, "\nIngrese las horas trabajadas: ", "Error, Ingrese nuevamente la cantidad de horas.", 0, 1000, 2);

		utn_getNumero(&sueldo, "\nIngrese sueldo: ", "Error, Ingrese nuevamente el sueldo.", 0, 1000000, 2);
	}

	nuevoEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

	if(nuevoEmpleado != NULL)
	{
		if(ll_add(pArrayListEmployee, (Employee*) nuevoEmpleado) == 0)
		{
			printf("\nSe cargo con exito el nuevo empleado!\n\n");
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int flag = 0;
	int opcion;
	int salir;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int largoArray = 0;
	Employee* auxEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		largoArray = ll_len(pArrayListEmployee);

		if(controller_ListEmployee(pArrayListEmployee) == 0)
		{
			printf("No hay empleados por editar.\n");
		}
		else
		{
			do
			{
				utn_getNumero(&id, "Ingrese id del empleadp a modificar: ", "error", 0, 1000, 2);
				for(int i=0; i < largoArray; i++)
				{
					auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
					if(auxEmpleado->id == id)
					{
						flag = 1;
						break;
					}
				}
				if(!flag)
				{
					printf("Error. No existe empleado con ese id\n");
				}

			}while(flag == 0);

			if(auxEmpleado != NULL)
			{
				do
				{
					printf("***** Modificar empleado *****\n\n"
					"\n|   Id   |       Nombre       |  Horas trabajadas |  Sueldo    |\n"
					"----------------------------------------------------------------\n");
					printf("| %4d   |  %15s   |        %4d       |   %4d |\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
					printf("\n1- Modificar nombre\n"
							"2- Modificar horas tranajadas\n"
							"3- Modificar sueldo\n"
							"4- Salir\n\n"
							"Ingrese opcion: ");
					utn_getNumero(&opcion," Ingrese una opcion: \n","error\n",1,4,2);

					switch(opcion)
					{
						case 1:
							utn_getNombre(nombre, 128, "\nIngrese el nuevo nombre: ", "Error, Ingrese nuevamente un nombre.", 2);
							strcpy(auxEmpleado->nombre, nombre);
							retorno = 0;
							break;

						case 2:
							utn_getNumero(&horasTrabajadas, "\nIngrese las horas trabajadas: ", "Error, Ingrese nuevamente la cantidad de horas.", 0, 1000, 2);
							auxEmpleado->horasTrabajadas = horasTrabajadas;
							retorno = 0;
							break;

						case 3:
							utn_getNumero(&sueldo, "\nIngrese sueldo: ", "Error, Ingrese nuevamente el sueldo.", 0, 1000000, 2);
							auxEmpleado->sueldo = sueldo;
							retorno = 0;
							break;

						case 4:
							utn_getNumero(&salir,"Desea salir? 1=Si | 2=No", "error", 1, 2, 3);

							break;
					}
				}
				while(salir == 2);
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si se guardan los datos
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int largoArray = 0;
	int i = 0;
	int flag = 0;
	int id;
	int salir;
	Employee* auxEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		largoArray = ll_len(pArrayListEmployee);

		if(controller_ListEmployee(pArrayListEmployee) == 0)
		{
			printf("\nNo hay empleados por remover.\n");
		}
		else
		{
			utn_getNumero(&id, "Ingrese id: \n", "error, ingrese un id valido", 1, 99999, 2);
			for(i=0; i < largoArray; i++)
			{
				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				if(auxEmpleado->id == id)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				utn_getNumero(&salir, "Desea eliminar? Si=1 | No=2", "Error", 1, 2, 2);
				if(salir == 1)
				{
					if(ll_remove(pArrayListEmployee, i) == 0)
						retorno = 0;
				}
			}
			else
			{
				printf("No hay ningun empleado con ese id.\n");
			}
		}
	}

	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int contador = 0;
	int arrrayLen = 0;
	Employee* auxEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		arrrayLen = ll_len(pArrayListEmployee);

		for(contador = 0; contador < arrrayLen; contador++)
		{
			if(contador == 0)
			{
				printf("\n|   Id   |       Nombre       |  Horas trabajadas |  Sueldo    |\n");
				printf("----------------------------------------------------------------\n");
			}

			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, contador);

			if(auxEmpleado != NULL)
			{
				printf("| %4d   |  %15s   |        %4d       |   %d |\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
			}
		}
	}

	return contador;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 en caso de error y 0 si se pudo ordenar
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int order;
    if(pArrayListEmployee != NULL)
    {
    	utn_getNumero(&order, "Ingrese orden: 1 para ascendente y 0 para descendente", "error", 1, 2, 2);
    	if(!ll_sort(pArrayListEmployee, funcionCriterio, order))
    		retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	int largoArray = 0;
	FILE* file = NULL;
	Employee* auxEmpleado = NULL;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		largoArray = ll_len(pArrayListEmployee);

		file = fopen(path, "w");
		if(file == NULL)
		{
			return retorno;
		}
		if(largoArray > 0)
		{
			fprintf(file, "id,nombre,horasTrabajadas,sueldo\n");
			for(i=0; i < largoArray; i++)
			{
				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				if(auxEmpleado != NULL)
				{
					fprintf(file, "%d,%s,%d,%d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
				}
				else
				{
					break;
				}
			}
			if(i == largoArray)
			{
				retorno = 1;
			}
		}
		fclose(file);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	    int i;
	    int largoArray = 0;
	    FILE* file = NULL;
	    Employee* auxEmpleado = NULL;

	    if(pArrayListEmployee != NULL && path != NULL)
	    {
	        largoArray = ll_len(pArrayListEmployee);

	        file = fopen(path, "wb");
	        if(file == NULL)
	        {
	            return retorno;
	        }
	        if(largoArray > 0)
	        {
	            for(i=0; i < largoArray; i++)
	            {
	                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
	                if(auxEmpleado != NULL)
	                {
	                    fwrite((Employee*) auxEmpleado, sizeof(Employee), 1, file);
	                }
	                else
	                {
	                    break;
	                }
	            }
	            if(i == largoArray)
	            {
	            	retorno = 1;
	            }
	        }
	        fclose(file);
	    }
	    return retorno;
}

static int funcionCriterio(void* emp1, void* emp2)
{
    int orden;
    Employee* auxEmp1 = NULL;
    Employee* auxEmp2 = NULL;

    if(emp1 != NULL && emp2 != NULL)
    {
        auxEmp1 = (Employee*) emp1;
        auxEmp2 = (Employee*) emp2;

        if(strcmp(auxEmp1->nombre, auxEmp2->nombre) > 0)
        {
            orden = 1;
        }
        else if(strcmp(auxEmp1->nombre, auxEmp2->nombre) < 0)
        {
            orden = -1;
        }
        else
        {
            orden = 0;
        }
    }
    return orden;
}

