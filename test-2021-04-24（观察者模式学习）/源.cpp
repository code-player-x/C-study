#include<iostream>
#include<list>
using namespace std;
//�����Ӣ�ۣ��۲���
class AbstractHero {
public:
	//Boss��������Ϸ����
	virtual void Update() = 0;
};

class HeroA :public AbstractHero
{
public:
	HeroA() {
		cout << "Ӣ��A���ڴ�Boss������" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��Aֹͣ�򣬴���״̬......" << endl;
	}
};

class HeroB :public AbstractHero
{
public:
	HeroB() {
		cout << "Ӣ��B���ڴ�Boss������" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��Bֹͣ�򣬴���״̬......" << endl;
	}
};

class HeroC :public AbstractHero
{
public:
	HeroC() {
		cout << "Ӣ��C���ڴ�Boss������" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��Cֹͣ�򣬴���״̬......" << endl;
	}
};

class HeroD :public AbstractHero
{
public:
	HeroD() {
		cout << "Ӣ��D���ڴ�Boss������" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��Dֹͣ�򣬴���״̬......" << endl;
	}
};

class HeroE :public AbstractHero
{
public:
	HeroE() {
		cout << "Ӣ��E���ڴ�Boss������" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��Eֹͣ�򣬴���״̬......" << endl;
	}
};

class AbstractBoss {
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) = 0;
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) = 0;
		//֪ͨ���й۲���
	virtual void notify() = 0;
};

//����Ĺ۲���BossA
class BossA :public AbstractBoss {
public:
	list<AbstractHero*>pHeroList;
public:
	//���ӹ۲���
	virtual void addHero(AbstractHero* hero)
	{
		pHeroList.push_back(hero);
	}
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) {
		pHeroList.remove(hero);
	}
	//֪ͨ���й۲���
	virtual void notify() {
		for (auto it = pHeroList.begin(); it != pHeroList.end(); it++)
		{
			(*it)->Update();
		}

	}
};
void test01() {
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	AbstractHero* heroE = new HeroE;
	//�����۲�Ŀ��
	AbstractBoss* bossA = new BossA;
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);
	cout << "Ӣ��c����..." << endl;
	bossA->deleteHero(heroC);
	cout << "Boss����..֪ͨ����Ӣ��ֹͣ����,��װ��.." << endl;
	bossA->notify();
}
int main()
{
	test01();
	return 0;
}