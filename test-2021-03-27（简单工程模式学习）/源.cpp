#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
/////////////////////////////////////////////////////////
//����ƻ��
class AbstractApple{
public:
	virtual void ShowName() = 0;
};
//�й�ƻ��
class ChinaApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "�й�ƻ��!" << endl;
	}
};
//����ƻ��
class USAApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "����ƻ��!" << endl;
	}
};
//����ƻ��
class JapanApple :public AbstractApple{
public:
	virtual void ShowName(){
		cout << "����ƻ��!" << endl;
	}
};
/////////////////////////////////////////////////////////
//�����㽶
class AbsrtactBanana{
public:
	virtual void ShowName() = 0;
};
//�й��㽶
class ChinaBanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "�й��㽶!" << endl;
	}
};
//�����㽶
class USABanana :public AbsrtactBanana {
public:
	virtual void ShowName(){
		cout << "�����㽶!" << endl;
	}
};
//�����㽶
class JapanBanana :public AbsrtactBanana{
public:
	virtual void ShowName(){
		cout << "�����㽶!" << endl;
	}
};
/////////////////////////////////////////////////////////
// ����Ѽ��
class AbstractPear{
public:
	virtual void ShowName() = 0;
};
//�й�Ѽ��
class ChinaPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "�й�Ѽ��!" << endl;
	}
};
//����Ѽ��
class USAPear :public AbstractPear {
public:
	virtual void ShowName(){
		cout << "����Ѽ��!" << endl;
	}
};
//����Ѽ��
class JapanPear :public AbstractPear{
public:
	virtual void ShowName(){
		cout << "����Ѽ��!" << endl;
	}
};
/////////////////////////////////////////////////////////
//���󹤳���Բ�Ʒ�� �����ǲ�Ʒ�ĵȼ��ṹ
class AbstracFactory{
public:
	virtual AbstractApple*CreateApple() = 0;
	virtual AbsrtactBanana*CreateBanana() = 0;
	virtual AbstractPear*CreatePear() = 0;
};
//�й�����
class ChinaFactory :public AbstracFactory{
public:
	virtual AbstractApple*CreateApple() {
		return new ChinaApple;
	}
	virtual AbsrtactBanana*CreateBanana() {
		return new ChinaBanana;
	}
	virtual AbstractPear*CreatePear() {
		return new ChinaPear;
	}
};
//��������
class USAFactory :public AbstracFactory{
public:
	virtual AbstractApple*CreateApple() {
		return new USAApple;
	}
	virtual AbsrtactBanana*CreateBanana() {
		return new USABanana;
	}
	virtual AbstractPear*CreatePear() {
		return new USAPear;
	}
};
//��������
class JapanFactory :public AbstracFactory{
public:
	virtual AbstractApple*CreateApple() {
		return new JapanApple;
	}
	virtual AbsrtactBanana*CreateBanana() {
		return new JapanBanana;
	}
	virtual AbstractPear*CreatePear() {
		return new JapanPear;
	}
};
void test01() {
	AbstracFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbsrtactBanana* banana = NULL;
	AbstractPear* pear = NULL;
	//�й�����
	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
	delete pear;
	delete banana;
	delete apple;
	delete factory;
}
int main()
{
	test01();
	return 0;
}