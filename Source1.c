#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

int main() {

  setlocale(LC_ALL, "Rus");

  int i = 0, n = 0;
  double min = 0.0, max = 0.0;
  double* a;
	FILE* fnumbers = 0;

	printf("¬ведите n (кол-во случайных чисел): \t"); //кол-во чисел
	scanf_s("%d", &n);
	if (n <= 0)
	{
		printf("ќшибка! «начение n должно быть больше нул€.\n");
		return 0;
	}

	printf("¬ведите min (мин. значение диапазона): \t"); //минимальное значение
	scanf_s("%lf", &min);

	printf("¬ведите max (макс. значение диапазона): \t"); //максимальное значение
	scanf_s("%lf", &max);
	if (max < min)
	{
		printf("ќшибка! min должно быть больше max.\n");
		return 0;
	}

	a = (double*)malloc(n * sizeof(double));//массив дл€ рандомных чисел
	if (a == 0)
	{
		printf("ќшибка 1!\n");
		return 0;
	}

	fnumbers = fopen("C:\\Users\\Administrator\\Desktop\\numbers.txt", "w");
	for (i = 0; i < n; i++)
	{
		a[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;//забиваю массив
		fprintf(fnumbers, "%lf\n", a[i]);
	}
	fclose(fnumbers);
	free(a);
	return 0;
}