#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue> //queue��ͷ�ļ�
#include<Windows.h>
using namespace std;
//����Э����
class HandleClientProtocol
{
public:
    //�������ӽ��
    void Addmoney()
    {
        cout << "��������ӽ��!" << endl;
    }
    //����������ʯ
    void AddDiamond()
    {
        cout << "�����������ʯ!" << endl;
    }
    //�������װ��
    void AddEquipment()
    {
        cout << "����Ҵ�װ��!" << endl;
    }
    //������ҵȼ�
    void addLevel() {
        cout << "��������ӵȼ�!" << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////
// ����ӿ�
class AbstractCommand
{
public:
    virtual void  handle() = 0;//����ͻ�������Ľӿ�
};
//�������ӽ������
class AddMoneyCommand :public AbstractCommand
{
public:
    HandleClientProtocol* pProtocal;
public:
    AddMoneyCommand(HandleClientProtocol* pProtocal)
    {
        this->pProtocal = pProtocal;
    }
    virtual void  handle()
    {
        this->pProtocal->Addmoney();
    }
};
//����������ʯ������
class AddDiamondCommand :public AbstractCommand {
public:
    AddDiamondCommand(HandleClientProtocol* pProtocol) {
        this->pProtocol = pProtocol;
    }
    virtual void handle() {
        this->pProtocol->AddDiamond();
    }
public:
    HandleClientProtocol* pProtocol;
};
//��������װ��������
class AddEquipmentCommand : public AbstractCommand {
public:
    HandleClientProtocol* pProtocol;
public:
    AddEquipmentCommand(HandleClientProtocol* pProtocol) {
        this->pProtocol = pProtocol;
    }
    virtual void handle() {
        this->pProtocol->AddEquipment();
    }
};
//�����������������
class AddLevelCommand :public AbstractCommand {
public:
    HandleClientProtocol* pProtocol;
public:
    AddLevelCommand(HandleClientProtocol* pProtocol) {
        this->pProtocol = pProtocol;
    }
    virtual void handle() {
        this->pProtocol->addLevel();
    }
};
//////////////////////////////////////////////////////////////////////////////////
//����������
class Server {
public:
    queue<AbstractCommand*> mCommands;
public:
    void startHandle()
    {
        while (!mCommands.empty())
            //�鿴�Ƿ�Ϊ�շ��� M.empty()�ǵĻ�����1�����Ƿ���0;
        {
            Sleep(2000);
            AbstractCommand* command = mCommands.front();//��ʾ��һ��Ԫ��M.front()
            command->handle();
            mCommands.pop();//�����һ��Ԫ�� M.pop()
        }
    }
    void addRequest(AbstractCommand* command)
    {
        mCommands.push(command);//������Ԫ�غ�������Ԫ��   M.push()
    }
};
void test01()
{
    HandleClientProtocol* pProtocal = new HandleClientProtocol;
    //�ͻ������ӽ��е�����
    AbstractCommand* addmoney = new AddMoneyCommand(pProtocal);
    //�ͻ���������ʯ������
    AbstractCommand* adddiamond = new AddDiamondCommand(pProtocal);
    //�ͻ��˴�װ��������
    AbstractCommand* addequpment = new AddEquipmentCommand(pProtocal);
    //�ͻ�����������
    AbstractCommand* addlevel = new AddLevelCommand(pProtocal);
    Server* server = new Server;
    //���ͻ���������뵽����Ķ�����

    server->addRequest(addmoney);
    server->addRequest(adddiamond);
    server->addRequest(addequpment);
    server->addRequest(addlevel);
    //��������ʼ��������
    server->startHandle();
}
int main()
{
    test01();
    return 0;
}