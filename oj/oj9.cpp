#include<bits/stdc++.h>

using namespace std;

int josephusSurvivor(int n, int k) {
    vector<int> peoples;
    for (int i = 0; i <= n; ++i) {
        peoples.push_back(i);
    }
    int i = 0;
    while (true) {
        i += k - 1;
        while (i >= peoples.size()) {
            i = i - peoples.size();
        }
        peoples.erase(peoples.begin() + i);
        if (peoples.size() == 1) {
            break;
        }
    }
    return peoples[0];

}
