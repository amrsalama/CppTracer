#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include "tracer/array.h"
#include "tracer/matrix.h"
using namespace std;
using namespace tracer;

int main() {
  // Testing Area
  const int N = 5;
  int arr[N] = { 100, 22, 3, 42, 5 };
  ArrayTracer<int> tr(arr, N, 0.5);
  for(int i = 1; i < N; i++) {
    tr.select(i);
    int j = i;
    while((j > 0) && (arr[j] < arr[j-1])) {
        swap(arr[j], arr[j-1]);
        tr.update();
        j--;
    }
    tr.deselect(i);
  }





  // Example #1
  // char arr[] = "Happy New Year 2018";
  // int N = sizeof(arr) - 1;

  // ArrayTracer<char> tr(arr, N, 0.5);
  // for(int i = 0; i < N; i++) {
  //   tr.select(i);
  //   for(int j = 0; j < i; j++) {
  //     tr.notify(j);
  //     swap(arr[i], arr[j]);
  //     tr.update();
  //   }
  //   tr.deselect(i);
  // }




  // Example #2 (matrix)
  // const int N = 4, M = 8;
  // int mat[N][M];
  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++) {
  //     mat[i][j] = 1;
  //   }
  // }

  // MatrixTracer<int, N, M> mt(mat, 0.5, "Matrix Testing", tracer::DARK_THEME);
  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < M; j++) {
  //     mat[i][j] *= ((i+1) * j);
  //     mt.update();
  //     // mt.notify(i, j);
  //     // mt.select(i, j);
  //     // mt.deselect(i, j);
  //   }
  // }




  // Example #3
  // const int n = 10;
  // int arr[n];
  // for(int i = 0; i < n; i++) {
  //   arr[i] = i+1;
  // }
  // tracer::ArrayTracer<int> tr(arr, n, 0.2);
  // for(int i = 0; i < n; i++) {
  //   tr.select(i, 0.3);
  //   for(int j = 0; j < i; j++) {
  //     tr.notify(j);
  //     arr[j] *= 2;
  //     tr.update();
  //   }
  //   tr.deselect(i);
  // }
  // tr.notify(1, 5, 0.5);
  // tr.select(1, 5, 0.2);
  // tr.deselect(1, 5, 0.2);
  // tr.update();




  // Example #4
  // srand (time(NULL));
  // const int n = 10;
  // int arr[n];
  // for(int i = 0; i < n; i++) {
  //   arr[i] = i+1;
  // }
  
  // int A[1] = {0};
  // tracer::ArrayTracer<int> T(A, 1);
  // tracer::ArrayTracer<int> tr(arr, n, 1);
  // for(int j = 1; j <= 100; j++) {
  //   A[0] = j;
  //   T.update();
  
  //   for(int i = 0; i < n; i++) {
  //     int x = (rand() % 10 + 1);
  //     if(x <= 5) {
  //         arr[i] = (rand() % 10 + 1);
  //     }
  //   }
  //   tr.update();
  // }




  // Example #5
  // const int M = 3;
  // char array[M] = {'A', 'B', 'C'};
  // tracer::ArrayTracer<char> mainTR(array, M, 0.3, "Main Array");

  // for(int i = 0; i < M; i++) {
  //   mainTR.select(i);

  //   const int N = 5;
  //   int arr[N];
  //   for(int j = 1; j <= N; j++)
  //     arr[j-1] = i;
  //   tracer::ArrayTracer<int> subTR1(arr, N, 0.1, "Sub Array 1");

  //   const int M = 7;
  //   std::string arrr[M] = {"A\nB", "ll", "o,", "Wo", "rl", "d!", "A\tB\nC\tD"};
  //   tracer::ArrayTracer<std::string> subTR2(arrr, M, 0.1, "Sub Array 2");

  //   for(int j = 0; j < N; j++) {
  //     subTR1.select(j);
  //     for(int k = 0; k < M; k++)
  //       subTR2.notify(k);
  //     subTR1.deselect(j);
  //   }

  //   mainTR.deselect(i);
  // }


  return 0;
}
