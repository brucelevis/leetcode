/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0;
        bool havePoint = false;
        bool haveE = false;
        bool start = false;
        
        if(!s)	return false;
		while(s[i] && s[i] == ' ')	i++;
		if(!s[i])	return false;
		if(s[i] == '-' || s[i] == '+')	i++;
		if(!s[i])	return false;
		while(s[i])
		{
			if(start)
			{
				if(s[i] == 'e' && !haveE)
				{
					if(!(s[i+1]&&(isdigit(s[i+1]) || s[i+1] == '-' || s[i+1] == '+'))) return false;///////////////////
					haveE = true;
					i++;
					
					if(s[i] == '-' || s[i] == '+')
					{
						i++;
						if(!isdigit(s[i])) return false;						
					}					
					continue;
				}
				if(s[i] == ' ')///////////////////
				{
					while(s[i] && s[i] == ' ')	i++;///////////////////
					if(!s[i])	return true;//////////////////////
					else 		return false;////////////////////////////
				}
			}
			if(s[i] == '.' && !havePoint && !haveE)////////////////////// 
			{
				if(!((s[i+1]&&isdigit(s[i+1])) || start)) return false;/////////////////////////////////
				havePoint = true;
				i++;
				continue;
			}
			if(!isdigit(s[i]))	return false;
			else				start = true;
			i++;
		}
		return true; 
    }
};
/*
1���ո��ܳ���������֮��

2�����e���ֻ�ܳ���һ��

3������e֮ǰ����������

4��������Ҫô���������ֵ���ǰ�棬Ҫô�����ڽ�����e����

5��e������뻹��������

6������������������

*/
void check(char* in ,bool ret)
{
	printf("%10s",in);
	Solution so;
	if(so.isNumber(in) != ret)
		printf("************************failed\n");
	else
		printf("------------------------passed\n");
}
void test0()
{
	check("   ",false);
	check(" 0.1o  ",false);
	check(" abc  ",false);
	check(" ++2  ",false);
	check("  2..3 ",false);
	
	
	check("1 4",false);////////////////
	
	
	check("1 ",true);//////////////////////
	check("2.3",true);
	check(" 1.245",true);
	check(".",false);////////////////
	check("1. ",true);//////////////////////
	check(".1",true);//////////////////////// 
	check("6e6.5",false);////////////////
	check("4e+",false);//////////////////////// 
	check("0e",false);////////////////	
	check("005047e+6",true);//////////////////////// 
	
	 
	
	check(" 154",true);
	check(" 874",true);
	
	check(" 2e10",true);
}
int main()
{
//	printf("%f\n",2.0e3);
//	printf("%f\n",2.0e-3);
//	printf("%f\n",2.0e+3);
	
	test0();
	return 0;
}