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
	//�����治�����������ȥ��������
	//ʵ�ֵ�������
	//1�����캯��˽�л�������ģʽֻ��ʵ����һ������
	//2�����Ӿ�̬˽�еĵ�ǰ���ָ�����
	//3���ṩ��̬����ӿڣ��������û���õ�������
};
//int main()
//{
//
//	A::getInstance();
//
//	return 0;
//}
//������Ϊ����ʽ�Ͷ���ʽ
//����ʽ������getinstance��ʱ��Ż�ȥnewһ������

class Singleton_lazy
{
	//��̬
private:
	Singleton_lazy()
	{
		cout << "����ʽ����" << endl;
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
//	cout << "main����" << endl;
//	Singleton_lazy* p1 = Singleton_lazy::getInstance();
//	Singleton_lazy* p2 = Singleton_lazy::getInstance();
//	if (p1 == p2)
//	{
//		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���" << endl;
//	}
//	else
//	{
//		cout << "���ǵ���ģʽ" << endl;
//	}
//	Singleton_lazy::freespace();
//}


//����  ����ʽ
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
		cout << "���Ƕ�������" << endl;
	}
	//��Ա����
private:
	static Singleton_hungry* pSingleton;//ָ������ָ��
	static Garbo garbo;
};
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;
int main()
{
	cout << "����main����" << endl;
	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4)
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���" << endl;
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}
	Singleton_hungry::freespace();
	return 0;
}
//��ʵ����ģʽ�ĺ��ľ��ǹ��캯��˽�л������û������Լ�newһ������
//����ʽ��ֱ���ڵ���main����֮ǰ��ʼ��һ������
//����ʽ������Ҫ���ʶ���ʱ��ʵ����������֮��ͨ��static��
//��֤��ҷ��ʵĶ���һ��ʾ��

