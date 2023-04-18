#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Bitte Uebergeben sie mit dem Aufruf des Programms ein Argument");
        return 1;
    }
    printf("1. Para='%s'\n", argv[1]);
    // Ihr Code
    return 0;

    char input[100];
    printf(">>");
    fgets(input, 100, stdin);
    printf("Eingabe=%s\n", input);
    return 0;

    int inputPar = 1234567;

    int resultInt = 0;
    while (inputPar > 0)
    {
        int modVal = inputPar % 10;

        inputPar = inputPar / 10;

        resultInt = resultInt + modVal;

        printf("\n : %i", resultInt);
    }
}
