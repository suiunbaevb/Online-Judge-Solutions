#include <map>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(const msv &obj) {
    std::vector<std::string> keys;
    for (auto pair: obj) keys.push_back(pair.first);
    std::sort(keys.begin(), keys.end(), [](const std::string &a, const std::string &b) -> bool {
        return std::atoi(a.c_str()) >= std::atoi(b.c_str());
    });
    std::set<char> seen;
    msv obj2;
    for (const std::string &k: keys) {
        std::vector<char> v(obj.at(k)), v2;
        for (const int &e: v) {
            if (seen.find(e) == seen.end()) {
                seen.insert(e);
                v2.push_back(e);
            }
        }
        obj2[k] = v2;
    }
    return obj2;
}