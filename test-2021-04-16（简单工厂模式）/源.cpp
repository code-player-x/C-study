#include<iostream>
#include<string>
using namespace std;
//抽象水果
class AbstractFruit {

public:
	virtual void ShowName() = 0;

};

class Apple :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "我是苹果" << endl;
	}
};

class Banana :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "我是香蕉" << endl;
	}
};
class Pear :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "我是鸭梨" << endl;
	}
};

class FruitFactory
{
public:
	static AbstractFruit* CreateFruit(string flag)
	{

		if (flag == "apple")
		{
			return new Apple;
		}
		else if (flag == "banana")
		{
			return new Banana;
		}
		else if (flag == "pear")
		{
			return new Pear;
		}
		else
		{
			return NULL;
		}
	}
};
void test01()
{
	FruitFactory* factory = new FruitFactory;
	AbstractFruit* fruit = factory->CreateFruit("apple");
	fruit->ShowName();
	delete fruit;
	fruit = factory->CreateFruit("banana");
	fruit->ShowName();
	delete fruit;
	fruit = factory->CreateFruit("pear");
	fruit->ShowName();
	delete fruit;
	delete factory;
}

int main() {
	test01();
	return 0;
}