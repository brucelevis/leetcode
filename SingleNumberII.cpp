#include <iostream>

using namespace std;
#if 0
/*
ͳ��ÿһ��bit�ĸ�������mod3 
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int i = 0, j = 0, ret = 0,count = 0;
        for(i = 0; i< 32;i++)//32λ����
		{ 
	        for(j = 0;j<n;j++)
	        {
	        	if((A[j]>>i) & 1)count++;		//�״�㣺��Ҫ��&д��&&	        	
			}
			ret |= (count%3)<<i;
			count = 0;							//������Ҫ��0 
		} 
		return ret;
    }
};
#elif 0
class Solution {
public:
    int singleNumber(int A[], int n) {
        int one=0, two=0, three=0;			//one��¼����һ�Σ�two��¼�������Σ�three��¼�������� 
        int i = 0; 
		for (i=0;i<n;i++) 
		{
 			two |= one & A[i];				//�������ε�����һ�γ���һ�Σ��뱾�ε������롣Ȼ���ٻ���ԭ���������εġ� 
			one ^= A[i];					//��¼ֻ����һ�εġ���Ϊ�������εľ����Ϊ0�ˣ�Ȼ���¼���������� 
 			three = one & two;				//���ξ������κ�һ�ε��� 
 			one &= ~three;					//����������ε� 
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
            threes = twos & A[i]; //�Ѿ��������β����ٴγ���
            twos = twos | ones & A[i]; //�����������εĻ�����������һ�ε����ٴγ��ֵ�
            ones = ones | A[i]; //����һ�ε�
            
            twos = twos & ~threes; //��ĳһλ�������κ����Ǿʹӳ���������������λ
            ones = ones & ~threes; //��ĳһλ�������κ����Ǿʹӳ���һ����������λ
            //printf("%d--%d---%d\n",ones,twos,threes);
        }
        return ones; //twos, threes���ն�Ϊ0.ones��ֻ����һ�ε���
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

