#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <winbgim.h>

int main()
{
    int *tablero;

	/*vector din�mico que guarda la soluci�n
	 ( numero de columna en la que est� la reina ) :*/
	tablero = (int*)malloc(sizeof(int));

	if(tablero==NULL){
            /*NO PUDO ASIGNAR ESPACIO*/
            printf("\n No se pudo reservar espacio en memoria memoria \n\n");
	}
	else{
            /*HUBO ESPACIO SUFICIENTE*/
            printf("\n Espacio de memoria reservado correctamente \n\n");
	}

	system("pause");

    return 0;
}
