/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sizea = a.size()-1, sizeb = b.size()-1;
        unsigned char takeover = 0 , tmp = 0;
        string ret = "";
        while(sizea >= 0 || sizeb >= 0)
        {
        	if(sizea >= 0 && sizeb >= 0)
        		tmp = a[sizea] - '0' + b[sizeb] - '0' + takeover;
       		else if(sizea >= 0)
       			tmp = a[sizea] - '0' + takeover;
 			else
 				tmp = b[sizeb] - '0' + takeover;
			if(tmp > 1)
			{
				ret = (char)(tmp-2+'0')+ret;////////////////////////应该是-2 而不是>>2 
				takeover = 1;
			}
			else
			{
				ret = (char)(tmp+'0')+ret;
				takeover = 0;
			}
			sizea--;
			sizeb--;
				
		}
		if(takeover>0)
			ret = '1'+ret;
			
		//cout<<a<<"+"<<b<<"="<<ret<<endl;
		return ret;
    }
};
void test0()
{
	Solution so;
	if(so.addBinary("11","11") != "110")
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}