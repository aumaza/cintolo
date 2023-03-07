#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayList.h"
#include "spcopr.h"

Spcopr * newSpcopr(){
    
    Spcopr* newSpcopr = (Spcopr*)malloc(sizeof(Spcopr));
    
    if(newSpcopr != NULL){
        strcpy(newSpcopr->line, "");
    }
    
    return newSpcopr;
}



void infoSpcopr(char* path){
    
    FILE* fp = fopen(path, "r");
    int noOfChar = 0, noOfSpace = 0, noOfTab = 0, noOfNewline = 0, cantAmp = 0, cantMinor = 0, cantSquare = 0, cantSInverted = 0, cantEgg = 0;
    char ch;
    
    if(fp == NULL){
        printf("===============================================================\n");
        printf("\nError Open File");
        printf("===============================================================\n");
    }else{
        printf("===============================================================\n");
        printf("Carga de Archivo OK!\n");
        printf("===============================================================\n");
        
        while(fp){
            ch = fgetc(fp);
            if(ch == EOF){
                break;
            }else{
                noOfChar++;
            }
            if(ch == ' '){
                noOfSpace++;
            }
            if(ch == '\t'){
                noOfTab++;
            }
            if(ch == '\n'){
                noOfNewline++;
            }
            if(ch == '&'){
                cantAmp++;
            }
            if(ch == ''){
                cantMinor++;
            }
            if(ch == ''){
                cantSquare++;
            }
            if(ch == ''){
                cantSInverted++;
            }
            if(ch == ''){
                cantEgg++;
            }
            
        }
        
       
    }
        fclose(fp);
        printf("===============================================================\n");
        printf("Cantidad Total de Caracteres: %d\n", noOfChar);
        printf("===============================================================\n");
        printf("Cantidad Total de Espacios: %d\n", noOfSpace);
        printf("===============================================================\n");
        printf("Cantidad Total de tabs: %d\n", noOfTab);
        printf("===============================================================\n");
        printf("Cantidad Total de lineas: %d\n", noOfNewline);
        printf("===============================================================\n");
        printf("Cantidad Total del caracter (&): %d\n", cantAmp);
        printf("===============================================================\n");
        printf("Cantidad Total del caracter (<): %d\n", cantMinor);
        printf("===============================================================\n");
        printf("Cantidad Total del caracter (): %d\n", cantSquare);
        printf("===============================================================\n");
        printf("Cantidad Total del caracter (): %d\n", cantSInverted);
        printf("===============================================================\n");
        printf("Cantidad Total del caracter (): %d\n", cantEgg);
        printf("===============================================================\n");
                
        printf("Presione una tecla para continuar...");
        getchar();
}


void parserTableSpcopr(char* path, ArrayList* Lista){
    
    FILE* fp;
    Spcopr* nSpcopr;

    int cant;
    char buffer[1][1024];
    fp = fopen(path, "r");

    if(fp != NULL && Lista != NULL){
        
        fscanf(fp,MASCARA_ARCHIVO,BUFFER);

        while(!feof(fp)){
            
            cant = fscanf(fp,MASCARA_ARCHIVO,BUFFER);

            if( cant == 1){
                
                nSpcopr = newSpcopr();

                if(nSpcopr != NULL){
                    
                    strcpy(nSpcopr->line,buffer[0]);
                    
                    Lista->add(Lista,nSpcopr);
                }
            }
            else{
                break;
            }
        }
        fclose(fp);
        system("clear");
        printf("========================================================================================================\n");
        printf("El archivo ha sido cargado y parseado Exitosamente. Presione una tecla para continuar...\n");
        printf("========================================================================================================\n");
        getchar();
    }

}


void listOneSpcopr(Spcopr* spcopr){
    printf("%s\n", spcopr->line);
}


void listSpcopr(ArrayList* Lista){
    system("clear");
    Spcopr* oneSpcopr;
    int count = 0;
    int page = 0;
    int length = Lista->len(Lista);
    char answer = 'S';
    
    if(length > 100 ){

        printf("El archivo contiene más de 100 Líneas. Desea continuar con la visualización? S/N: ");
        scanf("%c", &answer);
        getchar();
    }

    if(length == 0){
        printf("=============================================================================================\n");
        printf("Aún no Cargado cargado el contenido del Archvio. Por favor seleccione la Opcion 1.\n");
        printf("=============================================================================================\n");
        getchar();
    }

    if(answer == 'S'){

        for(int i = 0; i < length; i++){
            oneSpcopr = (Spcopr*)Lista->get(Lista,i);

            if(oneSpcopr != NULL){
                listOneSpcopr(oneSpcopr);

                while(count == 25){

                    page++;
                    printf("===============================================================\n");
                    printf("Paginación Nro %d\n", page);
                    printf("===============================================================\n");
                    printf("Presione una tecla para continuar...\n");
                    printf("===============================================================\n");
                    getchar();
                    system("clear");
                    count = 0;



                }
                count++;
            }
        }

    printf("===============================================================\n");
    printf("Cantidad de Registros: %d\n", length);
    printf("===============================================================\n");

    }

    if(answer == 'N'){
        printf("===============================================================\n");
        printf("Para retornar al Menú presione cualquier tecla\n");
        printf("===============================================================\n");
        getchar();
    }
    
}

