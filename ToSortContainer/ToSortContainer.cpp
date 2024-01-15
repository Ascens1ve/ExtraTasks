#include <initializer_list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <type_traits>

template <typename T>
class ToSortContainer {
    std::vector<T> container;
    public:
        ToSortContainer(std::initializer_list<T> numbers) {
            container.insert(container.end(), numbers.begin(), numbers.end());
        }
        template <typename Comparator>
        std::vector<T> getSortedBy(Comparator cmp) {
            if constexpr (std::is_invocable_r_v<bool, Comparator, const T, const T>) {
                std::sort(container.begin(), container.end(), cmp);
            } else {
                throw std::logic_error("Invalid comparator!");
            }
            return container;
        }
        void print() const {
            for (int i = 0; i < container.size(); i++) {
                std::cout << container[i] << " ";
            }
            std::cout << std::endl;
        }
};

int func(int a, int b, int c) {
    return a+b+c;
}

bool func_1(int& a, int& b) {
    a += 10;
    return a > b;
}

int main() {
    try {
        ToSortContainer tsc = {2, 3, -4, 1, 6};
        tsc.print();
        auto x = tsc.getSortedBy(std::greater<int>());
        for (int i = 0; i < x.size(); i++) {
            std::cout << x[i] << " ";
        }
        std::cout << "\n";
        auto y = tsc.getSortedBy([](auto x, auto y){return x < y;});
        for (int i = 0; i < y.size(); i++) {
            std::cout << y[i] << " ";
        }
        std::cout << "\n";
        auto w = tsc.getSortedBy(func_1);
        for (int i = 0; i < w.size(); i++) {
            std::cout << w[i] << " ";
        }
        std::cout << "\n";
        //auto z = tsc.getSortedBy(func);
        //for (int i = 0; i < z.size(); i++) {
        //    std::cout << z[i] << " ";
        //}
        //std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
