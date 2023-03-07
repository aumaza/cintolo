#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int optionValid(){

   int ok;
   int ch;
   int opc;

    do
    {
      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);

   return opc;
}


int validNULL(void* string){

    if(string == NULL){
        return 1;
    }else{
        printf("SUCCESS!!\n");
        return 0;
    }
}
