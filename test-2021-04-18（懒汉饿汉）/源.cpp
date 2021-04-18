#include<iostream>
#include<string>
using namespace std;

class A
{
private:
	A()
	{
		a = new A;
	}
public:
	static A* getInstance()
	{
		return a;
	}
private:
	static A* a;//
	//在外面不能利用这个类去创建对象
	//实现单例步骤
	//1、构造函数私有化（单例模式只能实例化一个对象）
	//2、增加静态私有的当前类的指针变量
	//3、提供静态对外接口，可以让用户获得单例对象
};
//int main()
//{
//
//	A::getInstance();
//
//	return 0;
//}
//单例分为懒汉式和饿汉式
//懒汉式，调用getinstance的时候才回去new一个对象

class Singleton_lazy
{
	//静态
private:
	Singleton_lazy()
	{
		cout << "懒汉式创建" << endl;
	}
private:
	static Singleton_lazy* pSingleton;
public:
	static Singleton_lazy* getInstance()
	{
		if (pSingleton == nullptr)
		{
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
	static void freespace()
	{
		if (pSingleton != nullptr)
			delete pSingleton;
	}
};
Singleton_lazy* Singleton_lazy::pSingleton = NULL;//

//int main()
//{
//	cout << "main函数" << endl;
//	Singleton_lazy* p1 = Singleton_lazy::getInstance();
//	Singleton_lazy* p2 = Singleton_lazy::getInstance();
//	if (p1 == p2)
//	{
//		cout << "两个指针指向同一块内存空间，是单例" << endl;
//	}
//	else
//	{
//		cout << "不是单例模式" << endl;
//	}
//	Singleton_lazy::freespace();
//}


//单例  饿汉式
class Singleton_hungry
{
	class Garbo
	{
		~Garbo()
		{
			if (pSingleton != nullptr)
				delete pSingleton;
		}
	};
public:
	static Singleton_hungry* getInstance()
	{
		return pSingleton;
	}
	static void freespace()
	{
		if (pSingleton != nullptr)
			delete pSingleton;
	}
private:
	Singleton_hungry()
	{
		cout << "我是饿汉构造" << endl;
	}
	//成员变量
private:
	static Singleton_hungry* pSingleton;//指向对象的指针
	static Garbo garbo;
};
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;
int main()
{
	cout << "进入main函数" << endl;
	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4)
		cout << "两个指针指向同一块内存空间，是单例" << endl;
	else
	{
		cout << "不是单例模式" << endl;
	}
	Singleton_hungry::freespace();
	return 0;
}
//其实单例模式的核心就是构造函数私有化，让用户不能自己new一个对象
//饿汉式是直接在调用main函数之前初始化一个对象，
//懒汉式是在需要访问对象时才实例化，完事之后通过static来
//保证大家访问的都是一个示例

