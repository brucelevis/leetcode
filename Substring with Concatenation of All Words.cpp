/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <map>
#include <vector>
#include "leetcode.h"
using namespace std;
#if 0
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        map<string, int> words;
        map<string, int> visited;
        for (int i = 0; i < L.size(); i++) {
            words[L[i]]++;
        }
        int len=L[0].size();
        for (int ii = 0; ii < (1 - L.size() * len); ii++) {
        	//printf("i %d s %d l %d l%d d%d\n", ii, S.size(),  L.size(), L[0].size(), S.size() - L.size() * L[0].size());
        	printf("ii = %d, d = %d\n", ii, (S.size() - L.size() * L[0].size()));
        	printf("%d\n", ii < (S.size() - L.size() * L[0].size()));
        	system("pause");
            visited.clear();
            for (int j = ii; j < S.size(); j += L[0].size()) {
                string tmpstr = S.substr(j, L[0].size());
                map<string, int>::iterator it0 = words.find(tmpstr);
                if (it0 == words.end()) break;
                map<string, int>::iterator it1 = visited.find(tmpstr);
                if (it1 == visited.end()) {
                    visited[tmpstr] = 1;
                } else if (visited[tmpstr] >= words[tmpstr]) {
                    break;
                } else {
                    visited[tmpstr]++;
                }
            }
            if (words == visited) {
                ret.push_back(ii);
            }
        }
        return ret;
    }
};
#elif 1
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        map<string,int> words;
        map<string,int> visited;
        map<string,int>::iterator iter1,iter2;
        int i,j;
        int len=L[0].size();
        //if(S.size()<L.size()*len) return res;
        for(i=0;i<L.size();i++) words[L[i]]++;
        for(i=0;i<=S.size()-L.size()*len;i++)
        {
            visited.clear();
            for(j=i;j<=S.size()-len;j=j+len)
            {
                string temp=S.substr(j,len);
                iter1=words.find(temp);
                iter2=visited.find(temp);
                if(iter1==words.end()) break;
                if(iter1->second<=iter2->second) break;
                visited[temp]++;
            }
            if(words==visited) res.push_back(i);
        }
        return res;
    }
};
#endif
void test0()
{
	
	Solution so;
	vector<int> exspect;
	vector<string> L;
	L.push_back("a");
	L.push_back("a");
	vector<int> out = so.findSubstring("a",L);
	printvec(out, "out");
	if(0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		/**/
}
int main()
{
	test0();
	return 0;
}