#include <stdio.h>  //fuer printf() size_t stderr
#include <stdlib.h> //fuer malloc() free()
#include <string.h> //fuer strcpy() memcpy()
#include <stdint.h> //fuer uintptr_t

// Compilerschalter: -fsanitize=address -Wall -m32
//-m32 zur Umschaltung auf eine 32-Bit Architektur

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

#if 0
//Aufgabe b)
//Kopie der Standarausgabe von debug
#endif

typedef struct vl
{
    struct vl *next;
    char data[];
} vl_t;
vl_t *head;

void vl_init(void)
{
    head = NULL;
}

void vl_close(void)
{
    // Liste durchgehen und allen Speicher löschen
}

static void vl_debug(void)
{
    printf("------------\n");
    printf("head=%p\n", head);
    if (head != NULL)
    {
        vl_t *start = head;
        vl_t *end = head;
        printf("Inhalt der Struktur:\n");
        for (vl_t *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            printf("0x%0*zx:", (int)sizeof(void *) * 2, (uintptr_t)ptr);
            printf("{.next=0x%0*zx: .data='%s'}\n", (int)sizeof(void *) * 2, ptr->next, ptr->data);
            start = start > ptr ? ptr : start;
            end = end < ptr ? ptr : end;
        }
        dump(start, (char *)end - (char *)start + sizeof(vl_t) + strlen(end->data) + 1, 16, DUMP_8A);
    }
    // Größe des benötigten Speichers berechnen
}
int vl_addfront(const char *value)
{
    vl_t *new;
    new = malloc(sizeof(vl_t) + strlen(value) + 1);
    if (new == NULL)
        return -1;
    strcpy(new->data, value);
    new->next = head;
    head = new;
    return 0;
}
int vl_addback(const char *value)
{
    return 0;
}
char *vl_getfront(void)
{
    return NULL; // Im Fehlerfall
}
char *vl_getback(void)
{
    return NULL; // Im Fehlerfall
}

const char help[] = "\n"
                    "setf <value> - Fügt <value> am Anfang der Liste ein\n"
                    "setb <value> - Fügt <value> am Ende der Liste ein\n"
                    "getf         - Gibt das erste Element zurück und\n"
                    "               entfernt dieses aus der Liste\n"
                    "getb         - Gibt das letzte Element zurück und \n"
                    "               entfernt dieses aus der Liste\n"
                    "\e[1mdebug\e[0m        - Gibt die gesamte Liste aus\n"
                    "help         - Führt alle Operationen auf.\n"
                    "\e[1mquit\e[0m         - Beendet das Programm.\n";
int main(int argc, char const *argv[])
{
    // Konstruktoren
    vl_init();
    printf("File:"__FILE__
           " erstellt am "__DATE__
           " um "__TIME__
           " gestartet\n");
    printf(help);
    while (1)
    {
        fflush(stdout);
        char input[100];
        if (fgets(input, 100, stdin) == NULL)
            break;
        char *arg1 = strtok(input, " \n\r");
        char *arg2 = strtok(NULL, " \n\r");

        if (arg1 == NULL)
        {
            continue;
        }
        else if ((strcmp(arg1, "setf") == 0) && (arg2 != NULL))
        {
            if (vl_addfront(arg2) == -1)
                printf("Fehler: Element konnte nicht eingefügt werden");
        }
        else if ((strcmp(arg1, "setb") == 0) && (arg2 != NULL))
        {
            if (vl_addback(arg2) == -1)
                printf("Fehler: Element konnte nicht eingefügt werden");
        }
        else if (strcmp(arg1, "getf") == 0)
        {
            char *ret = vl_getfront();
            if (ret != NULL)
            {
                printf("'%s'", ret);
                free(ret);
            }
            else
                printf("getfront():Error\n");
        }
        else if (strcmp(arg1, "getb") == 0)
        {
            char *ret = vl_getback();
            if (ret != NULL)
            {
                printf("'%s'", ret);
                free(ret);
            }
            else
                printf("getback():Error\n");
        }
        else if (strcmp(arg1, "debug") == 0)
        {
            vl_debug();
        }
        else if (strcmp(arg1, "help") == 0)
        {
            printf(help);
        }
        else if (strcmp(arg1, "quit") == 0)
        {
            break;
        }
        else
        {
            printf("unbekanntes Kommando\n");
        }
    }
    vl_close();
    return 0;
}

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
    //   printf("Adressbreite: %d Bytes von 0 .... %p\n",sizeof(char *),(uintptr_t)-1);
    printf("Speicherdump: %10p .. %10p Mode=%s ---", start, start + len - 1, dump_str[mode]);
    while (ptr < start + len)
    {
        // printf("\n%0*p:",sizeof(void *)*2+2,ptr);
        printf("\n0x%0*zx:", (int)sizeof(void *) * 2, (uintptr_t)ptr);
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
                    char ch = *(((unsigned char *)ptr) + lauf) & 0xFF;
                    printf("%c", ch < 0x20 ? '.' : ch);
                    break;
                case DUMP_8:
                case DUMP_16:
                case DUMP_32:
                    break;
                }
        }
        ptr += width * size;
    }
    printf("\n");
    return 0;
}