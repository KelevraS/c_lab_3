#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <stdlib.h>

void getPath(char output[256], int bufSize)
{
	char input_path[256] = "\0";
	char iterated_path[256] = "\0";
	char filename[256] = "\0";

	char* next_token = NULL;

	printf_s("Input path:\n");
	scanf_s("%255s", input_path, (unsigned)_countof(input_path));

	char* token = strtok_s(input_path, "\\", &next_token);

	while (token != NULL) {
		strcat_s(iterated_path, 256, token);
		strcat_s(iterated_path, 256, "\\");
		_mkdir(iterated_path);
		token = strtok_s(NULL, "\\", &next_token);
	}

	printf_s("Input filename:\n");
	scanf_s("%255s", filename, (unsigned)_countof(filename));

	strcat_s(iterated_path, (unsigned)_countof(iterated_path), filename);
	strcat_s(output, bufSize, iterated_path);
}