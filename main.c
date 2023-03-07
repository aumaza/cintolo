#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "spcopr.h"
#include "lib_system.h"

int main(){
    
    system("clear");
    // SE VALIDA QUE EL ARRAYLIST NO SEA NULL
    ArrayList* lista = al_newArrayList();
    validNULL(lista);

    int option;

    do{
        system("clear");
        printf("\n=====================================");
        printf("\n--------------- M E N U -------------");
        printf("\n=====================================");
        printf("\n1. Cargar y Parsear Archivo");
        printf("\n2. Ver Información del Archivo");
        printf("\n3. Ver Contenido del Archivo");
        printf("\n4. Cambiar Codificación del Archivo");
        printf("\n5. Guardar Cambios");
        printf("\n=====================================");
        printf("\n0. Salir");
        option = optionValid();

        switch(option){

            case 1: parserTableSpcopr("SPCOPR",lista); break;

            case 2: infoSpcopr("SPCOPR"); break;

            case 3: listSpcopr(lista); break;
        }

    }while(option != 0);

    
    return 0;
}
