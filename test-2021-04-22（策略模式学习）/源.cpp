#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//��������  ��������
class WeaponStrategy
{
public:
    virtual void UseWeapon() = 0;
};
class Knife :public WeaponStrategy
{
public:
    virtual void UseWeapon() {
        cout << "ʹ��ذ��!" << endl;
    }
};
class AK47 : public WeaponStrategy {
public:
    virtual void UseWeapon() {
        cout << "ʹ��AK47!" << endl;
    }
};
/*************************************************/
class Character
{
public:
    WeaponStrategy* pWeapon;
public:
    void setWeapon(WeaponStrategy* pWeapon)
    {
        this->pWeapon = pWeapon;
    }
    void ThrowWeapon()
    {
        this->pWeapon->UseWeapon();
    }
};
void test01()
{
    //��������
    WeaponStrategy* knife = new Knife;
    WeaponStrategy* ak47 = new AK47;
    //������ɫ
    Character* character = new Character;
    character->setWeapon(knife);
    character->ThrowWeapon();
    character->setWeapon(ak47);
    character->ThrowWeapon();
    delete ak47;
    delete knife;
    delete character;
}
int main()
{
    test01();
    return 0;
}