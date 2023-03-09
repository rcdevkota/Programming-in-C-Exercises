#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char str1a[] = "Der String %s hat keine Bedeutung";
    char str1b[] = "%s ersetzt %s";
    char str2a[] = "1";
    char str2b[] = "12111";
    char str2c[] = "lang";
#if 1 // Aufgabe 1 Eine beliebige Ganzzahl (bspw. 4711, ‐0, 3000000000) in einen String wandeln (ohne Nutzung von sprintf())
    int i = 0;
    int flag = 0;
    long var = -0;
    if (var < 0)
    {
        i = 1;
        var = var * (-1);
        flag = 1;
    }
    if (var == 0)
    {
        flag = 2;
    }

    long tempVar = var;
    while (tempVar)
    {
        tempVar = tempVar / 10;
        i++;
    }
    if (flag == 2)
    {
        i++;
    }
    tempVar = var;
    char newString[i + 1];
    newString[i] = 0;
    int t = i - 1;
    for (int j = 0; j < i; j++)
    {
        int k = tempVar % 10;
        tempVar /= 10;
        newString[t] = '0' + k;
        t--;
    }
    if (flag == 1)
    {
        newString[0] = '-';
    }
    if (flag == 2)
    {
        newString[0] = '0';
    }
    printf("\n string: %s", newString);
#endif
#if 1 // Aufgabe 2 Eine beliebige Ganzzahl in einen String wandeln (auf Basis von sprintf())
    int i = 0;
    int flag = 0;
    long var = 0;
    if (var < 0)
    {
        i = 1;
    }
    if (var == 0)
    {
        flag = 2;
    }

    long tempVar = var;
    while (tempVar)
    {
        tempVar = tempVar / 10;
        i++;
    }
    if (flag == 2)
    {
        i++;
    }
    tempVar = var;
    char newString[i + 1];
    // newString[i]=0;
    sprintf(newString, "%i", var);

    if (flag == 2)
    {
        newString[0] = '0';
    }

    printf("\n string: %s", newString);
#endif
#if 0 // Aufgabe 3 Den Inhalt eines Strings, welcher eine Zahl enthält (bspw. "1234","‐12",34ab") in eine 
//Integervariable wandelt (ohne Nutzung von atoi() / strtol() / scanf())

int strInt =0;
char input[]="a1a-2";
int i=0, j=strlen(input)-1,k=1;
for(i;i<strlen(input);i++){
    if(!(input[j]<'0'||input[j]>'9')){
        int temp =input[j]  - '0';
        strInt = strInt +(temp*k);
        k=k*10;    
    }
     j--;
   // printf("\nintval: %i", temp);   
}
if(input[0]=='-'){
    strInt*=(-1);
}
printf("\n final int: %i", strInt);
#endif
#if 0 // Aufgabe 4 Den Inhalt eines String, welcher eine Zahl enthält in eine Integervariable wandelt (auf Basis von strtol())
    char *ptr;
   int ret;
   char input[]="-111";
   ret = strtol(input, &ptr, 10);
   printf("the integer is %i\n", ret);
#endif
#if 0 // Aufgabe 5 Den Platzhalter "%s" in einem String (bspw. str1x) durch den Inhalt eines anderen String (bspw. str2x) ersetzt.
    char firstString[] = "%s";
    char secondString[] = "1";

    int k = 0;
    int stringLength = strlen(firstString);
    // for the length of the final string
    for (int i = 0; i < stringLength; i++)
    {
        if (firstString[i] == '%' && firstString[i + 1] == 's')
        {
            k++;
        }
    }

    int f = (stringLength + strlen(secondString) * k) + 1 - (k * 2);
    // printf("%i",f);
    // printf("%i",k);
    char finalStr[f];
    k = 0;
    for (int i = 0; i < stringLength; i++)
    {
        if (firstString[i] == '%' && firstString[i + 1] == 's')
        {
            int tempLength = strlen(secondString);
            for (int j = 0; j < tempLength; j++)
            {
                finalStr[k] = secondString[j];
                k++;
            }
            i++;
        }
        else
        {
            finalStr[k] = firstString[i];
            k++;
        }
    }
    finalStr[f - 1] = 0;
    printf("%s\n", finalStr);
// printf("%s",finalStr);
#endif

    int a = 0, i = 0, k = 0;

    while (haystack[i] && !a)
    {
        k = i;
        int j = 0;

        printf("\nConcatenated string: %c", haystack[i]);

        while (needle[j])
        {
            printf("\ncompare: %c %c", haystack[k], needle[j]);
            if (haystack[k] == needle[j])
            {
                j++;
                k++;
            }
            else
            {
                break;
            }
            if (!needle[j])
            {
                a = 1;

                printf("\nConcatenated string: %i", a);
            }
        }
        i++;
    }

    return &haystack[i - 1];
}
}