#include <iostream>

constexpr int base_shift = 3;
constexpr int uppercase = static_cast<int>('A');
constexpr int lowercase = static_cast<int>('a');

class CaesarEncrypt {
    int shift;
    void crypt(std::string& word, bool op) {
        int direction = op == true ? 1 : -1;
        for (int i = 0; i < word.size(); i++) {
            if (isalpha(word[i])) {
                int pos = static_cast<int>(word[i]);
                int power = abs(pos - lowercase) < abs(pos - uppercase) ? lowercase : uppercase;
                word[i] = static_cast<char>((pos + shift * direction) % power + power);
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
    } catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}