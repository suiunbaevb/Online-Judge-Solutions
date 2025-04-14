#include <iostream>
#include <string>
#include <regex>

std::string incrementString(const std::string &str) {
    std::regex regexPattern("([0-8]|\\d?9+)?$");
    std::smatch match;

    if (std::regex_search(str, match, regexPattern)) {
        std::string matchedStr = match[0];
        if (!matchedStr.empty()) {
            int number = std::stoi(matchedStr);
            number++;
            std::string incrementedStr = std::to_string(number);
            int leadingZeros = matchedStr.size() - incrementedStr.size();
            for (int i = 0; i < leadingZeros; i++) {
                incrementedStr = "0" + incrementedStr;
            }
            return str.substr(0, str.size() - matchedStr.size()) + incrementedStr;
        }
    }

    return str + "1";
}
