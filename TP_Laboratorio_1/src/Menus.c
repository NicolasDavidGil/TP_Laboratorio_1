/*
 * Menus.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Gil Nicolás David
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "Ingresos.h"
#include "Calculos.h"
#include "Menus.h"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void MenuPrincipal(void)
{
	int respuestaSalir; 			/// Para case6 verifica el salir del programa.
	int respuestaOpcion; 			/// Se usa dentro del menu de opciones.
	double kilometrosIngresados = 0;
	double precioAerolineas = 0;
	double precioLatam = 0;
	int flagKilometros = 0; 		/// Cambia despues de que el usuario ingresa un valor.
	int flagPrecioAerolineas = 0;	/// Cambia despues de que el usuario ingresa un valor.
	int flagPrecioLatam = 0;		/// Cambia despues de que el usuario ingresa un valor.
	int respuestaCase2; 			/// Para el submenu de precio de vuelos.
	float precioLatamDebito;
	float precioLatamCredito;
	float precioLatamBitcoin;
	float precioLatamKilometro;
    float precioAerollineasDebito;
	float precioAerolineasCredito;
	float precioAerolineasBitcoin;
	float precioAerolineasKilometro;
	float diferenciaLatamAerolineas;
	char mensajeKilometros[50] = "Ingrese los kilometros de su vuelo: ";
	char mensajeVuelos[50] = "Ingrese el costo de su vuelo: ";
	int flagCalculosHechos = 0; 	/// Verifica no entrar en mostrar resultados sin haber calculado antes.

	do
	{
		if(flagKilometros == 0 && flagPrecioAerolineas == 0 && flagPrecioLatam == 0)
		{
			MenuInteractivo(0, 0, 0);
		}
		if(flagKilometros == 1 && flagPrecioAerolineas == 0 && flagPrecioLatam == 0)
		{
			MenuInteractivo(kilometrosIngresados, 0, 0);
		}
		if(flagKilometros == 1 && flagPrecioAerolineas == 1 && flagPrecioLatam == 0)
		{
			MenuInteractivo(kilometrosIngresados, precioAerolineas, 0);
		}
		if(flagKilometros == 1 && flagPrecioAerolineas == 0 && flagPrecioLatam == 1)
		{
			MenuInteractivo(kilometrosIngresados, 0, precioLatam);
		}
		if(flagKilometros == 0 && flagPrecioAerolineas == 1 && flagPrecioLatam == 0)
		{
			MenuInteractivo(0, precioAerolineas, 0);
		}
		if(flagKilometros == 0 && flagPrecioAerolineas == 0 && flagPrecioLatam == 1)
		{
			MenuInteractivo(0, 0, precioLatam);
		}
		if(flagKilometros == 0 && flagPrecioAerolineas == 1 && flagPrecioLatam == 1)
		{
			MenuInteractivo(0, precioAerolineas, precioLatam);
		}
		if(flagKilometros == 1 && flagPrecioAerolineas == 1 && flagPrecioLatam == 1)
		{
			MenuInteractivo(kilometrosIngresados, precioAerolineas, precioLatam);
		}
		scanf("%d", &respuestaOpcion);

		switch(respuestaOpcion)
		{
			case 1:
				kilometrosIngresados = PedirIngresoNumero(mensajeKilometros);
				flagKilometros = 1;
				break;
			case 2:
				printf("\n¿Qué precio desea ingresar o modificar?\n"
							"\t1- Para ingresar o modificar precio de Aerolineas Argentinas. \n"
							"\t2- Para ingresar o modificar precio de LATAM. \n"
							"\t3- Volver sin modificar.\n"
							"Ingrese opción deseada: ");
				scanf("%d", &respuestaCase2);
				switch(respuestaCase2)
				{
					case 1:
						precioAerolineas = PedirIngresoNumero(mensajeVuelos);
						flagPrecioAerolineas = 1;
						break;
					case 2:
						precioLatam = PedirIngresoNumero(mensajeVuelos);
						flagPrecioLatam = 1;
						break;
					case 3:
						break;
					default:
						printf(RED"\nAlgo salió mal, por favor ingrese solo números positivos: \n"RESET);
						break;
				}
				break;
			case 3:
				if(flagKilometros == 1 && flagPrecioAerolineas == 1 && flagPrecioLatam == 1)
				{

				    precioLatamDebito = CuentaDebCreBit(precioLatam, 1);
				    precioLatamCredito = CuentaDebCreBit(precioLatam, 2);
				    precioLatamBitcoin = CuentaDebCreBit(precioLatam, 3);
				    precioLatamKilometro = CalcularDiferenciaPrecioKilometro(precioLatam, kilometrosIngresados, 1);
				    precioAerollineasDebito = CuentaDebCreBit(precioAerolineas, 1);
				    precioAerolineasCredito = CuentaDebCreBit(precioAerolineas, 2);
				    precioAerolineasBitcoin = CuentaDebCreBit(precioAerolineas, 3);
				    precioAerolineasKilometro = CalcularDiferenciaPrecioKilometro(precioAerolineas, kilometrosIngresados, 1);
				    diferenciaLatamAerolineas = CalcularDiferenciaPrecioKilometro(precioAerolineas, precioLatam, 2);
				    flagCalculosHechos = 1;
				    printf(GREEN"\n");
				    printf("=================================================================================================================");
				    printf("\nYa hemos realizado las operaciones solicitadas. \n"
				    			"La opción 4 para ver los resultados ya esta habilitada. \n");
				    printf("=================================================================================================================");
				    printf("\n"RESET);
				}else
				{
					printf(RED"\n");
					printf("=================================================================================================================");
					printf("\nLo sentimos, no se ha podido  realizar esta operación. \n"
								"Debemos tener ingresados los kilometros y los precios de los vuelos.\n");
					printf("=================================================================================================================");
					printf("\n"RESET);
				}
				break;
			case 4:
			    if(flagCalculosHechos == 1)
			    {
			    	printf("\n");
			    	printf(GREEN"=================================================================================================================");
		            printf("\nEstos son los resultados obtenidos: \n"RESET CYAN
	                       "\nKilometros Ingresados:"RESET "%.2f \n", kilometrosIngresados);
		            printf(CYAN"\nLatam: \n");
		            printf(RESET);
		            printf("\nValor total: $%.2f \n", precioLatam);
	                printf("Precio con tarjeta de débito: $%.2f \n", precioLatamDebito);
	                printf("Precio con tarjeta de crédito: $%.2f \n", precioLatamCredito);
	                printf("Precio con Bitcoin: %.2lf BTC \n", precioLatamBitcoin);
	                printf("Precio por kilometros: $%.2f \n", precioLatamKilometro);
	                printf("\n");
	                printf(CYAN);
	                printf ("Aerolíneas Argentinas: \n");
	                printf(RESET);
	                printf("\nValor total: $%.2f \n", precioAerolineas);
	                printf("Precio con tarjeta de débito: $%.2f \n", precioAerollineasDebito);
	                printf("Precio con tarjeta de crédito: $%.2f \n", precioAerolineasCredito);
	                printf("Precio con Bitcoin: %.2lf BTC \n", precioAerolineasBitcoin);
	                printf("Precio por kilometros: $%.2f \n"
	                       "\n", precioAerolineasKilometro);
	                printf("La direfencia entre ambos vuelos es: %.2f \n", diferenciaLatamAerolineas);
	                printf(GREEN"=================================================================================================================");
	                printf(RESET"\n");

			    }else
			    {
			    	printf(RED"\n");
			    	printf("=================================================================================================================");
			        printf("\nNo podemos realizar esta operación sin antes realizar los cálculos.\n"
			        			"Tiene a su disposición la opción 3 para esto. \n");
			        printf("=================================================================================================================");
			        printf(RESET"\n");
			    }
			    break;
			case 5:
				IniciarCargaForzada();
				break;
			case 6:
				printf(RED"\nEsta a punto de abandonar el programa. Esta seguro? \n"RESET);
				printf("\n1- Para salir. \n"
					   " Cualquier otra tecla para volver al programa. \n"
					   "\n¿Que desea hacer?: ");
				scanf("%d", &respuestaSalir);
				switch(respuestaSalir)
				{
					case 1:
						printf(GREEN"\n");
						printf("=================================================================================================================");
						printf("\nGracias por usar nuestro programa! Hasta pronto. \n");
						printf("=================================================================================================================");
						break;
					default:
						printf("\n");
						printf("=================================================================================================================");
						printf("\nGracias por quedarte! Sigamos... \n");
						printf("=================================================================================================================");
						printf("\n"RESET);
						break;
				}
				break;
				default:
						printf(RED"\nLo sentimos, el ingreso no corresponde a un valor válido del menu.\n"
									"Por favor ingrese otro valor: \n"RESET);
				break;
		}
	}while(respuestaSalir!= 1);
}






void MenuInteractivo(double kilometros, double AeroArg, double Latam)
{
	printf(CYAN	"\n¿Qué desea hacer? \n"RESET
			"\n1- Ingresar Kilometros del vuelo:" GREEN"%.2lf \n"RESET
			"2- Ingresar precios de vuelos: \n"
			"\tPrecio Aerolineas Argentinas: "GREEN"%.2lf \n"RESET, kilometros, AeroArg);
	printf("\t\tPrecio Latam:" GREEN"%.2lf \n" RESET
			"3- Calcular todos los costos. \n"
			"4- Informar resultados. \n"
			"5- Carga forzada de datos. \n"
			"6- Salir \n"CYAN
			"\nIngrese una opción: "RESET, Latam);
}
