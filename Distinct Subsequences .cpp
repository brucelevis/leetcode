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
#if 1
class Solution {
    public:
int numDistinct(string S, string T) {
        vector <vector <int> > num(S.size()+1,vector<int>(T.size()+1));
        for(int i = 0; i<=S.size(); i++){
            num[i][0] = 0;
        }
        for(int j=0; j<=T.size(); j++){
            num[0][j] = 0;
        }
        
        for(int i = 1; i<=S.size(); i++){
            for(int j = 1; j<=i && j<=T.size(); j++){
                num[i][j] = num[i-1][j];
                if(S[i-1] == T[j-1]){
                    if(j == 1){
                        num[i][j] += 1;
                    }else{
                        num[i][j] += num[i-1][j-1];
                    }
                }
            }
        }
        
        //printvecvec(num,"ret");
        return num[S.size()][T.size()];
    }
};
#elif 1
class Solution {
public:

    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int len_s = S.size();
		int len_t = T.size();
		vector <vector <int> > f(len_s+1,vector<int>(len_t+1));
		if(len_s < len_t)
			return 0;
		for(int i = 0 ; i <= len_s ; i++)
			f[i][0] = 0;
		for(int j = 0 ; j <= len_t ; j++)
			f[0][j] = 0;

		for(int i = 1 ; i <= len_s ;i++)
			if(S[i-1]==T[0])
				f[i][1] = f[i-1][1] + 1;
			else
				f[i][1] = f[i-1][1];			
		for(int i = 2;  i <= len_s ; i++)
			for(int j = 2; j <= len_t ; j++)
				if(S[i-1]==T[j-1])
					f[i][j] = f[i-1][j-1] + f[i-1][j];
				else
					f[i][j] = f[i-1][j];
		return f[len_s][len_t];
    }
};
#endif
void test0()
{
	Solution so;
	if(so.numDistinct("rabbbit","rabbit") != 3)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
} 
int main(int argc, char *argv[])
{
	test0();
	return 0;
}
