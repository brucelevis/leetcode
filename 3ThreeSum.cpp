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
#if 1
class Solution {

public:

    vector<vector<int> > threeSum(vector<int> &num) {

        sort(num.begin(), num.end());

        vector<vector<int> > ret;

        if (num.size() < 3) return ret;

        

        for (int i = 0; i < num.size(); i++) {

            if (i > 0 && num[i] == num[i - 1])

                continue;

            int m = i + 1, n = num.size() -1;

            while (m < n) {
			  printf("%d %d %d\n",i,m,n);
                if (m > i + 1 && num[m] == num[m - 1]) {

                    m++;

                    continue;

                }

                if (n < num.size() - 1 && num[n] == num[n + 1]) {

                    n--;

                    continue;

                }

                if (num[i] + num[m] + num[n] == 0) {

                    vector<int> tmp;

                    tmp.push_back(num[i]);

                    tmp.push_back(num[m]);

                    tmp.push_back(num[n]);

                    ret.push_back(tmp);
                    m++;

                } else if (num[i] + num[m] + num[n] > 0) {

                    n--;

                } else {

                    m++;

                }

            }

        }

        return ret;

    }

};
#elif 1
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ret;
		 ret.clear();
        sort(num.begin(),num.end());
        for(int i=0; i!=num.size();i++){
    		if(i > 0 && num[i]==num[i-1])		//和前一个相同表示该子问题已经解决 
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
				 int sum = num[i] + num[j] + num[k];
				if(sum>0){
					k--;
				}else if(sum<0){
					j++;
				}else{
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);
					ret.push_back(tmp);
					j++;
				}
			}
		}
		return ret;
            
    }
};
#endif 
void test0()
{
	int arr[] = {0,-1,2,3,-4,5,6,-7,8,9};
	vector<int> numbers (arr, arr + sizeof(arr) / sizeof(int) );
	Solution so;
	vector< vector<int> > out = so.threeSum(numbers);
	int i = 0,j = 0, flag = 1;
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
	if(flag == 1)
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

 

