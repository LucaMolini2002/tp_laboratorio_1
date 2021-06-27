/*
 * Employee.h
 *
 *  Created on: 12 may. 2021
 *      Author: Luk
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct{
	int id;
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int emp_initEmployees(Employee* list, int len);
int emp_addEmployees(Employee* list, int len, int* id);
int emp_modifyEmployees(Employee* list,int len, int index);
int emp_findEmployeeById(Employee* list, int len, int id);
int emp_getEmptyIndex(Employee* list,int len);
int emp_removeEmployee(Employee* list, int len, int id);
int emp_sortEmployee(Employee* list, int len);
int emp_print(Employee* pElement);
int emp_printEmployees(Employee* list, int len);
int emp_calculateAverageSalary(Employee* list, int len, int index);
int emp_salaryExceeded(Employee* list, int index, int* employeesAverage, float salaryAverage);

#endif /* EMPLOYEE_H_ */
