#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>

uint32_t ip_to_int32(const std::string &ip) {
    std::vector<std::string> octets;
    std::istringstream iss(ip);
    std::string octet;

    while (std::getline(iss, octet, '.')) {
        octets.push_back(octet);
    }

    uint32_t result = 0;
    for (const auto &octet : octets) {
        result = result * 256 + std::stoi(octet);
    }

    return result;
}

int main() {
    std::string ip_address = "128.32.10.1";
    uint32_t result = ip_to_int32(ip_address);

    std::cout << "ip_to_int32(\"" << ip_address << "\") => " << result << std::endl;

    return 0;
}
