#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include "Header.h"

//счет строк в файле
int sc(FILE* fnumbers) {
  int result = 0;
  rewind(fnumbers);
  while (!ferror(fnumbers) && !feof(fnumbers)) {
    if (fgetc(fnumbers) == '\n') ++result;
  }
  return result;
}

int main() {

  setlocale(LC_ALL, "Rus");

  FILE* fnumbers;
  int i = 0, j = 0, n = 0, cmd = 0, sort = 0;
  double b = 0.0;
  double* a;
  double t = 0;

  fnumbers = fopen("C:\\Users\\Administrator\\Desktop\\numbers.txt", "r");

  n = sc(fnumbers); //подсчет кол-ва строк

  a = (double*)malloc(n * sizeof(double));
  if (a == 0)
  {
    printf("Ошибка 1!\n");
    return 0;
  }

  rewind(fnumbers);
  for (i = 0; i < n; i++)
  {
    fscanf_s(fnumbers, "%lf", &a[i]);
  }

  do
  {
    printf("Выберите действие:\n1. Печать\n2. Сортировка\n3. Сброс\n4. Выход\n");
    printf("Введите № команды: ");
    scanf_s("%d", &cmd);

    if (cmd == 1)
    {
      for (i = 0; i < n; i++)
      {
        printf("a[%d] = %lf\n", i, a[i]);
      }
    }

    else if (cmd == 2)
    {
      printf("Выберите метод сортировки:\n1. Пузырьком\n2. Вставкой\n3. Быстрая\n");
      printf("Введите № сортировки: ");
      scanf_s("%d", &sort);
      if (sort == 1)  //сортировка пузырьком
      {
        clock_t start = clock();
        BubbleSort(n, a);
        clock_t end = clock();
        t = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время, занятое сортировкой: %lf\n", t);
      }

      else if (sort == 2) //сортировка вставкой
      {
        rewind(fnumbers);
        clock_t start = clock();
        InsertionSort(n, a);
        clock_t end = clock();
        t = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время, занятое сортировкой: %lf\n", t);
      }

      else if (sort == 3) //быстрая сортировка
      {
        clock_t start = clock();
        qs(a, 0, n - 1);
        clock_t end = clock();
        t = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время, занятое сортировкой: %lf\n", t);
      }
    }

    else if (cmd == 3)
    {
      rewind(fnumbers);
      for (i = 0; i < n; i++)
      {
        fscanf_s(fnumbers, "%lf", &a[i]);
      }
      printf("Массив сброшен к исходному.\n");
    }

    else if (cmd == 4)
    {
      printf("Завершение работы.\n");
    }

    else
    {
      printf("Error.\n");
    }
  } while (cmd != 4);
  fclose(fnumbers);
  free(a);
  return 0;
}
