/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		string ret = "";
		int size1 = num1.size();
		int size2 = num2.size();
		if(size1 == 0 || size2 == 0)	return ret;
		
		if(num1 == "0" || num2 == "0")
			return ret = "0";
		
		int *n1 = new int[size1];
		int *n2 = new int[size2];
		int *nsum = new int[size1+size2];
		memset(nsum,0,(size1+size2)*sizeof(int));
		for(int i = 0;i<size1;i++)
			n1[i] = num1[i] - '0';
		
		for(int i = 0;i<size2;i++)
			n2[i] = num2[i] - '0';
		
		for(int i = 0;i<size1;i++)////////////////还是尽量避免使用i j这种分不清的变量吧 
		{
			for(int j = 0;j<size2;j++)
			{
				nsum[i+j+1] += n1[i]*n2[j];//////////////////////////////+=   i+j+1
			}
		}
		//printf("1\n");	
		for(int k = size1 + size2 -1;k>=0;k--)/////////////////k>=0
		{
			if(k>0)//////////////////////////
				nsum[k-1] += nsum[k]/10;
			nsum[k] = nsum[k]%10;
			ret = char(nsum[k]+'0') + ret;	
		}
		//最高位可能是0
		ret = ret[0] == '0'?ret.substr(1):ret; 
		//return ss.empty()?"0":ss;
		return ret;
	}
};


using namespace std;
void check(string s1, string s2, string exp)
{
	Solution so;
	string out  = so.multiply(s1,s2);
	if(out != exp)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	check("123","345","42435");
	return 0;
}