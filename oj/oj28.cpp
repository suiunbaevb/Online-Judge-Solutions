#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

class StockList {
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories) {
        if (lstOfArt.empty() || categories.empty()) {
            return "";
        }
        std::map<std::string, int> categorySums;
        for (const std::string &book: lstOfArt) {
            std::string category = std::string(1, book[0]);
            int quantity = extractQuantity(book);
            if (std::find(categories.begin(), categories.end(), category) != categories.end()) {
                categorySums[category] += quantity;
            }
        }
        std::stringstream result;
        for (const std::string &category: categories) {
            result << "(" << category << " : " << categorySums[category] << ") - ";
        }
        std::string resultStr = result.str();
        resultStr = resultStr.substr(0, resultStr.length() - 3);
        return resultStr;
    }

private:
    static int extractQuantity(const std::string &book) {
        size_t spacePos = book.find(' ');
        if (spacePos != std::string::npos) {
            return std::stoi(book.substr(spacePos + 1));
        }
        return 0;
    }
};