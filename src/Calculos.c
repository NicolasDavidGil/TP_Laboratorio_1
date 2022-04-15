/*
 * Calculos.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Gil Nicolás David
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "Menus.h"
#include "Ingresos.h"
#include "Calculos.h"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void IniciarCargaForzada(void)
{
	int kilometrosCargaForzada;
	float precioAerolineasCargaForzada;
	float precioLatamCargaForzada;
	kilometrosCargaForzada = 7090;
	precioAerolineasCargaForzada = 162965;
	precioLatamCargaForzada = 159339;
	float latamCargaForDebito;
	float latamCargaForCredito;
	float latamCargaForBitcoin;
	float latamCargaKilometros;
	float aerolineasCargaForDebito;
	float aerolineasCargaForCredito;
	float aerolineasCargaForBitcoin;
	float aerolineasCargaKilometros;
	float diferenciaLatamAerolineasCargaFor;

	latamCargaForDebito = CuentaDebCreBit(precioLatamCargaForzada, 1);
	latamCargaForCredito = CuentaDebCreBit(precioLatamCargaForzada, 2);
	latamCargaForBitcoin = CuentaDebCreBit(precioLatamCargaForzada, 3);
	latamCargaKilometros = CalcularDiferenciaPrecioKilometro(precioLatamCargaForzada, kilometrosCargaForzada, 1);
	aerolineasCargaForDebito = CuentaDebCreBit(precioAerolineasCargaForzada, 1);
	aerolineasCargaForCredito = CuentaDebCreBit(precioAerolineasCargaForzada, 2);
	aerolineasCargaForBitcoin = CuentaDebCreBit(precioAerolineasCargaForzada, 3);
	aerolineasCargaKilometros = CalcularDiferenciaPrecioKilometro(precioAerolineasCargaForzada, kilometrosCargaForzada, 1);
	diferenciaLatamAerolineasCargaFor = CalcularDiferenciaPrecioKilometro(precioAerolineasCargaForzada, precioLatamCargaForzada, 2);
	printf(GREEN"\n");
	printf("=================================================================================================================");
	printf("\n...Iniciando carga forzada... \n");
	printf("\n=================================================================================================================");
	printf(RESET CYAN"\nKilometros ingresados: "RESET"%d \n"CYAN
	       "\nLatam: \n"RESET
	       "\nValor total: $%.2f \n", kilometrosCargaForzada, precioLatamCargaForzada);
	printf("Precio con tarjeta de débito: $%.2f \n", latamCargaForDebito);
	printf("Precio con tarjeta de credito: $%.2f \n", latamCargaForCredito);
	printf("Precio con Bitcoin: %.2f BTC \n", latamCargaForBitcoin);
	printf("Precio por kilometros: $%.2f \n", latamCargaKilometros);
	printf("\n"CYAN
	       "Aerolíneas Argentinas: \n"RESET
	       "\nValor total: $%.2f \n", precioAerolineasCargaForzada);
	printf("Precio con tarjeta de débito: $%.2f \n", aerolineasCargaForDebito);
	printf("Precio con tarjeta de credito: $%.2f \n", aerolineasCargaForCredito);
	printf("Precio con Bitcoin: %.2f BTC \n", aerolineasCargaForBitcoin);
	printf("Precio por kilometros: $%.2f \n"
	       "\n", aerolineasCargaKilometros);
	printf("Diferecia entre ambos vuelos: %.2f\n", diferenciaLatamAerolineasCargaFor);
	printf(GREEN"=================================================================================================================\n");
	printf("\n...Carga forzada completada... \n");
	printf("\n=================================================================================================================\n"RESET);
}

double CuentaDebCreBit(double precio, int aux)
{
	double precioFinal;
	double valorBitcoin = 4606954.55;
	if(aux == 1)
	{
		precioFinal = precio - (precio * 0.10);
	}else if(aux == 2)
	{
		precioFinal = precio + (precio * 0.25);
	}else if(aux == 3)
	{
		precioFinal = precio / valorBitcoin;
	}

	return precioFinal;
}
float CalcularDiferenciaPrecioKilometro(float precio1, float precio2, int aux)
{
	float resultado;
	if(aux == 1)
	{
		if(precio2 != 0)
		{
			resultado = precio1 / precio2;
		}else
		{
		    resultado = 0;
		}

	}
	if(aux == 2)
	{
		if(precio1 > precio2)
		{
			resultado = precio1 - precio2;
		}else if(precio2 > precio1)
		{
			resultado = precio2 - precio1;
		}else
		{
			resultado = 0;
		}
	}

	return resultado;
}
