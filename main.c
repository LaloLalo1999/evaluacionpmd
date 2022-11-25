// #include "library.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(List historico);

void abrir_archivo(char *);

int main() {
//     setbuf(stdin, NULL);
//     setbuf(stdout, NULL);
    char nombre_archivo[20];
    printf("Bienvenido al programa de archivos de texto\n");
    List historico = listCreate(sizeof(char[20]));
    int opcion;
    int indicerec = 0;
    do {
        opcion = menu(historico);
        switch (opcion) {
            case 1:// Abrir archivo
                printf("Nombre del archivo: ");
                scanf("%s", nombre_archivo);
                getchar();
                if(listSearch(historico, nombre_archivo) == -1){
                    listAdd(historico, nombre_archivo);
                }
                // listAdd(historico, nombre_archivo);
                abrir_archivo(nombre_archivo);
                indicerec = listSearch(historico, nombre_archivo);
                break;
            case 2:// Salir
                printf("Gracias por utilizar el programa");
                break;
            case 3:// Mostrar reciente
                abrir_archivo(listGet(historico, indicerec));
                break;
            case 4:// Mostrar anterior
                indicerec--;
                if(indicerec < 0){
                    indicerec = 0;
                    printf("No hay mas archivos anteriores\n");
                }
                abrir_archivo(listGet(historico, indicerec));
                break;
            case 5:// Mostrar siguiente
                indicerec++;
                if(indicerec > listSize(historico) - 1){
                    indicerec = listSize(historico) - 1;
                    printf("No hay mas archivos siguientes\n");
                }
                abrir_archivo(listGet(historico, indicerec));
                break;
            case 6: // Mostrar primero
                indicerec = 0;
                abrir_archivo(listGet(historico, indicerec));
                break;
            case 7:// Mostrar ultimo
                indicerec = listSize(historico) - 1;
                abrir_archivo(listGet(historico, indicerec));
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    } while (opcion != 2);
    return 0;
}

int menu(List historico) {
    int opcion;
    unsigned int cant_archivos = listSize(historico);
    printf("\nElige una opcion: \n");
    printf("[1] Abrir archivo\n");
    printf("[2] Salir\n");
    if (cant_archivos > 0) {
        printf("[3] Mostrar reciente\n");
        printf("[4] Mostrar anterior\n");
        printf("[5] Mostrar siguiente\n");
    }
    if (cant_archivos >= 3){
        printf("[6] Mostrar primero");
        printf("[7] Mostrar ultimo");}
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    getchar();
    return opcion;
}

void abrir_archivo(char nombre_archivo[20]) {
    FILE *archivo;
    archivo = fopen(nombre_archivo, "r");
    char letra;
    if (archivo == NULL) {
        printf("Archivo creado\n");
        printf("Ingrese el texto: ");
        char texto[100];
        // getchar();
        fgets(texto, sizeof(texto), stdin);
        // fclose(archivo);
        archivo = fopen(nombre_archivo, "w");
        unsigned int contador = 0;
        // char *p = &texto[0];
        while (contador <= strlen(texto)) {
            letra = texto[contador];
            fputc(letra, archivo);
            // p++;
            contador++;
        }
    } else {
        printf("Archivo abierto\n");
        while(1){
            letra=fgetc(archivo);
            if (feof(archivo)) break;
            printf("%c",letra);
        }
    }
    fclose(archivo);
}