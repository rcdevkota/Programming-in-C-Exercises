#include <stdio.h>  //fuer printf

//Compilerschalter: -fsanitize=address -Wall

//1) Gegeben seien folgende 'Definitionen':
struct {
    int x;
    int y;
    int z;
};
struct xyz2 {
    int x;
    int y;
    int z;
};
struct {
    int x;
    int y; 
    int z;
} xyz3;
struct xyz4 {
    int x;
    int y;
    int z;
} xyz4;
	
#if 0
a) Legen sie von jedem Datentyp eine neue Variable an, sofern möglich.
b) Was sagen die einzelnen Definitionen aus? 
   struct {};           -->
   struct xyz2 {};      -->
   struct {} xyz3;      -->
   struct xyz4 {} xyz4; -->
c) Wie sieht die Zuweisung zweier Variablen des identischen Datentyps aus?
d) Wie sieht der Vergleich zweier Variablen des identischen Datentyps aus?
e) Wie sieht die Zuweisung zweier Variablen unterschiedlichen Datentyps aus (Inhalt der Strukturen ist identisch)? 
f) Wie sieht der Vergleich zweier Variablen unterschiedlichen Datentyps aus (Inhalt der Strukturen ist identisch)?
g) Wie sieht eine Initialisierung/Zuweisung von neuen Variablen des Datentyps 'struct xyz4' in folgenden Fällen aus:
g1) Initialisierung einer Variablen bei der Definition der Variablen mit Werten in der Reihenfolge der Strukturelemente
g2) Initialisierung einer Variablen bei der Definition der Variablen mit Werte in einer anderen Reihenfolgen, als die Struktur vorgibt (z.B. zuerst z, dann x und dann y)
g3) Zuweisung einer bereits angelegten Variablen mit einer Konstanten (Stichwort Compound Literal) 
#endif	

//	2) Gegeben seien folgende 'Datentypen'
struct sub1struct {
    int  integer;
    char str[40];
};
struct mainstruct {
    int a;
    int b[10];
    struct sub1struct c[3];
    struct sub2struct {
        int d;
        int e;
        struct sub1struct f;
    } g;
}h,i[2];
	
#if 0
a) Schreiben sie den Debug-Funktion, welche sämtliche Strukturelemente (incl. Substrukturelemente) der Variablen h formatiert ausgibt
void debug_mainstruct(struct mainstruct var) {

}
b) Legen sie von 'mainstruct' eine neue Variable k an und initialisieren sie alle Elemente (incl. Substrukturelemente) bei der Definition dieser Variablen mit einen beliebigen Wert (Zur Selbstkontrolle am besten obige Debug-Funtkion nutzen!)
Hilfe: Arrays werden in C wie folgt Initialisiert:   int arr[3]={1,2,3};
c) Überlegen sie sich den benötigten Speicherbedarf, den eine Variable des Datentyps struct mainstruct belegt?
d) Alle Strukturelemente werden über einen Offset bezogen auf das erste Strukturelement angesprochen. Welchen Offset haben die einzelnen Strukturelemente?
   (Gerne als Kommentar direkt oben bei der Struktdefinition)
#endif

#if 0
3) Eine Struktur entspricht einer Klasse bei objektorientierten Sprachen. Beschreiben sie mehrere Unterschiede/Gemeinsamkeiten zwischen der Struktur in C und der Klasse in JAVA.
#endif

int main(int argc, char *argv[])
{
    
    return 0;
}