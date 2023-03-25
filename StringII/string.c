#include <stdio.h>	//fuer printf()
#include <stdlib.h> //fuer free()
#include <string.h>

// Compilerschalter: -Wall -fsanitize=address

void aufgabe1_int2str_manuell(char *dst, int zahl)
{
	// Eine Ganzzahl in einen String wandeln (ohne Nutzung von sprintf())
	// Speicher wird durch den Aufrufer reserviert
	if (zahl == 0)
	{
		dst[0] = '0';
		dst[1] = 0;
		return;
	}

	int i = 0;
	int zahl1 = zahl;
	while (zahl)
	{
		zahl /= 10;
		i++;
	}
	if (zahl1 < 0)
	{
		zahl1 *= -1;
		i++;
		dst[0] = '-';
	}

	dst[i] = 0;

	i--;

	while (zahl1)
	{
		dst[i--] = '0' + (zahl1 % 10);
		zahl1 /= 10;
	}

	//  printf("\n string: %s", dst);
}

char *aufgabe2_int2str_sprintf(int zahl)
{
	// Eine Ganzzahl in einen String wandeln (unter Nutzung von sprintf())
	// Die Speicherplatzreservierung für den Zielstring erfolgt durch die aufgerufene Funktion. Diese reserviert passend Speicher!

	int i = 0;

	int tempVar = zahl;
	while (tempVar)
	{
		tempVar /= 10;
		i++;
	}
	if (zahl <= 0)
	{
		i++;
	}

	char *newString = (char *)malloc(i + 1);
	sprintf(newString, "%i", zahl);

	return newString; // Bitte ersetzen
}

int aufgabe3_str2int(const char *str)
{
	// Den Inhalt eines Strings, welcher eine Zahl enthält in eine Integervariable wandeln (unter Nutzung von strtol())
	char *ptr;
	int ret;

	ret = strtol(str, &ptr, 10);
	// printf("the integer is %i\n", ret);
	return ret; // Bitte ersetzen
}

char *aufgabe4_strstr(char *str, char *substr)
{
	// Das erste Auftreten eines Substrings substr im String str finden.
	// Als Rückgabewert wird der String ab der gefundenen Position zurückgegeben.
	// Wenn der Substring nicht vorhanden ist, soll der Wert NULL zurückgegeben werden.
	// Das erste Auftreten eines Substrings substr im String str finden.
	// Als Rückgabewert wird der String ab der gefundenen Position zurückgegeben.
	// Wenn der Substring nicht vorhanden ist, soll der Wert NULL zurückgegeben werden.

	int strLength = strlen(str);
	int substrLength = strlen(substr);

	for (int i = 0; i <= strLength - substrLength; i++)
	{

		int j;
		int flag = 1;
		int k = i;

		for (j = 0; j < substrLength; j++, k++)
		{
			if (str[k] != substr[j])
			{
				flag = 0;
				break;
			}
		}

		if (flag)
			return str + i;
	}

	return NULL;
}

char *aufgabe5_strreplace(const char *str, const char *replace)
{
	// Den ersten Platzhalter "%s" im String str durch den Inhalt des Strings replace ersetzen.
	// Der Speicherplatzreservierung für den Zielstring erfolgt durch die aufgerufene Funktion. Diese reserviert passend Speicher!

	int k = 0;
	int i = 0;
	// for the length of the final string
	for (; str[i]; i++)
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			k = 1;
			break;
		}
	}

	//  int tempLength = strlen(replace);
	int f = strlen(str) + 1;
	if (k)
		f += strlen(replace) - 2;

	char *finalStr = (char *)malloc(f);
	int x = 0;
	for (int j = 0; str[x]; j++)
	{
		if (j == i && k)
		{
			int l = 0;
			for (int m = j; replace[l]; l++, m++)
			{
				finalStr[m] = replace[l];
			}
			j += l - 1;
			x += 2;
		}
		else
		{
			finalStr[j] = str[x];
			x++;
		}
	}
	finalStr[f - 1] = 0;
	return finalStr; // Bitte ersetzen
}

int main(int argc, char *argv[])
{
	int aufgabe = 1;
	if (argc > 1)
	{ // Optional, Aufgabeauswahl über "Execution Arguments"
		aufgabe = argv[1][0] - '0';
		if ((aufgabe < 1) || (aufgabe > 5))
			aufgabe = 1;
	}

	switch (aufgabe)
	{
	case 1:
	{
		char string[10 /*Für Stellen*/ + 1 /*Vorzeichen*/ + 1 /*Stringendezeichen*/] = "1234";
		aufgabe1_int2str_manuell(string, 123);
		// aufgabe1_int2str_manuell(string,-0);
		// aufgabe1_int2str_manuell(string,3000000000);
		printf("1. Zahl='%s'\n", string);
		break;
	}
	case 2:
	{
		char *str_ptr;
		str_ptr = aufgabe2_int2str_sprintf(98765433);
		if (str_ptr != NULL)
		{
			printf("2. Zahl='%s'\n", str_ptr);
			free(str_ptr);
		}
		break;
	}
	case 3:
	{
		int val;
		val = aufgabe3_str2int("1234");
		val = aufgabe3_str2int("   -4711");
		val = aufgabe3_str2int("34ab");
		val = aufgabe3_str2int("a123");
		printf("3. Val=%d\n", val);
		break;
	}
	case 4:
	{
		char *str_ptr;
		str_ptr = aufgabe4_strstr("1234{1}56{0}78", "{1}");
		str_ptr = aufgabe4_strstr("{1}ab{0}", "{0}");
		str_ptr = aufgabe4_strstr("abcdefg", "dd");
		printf("4. Inhalt ab gefundener Position='%s'\n", str_ptr);
		break;
	}
	case 5:
	{
		char *str_ptr;
		str_ptr = aufgabe5_strreplace("Der String %s hat keine Bedeutung", "aaa");
		// str_ptr = aufgabe5_strreplace("Der String %s hat keine Bedeutung", "'123456789'");
		//  str_ptr = aufgabe5_strreplace("%s ersetzt %s", "abc");
		// str_ptr = aufgabe5_strreplace("%s", "a");
		if (str_ptr != NULL)
		{
			printf("5. String='%s'\n", str_ptr);
			free(str_ptr);
		}
		break;
	}
	}
}