/*
 * 	Menus.c
 *
 *  	Created on: 12 abr. 2022
 *      Author: Gil Nicolás David
 */

#include "Menus.h"

void MenuPrincipal(void)
{
	int respuestaSalir; 			/// Para case6 verifica el salir del programa.
	int respuestaOpcion; 		
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
	char mensajeKilometros[50] = "\nIngrese los kilometros de su vuelo: ";
	char mensajeVuelos[50] = "\nIngrese el costo de su vuelo: ";
	int flagCalculosHechos = 0; 	/// Verifica no entrar en mostrar resultados sin haber calculado antes.

	do
	{
		respuestaOpcion = MenuInteractivo(kilometrosIngresados, precioAerolineas, precioLatam);
		switch(respuestaOpcion)
		{
			case 1:
				kilometrosIngresados = RequestIntInRange(mensajeKilometros, "Ingreso no valido", 1, INT_MAX);
				flagKilometros = 1;
				break;
			case 2:
				printf("\n¿Qué precio desea ingresar o modificar?\n"
							"\t1- Para ingresar o modificar precio de Aerolineas Argentinas. \n"
							"\t2- Para ingresar o modificar precio de LATAM. \n"
							"\t3- Volver sin modificar.\n");
				respuestaCase2 = RequestIntInRange("Ingrese opción deseada: ", "Opcion no valida", 1, 3);
				switch(respuestaCase2)
				{
					case 1:
						precioAerolineas = RequestIntInRange(mensajeVuelos, "Ingreso no valido", 1, INT_MAX);
						flagPrecioAerolineas = 1;
						break;
					case 2:
						precioLatam = RequestIntInRange(mensajeVuelos, "Ingreso no valido", 1, INT_MAX);
						flagPrecioLatam = 1;
						break;
					case 3:
						break;
					default:
						printf("\nAlgo salió mal, por favor ingrese solo números positivos: \n");
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

				    printf("\n================================================================================================================="
								"\nYa hemos realizado las operaciones solicitadas. \n"
								"La opción 4 para ver los resultados ya esta habilitada. \n"
								"=================================================================================================================\n");
				}else
				{
					printf("\n================================================================================================================="
								"\nLo sentimos, no se ha podido  realizar esta operación. \n"
								"Debemos tener ingresados los kilometros y los precios de los vuelos.\n"
								"=================================================================================================================\n");
				}
				break;
			case 4:
			    if(flagCalculosHechos == 1)
			    {
			    	printf("\n=================================================================================================================");
		            printf("\nEstos son los resultados obtenidos: \n"
	                       "\nKilometros Ingresados: %.2f \n", kilometrosIngresados);
		            printf("\nLatam: \n");
		            printf("\nValor total: $%.2f \n", precioLatam);
	                printf("Precio con tarjeta de débito: $%.2f \n", precioLatamDebito);
	                printf("Precio con tarjeta de crédito: $%.2f \n", precioLatamCredito);
	                printf("Precio con Bitcoin: %.2lf BTC \n", precioLatamBitcoin);
	                printf("Precio por kilometros: $%.2f \n", precioLatamKilometro);

	                printf ("\nAerolíneas Argentinas: \n");
	                printf("\nValor total: $%.2f \n", precioAerolineas);
	                printf("Precio con tarjeta de débito: $%.2f \n", precioAerollineasDebito);
	                printf("Precio con tarjeta de crédito: $%.2f \n", precioAerolineasCredito);
	                printf("Precio con Bitcoin: %.2lf BTC \n", precioAerolineasBitcoin);
	                printf("Precio por kilometros: $%.2f \n"
	                       "\n", precioAerolineasKilometro);
	                printf("La direfencia entre ambos vuelos es: %.2f \n", diferenciaLatamAerolineas);
	                printf("=================================================================================================================\n");


			    }else
			    {

			    	printf("\n================================================================================================================="
								"\nNo podemos realizar esta operación sin antes realizar los cálculos.\n"
								"Tiene a su disposición la opción 3 para esto. \n"
								"=================================================================================================================\n");
			    }
			    break;
			case 5:
				IniciarCargaForzada();
				break;
			case 6:
				printf("\nEsta a punto de abandonar el programa. Esta seguro? \n"
							"\n1- Para salir. \n"
						   " Cualquier otra tecla para volver al programa. \n");
				respuestaSalir = RequestIntInRange("\n¿Que desea hacer?: ", "Ingreso no valido.", 1, INT_MAX);
				switch(respuestaSalir)
				{
					case 1:
						printf("\n================================================================================================================="
									"\nGracias por usar nuestro programa! Hasta pronto. \n"
									"=================================================================================================================");
						break;
					default:
						printf("\n"
									"================================================================================================================="
									"\nGracias por quedarte! Sigamos... \n"
									"=================================================================================================================\n");
						break;
				}
				break;
				default:
						printf("\nLo sentimos, el ingreso no corresponde a un valor válido del menu.\n"
									"Por favor ingrese otro valor: \n");
				break;
		}
	}while(respuestaSalir!= 1);
}


int MenuInteractivo(double kilometros, double AeroArg, double Latam)
{
	int opcion;
	printf("\n¿Qué desea hacer? \n"
			"\n1- Ingresar Kilometros del vuelo: %.2lf \n"
			"2- Ingresar precios de vuelos: \n"
			"\tPrecio Aerolineas Argentinas: ""%.2lf \n", kilometros, AeroArg);
	printf("\t\tPrecio Latam: %.2lf \n"
			"3- Calcular todos los costos. \n"
			"4- Informar resultados. \n"
			"5- Carga forzada de datos. \n"
			"6- Salir \n", Latam);
	opcion = RequestIntInRange("\nIngrese una opción: ", "Ingreso no valido.", 1, 6);

	return opcion;
}
