#include <string>
#include <bitset>
#include <cmath>

std::string whitespace_number(int n) {
    std::string s = std::bitset<32>(abs(n)).to_string(), str = "";
    s.erase(0, s.find('1'));
    str += (n < 0) ? '\t' : ' ';
    for (auto a: s)
        str += std::string(1, a == '0' ? ' ' : '\t');
    str += '\n';
    return str;
}