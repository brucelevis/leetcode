/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
//������Ҫע�� *����0��ʱ��ʾǰ����һ������Ч�ġ� 
class Solution {
public:
   bool isMatch(const char *s, const char *p) {
    //assert(s && p);
    if (*p == '\0') return *s == '\0';

    // next char is not '*': must match current character
    if (*(p+1) != '*') {
        //assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);//�ڽ���s+1ʱҪ��֤s���ǿ� 
    }
	
    // next char is '*'
    while ((*p == *s) || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p+2)) return true;
        s++;
    }
    //��ѭ���������� *p��=*s && ��*p ��= '.' || *s == '\0'�� 
    return isMatch(s, p+2);//*p �����Ǹ� *��ʾ 0 
}
};
void test0(char *s,char *p,bool ret)
{
	Solution so;
	if(so.isMatch(s,p) != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0("aa","a",false);
	test0("aa","aa",true);
	test0("aaa","aa",false);
	test0("aa", "a*",true);
	test0("aa", ".*",true);
	test0("ab", ".*",true);
	test0("aab", "c*a*b",true);
	test0("ab", ".*c",false);
	test0("ab", "ab.",false);//��.��ƥ�����ⵥ���ַ�����*��ƥ��0������ǰһ�ַ������ƥ������������true��
	return 0;
}