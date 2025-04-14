#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
int main() {
    scanf("%*d");
    int a, b, n;
    while(scanf("%d %d", &a, &b) == 2) {
        map<int, int> r;
        while(a--)
            scanf("%d", &n), r[n]++;
        while(b--)
            scanf("%d", &n), r[n]--;
        n = 0;
        for(map<int,int>::iterator it = r.begin();
            it != r.end(); it++)
            n += abs(it->second);
        printf("%d\n", n);
    }
    return 0;
}