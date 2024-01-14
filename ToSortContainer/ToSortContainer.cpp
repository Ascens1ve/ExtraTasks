#include <initializer_list>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
class ToSortContainer {
    std::vector<T> container;
    public:
        ToSortContainer(std::initializer_list<T> numbers) {
            container.insert(container.end(), numbers.begin(), numbers.end());
        }
        template <typename C>
        std::vector<T> getSortedBy(C comparator) {
            std::sort(container.begin(), container.end(), comparator);
            return container;
        }
        void print() const {
            for (int i = 0; i < container.size(); i++) {
                std::cout << container[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main() {
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
    std::cout << std::endl;
    return 0;
}
