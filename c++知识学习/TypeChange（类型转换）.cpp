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
	//���������pa��ָ���࣬�����������
	//���pa��ָ�����������ת���ɹ���
	//���paָ���������ת��ʧ�ܷ���nullptr
	B* pb = dynamic_cast<B*>(pa);
	if (pb != nullptr)
	{
		cout << "ת���ɹ���paָ���������" << endl;
		pb->_a = 1;
		pb->_b = 1;
	}
	else
	{
		cout << "ת��ʧ�ܣ�paָ���������" << endl;

	}
}
int x1()
{
	//hungry_man::x2();
	int i = 0;
	double d = 8.88;
	i = d;//����ת�� c����֧��������͵���ʽ����ת����������ͣ�Ҳ�����������Ƶ����ͣ�
	cout << i << endl;
	 
	int *p = nullptr;
	p = (int*)i;//c����֧��������͵�ǿ������ת������������ͣ�Ҳ����������ܴ�����ͣ�
	cout << p << endl;
	

	// C++����C��������������ʽת������ʾת��������C++����C�������ò��淶��C++��淶һ��
	//static_cast
	d = static_cast<double>(i);//��ӦC���Ե���ʽ����ת����������ͣ�
	p = reinterpret_cast<int*>(i);//��ӦC���Դ󲿷�ǿ������ת������������ͣ�
	
	volatile const int ci = 10;
	int *pi = const_cast<int*>(&ci);//��ӦC����ǿ������ת����ȥ��const���Եģ���������ͣ�
	
	*pi = 100;
	cout << *pi << endl;//100
	cout << ci << endl;//10 �����ӡ��10����Ϊci�洢���ڴ汻���ˣ�����ci���Ž��˼Ĵ��������ȥ�Ĵ�����ȡ������10�������������ڱ�������const�����ȡ�Ż����Ƶ��¡���һ��volatile���Է�ֹ�Ż�����

	A a;
	B b;
	//c++�����������Ը�ֵ������Ķ���ָ�룬���ã���������лᷢ����Ƭ������������﷨��Ȼ֧�ֵģ����������ת��

	//����Ǹ����ָ��������ã����������ָ�룬������̽�����ת������������п��ܳɹ���Ҫ���������
	//�����Ҫע����ǣ�dynamic_cast����ת��ֻ����Լ̳��еĶ�̬���ͣ������������麯����

	////��Ϊdynamic_cast���ʶ�����ָ����ָ�������������������? dynamic_cast��ԭ��// dynamic_castͨ��ȥ�����Ϸ��洢�ı�ʶ��Ϣ�����ж�ָ����������������|

	//dynamic_cast��ͨ����paָ����������Ϸ��ҵ���ʶ�������Ϣ�����A���Ͳ���ת�����ؿ�
	//�����B������ת���������ض����ַ����Ҫ��A�����Ƕ�̬����

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
	// ��ʽת��-> A tmp(1); A a2(tmp);���Ż���ֱ�ӹ���
	//AA a2 = 1;
}