/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
using namespace std;
	
/*
vector<vector<int> > ��һ��>ǰ��Ҫ��һ���ո� 
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num,int target) {
		if(num.size() < 3)	return 0;
		sort(num.begin(),num.end());
		int ret = num[0]+num[1]+num[2];
        for(int i=0; i!=num.size();i++){
    		if(i > 0 && num[i]==num[i-1])		//��ǰһ����ͬ��ʾ���������Ѿ���� 
				continue;
			int j,k;
			j=i+1;
			k=num.size()-1;
			while(j<k){
				if(j>i+1&&num[j]==num[j-1]){ 	//��ǰһ����ͬ��ʾ���������Ѿ���� 
					j++;
					continue;
				}
				if(k<num.size()-1&& num[k]==num[k+1]){//��ǰһ����ͬ��ʾ���������Ѿ���� 
					k--;
					continue;
				}
				 int sum = num[i] + num[j] + num[k];
				 if(abs(sum - target) < abs(ret - target))
				 	ret = sum;
				if(sum>target){
					k--;
				}else if(sum<target){
					j++;
				}else{
					return target;
				}
			}
		}
		return ret;
            
    }
};
void test0()
{
	int arr[] = {0,1,3,5,7,8,9};
	vector<int> numbers (arr, arr + sizeof(arr) / sizeof(int) );
	Solution so;
	int out = so.threeSumClosest(numbers,11);
	
	if(out == 11)
	{
		printf("------------------------passed\n");
	}
	else
	{
		printf("------------------------failed\n");
	}
}
int main()
{
	test0();
	//test1();
	
	return 0;
}

 

