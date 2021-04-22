#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//抽象武器  武器策略
class WeaponStrategy
{
public:
    virtual void UseWeapon() = 0;
};
class Knife :public WeaponStrategy
{
public:
    virtual void UseWeapon() {
        cout << "使用匕首!" << endl;
    }
};
class AK47 : public WeaponStrategy {
public:
    virtual void UseWeapon() {
        cout << "使用AK47!" << endl;
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
    //武器策略
    WeaponStrategy* knife = new Knife;
    WeaponStrategy* ak47 = new AK47;
    //创建角色
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