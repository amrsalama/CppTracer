#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstring>
#include "tracer/array.h"

int main() {
  srand (time(NULL));
  const int N = 10;
  int arr[N];
  for(int i = N, j = 0; i >= 1; i--, j++) {
    int x = (rand() % 10 + 1);
    arr[j] = x;
  }

  tracer::ArrayTracer<int> tr(arr, N, 0.5);
  for(int i = 0; i < N; i++) {
    int minI = i;
    tr.select(i);
    for(int j = i + 1; j < N; j++) {
      tr.notify(j);
      if(arr[j] < arr[minI]) {
        if(minI != i)
          tr.deselect(minI);
        minI = j;
        tr.select(minI);
      }
    }

    if(minI != i) {
      std::swap(arr[i], arr[minI]);
      tr.update();
      tr.deselect(minI);
    }

    tr.deselect(i);
  }

  for(int i = 0; i < N; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}