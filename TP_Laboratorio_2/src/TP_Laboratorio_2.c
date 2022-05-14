/*
 ============================================================================
 Name        : 		TP_Laboratorio_2.c
 Author      : 		Gil Nicol�s David.
 Description : 	TP_Laboratorio_2

							1 Enunciado
							Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
							no puede tener m�s de 2000 pasajeros.

							Datos:

							El sistema deber� tener el siguiente men� de opciones:
							1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
								n�mero de Id. El resto de los campos se le pedir� al usuario.
							2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
								o Precio o Tipo de pasajero o C�digo de vuelo
							3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
							4. INFORMAR:
								1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
								2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
								promedio.
								3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
							5. Carga Forzada Preferentemente con 5 pasajeros.
							1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
							Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
							carga de alg�n pasajero.
							2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 ============================================================================
 */

#include "Menus.h"


int main(void)
{
	setbuf(stdout, NULL);

	printf("=========================================================================================================================================\n"
			"\tB I E N V E N I D O S\n"
			"============================================================================================================================================");

	MainMenu();
	return 0;
}
