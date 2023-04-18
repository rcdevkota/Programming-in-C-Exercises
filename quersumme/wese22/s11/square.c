#include "square.h"
#include <stdlib.h>

void square_open(struct square **me)
{
    *me = malloc(sizeof(struct square));
    (*me)->pub1 = 0;
    (*me)->pub2 = 1;
    priv_set(*me, 2, 3);
}
void square_close(struct square **me)
{
    free(*me);
}

void priv_set(struct square *me, int a, int b)
{
    *(me->priv1) = a;
    *(me->priv2) = b;
}
int pub_get(struct square *me)
{
    return me->pub1 + me->pub2;
}