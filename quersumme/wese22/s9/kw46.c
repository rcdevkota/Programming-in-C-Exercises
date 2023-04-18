#include <stdio.h>	//fuer printf() size_t stderr
#include <stdlib.h> //fuer malloc() free()
#include <string.h> //fuer strcpy() memcpy()
// Compilerschalter: -fsanitize=address -Wall -m32
//-m32 zur Umschaltung auf eine 32-Bit Architektur
#if 0
//Aufgabe b)
//Kopie der Standarausgabe von debug

// head=0xf5600730 
// Inhalt der Struktur:
// 0xf5600730:{.next=0xf56007b0: .data='test'}
// 0xf56007b0:{.next=0xf5600790: .data='test1'}
// 0xf5600790:{.next=0xf5600770: .data='test2'}
// 0xf5600770:{.next=0xf5600750: .data='test3'}
// 0xf5600750:{.next=(nil): .data='test4'}
// Speicherdump:
// 0xf5600730:b0 07 60 f5 74 65 73 74 00 
			  // the first 4 bytes are pointer to next node
						  //next 4 bytes are string in data
						  //00 is end of string 
// 0xf56007b0:90 07 60 f5 74 65 73 74 31 00 
// 0xf5600790:70 07 60 f5 74 65 73 74 32 00 
// 0xf5600770:50 07 60 f5 74 65 73 74 33 00 
// 0xf5600750:00 00 00 00 74 65 73 74 34 00
			//here the first 4 bytres are NULL because its the last node and doesnot have
			// pointer value to the next node
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
	// Liste durchgehen und allen Speicher l�schen
	vl_t *node = head;
	while (node != NULL)
	{
		head = node->next;
		free(node);
		node = head;
	}
}
static void vl_debug(void)
{
	printf("------------\n");
	printf("head=%p\n", head);
	if (head != NULL)
	{
		printf("Inhalt der Struktur:\n");
		for (vl_t *ptr = head; ptr != NULL; ptr = ptr->next)
			printf("%p:{.next=%p: .data='%s'}\n", ptr, ptr->next, ptr->data);
		printf("Speicherdump:\n");
		for (vl_t *ptr = head; ptr != NULL; ptr = ptr->next)
		{
			printf("%p:", ptr);
			unsigned char *start = (unsigned char *)ptr;
			unsigned char *end = start + sizeof(char *) + strlen(ptr->data) + 1;
			do
			{
				printf("%02x ", *start++);
			} while (start < end);
			printf("\n");
		}
	}
	// Gr��e des ben�tigten Speichers berechnen
}
int vl_addfront(const char *value)
{
	vl_t *new;
	new = malloc(sizeof(vl_t) + strlen(value) + 1);
	if (new == NULL)
		return -1;
	strcpy(new->data, value);
	if (head == NULL)
	{
		head = new;
		head->next = NULL;
	}
	else
	{
		new->next = head;
		head = new;
	}
	return 0;
}
int vl_addback(const char *value)
{
	vl_t *new;
	new = malloc(sizeof(vl_t) + strlen(value) + 1);
	if (new == NULL)
		return -1;
	strcpy(new->data, value);
	new->next = NULL;
	vl_t *node;
	node = head;
	if (node == NULL)
	{
		head = new;
		return 0;
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = new;
	return 0;
}
char *vl_getback(void)
{
	vl_t *node;
	vl_t *nextNode;

	node = head;
	if (node != NULL)
	{
		nextNode = node->next;
		while (nextNode->next != NULL)
		{ // 1 -> 2 -> 3 -> 4 -> NULL
			node = nextNode;
			nextNode = nextNode->next;
		}
		node->next = NULL;
		char *lastData = nextNode->data;
		free(nextNode);
		return lastData;
	}

	return NULL;
}

const char help[] = "\n"
					"setf <value> - F�gt <value> am Anfang der Liste ein\n"
					"setb <value> - F�gt <value> am Ende der Liste ein\n"
					"getb         - Gibt das letzte Element zur�ck und \n"
					"               entfernt dieses aus der Liste\n"
					"\e[1mdebug\e[0m        - Gibt die gesamte Lite aus\n"
					"help         - F�hrt alle Operationen auf.\n"
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
				printf("Fehler: Element konnte nicht eingef�gt werden");
		}
		else if ((strcmp(arg1, "setb") == 0) && (arg2 != NULL))
		{
			if (vl_addback(arg2) == -1)
				printf("Fehler: Element konnte nicht eingef�gt werden");
		}
		else if (strcmp(arg1, "getb") == 0)
		{
			char *ret = vl_getback();
			if (ret != NULL)
			{
				printf("'%s'", ret);
				free(ret);
			}
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
