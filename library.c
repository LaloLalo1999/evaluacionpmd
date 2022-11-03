#include "library.h"
#include <stdio.h>
#include <stdlib.h>

struct strArch {
    file_t data;
    char* nombre;
    struct strArch * anterior;
    struct strArch * siguiente;
};

struct strHistorico {
    Archivo primero;
    Archivo ultimo;
    Archivo reciente;
    unsigned int cantidad;
};

Archivo nuevo_archivo(char* nombre) {
    Archivo arch = malloc(sizeof(struct strArch));
    arch->nombre = nombre;
    arch->data = fopen(nombre, "w");
    printf("Archivo %s creado\n", nombre);
    printf("Archivo %s abierto\n", nombre);
    scanf("Escribe ");
    arch->anterior = NULL;
    arch->siguiente = NULL;
    return arch;
}

Historico nuevo_historico() {
    Historico h = malloc(sizeof(struct strHistorico));
    h->primero = NULL;
    h->ultimo = NULL;
    h->reciente = NULL;
    h->cantidad = 0;
    return h;
}


void agregar_archivo(Historico h, Archivo arch) {
    if (h->primero == NULL) {
        h->primero = arch;
        h->ultimo = arch;
        h->reciente = arch;
    }
    else {
        h->ultimo->siguiente = arch;
        arch->anterior = h->ultimo;
        h->ultimo = arch;
        h->reciente = arch;
    }
    h->cantidad++;
}

void abrir_archivo(Archivo a) {
    a->data = fopen(a->nombre, "r");
    if (a->data == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }
    char c;
    while ((c = (char)fgetc(a->data)) != EOF) {
        printf("%c", c);
    }
    fclose(a->data);
}

void mostrar_reciente(Historico h) {
    if (h->reciente == NULL) {
        printf("No hay archivos abiertos");
        return;
    }
    printf("Archivo: %s\n", h->reciente->nombre);
    abrir_archivo(h->reciente);
}

void mostrar_anterior(Historico h) {
    if (h->reciente == NULL) {
        printf("No hay archivos abiertos");
        return;
    }
    if (h->reciente->anterior == NULL) {
        printf("No hay archivos anteriores");
        return;
    }
    h->reciente = h->reciente->anterior;
    mostrar_reciente(h);
}

void mostrar_siguiente(Historico h) {
    if (h->reciente == NULL) {
        printf("No hay archivos abiertos");
        return;
    }
    if (h->reciente->siguiente == NULL) {
        printf("No hay archivos siguientes");
        return;
    }
    h->reciente = h->reciente->siguiente;
    mostrar_reciente(h);
}

void mostrar_primero(Historico h) {
    if (h->primero == NULL) {
        printf("No hay archivos abiertos");
        return;
    }
    h->reciente = h->primero;
    mostrar_reciente(h);
}

void mostrar_ultimo(Historico h) {
    if (h->ultimo == NULL) {
        printf("No hay archivos abiertos");
        return;
    }
    h->reciente = h->ultimo;
    mostrar_reciente(h);
}

int cantidad_archivos(Historico h) {
    int signedInt = (int)h->cantidad;
    return signedInt;
}
