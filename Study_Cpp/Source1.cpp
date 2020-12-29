#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int dump(char* first_memory, int size_arr);



int main(void)
{
	char name[] = "Qwerty\%с";
	int i; // Счётчик
	char* c; // Указатель на 1 байт массива
	int size_arr; // Размер массива


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	c = &name[0];


	printf_s("Вывод массива\n");
	for (i = 0; i < (sizeof(name) / sizeof(name[0])); i++)
	{

		printf_s("%c", name[i], 1);

	}

	printf_s("\nРазмер массива в байтах = %d", sizeof(name));
	size_arr = sizeof(name);
	printf_s("\nКоличество элементов в массиве = %d", sizeof(name) / sizeof(name[0]));

	dump(c, size_arr);


	_getch();
	return 0;
}

#include <stdio.h>

extern string;

int dump(char* first_memory, int size_arr)
{

	printf("\nЗначение байта");
	printf("\n%X", first_memory);

	return 0;
}
