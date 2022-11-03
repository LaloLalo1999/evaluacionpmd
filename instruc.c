#include <stdio.h>
#include <stdlib.h>

// En esta actividad, su objetivo es crear un programa que permita al usuario consultar el contenido de archivos de texto y navegar entre el histórico de archivos que ha consultado (reciente, anterior, siguiente).
// Para implementar la navegación entre archivos del histórico deberá hacer uso de los contenedores que hemos abordado hasta este momento en el curso de programación con memoria dinámica.


int main() {
    // Antes de poder leer o escribir texto en un archivo, es necesario abrir el archivo o crearlo.
    // Para esto, en C podemos utilizar la función fopen()
    // FILE* pf;
    // Donde pf es el apuntador de tipo FILE, “nombre del archivo” es el nombre del archivo que
    // queremos abrir o crear. Este nombre debe ir encerrado entre comillas. También podemos
    // especificar la ruta donde se encuentra o utilizar una cadena de caracteres que contenga el
    // nombre del archivo
    // pf=fopen("datos.txt","r");
    // El segundo argumento de la función fopen() es el modo de apertura del archivo. Este
    // argumento puede ser:
    // r: Abre un archivo de texto para lectura. Si el archivo no existe, el programa termina con un error.
    // w: Abre un archivo de texto para escritura. Si el archivo no existe, lo crea. Si el archivo existe, lo sobreescribe.
    // a: Abre un archivo de texto para escritura. Si el archivo no existe, lo crea. Si el archivo existe, agrega el nuevo contenido al final del archivo.
    // r+: Abre un archivo de texto para lectura y escritura. Si el archivo no existe, el programa termina con un error.
    // w+: Abre un archivo de texto para lectura y escritura. Si el archivo no existe, lo crea. Si el archivo existe, lo sobreescribe.
    // a+: Abre un archivo de texto para lectura y escritura. Si el archivo no existe, lo crea. Si el archivo existe, agrega el nuevo contenido al final del archivo.
    
    // La función fopen() devuelve un apuntador de tipo FILE. Este apuntador se utiliza para
    // referenciar al archivo que se está utilizando. Si el archivo no se pudo abrir, fopen()
    // devuelve NULL.
    // if (pf==NULL) {
    //     printf("Error al abrir el archivo");
    //     return 0;
    // }
    // Una vez que hemos acabado de trabajar con el archivo, debemos cerrarlo. Para esto, en C
    // podemos utilizar la función fclose()
    // Esta función cierra el archivo que se le pasa como argumento. Si el archivo se cerró con éxito,
    // fclose() devuelve 0.
    //     fclose(pf);

    // Para escribir caracteres en un archivo, en C podemos utilizar la función fputc()
    // Esta función escribe un carácter en el archivo que se le pasa como primer argumento.
    // El segundo argumento es el carácter que se quiere escribir.
    // su sintaxis es:
    // fputc(caracter, archivo);

    // Veamos un ejemplo en el que abrimos un archivo de texto para escritura y escribimos
    // una letra en él:
    // FILE* pf;
    // char letra = 'a';
    // pf = fopen("datos.txt", "w");
    // if (pf == NULL) {
    //     printf("Error al abrir el archivo");
    //     return 0;
    // }
    // else {
    //     fputc(letra, pf);
    //     fclose(pf);
    // }
    // return 0;

    // Para leer un carácter de un archivo, deberemos guardarlo en una variable.
    // En C podemos utilizar la función fgetc()
    // Ejemplo:
    // FILE* pf;
    // char letra;
    // pf = fopen("datos.txt", "r");
    // if (pf == NULL) {
    //     printf("Error al abrir el archivo");
    //     return 0;
    // }
    // else {
    //     letra = fgetc(pf);
    //     printf("%c", letra);
    //     fclose(pf);
    // }
    // return 0;

    // Si queremos leer todos los caracteres que se encuentran almacenados en un archivo de
    // texto, es necesario poder identificar cuando finaliza el archivo. Para esto, podemos utilizar
    // la función feof(). Su sintaxis es:
    // feof(apuntador_archivo);
    // Esta función devuelve un valor distinto de cero si se ha llegado al final del archivo.
    // Ejemplo:
    // FILE* pf;
    // char letra;
    // pf = fopen("datos.txt", "r");
    // if (pf == NULL) {
    //     printf("Error al abrir el archivo");
    //     return 0;
    // }
    // else {
    //     while (!feof(pf)) {
    //         letra = fgetc(pf);
    //         printf("%c", letra);
    //     }
    //     fclose(pf);
    // }
    // return 0;

    // Si no queremos leer y escribir a nivel carácter en los archivos, podemos utilizar las funciones fputs()
    // y fgets() que permiten escribir y leer cadenas de texto. Veamos un ejemplo del uso de la función
    // fgets() para leer el contenido de un archivo de texto.
    // setbuf(stdin, NULL);
    // setbuf(stdout, NULL);
    // FILE* pf;
    // char buffer[300];
    // pf = fopen("datos.txt", "r");
    // if (pf == NULL) {
    //     printf("Error al abrir el archivo");
    //     return 0;
    // }
    // else {
    //     while (!feof(pf)) {
    //         if (fgets(buffer, 296, pf) != NULL) {
    //             printf("%s", buffer);
    //         }
    //     }
    //     fclose(pf);
    // }
    // return 0;
}