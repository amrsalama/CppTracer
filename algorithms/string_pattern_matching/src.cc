// The algorithm design manual [Book]
// [2.5.3]  String Pattern Matching

#include <iostream>
#include <cstring>
#include "tracer/array.h"

int main() {
  char t[] = "Amr Salama", p[] = "Salama";
  int n = strlen(t), m = strlen(p);
  int i, j;

  tracer::ArrayTracer<char> tTracer(t, n, 0.5);
  tracer::ArrayTracer<char> pTracer(p, m, 0.5);

  for (i = 0; i <= (n-m); i++) {
    j = 0;
    while ((j < m) && (t[i+j] == p[j])) {
      tTracer.select(i+j, 0.2);
      pTracer.select(j, 0.2);
      j++;
    }

    if (j == m) {
      std::cout << i << std::endl;
      break;
    } else {
      tTracer.notify(i+j, 0.2);
      pTracer.notify(j, 0.2);
    }

    j = 0;
    while ((j < m) && (t[i+j] == p[j])) {
      tTracer.deselect(i+j, 0.01);
      pTracer.deselect(j, 0.01);
      j++;
    }
  }

  return 0;
}