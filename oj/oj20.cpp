#include <bits/stdc++.h>
using namespace std;
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    map<int, int> countMap; // Map to store the count of each element
    vector<int> result; // Result vector

    for (int element : arr) {
        if (countMap[element] < n) {
            result.push_back(element);
            countMap[element]++;
        }
    }

    return result;
}
int main() {
    vector<int> modified = deleteNth({1,1,3,3,7,2,2,2,2}, 3);

    for (int element : modified) {
        cout << element << " ";
    }

    return 0;
}