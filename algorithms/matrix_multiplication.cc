// The algorithm design manual [Book]
// [2.5.4]  Matrix Multiplication

#include <stdlib.h>
#include <time.h>
#include "tracer/matrix.h"
using namespace tracer;

int main() {
  srand (time(NULL));
  const int x = 3, y = 2, z = 3;
  int A[x][y], B[y][z], C[x][z];

  // initialize A
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      A[i][j] = (rand() % 10 + 1);
    }
  }

  // initialize B
  for(int i = 0; i < y; i++) {
    for(int j = 0; j < z; j++) {
      B[i][j] = (rand() % 10 + 1);
    }
  }

  // initialize C
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < z; j++) {
      C[i][j] = 0;
    }
  }

  MatrixTracer<int, x, y> tracerA(A, 0.5, "Matrix A");
  MatrixTracer<int, y, z> tracerB(B, 0.5, "Matrix B");
  MatrixTracer<int, x, z> tracerC(C, 0.5, "Matrix C", tracer::DARK_THEME);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < z; j++) {
      tracerC.select(i, j);
      for (int k = 0; k < y; k++) {
        tracerA.select(i, k, 0.1);
        tracerB.select(k, j);

        C[i][j] += A[i][k] * B[k][j];
        tracerC.update();

        tracerA.deselect(i, k, 0.1);
        tracerB.deselect(k, j, 0.1);
      }
      tracerC.deselect(i, j);
    }
  }

  return 0;
}