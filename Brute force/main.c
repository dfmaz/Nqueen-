// Nqueen - Brute force. Daniel Fernández Martínez.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

# define N 4

int place_queen(int []);
void brute(int []);
int row[N];
int count1 = 0;
int count2 = 0;

int main() {
    brute(row);
    return 0;
}

void brute(int sample[]) {
    for (int i = 0; i<N; i++)
    {
        sample[0] = i;
        for (int j = 0; j<N; j++)
        {
            sample[1] = j;
            for (int k = 0; k<N; k++)
            {
                sample[2] = k;
                for (int l=0; l<N; l++)
                {
                    count1++;
                    sample[3] = l;
                    if (place_queen(sample))
                    {
                        count2++;
                        printf("Solution %d:\n", count2);
                        printf("%d%d%d%d\n\n", i+1, j+1, k+1, l+1);
                    }
                }
            }
        }
    }
    printf("\nTotal configurations: %d\n", count1);
    printf("Valid configurations: %d\n", count2);
}

int place_queen(int perm[N])
{
    int i, j;
    for (i=0; i<N; i++)
    {
        for (j=i+1; j<N; j++) {
            if ((perm[i] == perm[j]) || (abs(perm[i]-perm[j])) == abs(i-j))
                return false;
        }
    }
    return true;
}
