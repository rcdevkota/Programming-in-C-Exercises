#include <stdio.h>  //fuer printf()  fgets()
#include <string.h> //fuer strtok()
                    // Compilerschalter

//-Wall -fsanitize = address void
debugstr(char *str, size_t n)
{
}
int quersumme(char *par)
{
}
static const char *help =
    "help -- > Ausgabe dieser Hilfsmeldung\n "
    "quit-- > Programm    beenden\n "
     "quersummepar1-- > Aufruf der Funktion aus der  ersten\n "
    " -- > Vorlesungswoche\n "                      "debugstr0
    par1-- > Aufruf der zuvor geschriebenen Funktion\n "
                            "

    mit einer Längenangabe von 0\n "
                                   "debugstr1
    n par2-- > Aufruf der zuvor geschriebenen
                   Funktion\n "
                              "              
    mit einer Längenangabe von n\n ";
    int
    main(int argc, char *argv[])
{
    enum status
    {
        OK,
        KO_FGETS,
        KO_END
    } ret = OK;
    printf("Programm:
"
        "\e[31m"  //Farbe Rot
 
      __FILE__
        "\e[39m"  //Farbe Schwarz
        "
\033[4m" //Unterstreichen ein.
        "started\
        \033[0m\n" ); //Unterstreichen aus.
    while(1) {
        fflush(stdout); // In Stdout gespeicherte Zeichen zur Ausgabe

        // bringen,
        so dass bei einem ggf.nachfolgenden

            // Programmabsturz
            die zwischengespeicherten

                // Zeichen
                nicht verloren gehen !char input[20];
        // Zur
        Befehlseingabe im 'Executor' mittels des Buttons 'Execution stdin'
            // den
            Eingabereich 'Execution stdin...' öffnen und dort ihre
                // Befehle
                eintragen.Die Eingabe kann mehrere Zeilen lang sein
                    // fgets()
                    liest diese zeilenweise ein !
            // In
            der letzten Zeile am besten quit eintragen !if (fgets(input, sizeof input, stdin) == NULL)
        {

            ret = KO_FGETS;
            break;
        }

        // Für
sie als Hilfsfunktion zur Darstellung der fgets Rückgabe
        //(kann
gerne gelöscht werden)
        debugstr(input,sizeof(input));
char *arg1 = strtok(input, "
                           ");

                    // Für
                    sie als Hilfsfunktion zur Darstellung der Arbeitsweise von strtok()
                    //(kann
                    gerne gelöscht werden)
    debugstr(input, sizeof(input));
if (arg1 == NULL)
    continue;
else if (strcmp(arg1, "quit\n") == 0)
    break;
// Ihre
Aufgabe
 
  }
    const char *retstring[]={
        [KO_FGETS]   ="Programm mangels Eingabe beendet",
        [OK]      
  ="Programm ordnungsgemäß beendet",
        [KO_END]     ="Unbekannter Rückgabewert"
 
  };
    printf("%s\n",retstring[ret>KO_END?KO_END:(ret<0?KO_END:ret)]);
    return (int)ret;
}