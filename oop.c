/*** square.h ***************************************/
-- > Inhalt der square.h Datei

     struct square
{

    // Public Attribute

    int pub1;

    int pub2;
};

int square_open(struct square **me);

void square_close(struct square **me);

int pub_get(struct square *me);

void priv_set(struct square *me, int a, int b);

int static_public(int val);

/*** square.c ***************************************/
-- > Inhalt der square.c Datei

#include "square.h"

#include "stdlib.h"

     // Private Attribute

     struct square_priv
{

    struct square square_pub;

    int priv1;

    int priv2;
};
int static_public(int val)
{
    return 2 * val;
}
static int static_private(int val)
{
    return val / 2;
}
int square_open(struct square **me)
{

    *me = malloc(sizeof(struct square_priv));

    if (me == NULL)
        return 1;

    (*me)->pub1 = 0;

    (*me)->pub2 = 1;

    priv_set(*me, static_public(6), static_private(5));

    return 0;
}

void square_close(struct square **me)
{

    free(*me);
}

int pub_get(struct square *me)
{

    return me->pub1 + me->pub2;
}

void priv_set(struct square *me, int a, int b)
{

    struct square_priv *temp;

    temp = (struct square_priv *)me;

    temp->priv1 = a;

    temp->priv2 = b;
}

/*** example.c *************************************/
-- > Inhalt der example.c Datei
#include "square.h"

#include "stdio.h"
     int
     main(void)
{

    struct square *obj1;
    square_open(&obj1);

    struct square *obj2;
    square_open(&obj2);

    printf("%d\n", pub_get(obj1));
    priv_set(obj1, 5, 6);
    static_public(4711);

    square_close(&obj1);
    square_close(&obj2);

    return 0;
}