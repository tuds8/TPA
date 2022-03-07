#include <stdio.h>

#define AUX 128

unsigned char v[AUX];


void SetFlag(int *n, int k) {
    (*n) = ((*n) | (1<<k));
}

void UnsetFlag(int *n, int k) {
    (*n) = (*n) & ~(1<<k);
}

int GetFlag(int n, int k) {
    ///return (1&(n >> k));
    return ((n &(1 << k)) == (1 << k));
}

int main()
{
    int x, i = 0, k = 0;
    while (scanf("%d", &x) == 1) {
        i = x / 8;
        k = 7 - (x % 8);
        v[i] = v[i] | (1 << k);
        ///SetFlag(v[i], k);
    }

    for (int i = 0; i < 128; i++) {
        if (v[i]) {
            for (int j = 7; j >= 0; j--) {
                if (GetFlag(v[i], j))
                {
                    int copie = 0;
                    copie = 8 * i + (7 - j);
                    printf("%d ", copie);
                }
            }
        }
    }
return 0;
}
