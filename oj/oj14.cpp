#include <iostream>
#include <string>
#include <unordered_map>

bool scramble(const std::string &s1, const std::string &s2) {
    std::unordered_map<char, int> occurrences;

    for (char c: s1) {
        if (occurrences.find(c) != occurrences.end()) {
            occurrences[c]++;
        } else {
            occurrences[c] = 1;
        }
    }

    for (char c: s2) {
        if (occurrences.find(c) != occurrences.end() && occurrences[c] > 0) {
            occurrences[c]--;
        } else {
            return false;
        }
    }

    return true;
}
