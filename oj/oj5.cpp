#include <string>

bool tidyNumber(int n) {
    std::string strN = std::to_string(n);

    for (int i = 0; i < strN.length() - 1; ++i) {
        if (strN[i] <= strN[i + 1]) {
            continue;
        } else {
            return false;
        }
    }

    return true;
}
