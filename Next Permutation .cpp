#include <iostream>
#include <vector>
using namespace std;
void printvec(vector<int > A, char *name)
{
	printf("%s:",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}
#if 0//�Ż�ǰ 
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if(size < 2)	return;
        for(int i = size -2;i>=0;i--)
        	for(int j = size - 1;j>i;j--)
        	{
        		if(num[i] < num[j])
        		{
        			//printvec(num,"0");
        			swap(num[i],num[j]);
        			//printvec(num,"1");
        			sort(num.begin()+i+1,num.end());
        			//printvec(num,"2");
        			return;
				}
			}
		sort(num.begin(),num.end());
    }
};
#elif 1
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if(size < 2)	return;
        int i = 0, j = 0;         
        //�ҵ���i���㡣��i֮���ǽ��������� num[i]<num[i+1] 
		for(i = size -2;i>=0;i--)
        	if(num[i] < num[i+1])
        		break;
		if(i == -1)//˵�����������ǽ������еģ�����ֱ�Ӱ����鷴�򼴿�
			reverse(num.begin(),num.end()); 
		else
		{//��β��ǰ�ң��ҵ���һ����num[i]�������Ȼ���num[i]�������ɵ��������� 
			for(j = size - 1;j>i;j--)
				if(num[i] < num[j])
        			break;
 			swap(num[i],num[j]);//���ʱ��Ҫ��i+1��n�ǽ���������ʱ��Ҫ�Ѻ����ȫ������һ��
			reverse(num.begin()+i+1,num.end()) ;
		}
    }
};
#endif 
void test0()
{
	int A[] = {1,2,3};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	so.nextPermutation(num);
	printvec(num,"num");
}
void test1()
{
	int A[] = {1,3,2};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	so.nextPermutation(num);
	printvec(num,"num");
}
void test2()
{
	int A[] = {2,1,3};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	so.nextPermutation(num);
	printvec(num,"num");
}
void test3()
{
	int A[] = {2,3,1};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	so.nextPermutation(num);
	printvec(num,"num");
}
void test4()
{
	int A[] = {3,1,2};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	so.nextPermutation(num);
	printvec(num,"num");
}
void test5()
{
	int A[] = {4,2,0,2,3,2,0};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	so.nextPermutation(num);
	printvec(num,"num");
}
int main(int argc, char *argv[])
{
/*	test0();
	test1();
	test2();
	test3();
	test4();*/
	test5();
	return 0;
}
