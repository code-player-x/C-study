#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//抽象模板
class DrinkTemplate
{
public:
	//煮水
	virtual void BoilWater() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加辅助料
	virtual void AddSomething() = 0;

	//模板方法
	void Make()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};
//冲泡咖啡
class Coffee :public DrinkTemplate
{
	//煮水
	virtual void BoilWater() {
		cout << "煮自来水..." << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡..." << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "咖啡倒入杯中..." << endl;
	}
	//加辅助料
	virtual void AddSomething() {
		cout << "加糖,加牛奶..." << endl;
	}
};
//冲泡茶
class Tea :public DrinkTemplate {
public:
	//煮水
	virtual void BoilWater() {
		cout << "煮山泉水..." << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶..." << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "茶叶倒入杯中..." << endl;
	}
	//加辅助料
	virtual void AddSomething() {
		cout << "不加辅助料..." << endl;
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
//优点：
//(1)在父类中形式化地定义一个算法，而由它的子类来实现细节的处理，
//在子类实现详细的处理算法时并不会改变算法中步骤的执行次序。
//(2)模板方法模式是一种代码复用技术它在类库设计中尤为重要。它提取了类库中的公共行为，
//将公共行为放在父类中，而通过其子类来实现不同的行为，它鼓励我们恰当使用继承来实现代码复用。
//(3)可实现一种反向控制结构，通过子类覆盖父类的钩子方法来决定某一特定步骤是否需要执行。
//(4)在模板方法模式中可以通过子类来覆盖父类的基本方法，不同的子类可以提供基本方法的不同实现，
//更换和增加新的子类很方便，符合单一职责原则和开闭原则。