#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;
public:
    Fraction() {}
    // Fraction(int num) : num(num), den(1) {}     this is legal but the next one is better
    Fraction(int num) : Fraction(num, 1) {}
    Fraction(int num, int den) : num(num), den(den) {} // first num after colon refers to private, one in parentheses refers to one called in this constructor's parentheses
    void print() const {
        cout << num << "/" << den;
    }
    Fraction add(Fraction r) const {
        Fraction ans(this->num * r.den + r.num * this->den, this->den * r.den);
        return ans;
        /*Fraction ans; // 0/1
        ans.num = ;
        ans.den = ;
        return ans;*/
    }
    // r.num refers to the righthand side of f2.add(f4), in this case f4 (the num of f4)
    // this->num (or just num) refers to the lefthand side, or the num of f2 in this case
    Fraction add2(Fraction r) const {
        Fraction ans(num * r.den + r.num * den, den * r.den);
        return ans;
    }
    // same as add, just a little shorter

    Fraction add3(Fraction r) const {
        return Fraction(num * r.den + r.num * den, den * r.den);
    }
    // same, but shorter and cleaner
    // if you declare a local variable named num in one of these functions, then you HAVE to use this->num to refer to the lefthand side
        };

int main() {
    Fraction f1;
    const Fraction f2(1, 2);
    Fraction f3(5);
    Fraction f4(1, 3);
    f1.print();   // 0/1
    f2.print();   // 1/2
    f3 = f2.add(f4);   // 1/2 + 1/3 = 5/6
    f3.print();
    return 0;
}