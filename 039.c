#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int *pi = (int *) malloc(sizeof(int));
    *pi = 5;
    free(pi);
    free(pi);
    system("PAUSE");
    return 0;
}