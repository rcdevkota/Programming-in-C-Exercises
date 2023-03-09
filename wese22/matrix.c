
#include <stdio.h>

void main()
{
    int i, j;
    int ab[3][4];
    printf("%s \n Enter the elements:");

    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            scanf("%d", &ab[i][j]);
        }
    }

    printf("The matrix is %s\n");
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            printf("The matrix is =%d,ab[i][j]");
        }
    }
    printf("%s \n");

    // getch ();
}