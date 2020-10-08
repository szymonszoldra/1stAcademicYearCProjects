#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)
#define MAX_LINE_LENGTH 255
FILE* txtFile;

int main() {

	if (!(txtFile = fopen("txtFile.txt", "r"))) {
		printf("Error!\n");
		exit(1);
	}
	char string[MAX_LINE_LENGTH];
	fgets(string, MAX_LINE_LENGTH, txtFile);
	printf("String to \"%s\"\nPodaj znak ktory mam usunac: \n", string);
	char character = getchar();
	int flag = 0;
	int length = 0;
	int index = 0;

	txtFile = fopen("txtFile.txt", "w");

	while (string[length] != 0) {
		if (string[length] == character && flag == 0) {
			flag = 1;
			index = length;
		}
		length++;

	}

	if (flag) {
		while (index < length) {
			string[index] = string[index + 1];
			index++;
		}
		fprintf(txtFile, "%s", string);
		printf("Pomyslnie usunieto pierwsze wystapienie znaku, zajrzyj do pliku!\n");
	}
	else {
		printf("Znak nie wystepuje w tym stringu!\n");
	}
	fclose(txtFile);
	txtFile = NULL;
	return 0;
}