#include <stdlib.h>
#include "student.h"
#include <string.h>

#define tamano_maximo 250

// lee la primer línea del archivo de entrada y la escribe en la primer línea del archivo de salida.
void feature1(FILE *fin, FILE *fout)
{

    char bufer[64];
    char *status = NULL;
    int cont = 0;
    do
    {
        status = fgets(bufer, sizeof(bufer), fin);
        cont++;
        if (status != NULL)
        {
            fputs(bufer, fout);
        }
    } while (cont <= 0);
    printf("\n");
    //free(bufer);
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
    char* temporal = (char *)calloc(1,sizeof(char));    
    char* bufer2 = strtok(bufer,"\n");
    int lon = strlen(bufer2);
    for(int i=0;i<(lon/2);i++){//ciclo para Leer al reves el texto siendo el indice i
        *temporal = bufer2[i];
        bufer2[i] = bufer2[lon - i - 1];
        bufer2[lon-i - 1 ] = *temporal;
    }
    fprintf(fout,"%s\n",bufer2);
    free(bufer2);
    free(temporal);
}

//lee el arreglo de enteros de la tercera línea del archivo de entrada,
//CALLOC se usa para reservar espacio y en 0
//calcula la suma y almacena el resultado en la tercera línea del archivo de salida.
void feature3(FILE *fin, FILE *fout){

char* bufer = (char *)calloc(tamano_maximo,sizeof(char));// uso de calloc para reservar
    short* numeros = (short *) calloc(tamano_maximo,sizeof(short));//uso calloc para reservar
    char* temporal = (char *)calloc(4,sizeof(char));
    char *bash;
    fgets(bufer,tamano_maximo,fin);
    int contador=0;
    int suma = 0;
    temporal = strtok(bufer, " ");
    while(temporal != NULL){
        numeros[contador] = strtol(temporal,&bash,10);
        suma = suma + numeros[contador];
        temporal = strtok(NULL, " ");
        contador++;        
    }
    fprintf(fout,"%d\n",suma);
    free(bufer);    
    free(temporal);
    free(numeros);
}


//lee el arreglo de enteros de la cuarta línea del archivo de 
//entrada así como la operación especificada luego del arreglo, 
//separada por un espacio.
//Aca igualmente se usa la operacion de calloc para reservar la memoria que vamos a necesitar
//Se usan comentarios con printf para ir verificando que si entre en las instruciones
//ya que no empleamos el archivo de salida para verificar.
void feature4(FILE *fin, int **parr, int *length, char **op){
    char* bufer = (char *)calloc(tamano_maximo,sizeof(char));
    char* temporal = (char *)calloc(4,sizeof(char));
    char *bash = (char *)calloc(4,sizeof(char));
    *parr = (int *)calloc(tamano_maximo,sizeof(int));
    *op = (char *)calloc(4,sizeof(char));
    *length = 0;
    int cont=0;
    fgets(bufer,tamano_maximo,fin);
    temporal = strtok(bufer, " ");
    
    while(temporal != NULL){
        (*parr)[cont] = strtol(temporal,&bash,10);
        temporal = strtok(NULL, " ");
        cont++;
        //printf("ENTRA AL CICLO CORRECTAMENTE\n");
        //printf("%c\n",*bufer);
        
    }
    //printf("sale del ciclo\n");
    strncpy(*op,bash,3);
    *length = cont;
    free(bufer);
    free(temporal);
    //free(parr); Se comenta porque ahora lo volvemos a usar


}


/*recibe la dirección del arreglo y de la operación leída en la feature anterior 
realiza la operación y guarda el resultado en la cuarta línea del archivo de salida.
 La operación puede ser avg, max, min correspondientes al promedio,
 máximo o mínimo. TODOS los resultados deben ser ENTEROS, NO en punto flotante.*/
void feature5(FILE *fout, int *parr, int length, char *op)
{
        int suma = 0;
        int contador=0;

    //condicional para promedio.
      if(strcmp(op,"avg")==0)
        {
        for(contador = 0;contador < length -1;contador++)
        {
            suma = suma + parr[contador];
            //printf("%d\n",suma); Observamos comportamiento de suma para verificar operacion.
        }
        fprintf(fout,"%d\n",(suma/(length-1)));        
    }

    //Condicional para calcular el minimo
    else if(strcmp(op,"min")==0)
        { 
        int minimo = 1000;
        for(contador=0; contador< length - 1;contador++){
            if(parr[contador] < minimo)
            {
                minimo = parr[contador];
                //printf("%d\n",minimo); Observamos comportamiento minimo
            }
        }
        fprintf(fout,"%d\n",minimo);        
    }

    //Condicional para el maximo
    else if(strcmp(op,"max")==0)
        {
        int maximo = -1000;
        for(contador=0; contador< length - 1;contador++){
            if(parr[contador] > maximo){
                maximo = parr[contador];
            }
        }
        fprintf(fout,"%d\n",maximo);        
    }
    //Else para sacarnos mensaje de error de operacion.
    else{
        fprintf(fout,"Porfavor digite una operacion valida.");
    }
    free(parr);//Liberamos memoria
    free(op);//Liberamos memoria

}

//lee la quinta línea del archivo de entrada y con esta información debes configurar 
//los valores de la siguiente estructura de datos cuya dirección se pasará a la
//función.
//Empezamos reservando con calloc el tamano que necesitamos
//Tener en cuenta el 10 de base de convercion.
void feature6(FILE *fin, struct Obj_t *pobj)
{
        char* bufer = (char *)calloc(tamano_maximo,sizeof(char));
        char* nombre = (char *)calloc(tamano_maximo,sizeof(char));
        pobj->nombre = (char *)calloc(tamano_maximo,sizeof(char));
        char* bash;
        
        fgets(bufer,tamano_maximo,fin);
        nombre = strtok(bufer,",");
        int cedula = strtol(strtok(NULL,","),&bash,10); 
        strcpy(pobj -> nombre,nombre);
        pobj->cedula = cedula;

       // printf("%s\n",nombre); // Se revisa que el nombre este saliendo correctamente.
      //  printf("%d\n",cedula); // Se mira que si este sacando el numero porque no tenemos FOUT
        free(bufer); //Liberar bufer
}

//recibe la dirección en memoria de la estructura anterior 
//y la guarda en la quinta línea del archivo de salida primero la cédula, seguido por una coma y finalizando con el nombre.
void feature7(FILE *fout, struct Obj_t *pobj)
{

    fprintf(fout,"%d,%s\n",pobj->cedula,pobj->nombre);
    free(pobj->nombre);
}

//lee la sexta línea del archivo de entrada que contiene un número entero positivo que especifica 
//la cantidad de cursos que un estudiante cursó en un semestre. Luego solicita al usuario ingresar el nombre del curso, los créditos y la nota así:
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length)
{
    char* bufer = (char *)calloc(tamano_maximo,sizeof(char));
    char *bash;
    char *bash2;
    int N=0;
    fgets(bufer,tamano_maximo,fin);
    N = strtol(bufer,&bash,10);
    struct _courseInfo_t *parr = (struct _courseInfo_t *)calloc(N,sizeof(struct _courseInfo_t));
    printf("Ingrese:\n Curso,Creditos,Nota (Recuerde separar por comas)\n");
    for(short i=0; i<N; i++)
    {
        int j=0;
        printf("Curso: %d: ",i+1);
        fgets(bufer,tamano_maximo,stdin);
        bash = strtok(bufer,",");
        while(bash!=NULL){
            if(j==0){
                strcpy(parr[i].name,bash);
            }else if(j==1){
                parr[i].credits = strtol(bash,&bash2,10);
            }
            else if(j==2){
                parr[i].grade= strtof(bash,&bash2);
            }
            j++;
            bash = strtok(NULL,",");
        }
    }
    *pobj = parr;
    *length = N;
    free(bufer);//liberamos el bufer
    fclose(fin);// cerramos el archivo de entrada porque ya solo nos queda escribir en el featuree 9
}

//finalmente, calcula el promedio ponderado del semestre. Pregunta al usuario si desea almacenar 
//la información la información en el archivo de salida así:
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length)
{
    char* bufer = (char*)calloc(10,sizeof(char));
    float calificacion = 0, creditos = 0;
    float promedio = 0.0f;

    for(short i=0;i<length;i++)
    {
        calificacion = calificacion + pobj[i].grade*pobj[i].credits;
        creditos = creditos + pobj[i].credits;        
    }
    promedio = calificacion/creditos;
    printf("Quiere guardar? (si) o (no \n");
    fgets(bufer,10,stdin);
    char *tk = strtok(bufer,"\n");
    if(strcmp(tk,"si")==0 || strcmp(tk,"SI")==0) // condicional de guardar
    {
        for(short i=0;i<length;i++){
            fprintf(fout,"%s,%d,%f\n",pobj[i].name,pobj[i].credits,pobj[i].grade);            
        }
        fprintf(fout,"el promedio es : %f",promedio);        
    }
    else{
        fprintf(fout,"el promedio es: %f",promedio);
    }
    free(bufer);//liberamos bufer
    free(pobj);//liberamos pobj
    fclose(fout);// cerramos el archivo de salida
}