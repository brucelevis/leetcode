/*
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
#include "LeetCodeUtils.h"

using namespace std;

/*
思路

*/

class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int guard = 0;
      for(int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
          nums[guard] = nums[i];
          guard++;
        }
      }
      for(int i = guard; i < nums.size(); i++) {
        nums[i] = 0;
      }
    }
};

void test0() {
  int arr[] = {0, 1, 0, 3, 12};
  vector<int> numbers(arr, arr + sizeof(arr) / sizeof(int));
  Solution so;
  PrintVector(numbers, "befor");
  so.moveZeroes(numbers);
  PrintVector(numbers, "after");
}


int main() {
  test0();
  return 0;
}



