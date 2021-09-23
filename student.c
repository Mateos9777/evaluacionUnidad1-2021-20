#include <stdlib.h>
#include "student.h"
#include <string.h>

#define tamano_maximo 250

// lee la primer línea del archivo de entrada y la escribe en la primer línea del archivo de salida.
void feature1(FILE *fin, FILE *fout)
{

    char buffer[64];
    char *status = NULL;
    int cont = 0;
    do
    {
        status = fgets(buffer, sizeof(buffer), fin);
        cont++;
        if (status != NULL)
        {
            fputs(buffer, fout);
        }
    } while (cont <= 0);
    printf("\n");
    //free(buffer);
    //free(status);

}

//lee la segunda línea del archivo de entrada,
//invierte su orden y la escribe en la segunda línea del archivo de salida.
//Usamos el buffer para el tamano de la memoria que usaremos
//Usamos la funcion fgets para saber el tamano del buffer
//hacemos un ciclo for que decrementa y le restamos dos por los espacios al final
//Usamos calloc para reservar el espacio y iniciarliazar en 0
void feature2(FILE *fin, FILE *fout)
{
    char* bufer = (char *)calloc(tamano_maximo,sizeof(char));
    fgets(bufer,tamano_maximo,fin);
    char* temp = (char *)calloc(1,sizeof(char));    
    char* bufer2 = strtok(bufer,"\n");
    int lon = strlen(bufer2);
    for(int i=0;i<(lon/2);i++){//ciclo para Leer al reves el texto siendo el indice i
        *temp = bufer2[i];
        bufer2[i] = bufer2[lon - i - 1];
        bufer2[lon-i - 1 ] = *temp;
    }
    fprintf(fout,"%s\n",bufer2);
    free(bufer2);
    free(temp);
}

//lee el arreglo de enteros de la tercera línea del archivo de entrada,
//CALLOC se usa para reservar espacio y en 0
//calcula la suma y almacena el resultado en la tercera línea del archivo de salida.
void feature3(FILE *fin, FILE *fout){

char* bufer = (char *)calloc(tamano_maximo,sizeof(char));
    short* numeros = (short *) calloc(tamano_maximo,sizeof(short));
    char* temp = (char *)calloc(4,sizeof(char));
    char *bash;
    fgets(bufer,tamano_maximo,fin);
    int contador=0;
    int suma = 0;
    temp = strtok(bufer, " ");
    while(temp != NULL){
        numeros[contador] = strtol(temp,&bash,10);
        suma = suma + numeros[contador];
        temp = strtok(NULL, " ");
        contador++;        
    }
    fprintf(fout,"%d\n",suma);
    free(bufer);    
    free(temp);
    free(numeros);
}
void feature4(FILE *fin, int **parr, int *length, char **op)
{
}
void feature5(FILE *fout, int *parr, int length, char *op)
{
}
void feature6(FILE *fin, struct Obj_t *pobj)
{
}
void feature7(FILE *fout, struct Obj_t *pobj)
{
}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length)
{
}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length)
{
}