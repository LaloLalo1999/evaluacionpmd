#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Requisitos funcionales:
    // Recordemos que nuestro objetivo es crear un programa que permita al usuario consultar el
    // contenido de archivos de texto y navegar entre el histórico de archivos que ha consultado.

// Para el diseño de la solución y su posterior implementación, consideremos los siguientes escenarios.    
    // a) Escenario 1 (inicio del programa): No existen archivos en el histórico
    // [1] Abrir archivo
    // [2] Salir
    // Seleccione una opción: 1
    // Ingrese el nombre del archivo: hola.txt
    //   Este es el archivo hola.txt
    //   Ya se acabó el archivo hola.txt
    //
    // b) Escenario 2: Existe un elemento en el histórico
    // [1] Abrir archivo
    // [2] Salir
    // [3] Mostrar reciente     Reciente es hola.txt
    // [4] Mostrar anterior     No hay anterior
    // [5] Mostrar siguiente    No hay siguiente
    // Seleccione una opción: 1
    //   Ingrese el nombre del archivo: adios.txt
    //   Este es el archivo adios.txt
    //   Ya se acabó el archivo adios.txt
    //
    // c) Escenario 3: Existen dos elementos en el histórico
    // [1] Abrir archivo
    // [2] Salir
    // [3] Mostrar reciente     Reciente es adios.txt
    // [4] Mostrar anterior     Anterior es hola.txt
    // [5] Mostrar siguiente    No hay siguiente
    // Seleccione una opción: 3
    //   Archivo adios.txt
    //   Este es el archivo adios.txt
    //   Ya se acabó el archivo adios.txt
    //
    // d) Escenario 4: Existen tres o más elementos en el histórico
    // [1] Abrir archivo
    // [2] Salir
    // [3] Mostrar reciente         Reciente es hola.txt
    // [4] Mostrar anterior         No hay anterior
    // [5] Mostrar siguiente        Siguiente es adios.txt
    // Seleccione una opción: 1     Estabamos en hola y abrimos nuevo, se perdió adios
    //   Ingrese el nombre del archivo:  nuevo.txt
    //   Este es el archivo nuevo.txt
    //   Ya se acabó el archivo nuevo.txt
    //
    // [1] Abrir archivo
    // [2] Salir
    // [3] Mostrar reciente         Reciente es nuevo.txt
    // [4] Mostrar anterior         Anterior es hola.txt
    // [5] Mostrar siguiente        No hay siguiente
    // Seleccione una opción: 1     El archivo abierto es igual a Anterior
    //   Ingrese el nombre del archivo:  hola.txt
    //   Este es el archivo nuevo.txt
    //   Ya se acabó el archivo nuevo.txt

int main() {
    file pf;
    char buffer[300];
    int opcion;
    char nombre_archivo[20] = "historico.txt";
    Historico historico;
    historico = crear_historico(nombre_archivo);
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                abrir_archivo(historico);
                break;
            case 2:
                printf("Gracias por utilizar el programa");
                break;
            default:
                printf("Opción inválida");
                break;
        }
    } while (opcion != 2);
}

int menu(Historico historico) {
    int opcion;
    printf("[1] Abrir archivo");
    printf("[2] Salir");
    if (historico->cantidad > 0) {
        printf("[3] Mostrar reciente");
        printf("[4] Mostrar anterior");
        printf("[5] Mostrar siguiente");
    }