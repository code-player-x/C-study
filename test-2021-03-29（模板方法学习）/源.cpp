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
	virtual void BoilWater() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//�Ӹ�����
	virtual void AddSomething() = 0;

	//ģ�巽��
	void Make()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};
//���ݿ���
class Coffee :public DrinkTemplate
{
	//��ˮ
	virtual void BoilWater() {
		cout << "������ˮ..." << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���..." << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "���ȵ��뱭��..." << endl;
	}
	//�Ӹ�����
	virtual void AddSomething() {
		cout << "����,��ţ��..." << endl;
	}
};
//���ݲ�
class Tea :public DrinkTemplate {
public:
	//��ˮ
	virtual void BoilWater() {
		cout << "��ɽȪˮ..." << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ..." << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "��Ҷ���뱭��..." << endl;
	}
	//�Ӹ�����
	virtual void AddSomething() {
		cout << "���Ӹ�����..." << endl;
	}
};
void test01()
{
	Tea* tea = new Tea;
	tea->Make();
	cout << "------------" << endl;
	Coffee* coffee = new Coffee;
	coffee->Make();
}
int main()
{
	test01();
	return 0;
}
//�ŵ㣺
//(1)�ڸ�������ʽ���ض���һ���㷨����������������ʵ��ϸ�ڵĴ���
//������ʵ����ϸ�Ĵ����㷨ʱ������ı��㷨�в����ִ�д���
//(2)ģ�巽��ģʽ��һ�ִ��븴�ü�����������������Ϊ��Ҫ������ȡ������еĹ�����Ϊ��
//��������Ϊ���ڸ����У���ͨ����������ʵ�ֲ�ͬ����Ϊ������������ǡ��ʹ�ü̳���ʵ�ִ��븴�á�
//(3)��ʵ��һ�ַ�����ƽṹ��ͨ�����า�Ǹ���Ĺ��ӷ���������ĳһ�ض������Ƿ���Ҫִ�С�
//(4)��ģ�巽��ģʽ�п���ͨ�����������Ǹ���Ļ�����������ͬ����������ṩ���������Ĳ�ͬʵ�֣�
//�����������µ�����ܷ��㣬���ϵ�һְ��ԭ��Ϳ���ԭ��