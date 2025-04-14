#include <iostream>
#include <string>
#include <vector>

std::string format_duration(int seconds) {
    std::vector<std::pair<std::string, int>> time = {
            {"year",   31536000},
            {"day",    86400},
            {"hour",   3600},
            {"minute", 60},
            {"second", 1}
    };
    std::vector<std::string> res;

    if (seconds == 0) {
        return "now";
    }

    for (const auto &entry: time) {
        const std::string &key = entry.first;
        int value = entry.second;

        if (seconds >= value) {
            int val = seconds / value;
            res.push_back(std::to_string(val) + (val > 1 ? " " + key + "s" : " " + key));
            seconds = seconds % value;
        }
    }

    if (res.size() > 1) {
        std::string result = "";
        for (size_t i = 0; i < res.size(); ++i) {
            if (i == res.size() - 1) {
                result += " and " + res[i];
            } else {
                if (!result.empty()) {
                    result += ", ";
                }
                result += res[i];
            }
        }
        return result;
    } else {
        return res[0];
    }
}