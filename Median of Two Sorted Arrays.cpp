#include <iostream>
using namespace std;

#if 1

class Solution {
public:
    double findKth(int a[], int m, int b[], int n, int k)
	{
		if(n<m)
			return findKth(b,n,a,m,k);
		if(m==0)
			return b[k-1];
		if(k==1)
			return min(a[0],b[0]);
		int pa = min(m,k/2);
		int pb = k - pa;
		if(a[pa-1] < b[pb-1])
			return findKth(a+pa,m-pa,b,n,k-pa);
		else if(a[pa-1] > b[pb-1])
			return findKth(a,m,b+pb,n-pb,k-pb);
		else
			return a[pa-1];
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once.
        int total = m+n;
		if(total & 0x1)
			return findKth(A,m,B,n,total/2+1);
		else
			return (findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2;
    }
};
#elif 0
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid0 = 0 , mid1 = 0, i = 0, j = 0,sum = 0;
        int flag = 0;
        //if(n==0 )
		if((m+n)%2 == 0) flag = 1;
		while(i<m&& j<n && sum < ((n+m)/2+1))
		{
			mid0 = mid1;
			if(A[i]<B[j])
			{
				mid1 = A[i];
				i++;////////////////////////////////////////i++µÄÎ»ÖÃ 
			}
			else
			{
				mid1 = B[j];
				j++;
			}
			sum++;
		//	printf("mid0 = %d,mid1=%d sum = %d\n",mid0,mid1,sum);
		} 
		while(i<m && sum < ((n+m)/2+1))
		{
			mid0 = mid1;
			mid1 = A[i];
			i++;
			sum++;
		}
		
		while(j<n && sum < ((n+m)/2+1))
		{
			mid0 = mid1;
			mid1 = B[j];
			j++;
			sum++;
		}
		
		if(flag == 1) 	return ((double)mid0+(double)mid1)/2;
		else			return (double)mid1;
    }
};

#endif
int main(int argc, char *argv[])
{
	int A[] = {1,2};
	int B[] = {1,2};
	
	Solution so;
	cout<<so.findMedianSortedArrays(A,2,B,2)<<endl;
	return 0;
}