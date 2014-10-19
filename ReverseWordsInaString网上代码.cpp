#include <iostream>
#include <string>

/*

*/
using namespace std;

/*
��������⹦��
�߽�����
�������� 
	1-һ���ո�
	2-�ո񿪹أ���β���м��������ո� 

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
���У�� 
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
	Solution So;//���ﲻ��Ҫnew 
	///*
	string input;
	input = "the sky is blue";
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = " the sky is blue";//�Կո��ͷ 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = "the sky is blue ";//�Կո��β 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = "the sky is            blue";//�м��������Ŀո� 
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"blue is sky the"); 
	
	input = "hello world!";//
	cout<<"input =|"<<input<<"."<<endl;	
	So.reverseWords(input);
	checkRes(input,"world! hello"); 
	
	input = " ";//ֻ��һ���ո� 
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
