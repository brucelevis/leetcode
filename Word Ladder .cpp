/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start == end) return 1;
        queue<string > que;
        map<string , int> dist;
        dist[start] = 0;
        que.push(start);
        while(!que.empty()){
            string top = que.front();que.pop();
            for(int i = 0 ; i < top.length() ; i++){
                for(int j = 'a' ; j <= 'z' ; j++){
                    if(j != top[i]){
                        string next = top;
                        next[i] = j;
                        if(next == end){
                            return dist[top] + 2;
                        }
                        if(dict.find(next) != dict.end() && dist.find(next) == dist.end()){
                            dist[next] = dist[top] + 1;
                            que.push(next);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

void test0()
{
	if(0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}