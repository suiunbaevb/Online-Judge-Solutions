#include <cstdio>
#include <iostream>
using namespace std;

int a, n, trackLen[20];
int ans, totalNear;

void choose(int total, int mask, int p) {
    if (total > a)
        return;
    if (total > totalNear) {
        totalNear = total;
        ans = mask;
    }
    if (p >= n)
        return;

    choose(total + trackLen[p], mask | (1 << p), p + 1);
    choose(total, mask, p + 1);
}

int main() {
    while (scanf("%d %d", &a, &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &trackLen[i]);
        }

        ans = -1;
        totalNear = -1;
        choose(0, 0, 0);

        for (int i = 0; i < n; i++) {
            if ((ans >> i) % 2)
                printf("%d ", trackLen[i]);
        }
        printf("sum:%d\n", totalNear);
    }

    return 0;
}