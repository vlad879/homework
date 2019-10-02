#include <stdio.h> 
#include <malloc.h>
#include <string.h>

#define S 25

int main() {
int n1, n2;
int res = 0, k = 0, i, j;
char **mn1, **mn2;

printf("Введите кол-во элементов множества 1: ");
  scanf("%d", &n1);
printf("Введите кол-во элементов множества 2: ");
  scanf("%d", &n2);
printf("_______________\n");

int a1[n1],
    a2[n2];

mn1 = (char**)malloc(n1 * sizeof(char*));
    for (int i = 0; i < n1; ++i)
        mn1[i] = (char*)malloc(S * sizeof(char));
mn2 = (char**)malloc(n2 * sizeof(char*));
    for (int i = 0; i < n2; ++i)
        mn2[i] = (char*)malloc(S * sizeof(char));

printf("Ввод множества 1(двоичные числа):\n");
    for (i = 0; i < n1; ++i)
     scanf("%s", mn1[i]);

printf("_______________\n");

printf("Ввод множества 2(двоичные числа):\n");
    for (i = 0; i < n2; ++i)
     scanf("%s", mn2[i]);

        
    for (i = 0; i < n1; ++i)
    {
        k = strlen(mn1[i]);
        for (j = 0; j < k; ++j) {
        if (mn1[i][j] != '0' && mn1[i][j] != '1')
    {
        if (mn1[i][j] == '\n') break;
    }
    res = res*2+(mn1[i][j]-'0');
        }        
    a1[i] = res;
    res = 0;
    }

    printf("_______________\n");

     for (i = 0; i < n2; ++i)
    {
        k = strlen(mn2[i]);
        for (j = 0; j < k; ++j) {
        if (mn2[i][j] != '0' && mn2[i][j] != '1')
    {
        if (mn2[i][j] == '\n') break;
    }
    res = res*2+(mn2[i][j]-'0');
        }  
    a2[i] = res;
    res = 0;
    }
    

    printf("Множество 1: { ");
    for (i = 0; i < n1; ++i)
    {
        printf("%3d ",a1[i] );
    }
    printf(" }\n");


    printf("Множество 2: { ");
     for (i = 0; i < n2; ++i)
    {
        printf("%3d ",a2[i] );
    }
    printf(" }\n");
    


    for (i = 0; i < n1; ++i)
        for (j = 0; j < n2; ++j) 
            if (a1[i] == a2[j]) 
                printf("%3d", a1[i] );



   return 0;
}
