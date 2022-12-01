#include <stdio.h>     //fuer printf() size_t stderr
#include <stdlib.h>    //fuer malloc() free()
#include <string.h>    //fuer strcpy() memcpy() 
//Compilerschalter: -fsanitize=address -Wall -m32
//-m32 zur Umschaltung auf eine 32-Bit Architektur
#if 0
//Aufgabe b)
//Kopie der Standarausgabe von debug
#endif
typedef struct vl {
		struct vl *next;
		char       data[];
} vl_t;
vl_t *head;
void vl_init(void)
{
	head=NULL;
}
void vl_close(void)
{
	//Liste durchgehen und allen Speicher löschen
}
static void vl_debug(void)
{
	printf("------------\n");
	printf("head=%p\n",head);
	if(head!=NULL) {
		printf("Inhalt der Struktur:\n");
		for(vl_t *ptr=head;ptr!=NULL;ptr=ptr->next)
			printf("%p:{.next=%p: .data='%s'}\n",ptr,ptr->next,ptr->data);
		printf("Speicherdump:\n");
		for(vl_t *ptr=head;ptr!=NULL;ptr=ptr->next) {
			printf("%p:",ptr);
			unsigned char *start=(unsigned char *)ptr;
			unsigned char *end  =start+sizeof(char *)+strlen(ptr->data)+1;
			do {
				printf("%02x ",*start++);
			} while(start<end);
			printf("\n");
		}
	}
	//Größe des benötigten Speichers berechnen
}
int vl_addfront(const char *value)
{
	vl_t *new;
	new=malloc(sizeof(vl_t)+strlen(value)+1);
	if(new==NULL)
		return -1;
	return 0;
}
int vl_addback(const char *value)
{
	return 0;
}
char *vl_getback(void)
{
	return NULL;
}
 
const char help[]= "\n"
  "setf <value> - Fügt <value> am Anfang der Liste ein\n"
  "setb <value> - Fügt <value> am Ende der Liste ein\n"
  "getb         - Gibt das letzte Element zurück und \n"
  "               entfernt dieses aus der Liste\n"
  "\e[1mdebug\e[0m        - Gibt die gesamte Lite aus\n"
  "help         - Führt alle Operationen auf.\n"
  "\e[1mquit\e[0m         - Beendet das Programm.\n";
int main(int argc, char const *argv[]) {
	//Konstruktoren 
	vl_init();
	printf("File:"__FILE__ " erstellt am "__DATE__" um "__TIME__ " gestartet\n");
	printf(help);
	while(1) {
		char input[100];
		if(fgets(input, 100, stdin)==NULL)
			break;
		char *arg1 = strtok(input, " \n\r");
		char *arg2 = strtok(NULL, " \n\r");
		
		if(arg1==NULL) {
			continue;
		}
		else if((strcmp(arg1,"setf")==0) && (arg2!=NULL)) {
			if(vl_addfront(arg2) == -1)
				printf("Fehler: Element konnte nicht eingefügt werden");
		}
		else if((strcmp(arg1,"setb")==0) && (arg2!=NULL)) {
			if(vl_addback(arg2) == -1)
				printf("Fehler: Element konnte nicht eingefügt werden");
		}
		else if(strcmp(arg1,"getb")==0)  {
			char *ret=vl_getback();
			if(ret!=NULL) {
				printf("'%s'",ret);
				free(ret);
			}
		}
		else if(strcmp(arg1,"debug")==0) {
			vl_debug();
		}
		else if(strcmp(arg1,"help")==0) {
			printf(help);
		}
		else if(strcmp(arg1,"quit")==0) {
			break;
		}
		else {
			printf("unbekanntes Kommando\n");
		}
	}
	vl_close();
	return 0;
}
