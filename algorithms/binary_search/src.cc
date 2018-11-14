#include <iostream>
#include "tracer/array.h"

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
  int N = sizeof(arr)/sizeof(int);
  
  tracer::ArrayTracer<int> tr(arr, N, 0.9);

  int target = 30;
  std::cout << "Searching for " << target << std::endl;

  int a = 0, b = N-1;
  int mid, x;
  while(true) {
    mid = (a+b)/2;
    x = arr[mid];

    tr.select(mid);
    if(x == target) {
      std::cout << "Found at index " << mid << std::endl;
      tr.notify(mid, 1.5);
      break;
    } else if(x < target) {
      tr.select(a, mid);
      a = mid + 1;
    } else {
      tr.select(mid, b);
      b = mid - 1;
    }
    
    if(a > b) {
      std::cout << "Not Found" << std::endl;
      break;
    }
  }


  return 0;
}