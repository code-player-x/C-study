#include<iostream>
#include<string>
using namespace std;

class Television
{
public:
	void On()
	{
		cout << "电视机打开" << endl;
	}
	void Off()
	{
		cout << "电视机关闭" << endl;
	}
};

class Light {
public:
	void On()
	{
		cout << "灯打开" << endl;
	}
	void Off()
	{
		cout << "灯关闭" << endl;
	}
};

class Audio {
public:
	void On()
	{
		cout << "音响打开" << endl;
	}
	void Off()
	{
		cout << "音响关闭" << endl;
	}
};

class Microphone {
public:
	void On()
	{
		cout << "麦克风打开" << endl;
	}
	void Off()
	{
		cout << "麦克风关闭" << endl;
	}
};

class DVDplayer {
public:
	void On()
	{
		cout << "DVD打开" << endl;
	}
	void Off()
	{
		cout << "DVD关闭" << endl;
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

