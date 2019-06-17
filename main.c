#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
int obtenerPosicionIncialPalabraLarga(char []);
void obtenerPalabraLarga(char [] , char [] , int);
void invertirPalabraLarga(char[]);
void cadenaModificada(char[] , char[] , int);

int main()
{
 FILE *archivoOrigen;
 FILE *archivoDestino;
 int positionInicial = 0;
 char  cadena[81] = "";
 char palabraLarga[15] ;
 char *nombreOrigen = "ficheroOrigen.txt";
 char *nombreDestino = "ficheroDestino.txt";


  if((archivoOrigen = fopen(nombreOrigen , "r")) == NULL)
  {
     printf("\n\n file  %s could not  be opened" , nombreOrigen);
  }

  if((archivoDestino = fopen(nombreDestino , "w")) == NULL)
  {
    printf("\n\n file  %s could not  be opened" , nombreDestino);
  }

   else
   {
       while(fgets(cadena , 81 , archivoOrigen))
       {
         positionInicial = obtenerPosicionIncialPalabraLarga(cadena);
         obtenerPalabraLarga(cadena , palabraLarga , positionInicial);
         invertirPalabraLarga(palabraLarga);
         cadenaModificada(cadena , palabraLarga , positionInicial);

         fputs(cadena , archivoDestino);
       }

   }

    fclose(archivoOrigen);
    fclose(archivoDestino);

    printf("\nFinish\n");
    getch();


    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int obtenerPosicionIncialPalabraLarga(char cadena[])
{
    int unsigned i=0;
    int control = 0;
    int palabra = 0;
    int contador = 0;
    int palabraLarga = 0;
    int palabraLargaAct = 0;
    int positionInicial = 0;

    while(cadena[i])
    {
        while(cadena[i] == ' ')// Omite espacios en blanco.
        {
            i++;
        }

        if(cadena[i]) // Si aún queda por recorrer,
          {
             while(cadena[i] != ' ' && cadena[i])
             {
                 contador++;
                 i++;
             }

             if(control == 0)
             {
                 palabraLarga = contador;
                 positionInicial = i-(contador);
                 contador = 0;
                 control++;
             }
             else
             {
                 palabraLargaAct = contador;
                 if(palabraLarga < palabraLargaAct)
                 {
                     palabraLarga = palabraLargaAct;
                     positionInicial = i - (contador);
                 }
                 contador = 0;
             }
           }
    }

    return positionInicial;
}
//////////////////////////////////////////////////////////////////////////////////////////
void obtenerPalabraLarga(char cadena[] , char palabraLarga[] , int positionInicial)
{
      int i = positionInicial;
      int j = 0;

      int largo = strlen(cadena);
      while(cadena[i] != 32 && cadena[i] != '\n')
      {
        palabraLarga[j]= cadena [i];
        i++;
        j++;
      }
      palabraLarga[j] = '\0';
}
////////////////////////////////////////////////////////////////////////////////////////////
void  invertirPalabraLarga(char palabraLarga[])
{
      strrev(palabraLarga);
}
/////////////////////////////////////////////////////////////////////////////////////////
void cadenaModificada(char cadena[] , char palabraLarga[] , int positionInicial)
{
     int i =positionInicial;
     int j = 0;
     //int largo = strlen(cadena);

        while(cadena[i] !=32 && cadena[i]!= '\n')
      {
        cadena[i]= palabraLarga[j];
        i++;
        j++;
      }
}
