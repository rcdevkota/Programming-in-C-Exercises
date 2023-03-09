 #include<stdio.h> // fuer printf

    // Compilerschalter: -fsanitize=address -Wall

    // 1) Gegeben seien folgende 'Definitionen':
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
} xyz3;
struct xyz4
{
    int x;
    int y;
    int z;
} xyz4;

#if 1
a) Legen sie von jedem Datentyp eine neue Variable an, sofern möglich.
// kann kein instanz angelegt werden
struct xyz2 newVariable = {2,3,4};
// xyz3 kann kein instanz anlegen
struct xyz4 newVarible = {4, 5, 6};

b) Was sagen die einzelnen Definitionen aus?
   struct
{
};
-- > weder zugreifen or instanz anlegen struct xyz2
{
};
-- > zugreifen struct
{
} xyz3;
-- > nur einmal zugegrifen werden struct xyz4
{
} xyz4; -->    kann zugreifen und ein instanz würde schon angelegt
c) Wie sieht die Zuweisung zweier Variablen des identischen Datentyps aus?
struct xyz2 var1 = {1,2,3};
struct xyz2 var2 = var1;
d) Wie sieht der Vergleich zweier Variablen des identischen Datentyps aus?
// mit memcomp funktion kann mann die zwei variable vergleichen zB:
// memcomp(var1, var2,seizeof(Var1));

e) Wie sieht die Zuweisung zweier Variablen unterschiedlichen Datentyps aus (Inhalt der Strukturen ist identisch)?
struct xyz2 var1 = {1,2,3};
struct xyz2 var2 = {4, 5, 6};

va1.x = var2.x;
va1.y = var2.y;
va1.z = var2.z;

f) Wie sieht der Vergleich zweier Variablen unterschiedlichen Datentyps aus (Inhalt der Strukturen ist identisch)?
struct xyz2 var1 = {1,2,3};
struct xyz2 var2 = {4, 5, 6};
if (var1.x == var2.x && va1.y == var2.y && var1.z == var2.z)
{
    // return true
}
else
{
    // return false
}

g) Wie sieht eine Initialisierung/Zuweisung von neuen Variablen des Datentyps 'struct xyz4' in folgenden Fällen aus:

g1) Initialisierung einer Variablen bei der Definition der Variablen mit Werten in der Reihenfolge der Strukturelemente
struct xyz2 var1= {3,4,5};
g2) Initialisierung einer Variablen bei der Definition der Variablen mit Werte in einer anderen Reihenfolgen, als die Struktur vorgibt (z.B. zuerst z, dann x und dann y)
struct xyz2 var1={.x=3,.y=4,.z=5};
g3) Zuweisung einer bereits angelegten Variablen mit einer Konstanten (Stichwort Compound Literal)
xyz4 = (struct xyz4){3,4,5};
#endif

//    2) Gegeben seien folgende 'Datentypen'
struct sub1struct
{
    int integer;  // offset =0
    char str[40]; // offset =4 bytes
};
struct mainstruct
{
    int a;                  // offset = 0
    int b[10];              // offset =4 bytes
    struct sub1struct c[3]; // offset = 44bytes
    struct sub2struct
    {
        int d;               // offset =176 bytes (berecnent mit sizeof(substruct))
        int e;               // offset = 180 bytes
        struct sub1struct f; // offset = 184;
    } g;
} h, i[2];

#if 0
a) Schreiben sie den Debug-Funktion, welche sämtliche Strukturelemente (incl. Substrukturelemente) der Variablen h formatiert ausgibt
void debug_mainstruct(struct mainstruct var) {
printf("%i ",var.a);
for(int i= 0;i<10;i++){
    printf("%i ",var.b[i]);
}
for(int i =0;i<3;i++){
    printf("%i %s ",var.c[i].integer, var.c[i].str);
}

for(int i =0;i<3;i++){
    printf("%i %i %i %s",var.g.d, var.g.e, var.g.f.integer,var.g.f.str);
}

}
b) Legen sie von 'mainstruct' eine neue Variable k an und initialisieren sie alle Elemente
(incl. Substrukturelemente) bei der Definition dieser Variablen mit einen
beliebigen Wert (Zur Selbstkontrolle am besten obige Debug-Funtkion nutzen!)

struct mainstruct k = {1,{1,2,3,4,5,6,7,8,9,0},{{1,"einstring"},{2,"einNeueString"},{3,"nochmalEinstring"}},{2,3,{1,"some random string"}}};

Hilfe: Arrays werden in C wie folgt Initialisiert:   int arr[3]={1,2,3};
c) Überlegen sie sich den benötigten Speicherbedarf, den eine Variable des Datentyps struct mainstruct belegt?
// die benötigten speicerbedarf für mainstruct 228 bytes
d) Alle Strukturelemente werden über einen Offset bezogen auf das erste Strukturelement angesprochen. Welchen Offset haben die einzelnen Strukturelemente?
   (Gerne als Kommentar direkt oben bei der Struktdefinition)

#endif

#if 1
3) Eine Struktur entspricht einer Klasse bei objektorientierten Sprachen. Beschreiben sie mehrere Unterschiede/Gemeinsamkeiten zwischen der Struktur in C und der Klasse in JAVA.
// Unterschiede
// struktur kann nicht beide methoden und Variables beinhalten anders als java klassen
// in java klassen kann mann Private/public deklarieren (encapsulation ist nicht möglish in strukrtur)
//  Polymorphism ist nicht möglish in struktur in C

// gemeinsamkeiten
//   beide speichern verschiedene variablen
//   beide können instanziiert werden

#endif

int main(int argc, char *argv[])
{

    return 0;
}