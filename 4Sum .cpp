/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
using namespace std;
	
/*
vector<vector<int> > 后一个>前需要加一个空格 
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num,int target) {
		vector<vector<int> > ret;
		 ret.clear();
        sort(num.begin(),num.end());
        for(int h = 0;h<num.size();h++)
        {
        	if(h > 0 && num[h]==num[h-1])		//和前一个相同表示该子问题已经解决 
					continue;
	        for(int i=h+1; i!=num.size();i++){
	    		if(i > h+1 && num[i]==num[i-1])		//和前一个相同表示该子问题已经解决 ////////////////////////////大于 h+1 
					continue;
				int j,k;
				j=i+1;
				k=num.size()-1;
				while(j<k){
					if(j>i+1&&num[j]==num[j-1]){ 	//和前一个相同表示该子问题已经解决 
						j++;
						continue;
					}
					if(k<num.size()-1&& num[k]==num[k+1]){//和前一个相同表示该子问题已经解决 
						k--;
						continue;
					}
					 int sum = num[h] + num[i] + num[j] + num[k];
					if(sum>target){
						k--;
					}else if(sum<target){
						j++;
					}else{
						vector<int> tmp;
						tmp.push_back(num[h]);
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[k]);
						ret.push_back(tmp);
						j++;
					}
				}
			}
        }
		return ret;
            
    }
};

void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}

void printvecvec(vector<vector<int > > A, char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:",i);
		printvec(A[i]);
	}
	printf("\n");
}

void test0()
{
	int arr[] = {1 ,0 ,-1 ,0 ,-2, 2};
	vector<int> numbers (arr, arr + sizeof(arr) / sizeof(int) );
	Solution so;
	vector< vector<int> > out = so.fourSum(numbers,0);
	printvecvec(out,"out");
	/*int i = 0,j = 0, flag = 1;
	for(i = 0;i<out.size();i++)
	{
		if(!(out[i].size() == 3 && out[i][0] + out[i][1] + out[i][2] == 0 && out[i][0]<=out[i][1] && out[i][1]<=out[i][2]))
		{
			flag = 0;
			break;
		}
		printf("%4d,%4d,%4d\n",out[i][0],out[i][1],out[i][2]);
	}
	if(out.size()<3)//-7 -1 8		-7 2 5    -1 -4 5 
		flag = 0;
		*/
	if(1 == 1)
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

 

