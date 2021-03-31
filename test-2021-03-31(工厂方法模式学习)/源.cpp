#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
//抽象水果
class AbstractFruit{
public:
	virtual void ShowName() = 0;
};
//苹果
class Apple :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是苹果!" << endl;
	}
};
//香蕉
class Banana :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是香蕉!" << endl;
	}
};
//鸭梨
class Pear :public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "我是鸭梨!" << endl;
	}
};
//抽象工厂
class AbstractFruitFactory{
public:
	virtual AbstractFruit*CreateFruit() = 0;
};
// 苹果工厂
class AppleFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit*CreateFruit(){
		return new Apple;
	}
};
//香蕉工厂
class BananaFactory :public AbstractFruitFactory{
public:
	virtual AbstractFruit*CreateFruit(){
		return new Banana;
	}
};
//鸭梨工厂
class PearFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit*CreateFruit(){
		return new Pear;
	}
};
void test01() {
	AbstractFruitFactory*factory = NULL;
	AbstractFruit*fruit = NULL;
	//创建一个苹果工厂
	factory = new AppleFactory;
	//创建苹果
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	//创建一个香蕉工厂
	factory = new BananaFactory;
	//创建香蕉
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	//创建一个鸭梨工厂
	factory = new PearFactory;
	//创建鸭梨
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