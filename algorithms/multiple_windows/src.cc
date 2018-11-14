#include <iostream>
#include <cstring>
#include "tracer/array.h"

int main() {
  const int M = 3;
  char array[M] = {'A', 'B', 'C'};
  tracer::ArrayTracer<char> mainTR(array, M, 0.3, "Main Array");

  for(int i = 0; i < M; i++) {
    mainTR.select(i);

    const int N = 5;
    int arr[N];
    for(int j = 1; j <= N; j++)
      arr[j-1] = i;
    tracer::ArrayTracer<int> subTR1(arr, N, 0.1, "Sub Array 1");

    const int M = 7;
    std::string arrr[M] = {"A\nB", "ll", "o,", "Wo", "rl", "d!", "A\tB\nC\tD"};
    tracer::ArrayTracer<std::string> subTR2(arrr, M, 0.1, "Sub Array 2");

    for(int j = 0; j < N; j++) {
      subTR1.select(j);
      for(int k = 0; k < M; k++)
        subTR2.notify(k);
      subTR1.deselect(j);
    }

    mainTR.deselect(i);
  }

  return 0;
}