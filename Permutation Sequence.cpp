#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int pCount = 1;
        for(int i = 0 ; i < n; ++i) {
            nums[i] = i + 1;
            pCount *= (i + 1);
        }

        k--;
		string res = "";
        for(int i = 0 ; i < n; i++) {
        	cout<<"pcount="<<pCount<<" k="<<k<<endl;
			pCount = pCount/(n-i);
            int selected = k / pCount;
			res += ('0' + nums[selected]);
            cout<<"res="<<res<<endl;
            for(int j = selected; j < n-i-1; j++)
                nums[j] = nums[j+1];
            k = k % pCount;
        }
        cout<<"res="<<res<<endl;
        return res;
    }
};

void test0()
{
	Solution so;
	cout<<so.getPermutation(4, 18)<<endl;
}
int main(int argc, char *argv[])
{
	test0();
	return 0;
}