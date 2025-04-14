#include <iostream>
#include <bitset>
#include <sstream>
#include <cstdint>

std::string uint32_to_ip(uint32_t ip) {
    if (ip == 0) {
        return "0.0.0.0";
    }

    std::bitset<32> bits(ip);
    std::ostringstream oss;

    for (int i = 0; i < 4; ++i) {
        uint8_t octet = static_cast<uint8_t>((bits >> (24 - i * 8)).to_ulong());
        oss << static_cast<int>(octet);

        if (i < 3) {
            oss << ".";
        }
    }

    return oss.str();
}

int main() {
    uint32_t int32_number = 2149583361;
    std::string result = uint32_to_ip(int32_number);

    std::cout << int32_number << " ==> " << result << std::endl;

    return 0;
}
