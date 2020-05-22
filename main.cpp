#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <winbgim.h>
void Reinas(int,int,int*);
void resultados(int,int*);
int esvalida(int,int,int*);
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


    void(*freinas)(int, int, int*); /*Preparo una variable tipo
    apuntador a funci�n*/

	freinas = &Reinas; /*Apunto a la direcci�n de memoria de la funci�n
	 que calcula e imprime tableros */

 	(*freinas)(1, 8, tablero);/*Mando a llamar mi funci�n mediante un apuntador*/

 	free(tablero); /*LIBERA EL ESPACIO DE MEMORIA USADO*/

    return 0;
}
void Reinas(int row,int n, int* b)
{ /*Recibe como par�metro la fila en que colocar� a la reina,
    el tamanyo del tablero y pasa por referencia la direcci�n de board
  */
    void(*fresultado)(int, int*); /*Prepara una variable tipo
    apuntador a funci�n*/

  	fresultado = &resultados; /*Apunto a la direcci�n de memoria de la funci�n
  	que se utilizar� posteriormente*/

	for(int col=1;col<=n;++col)
 	{
 	    /*Prueba con todas las columnas de la fila actual, es decir (row,col)
          buscando colocar la reina en algun lugar valido       */
          if(esvalida(row,col,b)) /*si ninguna la ataca*/
  		  {     /*Manda a llamar a una funci�n que devuelve
                1 si en esa coordenada ninguna reina puesta
                antes la ataca, 0 si alguna la ataca
                */
                *(b+row) = col; //No hay conflicto, coloca reina

                if(row==n) /*Pregunta si ya llen� el tablero*/
                {
                        /*Ha conseguido colocar todo un tablero*/


                } else {
                        /*aun faltan filas del tablero en donde poner reinas*/
                        Reinas(row+1,n, b);
                }

          }


 	}
}
int esvalida(int row,int column, int* b)
{
    //Determina si la reina no est� en peligro
 int i; /* iterador de las posiciones de board*/
 for(i=1;i<=row-1;++i)
 {
	  if(*(b+i)==column){
	   /* en esa i-esima  columna ya se ha puesto una reina*/
            return 0;
	  }else{

        if(abs(*(b+i)-column)==abs(i-row)){
            /*hay una reina que la ataca en diagonal*/
            return 0;
        }

	  }
 }
 /*ya ha preguntado con todas las reinas puestas antes,
 y ha encontrado un lugar para colocarla*/
 return 1;

}

void resultados(int n, int* b)
{ //funci�n que imprime el resultado

}

