#include <iostream>
#include <string>

/*

*/
using namespace std;

/*
正常输入测功能
边界输入
特殊输入 
	1-一个空格
	2-空格开关，结尾，中间有连续空格 

*/
class Solution {
public:
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
	
//	system("pause");
	return 0;
}
