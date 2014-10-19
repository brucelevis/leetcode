/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int x = matrix.size();
        if(0 == x)    return 0;
        int y = matrix[0].size();
        if(0 == y)    return 0;
        vector<vector<int> > result(x, vector<int>(y));
        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j)
                result[i][j] = '0' == matrix[i][j]? 0: 1;
        for(int i = 1; i < x; ++i)
            for(int j = 0; j < y; ++j)
                result[i][j] += 0 == result[i][j]? 0: result[i-1][j];
        int ret = 0;
        for(int i = 0; i < x; ++i)
            ret = max(ret, maxArea(result[i]));
        return ret;
    }

    int maxArea(vector<int>& line)
    {
        stack<int> S;
        line.push_back(0);
        int sum = 0;
        for (int i = 0; i < line.size(); i++) {
            if (S.empty() || line[i] > line[S.top()]) S.push(i);
            else {
                int tmp = S.top();
                S.pop();
                sum = max(sum, line[tmp]*(S.empty()? i : i-S.top()-1));
                i--;
            }
        }
        return sum;
    }
};
void test0()
{
	if(0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}