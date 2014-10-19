/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printvec(vector<string > A, char *name)
{
	printf("%s:\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%13d:",i);
		cout<<A[i]<<endl;
	}
	printf("\n");
}

#if 1
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int size = s.size();
        if(size < 4) return ret;
        string tmp = "";//////////////////////////////////////////////////
        restoreIpAddressesHelper(ret,s,tmp,0,0);//////////////////////////////////////////////////////////
    }
    void restoreIpAddressesHelper(vector<string> &ret,const string &s,string &tmp,int deep,int index)
    {
    	//printf("deep = %d i = %d \ntmp=",deep,index);
    //	cout<<tmp<<endl;
        if(deep == 4 && index == s.size())
        {
            //tmp.erase(index -1,1);//去除最后一个逗号///////////////////////////////////
            tmp.erase(tmp.size() -1,1);
            ret.push_back(tmp);
            tmp += ".";//恢复///////////////////////////////// 
            //cout<<"ret tmp="<<tmp<<endl;
            return;
        }
        if(deep == 4)   return;
        
        if(s[index]<= '9' && s[index] >='0')
        {
            tmp = tmp + (char)s[index] + ".";///////////////////////////////////////////////////////////////////////
            restoreIpAddressesHelper(ret,s,tmp,deep+1,index+1);//这一部分长1位
            tmp.erase(tmp.size()-2,2);//移除添加的部分
            //cout<<"00 tmp="<<tmp<<endl;
            if(s[index] != '0')//本字段如果要出现两位以上，那个这么第一个字符不能是0
            {
                if(index+1<s.size() && s[index+1]<= '9' && s[index+1] >='0')
                {
                    tmp = tmp + (char)s[index] + (char)s[index+1] + ".";
                    restoreIpAddressesHelper(ret,s,tmp,deep+1,index+2);//这一部分长2位
                    tmp.erase(tmp.size()-3,3);//移除添加的部分
                   // cout<<"11 tmp="<<tmp<<endl;
                    if(index+2<s.size() && s[index+2]<= '9' && s[index+2] >='0')
                    {
                        int tmpi = (s[index]-'0')*100+(s[index+1]-'0')*10+(s[index+2]-'0');
                        if(tmpi < 256)
                        {
                            tmp = tmp + (char)s[index] + (char)s[index+1] + (char)s[index+2] + ".";
                            restoreIpAddressesHelper(ret,s,tmp,deep+1,index+3);//这一部分长3位
                            tmp.erase(tmp.size()-4,4);//移除添加的部分
                         //   cout<<"22 tmp="<<tmp<<endl;
                        }
                    }
                }
            }
        }
    }
};
#elif 0
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> tmp;
        restoreIpAddresses(ret,s,tmp,0,0);
        return ret;
    }
    void restoreIpAddresses(vector<string> &ret,const string &s,vector<string> &tmp,int index,int deep)
    {
    	if(deep == 4 && index != s.size())	
			return;
    	
    	if(deep == 4 && index == s.size())
    	{
    		cout<<index<<" "<<s.size()<<endl;
    		string tmpstr = tmp[0]+"."+tmp[1]+"."+tmp[2]+"."+tmp[3];
    		
    	//	if(setret.find(tmpstr) == setret.end())
    		{
	    		ret.push_back(tmpstr);//去掉最后一个逗号 
	    	//	setret.insert(tmpstr);
	    		return;
    		}
		}
		 
			
    	if(index < s.size() && s[index]<='9' && s[index] >= '0')
    	{
    		tmp.push_back(s.substr(index,1));
    		printvec(tmp,"1");
    		restoreIpAddresses(ret,s,tmp,index+1,deep+1);
    		tmp.pop_back();
		}
		
		if(index < s.size()-1 && s[index+1]<='9' && s[index+1] >= '0')
    	{
    		if(s[index] != '0')
    		{
    			tmp.push_back(s.substr(index,2));
	    		printvec(tmp,"2");
	    		restoreIpAddresses(ret,s,tmp,index+2,deep+1);
	    		tmp.pop_back();
    		}
		}
		
    	if(index < s.size()-2 && s[index+2]<='9' && s[index+2] >= '0')
    	{
    		int tmpint = (s[index]-'0')*100+(s[index+1]-'0')*10+(s[index+2]-'0');
    		if(tmpint < 256 && tmpint > 99)
    		{
				tmp.push_back(s.substr(index,3));
	    		printvec(tmp,"3");
	    		restoreIpAddresses(ret,s,tmp,index+3,deep+1);
	    		tmp.pop_back();
    		}
		}	
   		
	}
	//set<string > setret;
};
#endif

void test0(string ips)
{
	Solution so;
	
	cout<<ips<<endl;
	vector<string> out = so.restoreIpAddresses(ips);
	
	printvec(out,"out");
}
int main()
{
	test0("25525511135");
	test0("0000");
	test0("111111");
	test0("010010");
	return 0;
}