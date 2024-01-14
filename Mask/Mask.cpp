#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

bool check_bin(int x) {
    if (x == 0 || x == 1) return true;
    return false;
}

template <size_t s>
class Mask {
    std::vector<int> mask;
    public:
        Mask(std::initializer_list<int> vec) {
            if (vec.size() != s) throw std::invalid_argument("Incorrect mask size!");
            if (std::all_of(vec.begin(), vec.end(), check_bin)) {
                mask.insert(mask.end(), vec.begin(), vec.end());
            } else {
                throw std::invalid_argument("Incorrect mask!");
            }
        }
        int at(size_t pos) {
            if (pos >= s) throw std::out_of_range("Incorrect index!");
            return mask[pos];
        }
        template <typename Container>
        void slice(Container& cont) {
            for (int i = 0, j = 0; i < cont.size(); i++, j++) {
                if (j == s) j = 0;
                if (mask.at(j) == 0) {
                    cont.erase(cont.begin() + i);
                    i--;
                }
            }
        }
        template <typename Container, typename Function>
        void transform(Container& cont, Function func) {
            for (int i = 0, j = 0; i < cont.size(); i++, j++) {
                if (j == s) j = 0;
                if (mask.at(j) == 1) {
                    cont.at(i) = func(cont.at(i));
                }
            }
        }
        template <typename Container, typename Function>
        void slice_and_transform(Container& cont, Function func) {
            for (auto i = 0, j = 0; i < cont.size(); i++, j++) {
                if (j == s) j = 0;
                if (mask.at(j) == 1) {
                    cont.at(i) = func(cont.at(i));
                } else {
                    cont.erase(cont.begin() + i);
                    i--;
                }
            }
        }
};

int func(int x) {
    return x + 2;
}

int main() {
    try {
        Mask<4> a = {1,0,0,1};
        std::vector<int> vec = {2,3,4,5,6,7,8};
        a.slice(vec);
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
        vec = {2,3,4,5,6,7,8};
        a.transform(vec, func);
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n";
        vec = {2,3,4,5,6,7,8};
        a.slice_and_transform(vec, func);
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}