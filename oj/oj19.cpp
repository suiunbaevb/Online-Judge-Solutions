#include <vector>
#include <algorithm>

long queueTime(std::vector<int> customers, int n) {
    std::vector<int> w(n, 0);

    for (int k : customers) {
        auto minElement = std::min_element(w.begin(), w.end());
        int idx = std::distance(w.begin(), minElement);
        w[idx] += k;
    }

    return *std::max_element(w.begin(), w.end());
}
