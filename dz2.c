#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main()
{
  int *a;
  int n;
  int i, j, m, k = 0;

  printf("Введите количество вершин: ");
  scanf("%d", &n);

  int g[n];
  a = (int*)malloc(n*n * sizeof(int));

srand(time(NULL));
for (i = 0; i < n; ++i) { //цикл по строкам матрицы
  for (j = 0+k; j < n; ++j) //цикл по столбцам матрицы
    if (j != i) { 
        *(a + i*n + j) = rand() % 2;
        g[j] = *(a + i*n + j);
    } else {
        *(a + i*n + j) = 0;
        g[j] = *(a + i*n + j);
      }
      ++k;
  for (m = k-1; m < n; ++m)
     *(a + m*n + (k-1)) = g[m];
}

// Вывод матрицы смежности
  for (i = 0; i<n; i++) 
  {
    for (j = 0; j<n; j++)  
      printf("%d ", *(a + i*n + j));
      printf("\n");
  }

//Запись матрицы смежности в txt для визуализации
    FILE *file_ptr;
    FILE* f = fopen("graph.txt", "w");
    for (i = 0; i<n; i++) 
    {
      for (j = 0; j<n; j++)  
        fprintf(f,"%d ", *(a + i*n + j) );
        fprintf(f, "\n");
    }                       
    fclose(f);

//Проверка графа на связность(по формуле)

int reb = 0; //кол-во рёбер

for (i = 0; i<n; i++) 
    for (j = 0; j<n; j++)  
        reb = reb + *(a + i*n + j);

    k = 0.5*(n-1)*(n-2);
    if (reb>k)
        printf ("Граф связный\n");
    if (reb<=k)
        printf ("Граф не связный\n");

printf("Матрица смежности записана в graph.txt для визуализации графа\n");

free(a); 

return 0;
}