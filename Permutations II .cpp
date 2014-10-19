#include <iostream>
#include <vector>
using namespace std;
void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}
void printvec(vector<int > A, char *name)
{
	printf("%s:",name);
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
#if 0

class Solution {
public:
    void internalpermuteUnique(vector<int> &num, int index, vector<int> &perm, vector<vector<int> > &result) {
        int size = num.size();
        
        if (size == index) {
        	//printvec(perm,"per");
            result.push_back(perm);
        }
        else {
            for (int i = index; i < size; ++i) {
                if ((i > index) && (num[i] == num[index])) {
                	//printvec(num,"num");
                	//printf("con num[i=%d] = %d num[index = %d] = %d\n",i,num[i],index,num[index]);
                  continue;
                }
                else {
                  swap(num[index], num[i]);
                  //printvec(num,"num2");
                }
                
                perm.push_back(num[index]);
                internalpermuteUnique(num, index + 1, perm, result);
                perm.pop_back();
            }
            
            sort(num.begin() + index, num.end());
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> perm;
        
        sort(num.begin(), num.end());
        internalpermuteUnique(num, 0, perm, result);
        
        return result;
    }
};
#elif 1
class Solution {
public:
    void internalpermuteUnique(vector<int> &num, int index,  vector<vector<int> > &result) {
        int size = num.size();
        
        if (size == index) {
        	//printvec(perm,"per");
            result.push_back(num);
        }
        else {
            for (int i = index; i < size; ++i) {
                if ((i > index) && (num[i] == num[index])) {
                	//printvec(num,"num");
                	//printf("con num[i=%d] = %d num[index = %d] = %d\n",i,num[i],index,num[index]);
                  continue;
                }
                else {
                  swap(num[index], num[i]);
                  //printvec(num,"num2");
                }
                
                internalpermuteUnique(num, index + 1, result);
            }
            
            sort(num.begin() + index, num.end());
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        
        sort(num.begin(), num.end());
        internalpermuteUnique(num, 0, result);
        
        return result;
    }
};
#endif

void test0()
{
	int A[] = {1,1,2,2};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	printvecvec(so.permuteUnique(num),"ret");
}
void test1()
{
	int A[] = {0,1,0,0,9};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	printvecvec(so.permuteUnique(num),"ret");
}
void test2()
{
	int A[] = {-1,2,0,-1,1,0,1};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	printvecvec(so.permuteUnique(num),"ret");
}

int main()
{
	//freopen("log.txt","w",stdout);
	test0();
	//fclose(stdout);
	//freopen("CON","w",stdout);
	//system("log.txt");
	return 0;
}
