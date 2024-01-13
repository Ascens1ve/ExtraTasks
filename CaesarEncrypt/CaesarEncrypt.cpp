#include <iostream>

constexpr int base_shift = 3;

class CaesarEncrypt {
    int shift;
    void crypt(std::string& word, bool op) {
        for (int i = 0; i < word.size(); i++) {
            if (isalpha(word[i])) {
                int pos = static_cast<int>(word[i]);
                int power = abs(pos - 97) < abs(pos - 65) ? 97 : 65;
                if (op == true) word[i] = static_cast<char>((pos + shift) % power + power);
                else word[i] = static_cast<char>((pos - shift) % power + power);
            }
        }
    }
    public:
        explicit CaesarEncrypt(int shift = base_shift) {
            if (shift > 25 || shift < 0) {
                throw std::invalid_argument("Shift is not correct!");
            }
            this->shift = shift;
        }
        void encrypt(std::string& word) {
            crypt(word, true);
        }
        void decrypt(std::string& word) {
            crypt(word, false);
        }
        ~CaesarEncrypt() = default;
};


int main() {
    try {
        CaesarEncrypt b(4);
        std::string s2 = "aAb42cdeпри2f";
        std::cout << s2 << "\n";
        b.encrypt(s2);
        std::cout << s2 << "\n";
        b.decrypt(s2);
        std::cout << s2 << "\n";
        CaesarEncrypt a(57);
        std::string s1 = "aAb42cdeпри2f";
        std::cout << s1 << "\n";
        a.encrypt(s1);
        std::cout << s1 << "\n";
        a.decrypt(s1);
        std::cout << s1 << "\n";
    } catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}