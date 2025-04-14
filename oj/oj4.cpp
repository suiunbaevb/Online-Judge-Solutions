#include <vector>

int solve(const std::vector<int> &arr) {
    for (int a: arr) {
        if (std::find(arr.begin(), arr.end(), -a) == arr.end()) {
            return a;
        }
    }
    // Return a default value or handle the case where no solution is found.
    // In this simplified translation, we're not handling this case.
    return 0; // Change this return value if needed.
}
