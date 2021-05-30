#include<iostream>
#include<memory>
using namespace std;

class A
{
public:
	virtual void f()
	{}

	int _a;
};
class B :public A
{
public:


	int _b;


};

void f_cast(A* pa)
{
	//如果想区分pa是指向父类，还是子类对象？
	//如果pa是指向子类对象，则转换成功，
	//如果pa指向父类对象，则转换失败返回nullptr
	B* pb = dynamic_cast<B*>(pa);
	if (pb != nullptr)
	{
		cout << "转换成功：pa指向子类对象" << endl;
		pb->_a = 1;
		pb->_b = 1;
	}
	else
	{
		cout << "转换失败：pa指向子类对象" << endl;

	}
}
int x1()
{
	//hungry_man::x2();
	int i = 0;
	double d = 8.88;
	i = d;//类型转换 c语言支持相近类型的隐式类型转换（相近类型，也就是意义相似的类型）
	cout << i << endl;
	 
	int *p = nullptr;
	p = (int*)i;//c语言支持相近类型的强制类型转换（不相近类型，也就是意义差别很大的类型）
	cout << p << endl;
	

	// C++兼容C语言留下来的隐式转换和显示转换，但是C++觉得C语言做得不规范，C++想规范一下
	//static_cast
	d = static_cast<double>(i);//对应C语言的隐式类型转换（相近类型）
	p = reinterpret_cast<int*>(i);//对应C语言大部分强制类型转换（不相近类型）
	
	volatile const int ci = 10;
	int *pi = const_cast<int*>(&ci);//对应C语言强制类型转换中去掉const属性的（不相近类型）
	
	*pi = 100;
	cout << *pi << endl;//100
	cout << ci << endl;//10 这里打印是10是因为ci存储的内存被改了，但是ci被放进了寄存器里，这里去寄存器中取，还是10，本质这是由于编译器对const对象存取优化机制导致。加一个volatile可以防止优化机制

	A a;
	B b;
	//c++中子类对象可以赋值给父类的对象，指针，引用，这个过程中会发生切片，这个过程是语法天然支持的，这个叫向上转换

	//如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程有可能成功，要看具体情况
	//最后需要注意的是，dynamic_cast向下转换只能针对继承中的多态类型（父类必须包含虚函数）

	////因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢? dynamic_cast的原理// dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。|

	//dynamic_cast是通过到pa指向对象的虚表上方找到标识对象的信息如果是A，就不让转，返回空
	//如果是B，可以转，正常返回对象地址所以要求A必须是多态类型

	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);
	return 0;
}

class AA
{
public:
	 explicit AA(int a1)
	{
		cout << "AA(int a)" << endl;
	}
	 explicit AA(int a1,int a2)
	 {
		 cout << "AA(int a1,int a2)" << endl;
	 }
	AA(const AA& a)
	{
		cout << "AA(const A& a)" << endl;
	}
private:
	int _a1;
	int _a2;

};
int main()
{
	AA a1(1);
	// 隐式转换-> A tmp(1); A a2(tmp);再优化成直接构造
	//AA a2 = 1;
}