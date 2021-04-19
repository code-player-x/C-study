#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
//抽象系统类
class AbstractCommonInterface
{
public:
	virtual void run() = 0;
};
//我已经写好的系统
class MySystem :public AbstractCommonInterface
{
public:
	virtual void run()
	{
		cout << "系统启动........" << endl;
	}
};
//必须要有权限验证，不是所有人都能来启动我的系统，提供用户名和密码
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
			cout << "用户名和密码正确，验证通过" << endl;
			this->psystem->run();
		}
		else
		{
			cout << "用户名或者密码错误，权限不足" << endl;
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