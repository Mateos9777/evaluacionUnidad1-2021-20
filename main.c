
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){

    FILE *inFile = fopen("./fin","r");
    FILE *inFileOut = fopen("./fout","a+");
    if(inFile == NULL){
        perror("Open File fin Fails :");
        return(EXIT_FAILURE);
    }
    if(inFileOut == NULL){
        perror("Open File fout fails: ");
        return(EXIT_FAILURE);
    }
    int *parr=NULL;
    int length =0;
    char *op=NULL;

    struct Obj_t pobj_t;

    
    for(int i=0;i<8;i++){
        if(i ==1 ) feature1(inFile,inFileOut);
        if(i ==2 ) feature2(inFile,inFileOut);
        if(i ==3 ) feature3(inFile,inFileOut); 
        if(i ==4 ) feature4(inFile, &parr, &length, &op); 
        if(i ==6 ) feature6(inFile, &pobj_t);
        if(i ==7 ) feature7(inFileOut, &pobj_t);
    }
    fclose(inFile);
    fclose(inFileOut);
}