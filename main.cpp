#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <winbgim.h>
void Reinas(int,int,int*);
void resultados(int,int*);
int main()
{
    int *tablero;

	/*vector dinámico que guarda la solución
	 ( numero de columna en la que está la reina ) :*/
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


    void(*freinas)(int, int, int*); /*Preparo una variable tipo
    apuntador a función*/

	freinas = &Reinas; /*Apunto a la dirección de memoria de la función
	 que calcula e imprime tableros */

 	(*freinas)(1, 8, tablero);/*Mando a llamar mi función mediante un apuntador*/

 	free(tablero); /*LIBERA EL ESPACIO DE MEMORIA USADO*/

    return 0;
}
void Reinas(int row,int n, int* b)
{ /*Recibe como parámetro la fila en que colocará a la reina,
    el tamanyo del tablero y pasa por referencia la dirección de board
  */
    void(*fresultado)(int, int*); /*Prepara una variable tipo
    apuntador a función*/

  	fresultado = &resultados; /*Apunto a la dirección de memoria de la función
  	que se utilizará posteriormente*/

	for(int col=1;col<=n;++col)
 	{
 	    /*Prueba con todas las columnas de la fila actual, es decir (row,col)
          buscando colocar la reina en algun lugar valido       */



 	}
}

void resultados(int n, int* b)
{ //función que imprime el resultado

}

