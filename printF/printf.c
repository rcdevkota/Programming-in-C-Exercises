#include <stdio.h>
// CompilerSchalter: -fsanitize=address -Wall -Werror
// 1) Realisieren sie für jedes dieser Datentypbeschreibungen einen C-Datentyp
enum aktiv
{
    student,
    dozent,
    hochschule
};
enum national
{
    deutsch,
    england,
    spanien,
    sonstiges
};
struct fach
{
    char name[11];
    float note;
};
struct student
{
    char vorname[11];
    char nachname[11];
    enum national national;
    int semester;
    struct fach sub[2];
};
struct dozent
{
    char titel[11];
    char name[11];
    enum national national;
    int einsteigsjahr;
    struct fach sub[2];
};
struct hochschule
{
    char name[11];
    char ort[11];
    int plz;
    char strasse[10];
    long studenten;
};

// 2) Realisieren sie einen weiteren Datentypen, welcher alle diese 3 Datentypen
//    aufnehmen kann, wobei nur einer von diesen Aktiv sein kann (Stichwort Union).
union uni
{
    struct student student;
    struct dozent dozent;
    struct hochschule hochschule;
};
struct element
{ // hier je nach dem welche struct aktiv sein soll werte 1 2 3 für student dozent und Hochschule
    enum aktiv aktivStruct;
    // int aktivStruct;
    union uni uni;
};

// 3) Mit dem Datentyp Specifier können einzelnen Strukturelementen zusätzliche
//    Eigenschaften/Einschränkungen gegeben werden. Überlegen sie sich für jeden
//    Specifier mindestens einen sinnvolles Strukturelement (sofern überhaupt möglich)
//    und Begründen sie dessen Verwendung. Wenn es keine Verwendung für einen Specifier
//    gibt, so bitte auch dieses Begründen
#if 0
- static:  Nationalität + wird nicht in anderen modulen  benötigt
                            alle variable könnte mann static machen, da wir hier nur mit 
                             ein datai arbeiten haben wir die variable als private deklariert
- extern:   keine + da wir hier nur ein c datai haben und nicht von 
            anderen datain irgendwas zugreiffen wollen, ist nicht genutzt
- volatile: keine + keine parallele zugriffe im programm
                    weil wir kein multithreading genutzt haben, haben wir kein volatile genutzt
- const:    einstiegsjahr + ändert sich nicht
                            die enums könnte mann als const nutzen aber leider "const enum Typen" wirft fehler
#endif

// 4) Legen sie vom Datentyp 'struct element' ein Array mit 9 Elemente an und
//    initialisieren sie dieses Array mit Musterdaten (je 3 von jedem Subdatentyp)
struct element elemente[9] = {

    [0] = {student, {.student = {"Ramchandr", "Devkota", sonstiges, 7, {{"ftse", 2.0}, {"qst", 1}}}}},
    [1] = {student, {.student = {"Peero", "Ahlers", deutsch, 7, {{"qst", 2.3}, {"ftse", 2}}}}},
    [2] = {student, {.student = {"Oli", "Karandsz", deutsch, 7, {{"web", 1.0}, {"web", 3}}}}},

    [3] = {dozent, {.dozent = {"Prof.Dr", "Justen", deutsch, 1996, {{"c", 1.0}, {"c++", 2.0}}}}},
    [4] = {dozent, {.dozent = {"Prof.Dr", "Weimar", deutsch, 1996, {{"Algodat", 3.0}, {"java", 2.0}}}}},
    [5] = {dozent, {.dozent = {"Prof.Dr", "Huhn", deutsch, 1996, {{"Qst", 1.0}, {"SE", 2.0}}}}},

    [6] = {hochschule, {.hochschule = {"Ostfalia", "Wolfen", 38302, "Am Exer", 8000}}},
    [7] = {hochschule, {.hochschule = {"Ostfalia", "Wolfs", 38302, "Am Exer", 9000}}},
    [8] = {hochschule, {.hochschule = {"Ostfalia", "Saalz", 38302, "Am Exer", 7000}}},

};

// 5) Schreiben sie eine Debug-Routine, welche das gesamte Array tabellarisch ausgibt.
void debug_element(void)
{

    printf(

        "----------+----------+----------+----------+----------+----------+----------+-------------\n"
        "Vorname   | Nachname |Nationali.|Semester  |Fach0-Name|Fach0-Note|Fach1-Name|Fach1-Note \n"
        "Titel     | Name     |Nationali.|EinsJahr  |Fach0-Name|Fach0-Note|Fach1-Name|Fach1-Note\n"
        " -        | Ort      |-         |Plz       |Straße    |Studenten |-         |-\n"
        "----------+----------+----------+----------+----------+----------+----------+-------------\n");

    for (int i = 0; i < 9; i++)
    {
        switch (elemente[i].aktivStruct)
        {
        case student:
            printf("%10s|", elemente[i].uni.student.vorname);
            printf("%10s|", elemente[i].uni.student.nachname);
            printf("%10i|", elemente[i].uni.student.national);
            printf("%10i|", elemente[i].uni.student.semester);
            printf("%10s|", elemente[i].uni.student.sub[0].name);
            printf("%10.1f|", elemente[i].uni.student.sub[0].note);
            printf("%10s|", elemente[i].uni.student.sub[1].name);
            printf("%10.1f", elemente[i].uni.student.sub[1].note);
            break;

        case dozent:
            printf("%10s|", elemente[i].uni.dozent.titel);
            printf("%10s|", elemente[i].uni.dozent.name);
            printf("%10i|", elemente[i].uni.dozent.national);
            printf("%10i|", elemente[i].uni.dozent.einsteigsjahr);
            printf("%10s|", elemente[i].uni.dozent.sub[0].name);
            printf("%10.1f|", elemente[i].uni.dozent.sub[0].note);
            printf("%10s|", elemente[i].uni.dozent.sub[1].name);
            printf("%10.1f", elemente[i].uni.dozent.sub[1].note);
            break;
        case hochschule:

            printf("%10s|", "-");
            printf("%10s|", elemente[i].uni.hochschule.ort);

            printf("%10s|", "-");
            printf("%10i|", elemente[i].uni.hochschule.plz);
            printf("%10s|", elemente[i].uni.hochschule.strasse);
            printf("%10li|", elemente[i].uni.hochschule.studenten);
            printf("%10s|", "-");
            printf("%10s", "-");
            break;
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