#include <stdio.h>  //fuer printf()
#include <string.h> //fuer strcpy() strcat() strlen()

// Compiler-Option: -Wall -fsanitize=address

int main(int argc, char *argv[])
{
    char str1[] = "HalloWelt";
    char str2[] = "Ich";
    printf("str1='%s'\n", str1);
    printf("str2='%s'\n", str2);
    printf("Länge str1=%zd\n"
           "Länge str2=%zd\n",
           strlen(str1),
           strlen(str2));
#if 0 // Aufgabe 1
int strlenStr1= strlen(str1);
int strlenStr2=strlen(str2);
int destStrLen = strlenStr1 + strlenStr2;
char destStr[destStrLen+1];
int i =0;
for(;i<strlenStr1;i++){
    destStr[i] = str1[i];
}
for(int j=0;j<strlenStr2;j++,i++){
     destStr[i] = str2[j];
}
destStr[i] ='\0';
printf("%s\n",destStr);
#endif
#if 0 // Aufgabe 2
int destStrLen = strlen(str1)+ strlen(str2);

char destStr[destStrLen +1];
strcpy(destStr,str1);
strcat(destStr,str2);
printf("%s",destStr);

#endif
#if 0 // Aufgabe 3
int strLen1 = strlen(str1);
char destStr[strLen1+ strlen(str2) +1];
strcpy(destStr,str1);
strcpy(destStr+strLen1,str2);
printf("%s",destStr);
#endif

#if 0 // Aufgabe 4
char destStr[strlen(str1)+strlen(str2)+1];
destStr[0]=0;
strcat(destStr,str1);
strcat(destStr,str2);
printf("%s",destStr);
#endif

#if 0 // Aufgabe 5 str2 an str1 anhängen, 
//d.h. kein separaten Speicher für den Zielstring reservieren, sondern str1 als Zielstring nutzen.
int i=0;
int j=0;
while(str1[i]!='\0'){
    i++;
}
while(str2[j]!='\0'){
    str1[i]=str2[j];
    i++;
    j++;
}
str1[i]='\0';
printf("%s",str1);
//so könnte mann das implementieren 
//aber str1 hat nicht genug speicer platz
#endif
#if 0 // Aufgabe 6
//str1 und str2 zu einem String verbinden (Konkatenation), wobei für den Zielstring nur 5 Bytes reserviert werden

char destStr[5];
strcpy(destStr,str1);
strcat(destStr,str2);
printf("%s",destStr); 

//die array ist nicht lang genug

#endif
#if 0 // Aufgabe 7
    // Schreiben sie auf Basis zweier FOR-Schleifen eine 'sichere' Konkatenation Funktionalität, die str1 und str2
    // unter Berücksichtigung der Größe des Zielstrings verbinden. Beispiele für mögliche Zielstrings
    //(d.h. die sichere Konkatenation Funktionalität soll gleichermaßen mit allen 4 Beispielstrings laufen)

    char str7a[5];
    char str7b[12];
    char str7c[13];
    char str7d[20];
    int strLen = sizeof(str7a) - 1;
    int i = 0;

    for (; str1[i] && strLen > i; i++)
    {
        str7a[i] = str1[i];
    }

    for (int j = 0; str2[j] && strLen > i; j++, i++)
    {
        str7a[i] = str2[j];
    }
    str7a[i] = 0;

    printf("%s", str7a);

#endif
#if 0 // Aufgabe 8
 Parameter n is the number of first bytes/characters to be copied form source string to destination string.
If there is no string end character then the destination string wont have the null terminator.
 If the source string is less then destination then rest of the bytes are written with null.
#endif
#if 0 // Aufgabe 9
While appending src string to dest string :
strncat() writes n+1 bytes to dest (n from src plus the terminating null byte) 
if src contains n or more bytes. So dest must be greater than or equal to strlen(dest)+n+1.

#endif

    return 0;
}