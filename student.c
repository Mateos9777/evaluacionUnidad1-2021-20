#include <stdlib.h>
#include "student.h"
#include <string.h>

void feature1(FILE *fin, FILE *fout){
    char buffer[64];
    char *status = NULL;
    int cont= 0; //Para controlar el ciclo que se haga solo para leer la primera linea de el archivo
    do{
        status = fgets(buffer,sizeof(buffer),fin);
        cont++;
        if(status != NULL){
        fputs(buffer, fout);
        }               
    }
    while (cont<=0);
    printf("\n");   
}
