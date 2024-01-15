#include <iostream>
#include <cmath>
#include <vector>

class Interval {
    double start, end;
    public:
        Interval(double x, double y) {
            if (x > y) {
                start = y;
                end = x;
            }
            else {
                start = x;
                end = y;
            }
        }
        double len() const {
            return fabs(end - start);
        }
        bool in(double x) const {
            if (x >= start && x <= end) {
                return true;
            }
            return false;
        }
        std::vector<double> split(int n) const {
            std::vector<double> ans;
            for (int i = 0; i < n + 1; i++) {
                ans.push_back(start + i*len()/n);
            }
            return ans;
        }
        void print() const {
            std::cout << "[" << start << ", " << end << "]" << std::endl;
        }
        Interval& operator * (double x) {
            start *= x;
            end *= x;
            return *this;
        }
        Interval& operator *= (double x) {
            return (*this * x);
        }
        friend Interval operator * (double x, const Interval& i) {
            return Interval(x * i.start, x * i.end);
        }
        Interval& operator / (double x) {
            return (*this * (1/x));
        }
        Interval& operator /= (double x) {
            return (*this / x);
        }
        Interval& operator + (double x) {
            start += x;
            end += x;
            return *this;
        }
        Interval& operator += (double x) {
            return (*this + x);
        }
        friend Interval operator + (double x, Interval& i) {
            return Interval(x + i.start, x + i.end);
        }
        Interval& operator - (double x) {
            return (*this + (-x));
        }
        Interval& operator -= (double x) {
            return (*this - x);
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
    a = 2 * a;
    a.print();
    a = a * 3;
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