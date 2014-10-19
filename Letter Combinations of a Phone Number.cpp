/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;		
        if(digits.size() < 1)
		{
		     ret.push_back("");
			 return ret;
		}
        string str[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> strvec;
		for(int i =0;i<10;i++)
			strvec.push_back(str[i]);
			
        letterCombinations(ret,"",digits,0,strvec);
        return ret;
    }
    void letterCombinations(vector<string> &ret,string tmp,string &digits,int index,vector<string> &strvec)
    {
    	//printf("index = %d\n",index);
    	if(index == digits.size())
    	{
    		ret.push_back(tmp);
    		return;
		}
		//是不要做非数字判断 
		for(int i = 0;i<strvec[digits[index]-'0'].size();i++)
		{
			letterCombinations(ret,tmp+strvec[digits[index]-'0'][i],digits,index+1,strvec);
		}
	}

};

void printvecvec(vector<string > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:",i);
		cout<<A[i]<<endl;
	}
	printf("\n");
}
void test0()
{
	Solution so;
	vector<string> out = so.letterCombinations("23");
	
	printvecvec(out);
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	
	test0();
	
	return 0;
}

