#include <exception>
#include <string>

class Kata {
    const std::string region = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;-?! '()$%&\"";

    static char switchCase(char const &c) {
        if (c >= 'A' && c <= 'Z')
            return c + 'a' - 'A';
        if (c >= 'a' && c <= 'z')
            return c + 'A' - 'a';
        return c;
    }

    static void step1(std::string &text) {
        for (auto i = 1; i < text.size(); i += 2)
            text[i] = switchCase(text[i]);
    }

    void step2(std::string const &text_in, std::string &text_out) {
        for (auto i = 1; i < text_in.size(); i++) {
            int diff = region.find(text_in[i - 1]) - region.find(text_in[i]);

            auto index = diff < 0 ? diff + 77 : diff;

            text_out[i] = region[index];
        }
    }

    void step3(std::string &text) {
        auto index = region.find(text[0]);
        text[0] = region[76 - index];
    }

public:
    std::string encrypt(std::string text) {
        if (text.empty())
            return text;

        if (text.find_first_not_of(region) != std::string::npos) {
            throw std::exception();
        }

        step1(text);

        std::string orig = text;
        step2(orig, text);

        step3(text);

        return text;
    }

    std::string decrypt(std::string encryptedText) {
        if (encryptedText.empty())
            return encryptedText;

        if (encryptedText.find_first_not_of(region) != std::string::npos)
            throw std::exception();

        step3(encryptedText);

        step2(encryptedText, encryptedText);

        step1(encryptedText);

        return encryptedText;
    }
};