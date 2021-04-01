#define CRT SECURE NOWARVINGS
#include <iostream>
#include<list>
using namespace std;
//һ��������ü̳�ʵ����Ĺ�����չ
//װ��ģʽ���Զ�̬��һ�������ӹ���
//����Ӣ��
class AbstractHero{
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
public:
	virtual void ShowStatus() = 0;
};
//����Ӣ��
class HeroA :public AbstractHero{
public:
	HeroA(){
		mHp = 0;
		mMp = 0;
		mAt = 0;
		mDf = 0;
	}
	virtual void ShowStatus(){
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};
//Ӣ�۴���ĳ��װ������ô�����Ǹ�Ӣ��
class AbstractEquipment :public AbstractHero{
public:
	AbstractHero*pHero;
public:
	AbstractEquipment(AbstractHero* pHero) {
		this->pHero = pHero;
	}
	virtual void ShowStatus() = 0;
};
//��ͽװ��
class KuangtuEquipment :public AbstractEquipment{
public:
	KuangtuEquipment(AbstractHero* hero) :AbstractEquipment(hero) {
	}
	//���Ӷ��⹦��
	void Add(){
		cout << "Ӣ�۴��Ͽ�ͽ֮��.." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;
		delete this->pHero;
	}
	virtual void ShowStatus(){
		Add();
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};
//�޾�֮��
class WujinzhiKnife :public AbstractEquipment{
public:
	WujinzhiKnife(AbstractHero*hero) :AbstractEquipment(hero){}
	//���Ӷ��⹦��
	void Add(){
		cout << "Ӣ�ۼ����޾�֮��֮��..." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 80;
		this->mDf = this->pHero->mDf;
		delete this->pHero;
	}
	virtual void ShowStatus(){
		Add();
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};
void test01(){
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();
	cout << "----------------" << endl;
	//���㱼��Ӣ�۴����·�
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();
	cout << "----------------" << endl;
	//��Ӣ��װ������
	hero = new WujinzhiKnife(hero);
	hero->ShowStatus();
}
int main()
{

	test01();

	return 0;
}