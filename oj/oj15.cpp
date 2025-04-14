#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>

long long nextBigger(long long n) {
    try {
        std::string n_str = std::to_string(n);
        std::vector<char> d;
        for (char c: n_str) {
            d.push_back(c);
        }

        int p = -1;
        for (int i = d.size() - 1; i > 0; i--) {
            if (d[i] > d[i - 1]) {
                p = i - 1;
                break;
            }
        }

        if (p == -1) return -1;

        std::vector<char> right(d.begin() + p, d.end());
        char pv = right[0];
        right.erase(right.begin());

        char mm = 0;
        int mmi = -1;
        for (int i = 0; i < right.size(); i++) {
            if (right[i] > pv) {
                if (mmi == -1 || right[i] < mm) {
                    mm = right[i];
                    mmi = i;
                }
            }
        }

        if (mmi == -1) return -1;

        right.erase(right.begin() + mmi);
        right.push_back(pv);
        std::sort(right.begin(), right.end());

        std::vector<char> result_vec(d.begin(), d.begin() + p);
        result_vec.push_back(mm);
        result_vec.insert(result_vec.end(), right.begin(), right.end());

        std::ostringstream ret_str_stream;
        for (char c: result_vec) {
            ret_str_stream << c;
        }

        std::string ret_str = ret_str_stream.str();
        long long ret = std::stoll(ret_str);
        if (ret < n) return -1;
        return ret;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}