//
// Created by yangxj on 16/2/29.
//

#include "LeetCodeUtils.h"

void PrintVector(vector<int> vec) {
  for(int i = 0;i<vec.size();i++)
  {
    printf("%d,",vec[i]);
  }
  printf("\n");
}

void PrintVector(vector<int> vec, char *name) {
  printf("%s\n",name);
  PrintVector(vec);
}

void PrintVector(vector<vector<int > > vec, char *name) {
  printf("%s\n",name);
  for(int i = 0;i<vec.size();i++)
  {
    printf("%3d:",i);
    PrintVector(vec[i]);
  }
  printf("\n");
}
