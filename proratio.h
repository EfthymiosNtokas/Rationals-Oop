//
// header file
//

#ifndef PRORATIO_PRORATIO_H
#define PRORATIO_PRORATIO_H

#include <iostream>

class rational{
public:
    rational(int n, int d=1);
    friend rational operator +(const rational &x, const rational &y);
    friend rational operator -(const rational &x, const rational &y);
    friend rational operator *(const rational &x, const rational &y);
    friend rational operator /(const rational &x, const rational &y);

    friend std::ostream & operator <<(std::ostream &out, const rational &x );
private:
    int nom, den;

    static int gcd(int x, int y);
};
#endif //PRORATIO_PRORATIO_H
