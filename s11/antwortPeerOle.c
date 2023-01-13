/*** square.h***************************************/

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

/*** square.c***************************************/

#include "square.h"

#include "stdlib.h"

// Private Attribute

struct square_priv
{

    struct square square_pub;

    int priv1;

    int priv2;
};

int square_open(struct square **me)
{

    *me = malloc(sizeof(struct square_priv));

    if (me == NULL)
        return 1;

    (*me)->pub1 = 1;

    (*me)->pub2 = 2;

    priv_set(*me, 2, 3);

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

/*** example.c*************************************/

#include "square.h"

#include "stdio.h"

int main(void)
{

    struct square *obj1;

    square_open(&obj1);

    printf("%d\n", pub_get(obj1));

    priv_set(obj1, 5, 6);

    square_close(&obj1);

    return 0;
}
