#include <stdio.h>  //fuer printf()  fgets()
#include <string.h> //fuer strtok()
#include <stdlib.h>

// Compilerschalter nicht vergessen!
//-Wall -fsanitize=address

static int printstr(char *str, size_t n);

int quersumme(char *input)
{
    // Ihre Realisierung aus der 1. Aufgabe
    int resultInt = 0;
    char *ptr;
    int strInt = strtol(input, &ptr, 10);
    while (strInt > 0)
    {
        int modVal = strInt % 10;
        strInt = strInt / 10;
        resultInt = resultInt + modVal;
    }
    return resultInt;
}
char *strstr_own(char *haystack, char *needle)
{
    printf("Suche in '%s' nach '%s'\n", haystack ?: "(null)", needle ?: "(null)");
    int k = strlen(haystack);
    int j = strlen(needle);
    int i = 0;
    for (; i < k; i++)
    {
        int x = i, l = 0;
        int true = 1;
        while (true == 1 && l < j)
        {
            if (haystack[x] == needle[l])
            {
                true = 1;
                if (l == (j - 1))
                {
                    return haystack + i;
                }
                x++;
                l++;
            }
            else
            {
                true = 0;
            }
        }
    }
    return NULL;
}

static const char *help =
    "help                   --> Ausgabe dieser Hilfsmeldung\n"
    "quit                   --> Ende des Programms\n"
    "printstr par1          --> Aufruf der Funktion printstr\n"
    "quersumme par1         --> Berechnung der Quersumme aus dem 1. Parameter\n"
    "strstr haystack needle --> Ohne worte\n";

int main(int argc, char *argv[])
{
    enum status
    {
        OK,
        KO_FGETS,
        KO_PRINTSTR,
        KO_END
    } ret = OK;
    printf("Programm: "
           "\e[31m" // Farbe Rot
           __FILE__
           "\e[39m"   // Farbe Schwarz
           " \033[4m" // Unterstreichen ein
           "started\
        \033[0m\n");  // Unterstreichen aus

    while (1)
    {
        char input[100];
        // Zur Befehlseingabe im 'Executor' mittels des Buttons 'Execution stdin'
        // den Eingabereich 'Execution stdin...' öffnen und dort ihre
        // Befehle eintragen. Die Eingabe kann mehrere Zeilen lang sein
        // fgets() liest diese zeilenweise ein!
        // In der letzten Zeile am besten quit eintragen!
        if (fgets(input, sizeof input, stdin) == NULL)
        {
            ret = KO_FGETS;
            break;
        }
        // wenn input quersumme aufgerufen wird
        char *token1 = strtok(input, " ");
        char *token2 = strtok(NULL, " ");
        char *token3 = strtok(NULL, " ");
        if (token1 == NULL)
        {
            continue;
        }
        else if (!strcmp(token1, "help\n"))
        {
            printf("%s", help);
        }
        else if (!strcmp(token1, "quit\n"))
        {
            break;
        }
        else if (!strcmp(token1, "printstr"))
        {
            printstr(token2, strlen(token2));
        }
        else if (!strcmp(token1, "quersumme"))
        {
            printf("%i\n", quersumme(token2));
        }
        else if (!strcmp(token1, "strstr"))
        {
            printf("%s\n", strstr_own(token2, token3));
        }
    }

    const char *retstring[] = {
        [KO_FGETS] = "Programm mangels Eingabe beendet",
        [OK] = "Programm ordnungsgemäß beendet",
        [KO_END] = "Unbekannter Rückgabewert",
        [KO_PRINTSTR] = "printstr failed"};
    printf("%s\n", retstring[ret > KO_END ? KO_END : (ret < 0 ? KO_END : ret)]);

    return (int)ret;
}

static int printstr(char *str, size_t n)
{
    if (n == 0)
        return printf("n muss größer als 0 sein!"), -1;

    for (size_t lauf = 0; lauf < n; lauf++)
        printf("'%1c'%s", str[lauf] >= 32 ? str[lauf] : '?', lauf == n - 1 ? "\n" : " ");
    unsigned char *ptr = (unsigned char *)str;
    for (size_t lauf = 0; lauf < n; lauf++)
        printf("%02x %s", ptr[lauf], lauf == n - 1 ? "\n" : " ");
    return 0;
}
