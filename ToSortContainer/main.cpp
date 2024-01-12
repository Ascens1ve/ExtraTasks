#include "ToSortContainer.hpp"

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