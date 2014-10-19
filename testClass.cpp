#include <iostream>
using namespace std;
class Base
{
	public:
		virtual void foo()
		{
			printf("Base foo\n");
		}
};

class Derived: public Base
{
	public:
		virtual void foo()
		{
			printf("Derived foo\n");
		}
};

int main(int argc, char *argv[])
{
	Base *pBase = NULL;
	Base objBase;
	Derived objDerived;
	
	pBase = &objDerived;
	pBase->foo();
	pBase->Base::foo();
	return 0;
}