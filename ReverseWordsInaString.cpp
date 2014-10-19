#include <iostream>
#include <string>

/*

*/
using namespace std;


class Solution {
public:
/*
正常输入测功能
边界输入
特殊输入 
	1-一个空格
	2-空格开关，结尾，中间有连续空格 

*/
#if 0 //自己写的 
    void reverseWords(string &s) {
        string tmps = "";
		if(s.length() <= 0)
        	return;
        	
		int len = s.length();
		int subStrStart = 0, subStrEnd = 0;
 		while(1)
 		{
			subStrEnd = s.find_first_of(' ',subStrStart);
			if(subStrEnd != string::npos)
			{
				//cout<<"1tmp = "<<tmps<<endl;
				if(subStrEnd == subStrStart)//以空格开头 或中间有连续空格 
				{
					subStrStart = subStrEnd + 1; 
					continue; 
				} 
				//cout<<"2tmp = "<<tmps<<endl;
				if(tmps != "") 
				{
					tmps.insert(0," ",0,1);//插入一个空格
				//	cout<<"add space"<<endl; 
				}
				
				//cout<<"3tmp = "<<tmps<<endl;
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));
				//cout<<"4tmp = "<<tmps<<endl;
				
				subStrStart = subStrEnd + 1; 
				//cout<<"5tmp = "<<tmps<<endl;
			}
			else//后面没有空格了 
			{
				subStrEnd = len;
				if(tmps != "" && subStrEnd != subStrStart) 
				{
					tmps.insert(0," ",0,1);//插入一个空格
				//	cout<<"add space"<<endl; 
				}
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));	
				//cout<<"6tmp = "<<tmps<<endl;
				break;
			} 
		 }
		 s=tmps;
		 return;      
    }
    #elif 1//优化自己的代码 
   void reverseWords(string &s) {
        string tmps = "";
		if(s.length() <= 0)
        	return;
        	
		int len = s.length();
		int subStrStart = 0, subStrEnd = 0;
 		while(1)
 		{
			subStrEnd = s.find_first_of(' ',subStrStart);
			if(subStrEnd != string::npos)
			{
				if(subStrEnd == subStrStart)//以空格开头 或中间有连续空格 
				{
					subStrStart = subStrEnd + 1; 
					continue; 
				} 
				if(tmps != "") 
				{
					tmps.insert(0," ",0,1);//插入一个空格
				}
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));
				subStrStart = subStrEnd + 1; 
			}
			else//后面没有空格了 
			{
				subStrEnd = len;
				if(tmps != "" && subStrEnd != subStrStart) 
				{
					tmps.insert(0," ",0,1);//插入一个空格
				}
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));	
				break;
			} 
		 }
		 s=tmps;
		 return;      
    }
   #elif 1//网上找的一个代码
   void reverseWords(string &s)
  {
    string rs;
    for (int i = s.length()-1; i >= 0; )
    {
      while (i >= 0 && s[i] == ' ') i--;
      if (i < 0) break;
      if (!rs.empty()) rs.push_back(' ');
      string t;
      while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);
      reverse(t.begin(), t.end());
      rs.append(t);
    }
    s = rs;
  }
   #else
   #endif 
};

/*
设计校验 
*/ 
void checkRes(string in,string expectedStr)
{
	if(in == expectedStr)
		cout<<"---------------------------------------pass!"<<endl;
	else
	{
		cout<<"---------------------------------------failed!!!!!"<<endl;
		cout<<"expected =|"<<expectedStr<<"."<<endl;
		cout<<"outpue   =|"<<in<<"."<<endl;	
	}		
}

int main()
{
	Solution So;//这里不需要new 
	///*
	string input;
	input = "the sky is blue";
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = " the sky is blue";//以空格打头 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = "the sky is blue ";//以空格结尾 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = "the sky is            blue";//中间有连续的空格 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = "hello world!";//
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"world! hello"); 
	
	input = " ";//只有一个空格 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,""); 
	//*/
	input = "1 ";//
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"1"); 
	//input.insert(0,"hello",0,4);
	
	//cout<<input.find_first_of(' ',4)<<endl;
	//cout<<input<<endl;
	
//	printf("%s\n",input.c_str());
//	system("pause");
	return 0;
}
