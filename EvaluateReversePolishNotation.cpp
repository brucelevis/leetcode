#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

#define DEBUG

using namespace std;

/**
���ܲ��ԣ��ܹ�������
�������룺�����ʽ���� ���븺��   -�͸������� 

*/
#if 1
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        
        for(int i = 0;i<tokens.size();i++)
        {
            int tmp = isOperator(tokens[i]);
            if(tmp == 0)
            {
                int num = atoi(tokens[i].c_str());
                stk.push(num);
            }
            else
            {
            	int num1 = 0, num2 = 0, num = 0;
                if(stk.size() >= 2)
                {
                    num1 = stk.top();
                    stk.pop();
                    num2 = stk.top();
                    stk.pop();
                }
                else
                    printf("error");
                switch(tmp)
                {
                    case 1:
                        num = num1 + num2;
                    break;
                    case 2:
                        num = num2 - num1;
                    break;
                    case 3:
                        num = num1 * num2;
                    break;
                    case 4:
                        num = num2 / num1;
                    break;
                }
                stk.push(num);
            }
            
        }
        int ret = stk.top();
        return ret;
    }
    /*
    1---+
    2----
    3---*
    4---/
    */
    int isOperator(string opr)
    {
        if(opr[0] == '*')
            return 3;
        if(opr[0] == '/')
            return 4;
        if(opr[0] == '+' && opr.size() == 1)
            return 1;
        if(opr[0] == '-' && opr.size() == 1)
            return 2;
        return 0;
    }
};
#elif 0
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
			//printf("1 %d\n",opt);
			opt = isOperator(tokens[i]);
			
			if(opt)//���������� 
			{
				stackTop = tempstack.size();
				if(stackTop >= 2)//����Ҫ2��Ԫ��
				{
					num2 = tempstack[--stackTop];
					tempstack.pop_back();//�������һ��Ԫ�� 
					num1 = tempstack[--stackTop];
					tempstack.pop_back();//�������һ��Ԫ��
  #ifdef DEBUG
  					printf("opt = %d num1 = %d, num2 = %d\n",opt,num1,num2);
  #endif					
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
  #ifdef DEBUG
					printf("the number of stack new\n");
					
					for(int it = 0;it < tempstack.size();it++)
					{
					  	cout<<tempstack[it]<<endl;
			  		}
					printf("----\n");
  #endif
				} 
				else
				{
  #ifdef DEBUG
  					printf("error 1\n");
  #endif					
				} 
			}
			else
			{//������ 
				//printf("3 %d\n",tempstack.size());
				tempstack.push_back(getNum(tokens[i]));
  #ifdef DEBUG
	  			printf("the number of stack\n");
	  			
	  			for(int it = 0;it < tempstack.size();it++)
	  			{
				  	cout<<tempstack[it]<<endl;
				  }
	  			printf("----\n");
  #endif 				
			} 
		} //end of for
		stackTop = tempstack.size();
		if(stackTop == 1)//���Ӧ��ʣ��1��Ԫ��
			return  tempstack[0];
		else
		{

#ifdef DEBUG
  			printf("error 2\n");  			
  #endif
  			return 0;
		}
			
    }
    /*
	�������� 
	*/
    int getNum(string input)
    {
    	const char *in = input.c_str();
    	int num = 0, i = 0, sign = 1;
    	//printf("g1 %d",input.length());
    	if(!isdigit(in[0]) && in[0] != '-' && in[0] != '+')
    	{
  #ifdef DEBUG
  			printf("no is a number\n");
  #endif  		
	    	return 0;//�����һ���ַ����������ַ��� false 
	    }
	    if(in[0] == '-') sign = -1,i = 1;
	    if(in[0] == '+') sign = 1,i = 1;
	    
    	//printf("i = %d sign = %d\n",i,sign);
   		while(in[i] != '\0')
	   {
   			if(isdigit(in[i]))
   				num = num*10+ in[i] - '0';
			else
			{
#ifdef DEBUG
  				printf("have unvalid number\n");
  #endif 
				break;
			}
			i++;
   		} 
  #ifdef DEBUG
  			printf("ret = %d\n",(sign*num));
  #endif 
   		return (sign*num);
    }
    /*
	+ ���� 1
	- ���� 2   
	* ���� 3
	/ ���� 4
	���� ���� 0 
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

#endif 

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
