#include <iostream>
#include <vector>
using namespace std;

#if 0
class Solution {
public:
void get(vector<int> &num, int index, vector<vector<int > > &solution)
	{
		if(index >= num.size())
		{
			solution.push_back(num);
			return;
		}else
			for(int i = index; i < num.size(); i++)
			{
				swap(num[index],num[i]);
				get(num,index+1,solution);
				swap(num[index],num[i]);
			}
	}
	vector<vector<int > > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once.
        vector<vector<int > > solution;
		if(num.size()<1)return solution;
		get(num, 0, solution);
		return solution;
    }
};
#elif 0
class Solution {
public:
    void internalPermute(vector<int> &num, int index, vector<int> &perm, vector<vector<int> > &result) {
        int size = num.size();
        
        if (size == index) {
            result.push_back(perm);
        }
        else {
            for (int i = index; i < size; ++i) {
                swap(num[index], num[i]);
                perm.push_back(num[index]);
                internalPermute(num, index + 1, perm, result);
                perm.pop_back();
                swap(num[index], num[i]);
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> perm;
        
        internalPermute(num, 0, perm, result);
        
        return result;
    }
};
#elif 1
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> rcd;
        subPermute(res, num, rcd);
        return res;
    }
    void subPermute(vector<vector<int> > &res, vector<int> &num, vector<int> &rcd){
        if(num.size() == 0){
            res.push_back(rcd);
            return;
        }
        for(int i = 0; i < num.size(); ++i){
            vector<int> temp = num;
            rcd.push_back(temp[i]);
            for(int j = i; j < num.size() -1 ;++j){
                temp[j] = temp[j+1];
            }
            temp.pop_back();
            subPermute(res, temp, rcd);
            rcd.pop_back();
        }
    }
};
#endif
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
	int A[] = {1,2,3,4};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	printvecvec(so.permute(num),"ret");
}
int main()
{
	test0();
	return 0;
}
