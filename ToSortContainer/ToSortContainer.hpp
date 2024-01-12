#ifndef TOSORTCONTAINER_HPP
#define TOSORTCONTAINER_HPP

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

#endif