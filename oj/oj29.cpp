#include<bits/stdc++.h>

using namespace std;

#define MAX 500000

typedef long long ll;
typedef unsigned long long ull;

int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dz[] = {0, 0, +1, -1, -1, +1, -1, +1};

int main() {
    char w[MAX];

    string temp;

    set<string> dic;
    set<string>::iterator it;

    while (gets(w)) {
        if (w[0] == 0)
            continue;

        for (int i = 0; w[i] != 0; i++) {
            if (isalpha(w[i]) || w[i] == '-') {
                temp += tolower(w[i]);
            } else if (isalpha(w[i]) == false && w[i] != '-')
                w[i] = 32;

            if (w[i] == 32) {
                dic.insert(temp);
                temp.clear();
            }
        }
        if (temp.size() != 0) {
            if (temp[temp.size() - 1] != '-') {
                dic.insert(temp);
                temp.clear();
            } else
                temp.erase(temp.end() - 1);
        }
    }

    it = dic.begin();

    temp = *it;

    if (temp.size() != 0)
        cout << temp << endl;

    it++;

    for (; it != dic.end(); it++)
        cout << *it << endl;

    return 0;
}