/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#if 1
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> mp;
        int maxlen = 0;
        for(int i = 0;i<num.size();i++)
            mp[num[i]] = 1;
        for(int i = 0;i<num.size();i++)
        {
            if(!mp[num[i]]) continue;
            int tmplen = 1;
            int tmp = num[i]-1;
            while(mp[tmp])
            {
                mp.erase(tmp--);
                tmplen++;
            }
            tmp = num[i]+1;
            while(mp[tmp])
            {
                mp.erase(tmp++);
                tmplen++;
            }
            if(tmplen > maxlen) maxlen = tmplen;
        }
        return maxlen;
    }
};
#elif 1
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> mp;
        int maxlen = 0;
        for(int i = 0;i<num.size();i++)
            mp[num[i]] = 1;
        for(int i = 0;i<num.size();i++)
        {
            if(mp[num[i]])
            {
                int font = 1;
                while(mp[num[i]-font])
                {
                    mp.erase(num[i]-font);
                    font++;
                }
                int back = 1;
                while(mp[num[i]+back])
                {
                    mp.erase(num[i]+back);
                    back++;
                }
                if(font + back -1 >maxlen)
                    maxlen = font+back-1;
                mp.erase(num[i]);
            }
        }
        return maxlen;
    }
};
#elif 1

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> mp;
        for(int i = 0;i< num.size();i++)
        	if(!mp.count(num[i])) mp[num[i]] = 1;
       	
       	int tmp_len = 0, max_len = 0;
       	for(int i = 0;i< num.size();i++)
       	{
       		if(!mp.count(num[i]))	continue;
       		
       		//printf("%d\n",num[i]);
       		int tmp = num[i]-1;
       		while(mp.count(tmp))
       		{
       			//printf("---%d\n",tmp);
       			tmp_len++;
       			mp.erase(tmp);
       			tmp--;
	   		}
	   		tmp = num[i]+1;
	   		while(mp.count(tmp))
       		{
       			//printf("+++%d\n",tmp);
       			tmp_len++;
       			mp.erase(tmp);
       			tmp++;
	   		}
	   		mp.erase(num[i]);
	   		tmp_len++;
	   		if(tmp_len > max_len) max_len = tmp_len;/////////////不要用tmp tmp_len这中易混的变量名 
	   		tmp_len = 0;
	   	}
	   	return max_len;
    }
};

#endif
void test0()
{
	int A[] = {100, 4, 200, 1, 3, 2};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	int out = so.longestConsecutive(num);
	if(out != 4)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}