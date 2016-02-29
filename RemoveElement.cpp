#include <iostream>

using namespace std;

class Solution {
  public:
    int removeElement(int A[], int n, int elem) {
      int i = 0, len = 0;
      while (i < n) {
        if (A[i] == elem)
          i++;
        else
          A[len++] = A[i++];
      }
      return len;
    }
};

void check(int A[], int B[], int len) {
  int i = 0;
  for (; i < len; i++) {
    if (A[i] != B[i])
      break;
  }
  if (i != len)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");
}

void test0() {
  int A[] = {0, 1, 2, 3, 4, 5, 3, 7, 3, 9};
  int B[] = {0, 1, 2, 4, 5, 7, 9};
  Solution so;
  int len = so.removeElement(A, 10, 3);
  check(A, B, len);
}

int main(int argc, char *argv[]) {
  test0();
  return 0;
}
