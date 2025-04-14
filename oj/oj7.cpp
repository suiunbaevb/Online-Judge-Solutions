#include <vector>

std::vector<int> snail(std::vector<std::vector<int>> &arr) {
    std::vector<int> finalArray;
    while (!arr.empty()) {
        finalArray.insert(finalArray.end(), arr[0].begin(), arr[0].end());
        arr.erase(arr.begin());

        for (auto &row: arr) {
            if (!row.empty()) {
                finalArray.push_back(row.back());
                row.pop_back();
            }
        }

        if (!arr.empty()) {
            std::reverse(arr.begin(), arr.end());
            for (auto &row: arr) {
                std::reverse(row.begin(), row.end());
            }
        }
    }
    return finalArray;
}
