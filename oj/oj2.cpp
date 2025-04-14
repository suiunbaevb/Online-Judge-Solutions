#include <vector>

std::vector<std::vector<int>>
matrixAddition(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
    std::vector<std::vector<int>> result = a; // Make a copy of matrix 'a'

    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}
