#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//����ģ��
class DrinkTemplate
{
public:
	//��ˮ
	virtual void BoildWater() = 0;
	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourInCup() = 0;
	//�Ӹ�����

	virtual void AddSomething() = 0;

	void Make()
	{
		BoildWater();
		Brew();
		PourInCup();
		AddSomething();
	}

};

//���ݿ���
class Coffee :public DrinkTemplate
{


	//��ˮ
	virtual void BoildWater()
	{
		cout << "��ũ��ɽȪ" << endl;
	}
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}

	//���뱭��
	virtual void PourInCup()
	{
		cout << "���ȵ��뱭��" << endl;
	}
	//�Ӹ�����

	virtual void AddSomething()
	{
		cout << "���ǣ���ţ��..." << endl;
	}

};
class Tea :public DrinkTemplate
{
public:

	//��ˮ
	virtual void BoildWater()
	{
		cout << "��ɽȪˮ" << endl;
	}
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}

	//���뱭��
	virtual void PourInCup()
	{
		cout << "��Ҷ���뱭��" << endl;
	}
	//�Ӹ�����

	virtual void AddSomething()
	{
		cout << "���Ӹ�����..." << endl;
	}

};

void test1()
{
	Tea* tea = new Tea;
	tea->Make();
	cout << "����������������������������������������������������������������" << endl;
	Coffee* coffee = new Coffee;
	coffee->Make();

}

int main()
{
	test1();
	return 0;
}
/*�ŵ�
1���ڸ�������ʽ���Ķ���һ���㷨����������������ʵ��ϸ�ڵĴ���������ʵ����ϸ�Ĵ���
�㷨ʱ��������ı��㷨�в����ִ�д���
2��ģ�巽��ģʽ��һ�ִ��븴�ü�������������������Ϊ��Ҫ������ȡ����еĹ�����Ϊ
����������Ϊ���ڸ����У���ͨ����������ʵ�ֲ�ͬ����Ϊ������������ǡ��ʹ�ü̳���ʵ�ִ��븴��
3����ʵ��һ�ַ�����ƽṹ��ͨ�����า�Ǹ���Ĺ��췽��������ĳһ�ض������Ƿ���Ҫִ��
4����ģ�巽��ģʽ�У�����ͨ�����������Ǹ���Ļ�����������ͬ����������ṩ���������Ĳ�ͬʵ��
�������������µ�����ܷ��㣬���ϵ�һְ��ԭ��Ϳ���ԭ��*/