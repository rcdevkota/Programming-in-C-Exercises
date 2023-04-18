#include <stdio.h>

#include <string.h>
#include <stdint.h> //fuer uintptr_t
// Compilerschalter: keine
typedef enum
{
    DUMP_8,
    DUMP_16,
    DUMP_32,
    DUMP_8A,
    DUMP_16A,
    DUMP_32A,
} DUMP_MODE;

int dump(void *start, size_t len, int width, DUMP_MODE mode);
typedef struct
{
    int x, y, z;
} xyz_t;
typedef union
{
    int a;
    short b;
    char c;
} abc_t;
// Bitte als globale Variablen belassen
int vari1 = 0x01234567;
short vars1 = 0x89ab;
short vars2 = 0xcdef;
char varc1 = 'a';
char varc2 = 49;
char varc3 = 50;
char varc4 = '\a';
int vari2 = 'a';
char varc5a[16] = "abcdefghijklmno";
xyz_t varxyz = {-2, -3, -4};
abc_t varabc = {.c = 3};
unsigned int *ptri = (unsigned int *)0x0001;
unsigned short *ptrs = (unsigned short *)0x0100;
unsigned char *ptrc = (unsigned char *)0x010000;
xyz_t *ptrxyz = (xyz_t *)-4;
abc_t *ptrabc = (abc_t *)-5;
void func_value(int vari)
{
    vari = 7;
}
void func_reference(unsigned int *ptri)
{
    *ptri = 7;
}
void func_ptrptr(unsigned int **pptri)
{
    *pptri = (unsigned int *)&vari2;
}
void func_return(void)
{
    unsigned int lokale = 4711;
    ptri = &lokale;
}
int main(void)
{
    // 1) Nachfolgende Funktion stellt den Speicherbereich rund um die oben
    //    definierten globalen Variablen dar. Fügen sie den DUMP-Ausdruck
    //    hier in den Kommentarbereich ein und kommentieren sie, welche
    //    Inhalte/Bytes zu welchen Variablen gehören
    dump(&vari1, (void *)&ptrabc - (void *)&vari1 + sizeof(ptrabc), 8, DUMP_8A);

// 2) Führen sie nachfolgende Befehle im Block aus
//    Überlegen sie sich vor Ausführung auf Basis des Speicherdumps
//    aus der vorherigen Aufgabe die dargestellten Werte für die
//    Dereferenzierung
//    Erklären sie für die markierten Zeilen, wie sich der Wert der
//    Pointervariablen zusammensetzt und woher der Inhalt
//    bei der Dereferenzierung stammt
#if 1
    printf("Adresse von vari1:%p\n", &vari1);
    ptrc = (unsigned char *)&vari1;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 1;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 2;
    printf("%02hhx\n", *ptrc); //<<<<
    ptrc = ((unsigned char *)&vari1) + 3;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 4;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 5;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 6;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 7;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 8;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 9;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 10;
    printf("%02hhx\n", *ptrc);
    ptrc = ((unsigned char *)&vari1) + 11;
    printf("%02hhx\n", *ptrc);
#elif 0
    printf("Adresse von vari1:%p\n", &vari1);
    ptrs = (unsigned short *)&vari1;
    printf("%04hx\n", *ptrs);
    ptrs = ((unsigned short *)&vari1) + 2;
    printf("%04hx\n", *ptrs);
    ptrs = ((unsigned short *)&vari1) + 3;
    printf("%04hx\n", *ptrs); //<<<<
    ptrs = ((unsigned short *)&vari1) + 4;
    printf("%04hx\n", *ptrs);
    ptrs = ((unsigned short *)&vari1) + 5;
    printf("%04hx\n", *ptrs);
#elif 0
    printf("Adresse von vari1:%p\n", &vari1);
    ptri = &vari1;
    printf("%08x\n", *ptri);
    ptri = &vari1 + 1;
    printf("%08x\n", *ptri); //<<<<
    ptri = &vari1 + 2;
    printf("%08x\n", *ptri);
#endif
// 3) Führen sie nachfolgende Zeilen einzeln durch.
//    Erklären sie, wie sich der Wert der
//    Pointervariablen zusammensetzt und
//    welche Adresse in der Tat dereferenziert wird.
//    Als Hilfestellung nutzen sie die 'Liste der Prioritäten'
//    https://de.wikibooks.org/wiki/C-Programmierung:_Liste_der_Operatoren_nach_Priorit%C3%A4t
//    Einige der Dereferenzierung schlagen fehl. Begründen sie, warum diese fehlschlagen
#if 0
//                                     printf("%02hhx\n",*ptrc);
//ptrc=(unsigned char *)0x100;         printf("%02hhx\n",*ptrc);
//ptrc=(unsigned char *)&vari1;        printf("%02hhx\n",*ptrc);     
//ptrc=(unsigned char *)&vari1+1;      printf("%02hhx\n",*ptrc);
//ptrc=(unsigned char *)(&vari1+1);    printf("%02hhx\n",*ptrc);   
//ptrc=(unsigned char *)&vari1;        printf("%02hhx\n",*ptrc+1);  
//ptrc=(unsigned char *)&vari1;        printf("%02hhx\n",*(ptrc+1)); 
//ptrc=(unsigned char *)(&vari1-100);  printf("%02hhx\n",*ptrc);   
//ptrc=(unsigned char *)(&vari1+4096); printf("%02hhx\n",*ptrc);
#endif

// 4) Lassen sie sich die Inhalte der Variablen vari1..varc4 vor und nach
//    der Ausführung folgender Anweisungen ausgeben
//    Begründen sie die Änderungen, die hier stattfinden
#if 0
  ptrxyz=(xyz_t  *)& vari1;
  ptrxyz->x=0x01234567;   
  ptrxyz->y=0x00020002; 
  ptrxyz->z=0x01020403;
#endif
// 5) Wie müssten  die  Variablen   vars2.. varc5a initialisiert  werden,
//   damit  nachfolgende  Bedingung  erfüllt ist
#if 0
  ptrxyz=(xyz_t*)& vars2;
  if((ptrxyz->x==1)  &&  (ptrxyz->y==-1)  && (ptrxyz->z==0x48495051))
        printf("True");
#endif
// 6) Erklären sie, wie der dargestellte Speicherdump 'zustandekommt'
#if 0
  varabc.a=0x11111111;
  varabc.b=0x22222222;
  varabc.c=0x33333333;
  dump(&varabc,4,4,DUMP_8);
#endif
// 7) Welche  Auswirkung  hat  der  Aufruf  der einzelnen  Funktionen  auf
//    die  zuvor  initialisierten globalen Variable/Pointer.
#if 0
  unsigned int vari1=1;
  func_value( vari1);
#elif 0
    unsigned int vari1 = 1;
    func_reference(&vari1);
#elif 0
    unsigned int vari1 = 1;
    ptri = &vari1;
    func_reference(ptri);
#elif 0
    ptri = (unsigned int *)&vari1;
    func_ptrptr(&ptri);
#endif
// 8) Erklären sie, warum bei den beiden printf Ausgabe unterschiedliche
//    Werte ausgegeben werden, obwohl ptri nur einmal gesetzt wird!
#if 0
volatile unsigned int lok=0;
func_return();
lok=*ptri;
fprintf(stderr,"1.Lauf Value=%u\n",lok);  
func_value(1111);
lok=*ptri;
fprintf(stderr,"2.Lauf Value=%u\n",lok);
#endif
// 9) Erklären sie anhand des Speicherdumps die Ausgabe nachfolgender printf Anweisung
#if 1
    printf("'%s'\n", &varc1);
#endif

    fprintf(stderr, "Main erfolgreich durchgelaufen");
    return 0;
}
/*---------------------------------------------------------------------------------------------*/
static char *dump_str[] = {
    "8-Bit",
    "16-Bit",
    "32-Bit",
    "8-Bit",
    "16-Bit",
    "32-Bit",
};
// Bei Nutzung dieser Funktion darf der Compiler-Schalter -Fsanitze=address nicht genutzt werden
int dump(void *start, size_t len, int width, DUMP_MODE mode)
{
    void *ptr;
    uintptr_t size;
    switch (mode)
    {
    case DUMP_8:
    case DUMP_8A:
        size = 0x01;
        break;
    case DUMP_16:
    case DUMP_16A:
        size = 0x02;
        break;
    case DUMP_32:
    case DUMP_32A:
        size = 0x04;
        break;
    default:
        fprintf(stderr, "Illegal Mode\n");
        return -1;
    }
    ptr = (void *)((uintptr_t)start & ~(size - 1));
    //  printf("Adressbreite: %d Bytes von 0 .... %p\n",sizeof(char *),(uintptr_t)-1);
    printf("--- Dump %10p .. %10p Mode=%s ---", start, start + len - 1, dump_str[mode]);
    while (ptr < start + len)
    {
        printf("\n0x%0*zx:", (int)sizeof(void *) * 2 + 2, (uintptr_t)ptr);
        for (int lauf = 0; lauf < width; lauf++)
            switch (mode)
            {
            case DUMP_8:
            case DUMP_8A:
                printf(" %02x", *(((unsigned char *)ptr) + lauf) & 0xFF);
                break;
            case DUMP_16:
            case DUMP_16A:
                printf(" %04x", *(((unsigned short *)ptr) + lauf) & 0xFFFF);
                break;
            case DUMP_32:
            case DUMP_32A:
                printf(" %08x", *(((unsigned int *)ptr) + lauf));
                break;
            }
        if ((mode == DUMP_8A) || (mode == DUMP_16A) || (mode == DUMP_32A))
        {
            printf(" - ");
            for (int lauf = 0; lauf < (width * size); lauf++)
                switch (mode)
                {
                case DUMP_8A:
                case DUMP_16A:
                case DUMP_32A:
                    printf("%c", *(((unsigned char *)ptr) + lauf) & 0xFF);
                    break;
                case DUMP_8:
                case DUMP_16:
                case DUMP_32:
                    break;
                }
        }
        ptr += width * size;
    }
    printf("\n----------\n");
    return 0;
}