/*
 ===================================================================================================================
 Name        : TP_Laboratorio_1.c
 Author      : Gil Nicolas David
 Description : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
			   para ofrecerlos a sus clientes.
 	 	 	   Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
 El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
 Para ello el programa iniciar� y contar� con un men� de opciones:
 1. Ingresar Kil�metros: ( km=x)
 2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
 - 			Precio vuelo Aerol�neas:
 - 			Precio vuelo Latam:
 3. Calcular todos los costos:
 	 	 a) Tarjeta de d�bito (descuento 10%)
 	 	 b) Tarjeta de cr�dito (inter�s 25%)
 	 	 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 	 	 d) Mostrar precio por km (precio unitario)
 	 	 e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
 4. Informar Resultados
 	 	 �Latam:
 	 	 a) Precio con tarjeta de d�bito:
 	 	 b) Precio con tarjeta de cr�dito:
 	 	 c) Precio pagando con bitcoin :
 	 	 d) Precio unitario:
    	  	 Aerol�neas:
 	 	 a) Precio con tarjeta de d�bito:
 	 	 b) Precio con tarjeta de cr�dito:
 	 	 c) Precio pagando con bitcoin :
 	 	 d) Precio unitario:
 	 	 La diferencia de precio es :
 5. Carga forzada de datos
 6. Salir
 ==================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#include "Menus.h"
#include "Ingresos.h"
#include "Calculos.h"


int main(void)
{
	setbuf(stdout, NULL);
	printf(CYAN);
	printf("\n***************************BIENVENIDOS********************************************************************************** \n "
		       "\n***************************EMPECEMOS********************************************************************************** \n"
	           "\n");
	printf(RESET);
	MenuPrincipal();

	return 0;
}
