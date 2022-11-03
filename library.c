#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strArch {
    file_t data;
    char* nombre;
    int i;
    struct strArch * anterior;
    struct strArch * siguiente;
};

struct strHistorico {
    file_t historico;
    Archivo primero;
    Archivo ultimo;
    Archivo reciente;
    unsigned int cantidad;
};

Historico nuevo_historico() {
    Historico h = malloc(sizeof(struct strHistorico));
    h->primero = NULL;
    h->ultimo = NULL;
    h->reciente = NULL;
    h->cantidad = 0;
    return h;
}

void abrir_archivo(Archivo a, Historico h) {
    a->data = fopen(a->nombre, "r");
    if (a->data == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }
    char c;
    while ((c = fgetc(a->data)) != EOF) {
        printf("%c", c);
    }
    fclose(a->data);
    if (h->cantidad == 0 && a != h->reciente) {
        h->primero = a;
        h->ultimo = a;
        h->reciente = a;
        h->cantidad++;
        a->anterior = NULL;
        a->siguiente = NULL;
        a->i = 0;
    } else if (h->cantidad > 0 && a != h->reciente) {
        h->ultimo->siguiente = a;
        a->anterior = h->ultimo;
        h->ultimo = a;
        h->reciente = a;
        h->cantidad++;
        a->i = h->cantidad - 1;
    }
}

void mostrar_reciente(Historico h) {
    if (h->reciente == NULL) {
        printf("No hay archivos abiertos");
        return;
    }
    printf("Archivo: %s\n", h->reciente->nombre);
    abrir_archivo(h->reciente, NULL);
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
    return h->cantidad;
}
