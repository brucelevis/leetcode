//
// Created by yangxj on 16/3/1.
//

/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
需要能够快速默写的函数
*/

#include <iostream>
#include <vector>
using namespace std;
//************************************二分查找
//输入为升序
int binarySearch(int a[], int n, int target)
{
  int low = 0, high = n -1;
  while (low <= high) {   // 这里需要有=号
    int mid = (low + high) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] > target) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}
void testBinarySearch()
{
  int a[] = {0,1,2,3,4,5,6,7,8,9};

  if(binarySearch(a,10,5) != 5)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");

  if(binarySearch(a,10,-1) != -1)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");

  if(binarySearch(a,10,10) != -1)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");

  int b[] = {5};

  if(binarySearch(b, 1, 5) != 0)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");

  if(binarySearch(b, 1, 0) != -1)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");
}

void print_list(int * list, int len,string listname)
{
  int i = 0;
  printf("%s 长度 = %d\n",listname.c_str(),len);

  for(i = 0;i < len;i++)
  {
    printf("-%2d",i);
  }
  printf("\n");
  for(i = 0;i < len;i++)
  {
    printf("%3d",list[i]);
  }
  printf("\n");
}
//************************************插入排序
void insertSort2(int a[], int n)
{
  for(int i = 1;i<n;i++)
  {
    if(a[i] < a[i-1])
    {
      int tmp = a[i],j = i-2;
      a[i] = a[i-1];
      for(j = i-2;j>=0;j--)
      {
        if(tmp < a[j])   a[j+1] = a[j];
        else break;
      }
      //tmp 最小时 j=-1
      a[j+1] = tmp;
    }
  }
}

void insertSort(int a[], int n)
{
  for (int i = 1; i < n; i++) {
    int tmp = a[i];
    int j = i;
    while (j > 0 && tmp < a[j - 1]) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = tmp;
  }
}

void testInsertSort()
{
  int a[] = {9,8,7,6,5,4,3,2,1,0};
  print_list(a,10, "befor insertSort");
  insertSort(a,sizeof(a)/sizeof(int));
  print_list(a,10, "after insertSort");
}

//************************************起泡排序
void bubbleSort2(int a[], int n)
{
  for(int i = 0;i<n-1;i++)
  {
    for(int j = 1;j<n-i;j++)
    {
      if(a[j-1]>a[j])
      {
        a[j-1] = a[j-1]^a[j];
        a[j] = a[j-1] ^ a[j];
        a[j-1] = a[j-1]^a[j];
      }
    }
  }
}

void bubbleSort(int a[], int n)
{
  for (int i = 1; i < n; i ++) {
    for (int j = 0; j < n - i; j ++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

void testBubbleSort()
{
  int a[] = {9,8,7,6,5,4,3,2,1,0};
  print_list(a,10,"befor bubbleSort");
  bubbleSort(a,sizeof(a)/sizeof(int));
  print_list(a,10,"after bubbleSort");
}

//************************************快速排序

int partition2(int *list, int low, int high)
{
  int pivotkey = list[low];
  while(low < high)
  {
    while(low < high && list[high]>= pivotkey) high--;
    list[low] = list[high];
    while(low < high && list[low]<= pivotkey) low++;
    list[high] = list[low];
  }
  list[low] = pivotkey;
  return low;
}
int myQsort2(int a[],int low, int high)
{
  if(low < high)
  {
    int pivotloc = partition2(a,low, high);
    myQsort2(a,low,pivotloc-1);
    myQsort2(a,pivotloc+1,high);
  }
  return 0;
}

int partition(int a[], int low, int high) {
  int tmp = a[low];
  while(low < high) {
    while(low < high && a[high] >= tmp) high--;
    a[low] = a[high];
    while (low < high && a[low] <= tmp) low++;
    a[high] = a[low];
  }
  a[low] = tmp;
  return low;
}
int myQsort(int a[],int low, int high)
{
  if (low >= high) {
    return 0;
  }
  int vo = partition(a, low, high);
  myQsort(a, low, vo - 1);
  myQsort(a, vo + 1, high);
  return 0;
}
void testMyQsort()
{
  int a[] = {9,8,7,6,5,4,3,2,1,0};
  print_list(a,10,"befor sort");
  myQsort(a,0,sizeof(a)/sizeof(int)-1);
  print_list(a,10,"after sort");
}

//************************************堆排序
void heapAdjust(int a[], int s, int m)
{
  int tmp = a[s],i = 0;
  for(i = 2*s+1;i<m;i *=2+1)
  {
    if(i<m && a[i] < a[i+1])  i++;
    if(tmp >= a[i])  break;
    a[s] = a[i];
    s = i;
  }
  a[s] = tmp;
}
void heapSort(int a[], int n)
{
  int i = 0;
  for(i = (n-1)/2;i>=0;i--)
    heapAdjust(a,i,n-1);
  for(i = n-1;i>0;i--)
  {
    swap(a[0],a[i]);
    heapAdjust(a,0,i-1);////这里是i-1
  }
}

void heapAdjust2(int a[], int s, int m) {
  int tmp = a[s];
  for (int i = 2*s + 1; i <= m; i = i * 2 + 1) {  // 这里需要=, i<=m
    if (i < m && a[i] < a[i + 1]) i++;    // 这里不需要=. i<m
    if (tmp >= a[i]) break;
    a[s] = a[i];
    s = i;
  }
  a[s] = tmp;
}
void heapSort2(int a[], int n) {
  for (int i = (n - 1) / 2; i >= 0; i--) {
    heapAdjust2(a, i, n - 1);
  }
  for (int i = 1; i < n; i++) {
    swap(a[0], a[n - i]);
    heapAdjust2(a, 0, n - 1 - i);
  }
}
void testHeapSort()
{
  int a[] = {9,8,7,6,5,4,3,2,1,0};
  print_list(a,10,"befor heapSort");
  heapSort2(a,sizeof(a)/sizeof(int));
  print_list(a,10,"after heapSort");

  int b[] = {8,7,6,5,4,3,2,0,1};
  print_list(b,9,"befor heapSort");
  heapSort2(b,sizeof(b)/sizeof(int));
  print_list(b,9,"after heapSort");
}
//************************************strcpy
/**********************
*C语言标准库函数strcpy的一种典型的工业级的最简实现
*返回值：目标串的地址。
*对于出现异常的情况ANSI-C99标准并未定义，故由实现者决定返回值，通常为NULL。
*参数：des为目标字符串，source为原字符串
*/
char *Mystrcpy(char *des, const char *source) ///const
{
  char*r=des;
//if ((NULL==strDest)||(NULL==strSrc)) throw "Invalid argument";
  while(*des++ = *source++);
  return r;//返回des
}
void testMystrcpy()
{
  char src[] = "hello world!";
  char des[100];
  if(strcmp("hello world!",Mystrcpy(des,src)) != 0)
    printf("------------------------failed\n");
  else
    printf("------------------------passed\n");
}

//************************************strcmp
int Mystrcmp(const char*str1,const char*str2)
{
  while(*str1==*str2)
  {
    if(*str1=='\0')
      return 0;
    str1++;
    str2++;
  }
  return*str1-*str2;
}
void testMystrcmp()
{
  if(Mystrcmp("hello","H") > 0 )
    printf("------------------------passed\n");
  else
    printf("------------------------failed\n");

  if(Mystrcmp("hello","hello") == 0 )
    printf("------------------------passed\n");
  else
    printf("------------------------failed\n");

  if(Mystrcmp("hello","i") < 0 )
    printf("------------------------passed\n");
  else
    printf("------------------------failed\n");

}
//************************************atoi

int atoi(const char *str) {
  long long tmp = 0;
  int index = 0;
  int sign = 1;
  while(str[index] && str[index] == ' ') index++;
  if(str[index] && str[index] == '-')
  {
    sign = -1;
    index++;
  }
  else if(str[index] && str[index] == '+')
  {
    sign = 1;
    index++;
  }
  //printf("%2d-%c-%5d\n",index,str[index],tmp);
  while(str[index] && str[index] >= '0' && str[index]<= '9')
  {
    tmp = tmp*10+str[index] - '0';
    //printf("%2d-%c-%5d\n",index,str[index],tmp);
    if(tmp/10 > INT_MAX)
      break;
    index++;
  }
  //printf("%2d-%c-%5d\n",index,str[index],tmp);
  tmp = sign*tmp;
  if(tmp > INT_MAX )           return INT_MAX;
  else    if(tmp < INT_MIN)    return INT_MIN;
  return (int)tmp;
}


int main()
{
//  testBinarySearch();
//  testInsertSort();
//  testBubbleSort();
//  testMyQsort();
  testHeapSort();
//  testMystrcpy();
  //testMystrcmp();
  return 0;
}
