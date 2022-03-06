// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double x = 1;
  for (int i = 1; i <= n; i++) {
    x *= value;
  }
  return x;
}

uint64_t fact(uint16_t n) {
    int res = 1;
    int i = 1;
    while (n >= i) {
        res = res * i;
        i++;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    double res = (pown(x, n) / fact(n));
    return res;
}

double expn(double x, uint16_t count) {
    double temp = 0;
    while (count != 0) {
       temp += calcItem(x, count--);
    }
    return temp + 1.0;
}

double sinn(double x, uint16_t count) {
  double value = 0;
  for (uint16_t i = 1; i <= count; i++) {
       value = value + pown(-1, i - 1) * pown(x, 2 * i - 1) / fact(2 * i - 1);
}
  return value;
}

double cosn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 1, n = 1; i <= count; ++i, ++n) {
    sum += pown(-1, n - 1) * calcItem(x, 2 * n - 2);
  }
  return sum;
}
