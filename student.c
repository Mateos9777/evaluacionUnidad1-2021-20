#include <stdlib.h>
#include "student.h"
#include <string.h>

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
}

//lee la segunda línea del archivo de entrada,
//invierte su orden y la escribe en la segunda línea del archivo de salida.
//Usamos el buffer para el tamano de la memoria que usaremos
//Usamos la funcion fgets para saber el tamano del buffer
//hacemos un ciclo for que decrementa y le restamos dos por los espacios al final
void feature2(FILE *fin, FILE *fout)
{

    char buffer[70]; // Revisar el tamano para modificarlos
    char *estado = NULL;
    int contador = 0;

    estado = fgets(buffer, sizeof(buffer), fin);
    if (estado != NULL)
    {
        for (contador = sizeof(buffer) - 2; contador >= 0; contador--)
        {
            fprintf(fout, "%c", buffer[contador]);
        }
         fprintf(fout,"%s","\n");
    }
   
    printf("\n");
}

//lee el arreglo de enteros de la tercera línea del archivo de entrada,
//FSCANF se usa para leer los datos y asi sumarlos.
//calcula la suma y almacena el resultado en la tercera línea del archivo de salida.
//el buffer es el tama;o que queremos que tome para sumar.
//revisar si puedo hacerlo sin buffer para mejorarlo.
void feature3(FILE *fin, FILE *fout)
{
    int contador = 0;
    char buffer[10];
    int resultado = 0, valoractual = 0;
    char *estado = NULL;
    estado = fgets(buffer, sizeof(buffer), fin);
    if (estado != NULL)
    {
        for (contador = 0; contador <= sizeof(buffer); contador++)
        {   fscanf(fin , "%d",&valoractual);
            resultado = resultado + valoractual; 
        }
     }
    
    fprintf(fout, "%d", resultado);
}

