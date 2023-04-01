#include <stdio.h>  //fuer printf()  fgets()
#include <string.h> //fuer strtok()
#include <stdlib.h>
// Compilerschalter nicht vergessen!
//-Wall -fsanitize=address

void debugstr(char *str, size_t n)
{

    if (n)
    {
        for (size_t i = 0; i < n; i++)
        {
            printf("%p,: %d,: '%c'\n", &str[i], (int)str[i], str[i]);
        }
    }
    else
    {
        size_t i = 0;
        for (; str[i]; i++)
        {
            printf("%p,: %d,: '%c'\n", &str[i], (int)str[i], str[i]);
        }
        printf("%p,: %d,: '%c'\n", &str[i], (int)str[i], str[i]);
    }
}
int quersumme(char *par)
{

    int quersumme = 0;

    // Ihr Code
    for (int i = 0; par[i]; i++)
    {
        if (par[i] > '0' && par[i] <= '9')
        {
            quersumme += par[i] - '0';
        }
    }
    return quersumme;
}
static const char *help =
    "help                  --> Ausgabe dieser Hilfsmeldung\n"
    "quit                  --> Programm beenden\n"
    "quersumme par1        --> Aufruf der Funktion aus der ersten\n"
    "                      --> Vorlesungswoche\n"
    "debugstr0 par1        --> Aufruf der zuvor geschriebenen Funktion\n"
    "                          mit einer Längenangabe von 0\n"
    "debugstr1 n par2      --> Aufruf der zuvor geschriebenen Funktion\n"
    "                          mit einer Längenangabe von n\n";

int main(int argc, char *argv[])
{
    enum status
    {
        OK,
        KO_FGETS,
        KO_END
    } ret = OK;
    printf("Programm:"
           "\e[31m" // Farbe Rot
           __FILE__
           "\e[39m"  // Farbe Schwarz
           "\033[4m" // Unterstreichen ein.
           "started\
        \033[0m\n"); // Unterstreichen aus.
    while (1)
    {
        fflush(stdout); // In Stdout gespeicherte Zeichen zur Ausgabe
        // bringen, so dass bei einem ggf. nachfolgenden
        // Programmabsturz zwischengespeicherten
        // Zeichen nicht verloren gehen!

        char input[50];
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

        // Für sie als Hilfsfunktion zur Darstellung der fgets Rückgabe
        //(kann gerne gelöscht werden)
        // debugstr(input,sizeof(input));
        char *arg1 = strtok(input, " ");

        // Für sie als Hilfsfunktion zur Darstellung der Arbeitsweise von strtok()
        //(kann gerne gelöscht werden)
        // debugstr(input,sizeof(input));
        if (arg1 == NULL)
        {
            continue;
        }
        else if (!strcmp(arg1, "quit\n"))
            break;
        else if (!strcmp(arg1, "help\n"))
            printf("%s", help);
        else if (!strcmp(arg1, "quersumme"))
        {
            char *arg2 = strtok(NULL, " ");
            printf("%i\n", quersumme(arg2));
        }
        else if (!strcmp(arg1, "debugstr0"))
        {
            char *arg2 = strtok(NULL, " ");
            debugstr(arg2, 0);
        }
        else if (!strcmp(arg1, "debugstr1"))
        {
            char *arg2 = strtok(NULL, " ");
            size_t arg3 = atoi(arg2);
            char *arg4 = strtok(NULL, " ");
            debugstr(arg4, arg3);
        }
    }
    const char *retstring[] = {
        [KO_FGETS] = "Programm mangels Eingabe beendet",
        [OK] = "Programm ordnungsgemäß beendet",
        [KO_END] = "Unbekannter Rückgabewert"};
    printf("%s\n", retstring[ret > KO_END ? KO_END : (ret < 0 ? KO_END : ret)]);
    return (int)ret;
}
