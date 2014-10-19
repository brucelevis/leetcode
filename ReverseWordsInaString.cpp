#include <iostream>
#include <string>

/*

*/
using namespace std;


class Solution {
public:
/*
��������⹦��
�߽�����
�������� 
	1-һ���ո�
	2-�ո񿪹أ���β���м��������ո� 

*/
#if 0 //�Լ�д�� 
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
				if(subStrEnd == subStrStart)//�Կո�ͷ ���м��������ո� 
				{
					subStrStart = subStrEnd + 1; 
					continue; 
				} 
				//cout<<"2tmp = "<<tmps<<endl;
				if(tmps != "") 
				{
					tmps.insert(0," ",0,1);//����һ���ո�
				//	cout<<"add space"<<endl; 
				}
				
				//cout<<"3tmp = "<<tmps<<endl;
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));
				//cout<<"4tmp = "<<tmps<<endl;
				
				subStrStart = subStrEnd + 1; 
				//cout<<"5tmp = "<<tmps<<endl;
			}
			else//����û�пո��� 
			{
				subStrEnd = len;
				if(tmps != "" && subStrEnd != subStrStart) 
				{
					tmps.insert(0," ",0,1);//����һ���ո�
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
    #elif 1//�Ż��Լ��Ĵ��� 
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
				if(subStrEnd == subStrStart)//�Կո�ͷ ���м��������ո� 
				{
					subStrStart = subStrEnd + 1; 
					continue; 
				} 
				if(tmps != "") 
				{
					tmps.insert(0," ",0,1);//����һ���ո�
				}
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));
				subStrStart = subStrEnd + 1; 
			}
			else//����û�пո��� 
			{
				subStrEnd = len;
				if(tmps != "" && subStrEnd != subStrStart) 
				{
					tmps.insert(0," ",0,1);//����һ���ո�
				}
				tmps.insert(0,s,subStrStart,(subStrEnd - subStrStart));	
				break;
			} 
		 }
		 s=tmps;
		 return;      
    }
   #elif 1//�����ҵ�һ������
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
	//input.insert(0,"hello",0,4);
	
	//cout<<input.find_first_of(' ',4)<<endl;
	//cout<<input<<endl;
	
//	printf("%s\n",input.c_str());
//	system("pause");
	return 0;
}
