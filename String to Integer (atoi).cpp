/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
using namespace std;
#if 0
class Solution {
public:
    int atoi(const char *str) {
        long long tmp = 0;////////////////////////////初始化 
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
		printf("%2d-%c-%5d\n",index,str[index],tmp);
		while(str[index] && str[index] >= '0' && str[index]<= '9')
		{
			tmp = tmp*10+str[index] - '0';
			printf("%2d-%c-%5d\n",index,str[index],tmp);
			if(tmp/10 > INT_MAX)
				break;	
			index++;			
		}
		printf("%2d-%c-%5d\n",index,str[index],tmp);
		tmp = sign*tmp;
		if(tmp > INT_MAX )			return INT_MAX;
		else	if(tmp < INT_MIN)	return INT_MIN;
		return (int)tmp; 
    }
};
#elif 1
class Solution {
public:
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
		if(tmp > INT_MAX )			return INT_MAX;
		else	if(tmp < INT_MIN)	return INT_MIN;
		return (int)tmp; 
    }
};
#endif

void test0()
{
	Solution so;
	cout<<so.atoi("-10293")<<endl;
	cout<<so.atoi("")<<endl;
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