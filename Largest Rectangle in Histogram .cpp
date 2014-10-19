/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#if 1
class Solution {
public:
    int Max(int a, int b){return a > b ? a : b;}
    int largestRectangleArea(vector<int> &height) {
    	height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()){
            if(stk.empty() || height[stk.top()] <= height[i]){
                stk.push(i++);
            }else {
                int t = stk.top();
				stk.pop();
                maxArea = Max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};
#elif 1
class Solution {
public:
    int Max(int a, int b){return a > b ? a : b;}
    int largestRectangleArea(vector<int> &height) {
    	height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()){
            if(stk.empty() || height[stk.top()] <= height[i]){
                stk.push(i++);
            }else {
                int t = stk.top();
				stk.pop();
                maxArea = Max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
                /*栈内元素一定是要比当前i指向的元素小的
				如果栈顶元素和当前元素相等时，也要出栈。这个高度对应的面积会在后期当前元素出栈后计算。 
				
				*/
            }
        }
        return maxArea;
    }
};
#endif
void test0(int a[],int n,int exp)
{
	vector<int > height(a,a+n);
	Solution so;
	int out = so.largestRectangleArea(height);
	if(out != exp)
		printf("------------------------failed %d\n",out);
	else
		printf("------------------------passed\n");
}
int main()
{
	int a0[] = {2,1,5,6,2,3};
	test0(a0,6,10);
	int a1[] = {1,2,3,4,5,6};
	test0(a1,6,6);
	return 0;
}