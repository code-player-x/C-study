#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
//����ˮ��
class AbstractFruit{
public:
	virtual void ShowName() = 0;
};
//ƻ��
class Apple :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����ƻ��!" << endl;
	}
};
//�㽶
class Banana :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "�����㽶!" << endl;
	}
};
//Ѽ��
class Pear :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����Ѽ��!" << endl;
	}
};
//���󹤳�
class AbstractFruitFactory{
public:
	virtual AbstractFruit*CreateFruit() = 0;
};
// ƻ������
class AppleFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit*CreateFruit(){
		return new Apple;
	}
};
//�㽶����
class BananaFactory :public AbstractFruitFactory{
public:
	virtual AbstractFruit*CreateFruit(){
		return new Banana;
	}
};
//Ѽ�湤��
class PearFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit*CreateFruit(){
		return new Pear;
	}
};
void test01() {
	AbstractFruitFactory*factory = NULL;
	AbstractFruit*fruit = NULL;
	//����һ��ƻ������
	factory = new AppleFactory;
	//����ƻ��
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	//����һ���㽶����
	factory = new BananaFactory;
	//�����㽶
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	//����һ��Ѽ�湤��
	factory = new PearFactory;
	//����Ѽ��
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
}
int main()
{
	test01();
	return 0;
}