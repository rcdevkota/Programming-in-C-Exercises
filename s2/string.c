#include <stdio.h>  //fuer printf()
#include <string.h> //fuer
// strcpy()
// strcat()
// strlen()
int main(int argc, char *argv[])
{
    char str1[] = "HalloWelt";
    char str2[] = "Ich";
    printf(str1);
    printf("str1='%s'\n", str1);
    printf("str2='%s'\n", str2);
    printf("Länge str1=%ld\n"
           "Länge str2=%ld\n",
           strlen(str1),
           strlen(str2));
#if 0 // Aufgabe 1
//str1 und str2 zu einem String verbinden (Konkatenation) auf Basis zweier FOR‐Schleifen.
//Reservieren sie für den Zielstring passend Speicher!

int destStrLength = strlen(str1)+ strlen(str2)+1;
char concatedString[destStrLength];

int  i =0,j=0;
for (i; i<strlen(str1); i++) 
{
  concatedString[j]= str1[i];
    j++;
}
printf("\nConcatenated string: %s\n", concatedString);
 i =0;
for (i; i<strlen(str2); i++) 
{
 concatedString[j]=str2[i];
    j++;
}
printf( "Länge=%ld\n", strlen(concatedString));
printf("\nConcatenated string: %s\n", concatedString);
#endif

#if 0 // Aufgabe 2
//str1 und str2 zu einem String verbinden (Konkatenation) unter Nutzung von strcpy() für die
//erste Kopieraktion und strcat() für das Anhängen. Reservieren sie für den Zielstring passend
//Speicher!

int destStrLength2 = strlen(str1)+ strlen(str2)+1;
char concatedString2[destStrLength2];
strcpy(concatedString2,str1);
strcat(concatedString2,str2);
printf("\nConcatenated string2: %s", concatedString);
#endif
#if 0 // Aufgabe 3
//str1 und str2 zu einem String verbinden (Konkatenation) nur unter Nutzung von strcpy() und
//strlen()
//Reservieren sie für den Zielstring passend Speicher!

int lengthStr1 =strlen(str1);
int destStrLength =lengthStr1 + strlen(str2)+1;
char concatedString[destStrLength];
strcpy(concatedString,str1);


char* temp = strcpy(concatedString,str1);
strcpy(temp+lengthStr1,str2);

printf("\nConcatenated string: %s", concatedString);

#endif

#if 1 // Aufgabe 4
    // str1 und str2 zu einem String verbinden (Konkatenation) nur unter Nutzung von strcat() (kein
    // strcpy() nutzen)
    int destStrLength = strlen(str1) + strlen(str2) + 1;
    char concatedString[destStrLength];

    printf("\nConcatenated string: %s", concatedString);
    char *temp = strcat(concatedString, str1);

    strcat(temp, str2);
    printf("\nConcatenated string: %s", concatedString);

#endif

#if 0 // Aufgabe 5
//str2 an str1 anhängen, d.h. kein separaten Speicher für den Zielstring reservieren, sondern str1
//als Zielstring nutzen (Bitte einmal mit Compilerschalter ‐fsanitize=address und einmal ohne
//diesen Compilerschalter ausprobieren)

strlen(str1)== strlen(str1)+strlen(str2+1);
printf( "Länge=%ld\n", strlen(str1));
 int i =strlen(str1), j=0;
for (i; i<strlen(str2); i++) 
{
 str1[j]=str2[i];
    j++;
}
printf( "Länge=%ld\n", strlen(str1));
printf("\nConcatenated string: %s\n", str1);

#endif
#if 1 // Aufgabe 6

#endif
#if 0 // Aufgabe 7
#endif
#if 0 // Aufgabe 8
#endif
#if 0 // Aufgabe 9
#endif
}