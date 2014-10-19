#include <iostream>
using namespace std;
void printarr(int A[],int n, char *name)
{
	printf("%s:",name);
	for(int i = 0;i<n;i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}
class Solution {
public:
    void sortColors(int A[], int n) {
        int total[3] = {0};
		for(int i = 0;i<n;i++)
		{
			if(A[i]<3 && A[i]>=0)
				total[A[i]]++;
		}
		//printf("%d-%d-%d\n",total[0],total[1],total[2]);
		int index = 0;
		for(int i=0;i<3;i++)
		{
			for(int j = 0;j<total[i];j++)
				A[index++] = i;
		}
    }
};

int main()
{
	int A[9] = {0,0,1,2,2,1,1,2,0};
	Solution so;
	so.sortColors(A,9);
	printarr(A,9,"");
	return 0;
}