#include<iostream>
#include<string>
using namespace std;

class Television
{
public:
	void On()
	{
		cout << "���ӻ���" << endl;
	}
	void Off()
	{
		cout << "���ӻ��ر�" << endl;
	}
};

class Light {
public:
	void On()
	{
		cout << "�ƴ�" << endl;
	}
	void Off()
	{
		cout << "�ƹر�" << endl;
	}
};

class Audio {
public:
	void On()
	{
		cout << "�����" << endl;
	}
	void Off()
	{
		cout << "����ر�" << endl;
	}
};

class Microphone {
public:
	void On()
	{
		cout << "��˷��" << endl;
	}
	void Off()
	{
		cout << "��˷�ر�" << endl;
	}
};

class DVDplayer {
public:
	void On()
	{
		cout << "DVD��" << endl;
	}
	void Off()
	{
		cout << "DVD�ر�" << endl;
	}
};

class KTVMode
{

public:
	Television* tv;
	Light* light;
	Audio* audio;
	Microphone* microphone;
	DVDplayer* dvd;
public:
	KTVMode()
	{
		tv = new Television;
		light = new Light;
		audio = new Audio;
		microphone = new Microphone;
		dvd = new DVDplayer;
	}
	~KTVMode()
	{
		delete tv;
		delete light;
		delete audio;
		delete microphone;
		delete dvd;

	}
	void OnKTV() {
		tv->On();
		light->On();
		audio->On();
		microphone->On();
		dvd->On();
	}
	void OffKTV() {
		tv->Off();
		light->Off();
		audio->Off();
		microphone->Off();
		dvd->Off();
	}
};

void test2()
{
	KTVMode* ktv = new KTVMode;
	ktv->OnKTV();
	delete ktv;
}

int main()
{
	test2();
	return 0;
}

