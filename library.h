
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LIBRARY_H
#define LIBRARY_H

typedef FILE* file_t;

typedef struct strArch * Archivo;

typedef struct strHistorico * Historico;

Historico nuevo_historico();

void abrir_archivo(Archivo, Historico);

void mostrar_reciente(Historico);

void mostrar_anterior(Historico);

void mostrar_siguiente(Historico);

void mostrar_primero(Historico);

void mostrar_ultimo(Historico);

int cantidad_archivos(Historico);

#endif // LIBRARY_H