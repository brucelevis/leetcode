#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        size_t pos = 0,prepos = 0;
        vector<string> vec;
        
        pos = path.find("/",0);
        while(pos != string::npos)
        {
        	string tmp= path.substr(prepos,pos-prepos);
        	if(tmp == "."){}
        	else if(tmp == "..")
        	{
        		if(vec.size()>0)
        			vec.pop_back();
			}
			else if(tmp != "")
				vec.push_back(tmp);
			prepos = pos+1;
			pos = path.find("/",pos+1);
			///*
			cout<<"tmp="<<tmp<<" pos="<<pos<<"prepos="<<prepos<<endl;
			
			for(int i = 0;i<vec.size();i++)
			{
				cout<<i<<" "<<vec[i]<<endl;
			}
			//*/
		}
		if(prepos < path.size())//////////////这部分的处理是一个重点 
		{
			string tmp= path.substr(prepos,path.size()-prepos+1);
			cout<<"tmp="<<tmp<<endl;
			if(tmp == "..")/////这些判断即使在最后一个也不能少 
				if(vec.size()>0) vec.pop_back();
				else{}////////////////////////////////////////////////
			else if(tmp != "." && tmp != "")
				vec.push_back(tmp);
		}
		string ret="";
		for(int i = 0;i<vec.size();i++)
		{
			cout<<i<<":"<<vec[i]<<endl;
			ret+="/"+vec[i];
		}
		if(ret == "")	ret = "/";
        return ret;
    }
};


int main(int argc, char *argv[])
{
	Solution so;
	//cout<<so.simplifyPath("/a/./b/../../c/")<<endl;
	//cout<<so.simplifyPath("///eHx/..")<<endl;
	cout<<so.simplifyPath("/..")<<endl;
	return 0;
}