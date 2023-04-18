#include <stdio.h>

// CompilerSchalter: -fsanitize=address -Wall -Werror

// 1) Realisieren sie für jedes dieser Datentypbeschreibungen einen C-Datentyp

enum Nationalität
{
        DEUTSCH,
        ENGLAND,
        SPANIEN,
        SONSTIGES,
};
enum Typen
{
        STUDENT,
        DOZENT,
        HOCHSCHULE,
};
struct Fächer
{
        char name[11];
        float note;
};
struct Student
{
        char vorname[11];
        char nachname[11];
        short nationalität;
        short semester;
        struct Fächer f[2];
};

struct Dozent
{
        char title[11];
        char name[11];
        short nationalität;
        short ejahr;
        struct Fächer f[2];
};

struct Hochschule
{
        char name[11];
        char ort[11];
        int plz;
        char strasse[11];
        long stunden;
};

union Data
{
        struct Student s;
        struct Dozent d;
        struct Hochschule h;
};
// 2) Realisieren sie einen weiteren Datentypen, welcher alle diese 3 Datentypen
//    aufnehmen kann, wobei nur einer von diesen Aktiv sein kann (Stichwort Union).
struct element
{
        // enum zu Identifikation des gültigen Unions
        // Union zur Aufnahme der 3 zuvor definierten Datentypen
        enum Typen active;
        union Data d;
};

// 3) Mit dem Datentyp Specifier können einzelnen Strukturelementen zusätzliche
//    Eigenschaften/Einschränkungen gegeben werden. Überlegen sie sich für jeden
//    Specifier mindestens einen sinnvolles Strukturelement (sofern überhaupt möglich)
//    und Begründen sie dessen Verwendung. Wenn es keine Verwendung für einen Specifier
//    gibt, so bitte auch dieses Begründen
#if 0
  - static:  mögliches Strukturelement + Begründung
  // alle variable könnte mann static machen, da wir hier nur mit ein datai arbeiten haben wir die variable als private deklariert

 - extern:   mögliches Strukturelement + Begründung
 //da wir hier nur ein c datai haben und nicht von anderen datain irgendwas zugreiffen wollen, ist nicht genutzt

 - volatile: mögliches Strukturelement + Begründung
 //weil wir kein multithreading genutzt haben, haben wir kein volatile genutzt

 - const:    mögliches Strukturelement + Begründung
 // die enums könnte mann als const nutzen aber leider "const enum Typen" wirft fehler
#endif

// 4) Legen sie vom Datentyp 'struct element' ein Array mit 9 Elemente an und
//    initialisieren sie dieses Array mit Musterdaten (je 3 von jedem Subdatentyp:
struct element elemente[9] = {
    [0] = {STUDENT, {.s = {"Ram", "Devkota", SONSTIGES, 7, {{"ftse", 2.0}, {"TheoInf", 2}}}}},
    [2] = {STUDENT, {.s = {"Jorg", "Weimar", SONSTIGES, 7, {{"ftse", 2.0}, {"TheoInf", 2}}}}},
    [1] = {STUDENT, {.s = {"Suzanne", "Bellmar", SONSTIGES, 7, {{"ftse", 2.0}, {"TheoInf", 2}}}}},
    [3] = {DOZENT, {.d = {"Prof.Dr", "Pero Ahlers", DEUTSCH, 1996, {{"ftse", 2.0}, {"TheoInf", 2}}}}},
    [4] = {DOZENT, {.d = {"Prof.Dr", "Karandese", SONSTIGES, 7, {{"ftse", 2.0}, {"TheoInf", 2}}}}},
    [5] = {DOZENT, {.d = {"Prof.Dr", "Justen", SONSTIGES, 7, {{"ftse", 2.0}, {"TheoInf", 2}}}}},
    [6] = {HOCHSCHULE, {.h = {"Ostfalia", "wof", 38302, "Am Exer", 800}}},
    [7] = {HOCHSCHULE, {.h = {"UniJena", "Jena", 70468, "Emil", 25000}}},
    [8] = {HOCHSCHULE, {.h = {"UniBerlin", "Berlin", 1001, "Am Exer", 9000}}},
};

// 5) Schreiben sie eine Debug-Routine, welche das gesamte Array tabellarisch ausgibt.
void debug_element(void)
{

        printf(
            "-----------+----------+-----------+----------+-----------+-----------+-----------+-----------------\n"
            "Vorname    | Nachname | Nationali.| Semester | Fach0-Name| Fach0-Note| Fach1-Name| Fach1-Note\n"
            "Titel      | Name     | Nationali.| EinsJahr | Fach0-Name| Fach0-Note| Fach1-Name| Fach1-Note\n"
            "-          | Ort      | -         | Plz      | Straße    | Studenten | -         | -\n"
            "-----------+----------+-----------+----------+-----------+-----------+-----------+-----------------\n");
        // Hinweis:
        //- Spaltenbreite der Überschrift darf angepasst werden!
        //- Die Spalten sollen im Ausdruck alle gleich breit sein
        for (int i = 0; i < 9; i++)
        {
                if (elemente[i].active == STUDENT)
                {
                        printf("%11s", elemente[i].d.s.vorname);
                        printf("%11s", elemente[i].d.s.nachname);
                        printf("%11i", elemente[i].d.s.nationalität);
                        printf("%11i", elemente[i].d.s.semester);
                        printf("%13s", elemente[i].d.s.f[0].name);
                        printf("%11f", elemente[i].d.s.f[0].note);
                        printf("%13s", elemente[i].d.s.f[1].name);
                        printf("%11f", elemente[i].d.s.f[1].note);
                }
                else if (elemente[i].active == DOZENT)
                {
                        printf("%11s", elemente[i].d.d.title);
                        printf("%11s", elemente[i].d.d.name);
                        printf("%11i", elemente[i].d.d.nationalität);
                        printf("%11i", elemente[i].d.d.ejahr);
                        printf("%13s", elemente[i].d.d.f[0].name);
                        printf("%11f", elemente[i].d.d.f[0].note);
                        printf("%13s", elemente[i].d.d.f[1].name);
                        printf("%11f", elemente[i].d.d.f[1].note);
                }
                else if (elemente[i].active == HOCHSCHULE)
                {
                        printf("%11s", "          ");
                        printf("%11s", elemente[i].d.h.name);
                        printf("%11s", elemente[i].d.h.ort);
                        printf("%11i", elemente[i].d.h.plz);
                        printf("%11s", elemente[i].d.h.strasse);
                        printf("%11li", elemente[i].d.h.stunden);
                }
                printf("\n");
        }
}

int main(int argc, char *argv[])
{
        (void)argc;
        (void)argv;

        debug_element();
        return 0;
}
