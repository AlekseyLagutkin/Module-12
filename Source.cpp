#include <iostream>

int IsKPeriodic(const char* str, int k)
{
	int n=0;
	while (str[n] != '\0')   //Вычисление размера строки
	{
		n++;
	}
	int i;
	int j;
	if ((n % k) || (n < k) || (k <= 0))   //Завершение работы функции, если задано некорректное К
	{
		return -1;
	}
	int m = n / k;
	char* a = new char[k];   //Временный массив размером К
	printf("a\tstr\n");
	for (i = 0; i < k; i++)    //Запись первых К элементов строки в массив
	{
		a[i] = str[i];
		printf("%c\t %c\n", a[i], str[i]);   
	}
	for (i = k; i < n; i = i + k)   //Проход по строке с шагом К
	{
		for (j = 0; j < k; j++)   //Сравнение первых К элементов со строкой
		{
			printf("%c\t %c\n", a[j], str[i + j]);
			if (a[j] != str[i + j])   //Выход из функции, если хотя бы один элемент не совпадает
			{
				delete[] a;
				return -1;
			}
		}
	}
	delete[] a;
	return m;   //Возврат кратности строки, если все элементы совпали
}

int main()
{
	int x;
	int k = 4;
	const char* s1{ "cdefcdefcdef" };
	x = IsKPeriodic(s1, k);
	printf("Result = %d\n", x);
	return 0;
}