#include <vector>

std::vector<int> move_zeroes(const std::vector<int> &arr) {
    std::vector<int> result(arr.size(), 0);
    int nonZeroIndex = 0;


    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != 0) {
            result[nonZeroIndex++] = arr[i];
        }
    }

    return result;
}