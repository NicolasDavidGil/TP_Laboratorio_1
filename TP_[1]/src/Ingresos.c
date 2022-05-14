/*
 * Ingresos.c
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
#include "Calculos.h"
#include "Ingresos.h"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

double PedirIngresoNumero(char mensaje[])
{
	char cadena[10];
    int auxValidacion;
	double resultado;
	do
	{
	    printf("\n%s: ", mensaje);
	    scanf("%s", cadena);
	    auxValidacion = ValidarIngresoNumeros(cadena);

	}while(auxValidacion == 0);

	resultado = atof(cadena);

	return resultado;
}

int ValidarIngresoNumeros(char numero[])
{
	for(int i=0; i < strlen(numero); i++)
    {
		if(!isdigit(numero[i]))
        {
        	printf(RED"\nAlgo salió mal, ingrese un número positivo por favor: \n"RESET);
        	return 0;
        }
    }

    return 1;
}
