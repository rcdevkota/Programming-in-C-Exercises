#include "square.h"
#include <stdio.h>

int main(void)
{
    struct square *obj1;
    square_open(&obj1);
    printf("%d\n", pub_get(obj1));
    priv_set(obj1, 5, 6);
    square_close(&obj1);
    return 0;

    int p = 0;   // 0xp = 0
    int *a = &p; // 0xa = 0xp => 0
}