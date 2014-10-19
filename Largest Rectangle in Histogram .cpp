/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
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
                /*ջ��Ԫ��һ����Ҫ�ȵ�ǰiָ���Ԫ��С��
				���ջ��Ԫ�غ͵�ǰԪ�����ʱ��ҲҪ��ջ������߶ȶ�Ӧ��������ں��ڵ�ǰԪ�س�ջ����㡣 
				
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