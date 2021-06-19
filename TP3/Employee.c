#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Busca espacio en memoria para una estructura de e inicializa los valores de la misma
 *
 * \return Employee* Retorna un puntero a Employee
 *
 */
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

/** \brief Carga los valores que se le pasan por parametro a una nueva estructura de empleado
 *
 * \param id int Direccion de memoria del id
 * \param nombre char* Direccion de memoria del nombre
 * \param horasTrabajadas int Direccion de memoria de las horas trabajadas
 * \param sueldo int Direccion de memoria del sueldo
 * \return Employee* Retorna un puntero a Employee
 *
 */
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo){
	Employee* auxEmployee= employee_new();
	if(auxEmployee!=NULL)
	{
		if( employee_setId(auxEmployee, id)<0 ||
			employee_setNombre(auxEmployee, nombre) <0 ||
			employee_setHorasTrabajadas(auxEmployee, horasTrabajadas) <0 ||
			employee_setSueldo(auxEmployee, sueldo) <0 ){
			employee_delete(auxEmployee);
			auxEmployee=NULL;
		}
	}
	return auxEmployee;
}

int employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

/** \brief Carga en la estructura  de empleado el id que se le pasa por parametro
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param id int valor del id
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_setId(Employee* this, int id)
{
    int retorno = 0;
    if(this != NULL && id > 0 && id <= 2000)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param id int* Direccion de memoria del id
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_getId(Employee* this, int* id)
{
    int retorno = 0;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}


/** \brief Carga en la estructura  de empleado el nombre que se le pasa por parametro
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param nombre char* Direccion de memoria del nombre
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this eEmployee* Direccion de memoria de la estructura
 * \param nombre char* Direccion de memoria del nombre
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_getNombre(Employee* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Carga en la estructura  de empleado las horas trabajadas que se le pasa por parametro
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param horasTrabajadas int Valor de las horas trabajadas
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param horasTrabajadas int* Direccion de memoria de las horas trabajadas
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


/** \brief Carga en la estructura  de empleado el sueldo que se le pasa por parametro
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param sueldo int Valor del sueldo
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this Employee* Direccion de memoria de la estructura
 * \param sueldo int* Direccion de memoria del sueldo
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


