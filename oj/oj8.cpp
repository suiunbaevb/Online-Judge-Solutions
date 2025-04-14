#include <vector>

struct PeaksResult {
    std::vector<int> pos;
    std::vector<int> peaks;
};

PeaksResult pickPeaks(const std::vector<int> &arr) {
    PeaksResult result;
    int position = -1;  // Initialize position to -1

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            position = i;
        } else if (arr[i] < arr[i - 1] && position != -1) {
            result.pos.push_back(position);
            result.peaks.push_back(arr[position]);
            position = -1;  // Reset position to -1
        }
    }

    return result;
}
