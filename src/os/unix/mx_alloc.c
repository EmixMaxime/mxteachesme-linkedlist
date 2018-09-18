#include <stdlib.h>
#include "mx_alloc.h"

void * mx_malloc(size_t size)
{
    void *p;

    p = malloc(size);

    if (p == NULL) {
		exit(EXIT_FAILURE);
    }

    return p;
}
