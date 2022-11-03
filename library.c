#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strArch {
    FILE* pf;
    int posicion;
    struct strArch * prev;
    struct strArch * next;
};
typedef struct strArch * Arch;

struct strHistorico {
    Arch first;
    Arch last;
    Arch current;
    unsigned int cantidad;
};

