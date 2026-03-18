#include <iostream>
#ifndef CONTEST
#include "babyratio.hpp"
#endif

using namespace std;

int rational::gcd(int a, int b){
  a = abs(a); b = abs(b);
  while (a > 0 && b > 0){
    if (a > b) a = a % b; else b = b % a;
  }
  return a+b;
}

rational::rational (int n, int d){
  int aplopoihsh = gcd(n,d);
  nom = n/aplopoihsh; den = d/aplopoihsh;
  if (den < 0) { nom = -nom; den = -den;
  }
}

rational rational::add (rational r){
  return rational(nom*r.den + den*r.nom, den*r.den);
}

rational rational::sub(rational r){
  return rational(nom*r.den - den*r.nom, den*r.den);
}

rational rational::mul(rational r){
  return rational(nom*r.nom, den*r.den);
}

rational rational::div(rational r){
  return rational(nom*r.den, den*r.nom);
}

void rational::print(){
 cout<<nom<<"/"<<den;
}
