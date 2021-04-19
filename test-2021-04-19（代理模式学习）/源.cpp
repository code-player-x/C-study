#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
//����ϵͳ��
class AbstractCommonInterface
{
public:
	virtual void run() = 0;
};
//���Ѿ�д�õ�ϵͳ
class MySystem :public AbstractCommonInterface
{
public:
	virtual void run()
	{
		cout << "ϵͳ����........" << endl;
	}
};
//����Ҫ��Ȩ����֤�����������˶����������ҵ�ϵͳ���ṩ�û���������
class MySystemProxy :public AbstractCommonInterface
{
public:
	MySystem* psystem;
	string mUserName;
	string mPassword;
public:
	MySystemProxy(string username, string password)
	{
		this->mUserName = username;
		this->mPassword = password;
		psystem = new MySystem;
	}
	~MySystemProxy()
	{
		if (psystem != nullptr)
			delete psystem;
	}

	bool checkUsernameAndPassword()
	{
		if (mUserName == "admin" && mPassword == "admin")
			return true;
		return false;
	}

	virtual void run()
	{
		if (checkUsernameAndPassword())
		{
			cout << "�û�����������ȷ����֤ͨ��" << endl;
			this->psystem->run();
		}
		else
		{
			cout << "�û��������������Ȩ�޲���" << endl;
		}
	}
};

void test1()
{
	MySystemProxy* proxy = new MySystemProxy("root", "admin");
	proxy->run();
	delete proxy;
	proxy = new MySystemProxy("admin", "admin");
	proxy->run();
	delete proxy;
}

int main()
{
	test1();
	return 0;
}