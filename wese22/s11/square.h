struct square
{ // Public Attribute
    int pub1;
    int pub2;

    // private Attribute
    int *priv1;
    int *priv2;
    // int ___priv1;
    // int ___priv2;
    // int priv[2];
};
void square_open(struct square **me);
void square_close(struct square **me);
// void priv_set(struct square *me, int a, int b);
//  int pub_get(struct square *me);
