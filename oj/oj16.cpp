#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;
    for (int k = 0; k < a; ++k) {
        int n;
        cin >> n;
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        vector<int> count(n - 1, 0);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (numbers[i] >= numbers[j]) {
                    count[i - 1]++;
                }
            }
        }

        int sum = 0;
        for (int nums: count) {
            sum += nums;
        }
        cout << sum << endl;
    }
    return 0;
}