#include <iostream>
#include <vector>

int main() {
    int s, n;
    std::cin >> s >> n;
    std::vector<std::pair<int, int>> list;

    // State 0 = hand folded, 1 = fist, 2 = palm down

    // Create ((0,1),(0,2),...,(0,n))
    for (int i = 1; i <= n; i++) {
        list.push_back(std::make_pair(0, i));
    }

    int index = 0;

    while (list.size() > 1) {
        index = (index + s - 1) % list.size();

        if (list[index].first == 0) {
            list[index].first = 1;
            // Add {1, x} into the position index
            list.insert(list.begin() + index, std::make_pair(1, list[index].second));
        } else if (list[index].first == 1) {
            list[index].first = 2;
            index += 1;
        } else {
            // Remove list[index]
            list.erase(list.begin() + index);
        }
    }

    std::cout << list[0].second << std::endl;

    return 0;
}
