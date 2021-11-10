#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>

//счет строк в файле
int sc(FILE* fnumbers) {
  int result = 0;
  rewind(fnumbers);
  while (!ferror(fnumbers) && !feof(fnumbers)) {
    if (fgetc(fnumbers) == '\n') ++result;
  }
  return result;
}

//сортировка вставками
void InsertionSort(int n, double a[])
{
  int location;
  double newElement;

  for (int i = 1; i < n; i++)
  {
    newElement = a[i];
    location = i - 1;
    while (location >= 0 && a[location] > newElement)
    {
      a[location + 1] = a[location];
      location = location - 1;
    }
    a[location + 1] = newElement;
  }
}

//Быстрая сортировка
void qs(double* items, int left, int right) {
  int i, j;
  double x, y;

  i = left;
  j = right;
  x = items[(left + right) / 2];
  do
  {
    while ((items[i] < x) && (i < right))
      i++;
    while ((x < items[j]) && (j > left))
      j--;
    if (i <= j)
    {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j) 
    qs(items, left, j);
  if (i < right)
    qs(items, i, right);
}

int main() {

  setlocale(LC_ALL, "Rus");

  FILE* fnumbers;
  int i = 0, j = 0, n = 0, cmd = 0, sort = 0;
  double b = 0.0;
  double* a;
  double* mass;

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
        for (i = 0; i < n - 1; i++) 
        {
          for (j = 0; j < n - i - 1; j++) 
          {
            if (a[j] > a[j + 1]) 
            {
              double tmp = a[j];
              a[j] = a[j + 1];
              a[j + 1] = tmp;
            }
          }
        }
        clock_t end = clock();
        printf("Время, занятое сортировкой: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
      }

      else if (sort == 2) //сортировка вставкой
      {
        rewind(fnumbers);
        clock_t start = clock();
        for (i = 0; i < n; i++)
        {
          InsertionSort(n, a);
        }
        clock_t end = clock();
        printf("Время, занятое сортировкой: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
      }

      else if (sort == 3) //быстрая сортировка
      {
        clock_t start = clock();
        qs(a, 0, n - 1);
        clock_t end = clock();
        printf("Время, занятое сортировкой: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
      }
    }

    else if (cmd == 3)
    {
      rewind(fnumbers);
      for (i = 0; i < n; i++)
      {
        fscanf_s(fnumbers, "%lf", &a[i]);
      }
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