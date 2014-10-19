#include <iostream>
#include <map> 
using namespace std;
//要想明白是从前到后还是从后到前 
//罗马数字 
#if 1
class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mp;
        mp[1] = "I";    mp[5] = "V";
        mp[10] = "X";   mp[50] = "L";
        mp[100] = "C";  mp[500] = "D";
        mp[1000] = "M";
        string ret;
        int tmp = 0, cmpnum = 1;
        while(num)
        {
        	tmp = num%10;
        	switch(tmp)
        	{
        		case 0:
       				break;
       			case 1:case 2:case 3:
	       			while(tmp--)
						ret = mp[cmpnum] + ret;
       				break;       			
       			case 4:case 9:
       				ret = mp[(tmp+1)*cmpnum] + ret;
       				ret = mp[cmpnum] + ret;
       				break;       			
       			case 5:
       				ret = mp[cmpnum*5] + ret;
       				break;
  				case 6:case 7:case 8:
  					while((tmp--)-5)
						ret = mp[cmpnum] + ret;
  					ret = mp[cmpnum*5] + ret;  					
				  	break; 
			}
			cmpnum *= 10;
			num = num/10;	
		}
		return ret;
    }
};
#elif 0
class Solution {
public:
    const string romans[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM", "", "", "", "", "", ""}
    };
    
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ans = "";
        int idx = 0;
        while (num != 0) {            
            ans = romans[idx][num % 10] + ans;
            num /= 10;
            idx++;
        }
        return ans;
    }
};
#endif
void test0(string x,int expect)
{
	Solution so;
	string ret = so.intToRoman(expect);
	if(ret != x)
		printf("------------------------%s<>%s failed\n",x.c_str(),ret.c_str());
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
	test0("MMMDCLIV",3654);
	return 0;
}
