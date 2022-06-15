//
// implementation
//
#ifndef CONTEST
#include "proratio.h"
#endif
using namespace std;
#include <iostream>
#include <stdlib.h>
rational::rational(int n, int d){
    nom = n; den = d;
}
int rational::gcd(int a, int b){
    int x = abs(a);int y= abs(b);
    while(x>0&&y>0){
        if(x > y){x%=y;}else y%=x;
    }return x+y;
}
rational operator + (const rational &x, const rational &y){
    int f = rational::gcd(x.nom*y.den+x.den*y.nom, x.den*y.den);
    int s = (x.nom*y.den+x.den*y.nom)/f; int t = x.den*y.den/f; int sign = 0;
    sign = s * t >= 0 ? 1 : -1;
    if (sign==1) {
        return rational(abs(s), abs(t));
    } else {
        return rational(-abs(s), abs(t));
    }
}
rational operator - (const rational &x, const rational &y){
    int f = rational::gcd(x.nom*y.den-x.den*y.nom, x.den*y.den);
    int s = (x.nom*y.den-x.den*y.nom)/f; int t = x.den*y.den/f; int sign = 0;
    if (s * t >= 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    if (sign==1) {
        return rational(abs(s), abs(t));
    } else {
        return rational(-abs(s), abs(t));
    }
}
rational operator * (const rational &x, const rational &y){
    int f = rational::gcd(x.nom*y.nom, x.den*y.den);
    int s = (x.nom*y.nom)/f; int t = x.den*y.den/f; int sign = 0;
    sign = s * t >= 0 ? 1 : -1;
    return rational(sign == 1 ? abs(s) : -abs(s), abs(t));
}
rational operator / (const rational &x, const rational &y){
    int f = rational::gcd(x.nom*y.den, x.den*y.nom);
    int s = (x.nom*y.den)/f; int t = x.den*y.nom/f; int sign = 0;
    sign = s * t >= 0 ? 1 : -1;
    return rational(sign==1 ? abs(s) : -abs(s), abs(t));
}
std::ostream & operator <<(std::ostream &out, const rational &x){
    int l = rational::gcd(x.nom, x.den);
    int n,d;
    if(x.nom*x.den >= 0){n = abs(x.nom/l); d = abs(x.den/l);}
    else{n = -abs(x.nom/l); d = abs(x.den/l);}
    out << n << "/" << d;

    return out;
}


