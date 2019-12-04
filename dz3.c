#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *num, int size)
{
  for (int i = 0; i < size - 1; i++)
    for (int j = (size - 1); j > i; j--) 
      if (num[j - 1] > num[j]) 
      {
        int temp = num[j - 1]; 
        num[j - 1] = num[j];
        num[j] = temp;
      }
}


int main()
{
  int *a;
  int n;
  int i, j, m, k = 0;

  printf("Введите количество вершин: ");
  scanf("%d", &n);

  int g[n];
  int sort[n];
  a = (int*)malloc(n*n * sizeof(int));

srand(time(NULL));
for (i = 0; i < n; ++i) { //цикл по строкам матрицы
  for (j = 0+k; j < n; ++j) { //цикл по столбцам матрицы
    if (j != i) { 
        *(a + i*n + j) = rand() % 2;
        g[j] = *(a + i*n + j);
    } else {
        *(a + i*n + j) = 0;
        g[j] = *(a + i*n + j);
      }
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
 k = 0;

//Запись матрицы смежности в graph.dot для визуализации
    FILE *file_ptr;
    FILE* f = fopen("graph.dot", "w");
    fprintf (f,"digraph test{\ngraph [bgcolor=green];\n");
    for (i = 0; i<n; i++) { 
      for (j = 0+k; j<n; j++)  
         if (*(a + i*n + j) > 0)
                    fprintf(f,"%d->%d[dir=both];\n",i,j);
          else fprintf(f,"%d\n",i);
    k++;
    }
    fprintf(f,"}");              
    fclose(f);

//поиск вершин с нечетными степенями
for (i = 0; i < n; ++i) {
  g[i] = 0;
  sort[i] = 0;
}

k = 0;
m = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      k = k + *(a + i*n + j);
    if (k % 2 != 0) {
      g[i] = k;
      sort[i] = g[i];
      m++;
    }
    k = 0;
  }
  printf("%d\n", m);

//сортировка и вывод
bubbleSort(sort,n);

for (i = 0; i < n; ++i) 
  for (j = 0; j < n; ++j)
    if ((sort[i] == g[j]) && (sort[i] != 0)) {
    printf("%d--", j);
    g[j] = -1;
    }
 
printf("\nМатрица смежности записана в graph.dot для визуализации графа\n");
free(a); 
system("dot -Tpng graph.dot -oexample1.png");

return 0;
}