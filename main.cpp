#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>

int count;
char ask;
char itab[10];
FILE *soluciones (fopen("soluciones.txt", "wt")); //genera un archivo de texto
void Reinas(int,int,int*);
void resultados(int,int*);
int esvalida(int,int,int*);
void tablaG(void);
void figura(int, int);
int main()
{
    puts("Presione S si desea iniciar un nuevo archivo con soluciones");
    scanf("%c",&ask);

    if(ask=='s' || ask=='S'){ // pregunta si desea generar un archivo nuevo
        fflush(soluciones); //reiniciamos nuestro archivo
    }

    if(soluciones==NULL){
        perror("ERROR EN LA APERTURA DEL ARCHIVO");
    }

    int *tablero;  /*vector din�mico que guarda la soluci�n
    ( numero de columna en la que est� la reina ) :*/

	tablero = (int*)malloc(sizeof(int)*20);

	if(tablero==NULL){
            /*NO PUDO ASIGNAR ESPACIO*/
           printf("\n No se pudo reservar espacio en memoria memoria \n\n");
	}else{
            /*HUBO ESPACIO SUFICIENTE*/
           // printf("\n Espacio de memoria reservado correctamente \n\n");
	}

	// system("pause");


    void(*freinas)(int, int, int*); /*Preparo una variable tipo
    apuntador a funci�n*/

	freinas = &Reinas; /*Apunto a la direcci�n de memoria de la funci�n
	 que calcula e imprime tableros */

    initwindow(700,700); //iniciamos la pantalla grafica
    setbkcolor(8);
    cleardevice();

 	(*freinas)(1, 8, tablero);/*Mando a llamar mi funci�n mediante un apuntador*/

 	free(tablero); /*LIBERA EL ESPACIO DE MEMORIA USADO*/
    fclose(soluciones);
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
                             tablaG();
                         (*fresultado)(n,b); /*Llama con punteros
                         a la funci�n  que imprime el tablero*/
                         outtextxy(100,600, "PRESIONE ESPACIO PARA CONTINUAR");
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
{ //funci�n que imprime el resultado

    printf("\n\nSolucion %d:\n\n",++count); //cuenta en consola
    fprintf(soluciones,"\n\n Solucion %d :\n\n",count); //cuenta en archivo
    //cuenta en grafico:
    sprintf(itab,"%d",count); //conversion para modo grafico
    settextstyle(3,0,3);
    outtextxy(250,10,"Tablero numero:");
    outtextxy(450,10,itab);

    for(int i=1;i<=n;++i) {
        printf("\t%d",i);//numeracion de columnas
        fprintf(soluciones,"\t%d",i);
    }

    for(int i=1;i<=n;++i)
    {
        printf("\n\n%d",i); //numeracion de filas
        fprintf(soluciones,"\n\n%d",i);
        for(int j=1;j<=n;++j) //
        {
            if(*(b+i)==j){
                figura(j,i); //coloca reina en grafico
                printf("\tQ"); /*coordenada con reina en consola*/
                fputs("\tQ",soluciones);
            }

            else{
                printf("\t#"); /*coordenada sin reina*/
                fputs("\t#",soluciones);
            }

        }

    }

    if(count==92){
        cleardevice();
        outtextxy(100,300,"Listo!, el archivo generado de las soluciones ");
        outtextxy(100,330,"se encuentra en la carpeta de este proyecto");
        getch();
    }

}
void figura(int a, int p){
    setcolor(14);
    int x=100+((a-1)*60), y=100+((p-1)*60);
 	line(x-20,y+20,x+20,y+20); //horizontal
	line(x-20,y+20,x-20,y-20);//linea izquierda vert
    line(x+20,y+20,x+20,y-20); //linea derecha vert
    line(x-20,y-20,x-10,y);//linea diagonal izquierda
    line(x+20,y-20,x+10,y); //linea diagonal derecha
    line(x-10,y,x,y-20); //diagonalcenizq
    line(x+10,y,x,y-20);//diagonal al centro derecha
    setcolor(4);
    circle(x,y-24,4);
    circle(x-20,y-24,4);
    circle(x+20,y-24,4);
    setcolor(15);
    circle(x,y,4);
}
