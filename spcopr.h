#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayList.h"

#ifndef SPCOPR_H_INCLUDED
#define SPCOPR_H_INCLUDED

#define MASCARA_ARCHIVO "%[^\n]\n"
#define BUFFER buffer[0]
#define HEADER "line\n"
#define MASC "%s\n"

typedef struct{
    char line[200] ;    
}Spcopr;

#endif // SPCOPR_H_INCLUDED

// CONSTRUCTOR
Spcopr* newSpcopr();

// FUNCIONES
void parserTableSpcopr(char* path, ArrayList* Lista);
void infoSpcopr(char* path);
void listOneSpcopr(Spcopr* spcopr);
void listSpcopr(ArrayList* Lista);
