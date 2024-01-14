#include <iostream>
#include <cmath>
#include <vector>

class Interval {
    std::pair<double, double> interval;
    public:
        Interval(double x, double y) {
            if (x > y) interval = {y, x};
            else interval = {x, y};
        }
        double len() const {
            return fabs(interval.second - interval.first);
        }
        bool in(double x) const {
            if (x >= interval.first && x <= interval.second) {
                return true;
            }
            return false;
        }
        std::vector<double> split(int n) const {
            std::vector<double> ans;
            for (int i = 0; i < n + 1; i++) {
                ans.push_back(interval.first + i*len()/n);
            }
            return ans;
        }
        void print() const {
            std::cout << "[" << interval.first << ", " << interval.second << "]" << std::endl;
        }
        Interval& operator * (double x) {
            interval.first *= x;
            interval.second *= x;
            return *this;
        }
        Interval& operator / (double x) {
            return (*this * (1/x));
        }
        Interval& operator + (double x) {
            interval.first += x;
            interval.second += x;
            return *this;
        }
        Interval& operator - (double x) {
            return (*this + (-x));
        }
};



int main() {
    Interval a(3.133, 5.134);
    std::cout << a.len() << std::endl;
    std::cout << a.in(3) << " " << a.in(3.14) << " " << a.in(5.1340) << std::endl;
    std::vector<double> vec = a.split(5);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    a.print();
    a = a * 2;
    a.print();
    std::cout << a.len() << std::endl;
    a = a / 2;
    a.print();
    std::cout << a.len() << std::endl;
    a = a + 2;
    a.print();
    std::cout << a.len() << std::endl;
    a = a - 2;
    a.print();
    std::cout << a.len() << std::endl;
    return 0;
}