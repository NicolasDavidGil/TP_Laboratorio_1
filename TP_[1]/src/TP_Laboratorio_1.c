/*
 ===================================================================================================================
 Name        : 			TP_Laboratorio_1.c
 Author      : 		Gil Nicolas David
 Description :	 	Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
							   para ofrecerlos a sus clientes.
							   Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
							 	 El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
							 Para ello el programa iniciará y contará con un menú de opciones:
							 1. Ingresar Kilómetros: ( km=x)
							 2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
							 - 			Precio vuelo Aerolíneas:
							 - 			Precio vuelo Latam:
							 3. Calcular todos los costos:
									 a) Tarjeta de débito (descuento 10%)
									 b) Tarjeta de crédito (interés 25%)
									 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
									 d) Mostrar precio por km (precio unitario)
									 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
							 4. Informar Resultados
									 “Latam:
									 a) Precio con tarjeta de débito:
									 b) Precio con tarjeta de crédito:
									 c) Precio pagando con bitcoin :
									 d) Precio unitario:
										 Aerolíneas:
									 a) Precio con tarjeta de débito:
									 b) Precio con tarjeta de crédito:
									 c) Precio pagando con bitcoin :
									 d) Precio unitario:
									 La diferencia de precio es :
							 5. Carga forzada de datos
							 6. Salir
 ==================================================================================================================
 */

#include "Menus.h"


int main(void)
{
	setbuf(stdout, NULL);
	printf("\n***************************BIENVENIDOS********************************************************************************** \n "
		       "\n***************************EMPECEMOS********************************************************************************** \n"
	           "\n");

	MenuPrincipal();

	return 0;
}
