#include <iostream>
#include <vector>
#include <cctype>

#define DEBUG

using namespace std;

/**
功能测试：能够算出结果
特殊输入：输入格式不对 输入负数   -和负的区分 

*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> tempstack;
        int size = tokens.size();
		int  i = 0,opt = 0,num1 = 0,num2 = 0,ret = 0,stackTop = 0;;
		if(size == 0)
			return 0;
		for(i = 0;i<size;i++)
		{
			opt = isOperator(tokens[i]);
			
			if(opt)//如果是运算符 
			{
				stackTop = tempstack.size();
				if(stackTop >= 2)//至少要2个元素
				{
					num2 = tempstack[--stackTop];
					tempstack.pop_back();//弹出最后一个元素 
					num1 = tempstack[--stackTop];
					tempstack.pop_back();//弹出最后一个元素
					switch(opt)
					{
					case 1:
						ret = num1+num2;
						break;
					case 2:
						ret = num1-num2;
						break;
					case 3:
						ret = num1*num2;
						break;
					case 4:
						ret = num1/num2;
						break;
					} 
					tempstack.push_back(ret);
				} 
				else
				{	
				} 
			}
			else
			{//操作数 
				tempstack.push_back(getNum(tokens[i]));
			} 
		} //end of for
		stackTop = tempstack.size();
		if(stackTop == 1)//最后应该剩下1个元素
			return  tempstack[0];
		else
		{
  			return 0;
		}
			
    }
    /*
	返回数字 
	*/
    int getNum(string input)
    {
    	const char *in = input.c_str();
    	int num = 0, i = 0, sign = 1;
    	if(!isdigit(in[0]) && in[0] != '-' && in[0] != '+')
    	{
	    	return 0;//如果第一个字符都不是数字返回 false 
	    }
	    if(in[0] == '-') sign = -1,i = 1;
	    if(in[0] == '+') sign = 1,i = 1;
	    
   		while(in[i] != '\0')
	   {
   			if(isdigit(in[i]))
   				num = num*10+ in[i] - '0';
			else
			{
				break;
			}
			i++;
   		} 
   		return (sign*num);
    }
    /*
	+ 返回 1
	- 返回 2   
	* 返回 3
	/ 返回 4
	其他 返回 0 
	*/
	int isOperator(string input) 
	{
		const char *in = input.c_str();
		if(input.length() > 1)
			return 0;
		switch(in[0])
		{
		case '+':
			return 1;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 4;
		}
		return 0;
	}
	
};



void test(string intokens[] , int n, int ret )
{
	Solution so;
	vector<string> tokens(intokens,intokens + n);
	cout<<"vector size = "<<tokens.size()<<endl;
	//cout<<tokens[3]<<endl;
	if(ret == so.evalRPN(tokens))
	{
		printf("------------------------------pass\n");
	}
	else
	{
		printf("------------------------------failed!!!\n");
	}
}
int main()
{
	
	string intokens[5] = {"2", "1", "+", "3", "*"}; 
	test(intokens,5,9); 
	
	string intokens1[5] = {"4", "13", "5", "/", "+"}; 
	test(intokens1,5,6); 
	
	string intokens2[5] = {"3","-4","+"}; 
	test(intokens2,3,-1); 
	
	return 0;
}
