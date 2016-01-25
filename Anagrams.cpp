/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
���ȼ򵥽���һ��Anagram�����Ĺ��ʷ�����Anagrams��ָ�ɵߵ���ĸ˳����ɵĵ��ʣ�����
��dormitory���ߵ���ĸ˳����ɡ�dirty room������tea�����ɡ�eat����
���Ĺ��ʷ���һ���ص㣺���������ĸ���������Ŀû�иı䣬ֻ�Ǹı�����ĸ������˳��
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> ret;
    	//mp ��ʼָ����ǵ�һ����ӵ��ַ��������������л��Ĵ�ʱ��ͨ���������
		//�����ҵ���һ�γ��ֵ��ַ�����Ӻ��mpָ��-1 
    	map<string, int> mp;
    	for(int i = 0;i<strs.size();i++)
    	{
    		string s = strs[i];
    		sort(s.begin(),s.end());
    		if(mp.count(s) > 0)
    		{
    			//���ֵڶ���ʱ��Ҫ����Ҫ�ѵ�һ������
				if(mp[s]>=0)
				{
					ret.push_back(strs[mp[s]]); 
					mp[s] = -1;
				}
				ret.push_back(strs[i]);
			}
			else
			{
				mp[s] = i;
			}
		}
		return ret;
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