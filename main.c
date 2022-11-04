#include "library.h"
#include <stdio.h>
#include <stdlib.h>

int menu(Historico);

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char nombre_archivo[50];
    printf("Bienvenido al programa de archivos de texto\n");
    Historico historico = nuevo_historico();
    int opcion;
    do {
        opcion = menu(historico);
        switch (opcion) {
            case 1:
                printf("Nombre del archivo: ");
                scanf("%s", nombre_archivo);
                getchar();
                Archivo a1 = nuevo_archivo(nombre_archivo);
                agregar_archivo(historico, a1);
                abrir_archivo(a1);
                break;
            case 2:
                printf("Gracias por utilizar el programa");
                break;
            case 3:
                mostrar_reciente(historico);
                break;
            case 4:
                mostrar_anterior(historico);
                break;
            case 5:
                mostrar_siguiente(historico);
                break;
            case 6:
                mostrar_primero(historico);
                break;
            case 7:
                mostrar_ultimo(historico);
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    } while (opcion != 2);
    return 0;
}

int menu(Historico historico) {
    int opcion;
    int cant_archivos = cantidad_archivos(historico);
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