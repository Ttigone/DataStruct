#include <stdio.h>
#include <stdlib.h>
#define max 100
int keepnum[max];
struct a {
    int num;
    int count;
};

int main()
{
    for (int j = 1; j < 1000; ++j) {
        int count = 0;
        for (int i = 1; i < j; ++i) {
            if (j % i == 0){
                keepnum[count++] = i;
            }
        }
        int sum = 0;
        for (int k = 0; k < count; ++k) {
            sum += keepnum[k];
        }
        if (sum == j) {
            printf("%d its factors are ", j);
            for (int l = 0; l < count; ++l) {
                printf("%d ", keepnum[l]);
            }
            printf("\n");
        }
    }
    system("pause");
}

