#include <iostream>
#include <string>
#include <unordered_map>

std::string duplicate_encoder(const std::string &word) {
    std::string result;
    std::unordered_map<char, int> charCount;

    for (char currentChar: word) {
        char lowerChar = std::tolower(currentChar);
        charCount[lowerChar]++;
    }

    for (char currentChar: word) {
        char lowerChar = std::tolower(currentChar);
        result += (charCount[lowerChar] == 1) ? '(' : ')';
    }

    return result;
}

//int main() {
//    std::string input;
//    std::cout << "Enter a word: ";
//    std::cin >> input;
//
//    std::string encodedString = duplicate_encoder(input);
//    std::cout << "Encoded string: " << encodedString << std::endl;
//
//    return 0;
//}
