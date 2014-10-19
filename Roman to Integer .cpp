#include <iostream>
#include <map> 
using namespace std;
//要想明白是从前到后还是从后到前 
//罗马数字 
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1;    mp['V'] = 5;
        mp['X'] = 10;   mp['L'] = 50;
        mp['C'] = 100;  mp['D'] = 500;
        mp['M'] = 1000;
        int size = s.size(), ret = 0, i = 0;
        while(i<size)
		{
			if(i<size - 1 && mp[s[i]] < mp[s[i+1]])
				ret = ret + mp[s[i+1]] - mp[s[i]],i+=2;
			else
				ret = ret + mp[s[i]],i++;
		}         
		return ret;
    }
};

void test0(string x,int expect)
{
	Solution so;
	int ret = so.romanToInt(x);
	if(ret != expect)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main(int argc, char *argv[])
{
	test0("I",1);
	test0("II",2);
	test0("IV",4);
	test0("V",5);
	test0("VI",6);
	test0("MMMCMXCIX",3999);
	return 0;
}
