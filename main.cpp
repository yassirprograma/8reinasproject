#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <winbgim.h>
int count;
void Reinas(int,int,int*);
void resultados(int,int*);
int esvalida(int,int,int*);
void tablaG(void);
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

    initwindow(700,700); //iniciamos la pantalla grafica
    setbkcolor(8);
    cleardevice();

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
          if(esvalida(row,col,b)) /*si ninguna la ataca*/
  		  {     /*Manda a llamar a una función que devuelve
                1 si en esa coordenada ninguna reina puesta
                antes la ataca, 0 si alguna la ataca
                */
                *(b+row) = col; //No hay conflicto, coloca reina

                if(row==n) /*Pregunta si ya llenó el tablero*/
                {
                        /*Ha conseguido colocar todo un tablero*/
                        tablaG();
                         (*fresultado)(n,b); /*Llama con punteros
                         a la función  que imprime el tablero*/
                        getch();
                        cleardevice();

                } else {
                        /*aun faltan filas del tablero en donde poner reinas*/
                        Reinas(row+1,n, b);
                }

          }


 	}
}
int esvalida(int row,int column, int* b)
{
    //Determina si la reina no está en peligro
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
void tablaG(){

	rectangle(70,70,550,550);
    int k=70;
    char imp[10], imp2[10];

    for(int i=1;i<=7;i++){

        line(k+(i*60),k,k+(i*60),550);
    }

    for(int i=1;i<=7;i++){

        line(70,k+(i*60),550,k+(i*60));
    }
   	for(int i=1; i<=8; i++){
   		sprintf(imp,"%i",i);
   		outtextxy(40+(60*i),50,imp);
	   }
	for(int i=1; i<=8; i++){
		sprintf(imp2,"%i",i);
		outtextxy(50,40+(60*i), imp2);
	}

}
void resultados(int n, int* b)
{ //función que imprime el resultado
     printf("\n\nSolucion %d:\n\n",++count);

    for(int i=1;i<=n;++i) printf("\t%d",i);//numeracion de columnas

    for(int i=1;i<=n;++i)
    {
        printf("\n\n%d",i); //numeracion de filas

        for(int j=1;j<=n;++j) //
        {
            if(*(b+i)==j)
                printf("\tQ"); /*coordenada con reina*/
            else
                printf("\t."); /*coordenada sin reina*/
        }

    }
}

