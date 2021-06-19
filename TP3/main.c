#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int option;
	int employeeAmount;
	int* employeeAmountP = &employeeAmount;
	int flag = 0;
	LinkedList* listaEmpleados = ll_newLinkedList();

	do{
		utn_getNumero(&option, "\n~~~~~~~~~~~~ Menu ~~~~~~~~~~~\n"
								"1. Cargar empleados en modo texto.\n"
								"2. Cargar empleados en modo binario.\n"
								"3. Alta de emplead.\n"
								"4. Modificar datos de empleado.\n"
								"5. Baja de empleado.\n"
								"6. Listar empleados.\n"
								"7. Ordenar empleados.\n"
								"8. Gardar empleados en modo texto.\n"
								"9. Guardar empleados en modo binario. \n"
								"10. Salir.\n", "\nError, ingrese una opcion correcta.\n", 1, 10, 2);

		switch(option)
		{
			case 1:
				if(!flag)
				{
					employeeAmount = controller_loadFromText("data.csv",listaEmpleados);
					if(employeeAmount > 0)
					{
						printf("\nSe cargaron en el sistema %d empleados.\n", employeeAmount);
						flag = 1;
					}
					else
					{
						printf("\nNo se pudo cargar ningun empleado.\n");
					}
				}
				else
				{
					printf("\nYa se cargaron los empleados anteriormente.\n");
				}
				break;
			case 2:
				if(!flag)
				{
					employeeAmount = controller_loadFromBinary("data.bin", listaEmpleados);
					if(employeeAmount > 0)
					{
						printf("\nSe cargaron en el sistema %d empleados.\n", employeeAmount);
						flag = 1;
					}
					else
					{
						printf("\nNo se pudo cargar ningun empleado.\n");
					}
				}
				else
				{
					printf("\nYa se cargaron los empleados anteriormente.\n");
				}
				break;
			case 3:
				controller_addEmployee(listaEmpleados, employeeAmountP);
				break;

			case 4:
				if(controller_editEmployee(listaEmpleados))
				{
					printf("\nEl empleado se modifico con exito.\n");
				}
				break;
			case 5:
				if(controller_removeEmployee(listaEmpleados))
				{
					printf("\nEl empleado se dio de baja con exito.\n");
				}
				break;
			case 6:
				employeeAmount = controller_ListEmployee(listaEmpleados);
				if(employeeAmount == 0)
				{
					printf("\nNo hay empleados por mostrar.\n\n");
				}
				break;
			case 7:
				if(controller_sortEmployee(listaEmpleados))
				{
					printf("Los nombres se ordenaron alfabeticamente con exito.\n");
				}
				break;
			case 8:
				if(ll_len(listaEmpleados) > 0)
				{
					if(controller_saveAsText("data.csv",listaEmpleados))
					{
						 printf("\nEmpleados guardados correctamente en modo texto.\n");
					}
					else
					{
						printf("\nNo se guardaron los empleados.\n");
					}
				}
				else
				{
					printf("\nNo hay empleados en el sistema.\n");
				}
				break;
			case 9:
				if(ll_len(listaEmpleados) > 0)
				{
					if(controller_saveAsBinary("data.bin",listaEmpleados))
					{
						 printf("\nEmpleados guardados correctamente en modo binario.\n");
					}
					else
					{
						printf("\nNo se guardaron los empleados.\n");
					}
				}
				else
				{
					printf("\nNo hay empleados en el sistema.\n");
				}
				break;
		}

	}while(option!=10);

	return 0;
}

