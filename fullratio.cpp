#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

int rational::gcd(int a, int b){
  a = abs(a); b = abs(b);
  while (a > 0 && b > 0){
    if (a > b) a = a % b; else b = b % a;
  }
  return a+b;
}

rational::rational(int n,int d){
  int aplopoihsh = gcd(n, d);
  nom = n/aplopoihsh; den = d/aplopoihsh;
  if (den < 0) {
    nom = -nom; den = -den;
  }
}

rational operator + (const rational &x, const rational &y){
  return rational(x.nom*y.den + y.nom*x.den, x.den*y.den);
}


rational operator - (const rational &x, const rational &y){
  return rational(x.nom*y.den - y.nom*x.den, x.den*y.den);
}


rational operator * (const rational &x, const rational &y){
  return rational(x.nom*y.nom, x.den*y.den);
}


rational operator / (const rational &x, const rational &y){
  return rational(x.nom*y.den, x.den*y.nom);
}


std::ostream & operator <<(std::ostream &out, const rational &x){
  out<<x.nom<<"/"<<x.den;
  return out;
}

