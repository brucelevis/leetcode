/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
#if 0
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != (s1.size() + s2.size()))	return false;
        return isInterleaveCore(s1,0,s2,0,s3,0);
    }
    bool isInterleaveCore(const string &s1,int index1,const string &s2,int index2, const string &s3,int index3)
    {
    	if(index3 == s3.size())	return true;
    	
    	//printf("%d-%d-%d\n");
    	if(s1[index1] == s3[index3] && isInterleaveCore(s1,index1+1,s2,index2,s3,index3+1))	return true;
    	if(s2[index2] == s3[index3] && isInterleaveCore(s1,index1,s2,index2+1,s3,index3+1))	return true;
    	return false;
	}
};
#elif 1
class Solution {
private:
    bool f[1000][1000];
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if (s1.size() + s2.size() != s3.size())
            return false;
            
        f[0][0] = true;
        for(int i = 1; i <= s1.size(); i++)
            f[i][0] = f[i-1][0] && (s3[i-1] == s1[i-1]);
            
        for(int j = 1; j <= s2.size(); j++)
            f[0][j] = f[0][j-1] && (s3[j-1] == s2[j-1]);
            
        for(int i = 1; i <= s1.size(); i++)
            for(int j = 1; j <= s2.size(); j++)
                f[i][j] = (f[i][j-1] && s2[j-1] == s3[i+j-1]) || (f[i-1][j] && s1[i-1] == s3[i+j-1]);
                
        return f[s1.size()][s2.size()];
    }
};
#endif
void test0(string s1, string s2, string s3, bool ret)
{
	Solution so;
	
	if(so.isInterleave(s1,s2,s3) != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	//test0("aabcc","dbbca","aadbbcbcac",true);
	//test0("aabcc","dbbca","aadbbbaccc",false);
	test0("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab",true);
	return 0;
}