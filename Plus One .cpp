#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	//vector<int> ret(digits);
        int size = digits.size();
        if(size == 0)	return digits;
        plusOneCore(digits,size - 1);
        return digits;
    }
    void plusOneCore(vector<int> &digits,int index)
    {
    	if(digits[index] < 9)
    		digits[index]++;
		else
		{
			digits[index] = 0; 
    		if(index == 0)//最高位要进1 
    			digits.insert(digits.begin(),1);
    		else
				plusOneCore(digits,index-1); //进位 
		}
	}
};

void printvec(vector<int > A, char *name)
{
	printf("%s:",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}
void test0()
{
	int A[] = {1,2,3,4,5,6,7,8,9};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	vector<int> out = so.plusOne(num);
	printvec(out,"ret");
}

void test1()
{
	int A[] = {9,9};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	vector<int> out = so.plusOne(num);
	printvec(out,"ret");
}

int main()
{
	test0();
	test1();

	return 0;
}


