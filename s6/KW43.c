#include <stdio.h>

//CompilerSchalter: -fsanitize=address -Wall -Werror

//1) Realisieren sie für jedes dieser Datentypbeschreibungen einen C-Datentyp
struct student {   
};
struct dozent  {   
};
struct hochschule {   
};

//2) Realisieren sie einen weiteren Datentypen, welcher alle diese 3 Datentypen 
//   aufnehmen kann, wobei nur einer von diesen Aktiv sein kann (Stichwort Union). 
struct element {
        //enum zu Identifikation des gültigen Unions
        //Union zur Aufnahme der 3 zuvor definierten Datentypen
};
            
//3) Mit dem Datentyp Specifier können einzelnen Strukturelementen zusätzliche 
//   Eigenschaften/Einschränkungen gegeben werden. Überlegen sie sich für jeden 
//   Specifier mindestens einen sinnvolles Strukturelement (sofern überhaupt möglich) 
//   und Begründen sie dessen Verwendung. Wenn es keine Verwendung für einen Specifier 
//   gibt, so bitte auch dieses Begründen
#if 0
  - static:  mögliches Strukturelement + Begründung
 - extern:   mögliches Strukturelement + Begründung
 - volatile: mögliches Strukturelement + Begründung
 - const:    mögliches Strukturelement + Begründung
#endif

//4) Legen sie vom Datentyp 'struct element' ein Array mit 9 Elemente an und 
//   initialisieren sie dieses Array mit Musterdaten (je 3 von jedem Subdatentyp:
struct element elemente[9]={ 
/*[0]=*/{    },
/*[1]=*/{    },
/*[2]=*/{    },
/*[3]=*/{    },
/*[4]=*/{    },
/*[5]=*/{    },
/*[6]=*/{    },
/*[7]=*/{    },
/*[8]=*/{    },
};
    
//5) Schreiben sie eine Debug-Routine, welche das gesamte Array tabellarisch ausgibt.
void debug_element(void) {
        printf(
"--------+----------+------------+----------+------------+------------+------------+------------\n"
"Vorname | Nachname | Nationali. | Semester | Fach0-Name | Fach0-Note | Fach1-Name | Fach1-Note\n"
"Titel   | Name     | Nationali. | EinsJahr | Fach0-Name | Fach0-Note | Fach1-Name | Fach1-Note\n"
"-       | Ort      | -          | Plz      | Straße     | Studenten  | -          | -\n"
"--------+----------+------------+----------+------------+------------+------------+------------\n"
              );
    //Hinweis:
    //- Spaltenbreite der Überschrift darf angepasst werden!
    //- Die Spalten sollen im Ausdruck alle gleich breit sein
}

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    debug_element();
    return 0;
}
