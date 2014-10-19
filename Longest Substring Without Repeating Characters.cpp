#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printstr(string s, int start,int end)
{
	for(int i = start;i<end;i++)
	{
		printf("%c,",s[i]);
	}
	printf("\n");
}

#if 0
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> start_index(256, -1);
        int sub_start = -1;
        int max_len = 0;
        for(int i = 0; i < s.size(); i++) {
            if (start_index[s[i]] > sub_start) {
                sub_start = start_index[s[i]];
            }
            if (i - sub_start > max_len)
                max_len = (i - sub_start);
            start_index[s[i]] = i;
        }
        return max_len;
    }
};
#elif 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int index = -1;//开始出现重复的下标 初始必须是-1 
		int locs[256] = {0};
		memset(locs,-1,256*sizeof(int));////!!!这里要* sizeof(int)
		
		for(int i = 0;i<s.size();i++)
		{
			if(locs[s[i]]>index)//如果s[i]出现过，就把index置为出现重复的坐标 
				index = locs[s[i]];
			if(i-index > max_len)
				max_len = i-index;
		 	locs[s[i]] = i;				
		}         
		return max_len;
    }
};
#endif
void test(string s,int ret)
{
	Solution so;
	int len = so.lengthOfLongestSubstring(s);
	if(len != ret)
		printf("------------------------failed out:%d expect:%d\n",len,ret);
	else
		printf("------------------------passed\n");
	
}
int main(int argc, char *argv[])
{
	test("abcabcbb",3);
	test("aaaaaaa",1);
	test("ruowzgiooobpple",7); 
	test("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST",94);
	return 0;
}


