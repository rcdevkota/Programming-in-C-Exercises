#include <stdio.h>
struct
{
    int x;
    int y;
    int z;
};
struct xyz2
{
    int x;
    int y;
    int z;
};
struct
{
    int x;
    int y;
    int z;
    s
} xyz3;
struct xyz4
{
    int x;
    int y;
    int z;
} xyz4;
#if 0
// a) Legen sie von jedem Datentyp eine neue Variable an, sofern möglich.

// kann kein instanz angelegt werden
struct xyz2 var1 = {1, 22, 5};
// xyz3 kann kein instanz anlegen
struct xyz4 var2 = {3, 3, 5};

// b) Was sagen die einzelnen Definitionen aus?
struct -- > weder zugreifen or instanz anlegen struct xyz2-- > zugreifen und auch ein instanz gestllt werden struct xyz3-- > nur zugegrifen werden, es gibt nur ein instanz struct xyz4-- > kann zugreifen und ein instanz würde schon angelegt und kann ein instanz gestellt werden
                                                                                                                                                        // c) Wie sieht die Zuweisung zweier Variablen des identischen Datentyps aus?
                                                                                                                                                        struct xyz2 var1 = {1, 2, 3};
struct xyz2 var2 = var1;
// d) Wie sieht der Vergleich zweier Variablen des identischen Datentyps aus?
//mit memcomp() funktion kann mann die zwei variable vergleichen : memcomp(var1, var2, seizeof(Var1));
// e) Wie sieht die Zuweisung zweier Variablen unterschiedlichen Datentyps aus (Inhalt der Strukturen ist identisch)?
struct xyz2 var1 = {1, 2, 3};
struct xyz2 var2 = {4, 5, 6};

va1.x = var2.x;
va1.y = var2.y;
va1.z = var2.z;

// f) Wie sieht der Vergleich zweier Variablen unterschiedlichen Datentyps aus (Inhalt der Strukturen ist identisch)?
struct xyz2 var1 = {1, 2, 3};
struct xyz2 var2 = {4, 5, 6};
if (var1.x == var2.x && va1.y == var2.y && var1.z == var2.z)
{
    printf("%s", "var1 und var2 sind gleich");
}
else
{
    printf("%s", "var1 und var2 sind nicht gleich");
}
// g) Wie sieht eine Initialisierung/Zuweisung von neuen Variablen des Datentyps 'struct xyz4' in folgenden Fällen aus:
// g1) Initialisierung einer Variablen bei der Definition der Variablen mit Werten in der Reihenfolge der Strukturelemente
struct xyz2 var1 = {3, 4, 5};
// g2) Initialisierung einer Variablen bei der Definition der Variablen mit Werte in einer anderen Reihenfolgen, als die Struktur vorgibt (z.B. zuerst z, dann x und dann y)
struct xyz2 var1 = {.x = 3,
                    .y = 4,
                    .z = 5};
// g3) Zuweisung einer bereits angelegten Variablen mit einer Konstanten (Stichwort Compound Literal)
xyz4 = ((struct xyz4){3, 4, 5});
#endif
#if 1
struct sub1struct
{
    int integer;
    char str[40];
};

struct mainstruct
{
    int a;                  // 0 bytes offset
    int b[10];              // 4 bytes offset
    struct sub1struct c[3]; // 44 bytes offset
    struct sub2struct
    {
        int d;               // 44+44*3 = 176 bytes offset
        int e;               // 180 bytes
        struct sub1struct f; // 184 bytes offset
    } g;

} h, i[2];
/*a) Schreiben sie den Debug-Funktion, welche sämtliche Strukturelemente (incl. Substrukturelemente) der Variablen h formatiert ausgibt
b) Legen sie von 'struct mainstruct' eine neue Variable k an und initialisieren sie alle Elemente (incl. Substrukturelemente) bei der Definition dieser Variablen mit einen beliebigen Wert (Zur Selbstkontrolle am besten obige Debug-Funtkion nutzen!)
--> siehe main
Hilfe: Arrays werden in C wie folgt Initialisiert:   int arr[3]={1,2,3};
c) Überlegen sie sich den benötigten Speicherbedarf, den eine Variable des Datentyps struct mainstruct belegt?
--> 228 Bytes
d) Alle Strukturelemente werden über einen Offset bezogen auf das erste Strukturelement angesprochen. Welchen Offset haben die einzelnen Strukturelemente?
-->
3) Eine Struktur entspricht einer Klasse bei objektorientierten Sprachen. Beschreiben sie mehrere Unterschiede/Gemeinsamkeiten zwischen der Struktur in C und der Klasse in JAVA.
-->
// Unterschiede
// Strukturen in C können keine Methoden und Variablen  enthalten, im Gegensatz zu Klassen in objektorientierten Sprachen wie Java.
// In Klassen (z.B. in Java) kann man Zugriffsmodifikatoren wie private und public verwenden (Kapselung ist in Strukturen nicht möglich).
// Polymorphie ist in Strukturen in C nicht möglich.

// Gemeinsamkeiten
// Beide können verschiedene Variablen speichern.
// Beide können instanziiert werden.
*/

void debug_struct(struct mainstruct var)
{
    printf("%s%i\n", "a = ", var.a);
    for (int i = 0; i < 10; i++)
    {
        printf("%s%i\n", "b = ", var.b[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s %i %s \n", "sub1struct:", var.c[i].integer, var.c[i].str);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%s %i %i %i %s\n", "sub2struct:", var.g.d, var.g.e, var.g.f.integer, var.g.f.str);
    }
}

#endif
int main(int argc, char *argv[])
{

    struct mainstruct k = {0, {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, {{0, "test"}, {12, "test1"}, {34, "test2"}}, {34, 45, {23, "test substruct"}}};

    debug_struct(k);

    return 0;
}