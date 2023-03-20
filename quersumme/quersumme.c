
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("Hello World\n");
    if (argc <= 1)
    {
        printf("Bitte übergeben sie mit dem Aufruf"
               "des Programms ein Argument\n");
        return 1;
    }
    int quersumme = 0;
    char *str = argv[1];
    // convertinginput string to integer
    int inputNum = atoi(str);

    printf("1. Para='%s'\n", str);
    printf("1. Zeichen='%c'\n", str[0]);

    // Ihr Code
    while (inputNum > 0)
    {
        quersumme = quersumme + (inputNum % 10);
        inputNum = inputNum / 10;
    }

    printf("Quersumme=%d\n", quersumme);
    return 0;
}