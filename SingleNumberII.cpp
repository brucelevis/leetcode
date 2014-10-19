#include <iostream>

using namespace std;
#if 0
/*
统计每一个bit的个数，再mod3 
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int i = 0, j = 0, ret = 0,count = 0;
        for(i = 0; i< 32;i++)//32位整数
		{ 
	        for(j = 0;j<n;j++)
	        {
	        	if((A[j]>>i) & 1)count++;		//易错点：不要把&写成&&	        	
			}
			ret |= (count%3)<<i;
			count = 0;							//这里需要清0 
		} 
		return ret;
    }
};
#elif 0
class Solution {
public:
    int singleNumber(int A[], int n) {
        int one=0, two=0, three=0;			//one记录出现一次，two记录出现两次，three记录出现三次 
        int i = 0; 
		for (i=0;i<n;i++) 
		{
 			two |= one & A[i];				//出现两次的是上一次出现一次，与本次的数字与。然后再或上原来就是两次的。 
			one ^= A[i];					//记录只出现一次的。因为出现两次的就异或为0了，然后记录在两次里了 
 			three = one & two;				//三次就是两次和一次的且 
 			one &= ~three;					//清除出现三次的 
			two &= ~three;
			//printf("%d--%d---%d\n",one,two,three);
 		}
   		return one;
    }
};
#elif 1
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for(int i = 0; i < n; i++)
        {
            threes = twos & A[i]; //已经出现两次并且再次出现
            twos = twos | ones & A[i]; //曾经出现两次的或者曾经出现一次但是再次出现的
            ones = ones | A[i]; //出现一次的
            
            twos = twos & ~threes; //当某一位出现三次后，我们就从出现两次中消除该位
            ones = ones & ~threes; //当某一位出现三次后，我们就从出现一次中消除该位
            //printf("%d--%d---%d\n",ones,twos,threes);
        }
        return ones; //twos, threes最终都为0.ones是只出现一次的数
    }
}; 
#endif
void test0()
{
	int A[] = {1,2,3,4,5,6,1,2,3,4,5,1,2,3,4,5};
	Solution so;
	int a = so.singleNumber(A,16);
	if(a != 6)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}

