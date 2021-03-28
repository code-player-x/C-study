#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
//电视机
class Television
{
public:
	void On()
	{
		cout << "电视机打开..." << endl;
	}
	void Off()
	{
		cout << "电视机关闭..." << endl;
	}
};
//灯
class Light {
public:
	void On() {
		cout << "打开..." << endl;
	}
	void Off() {
		cout << "灯关闭..." << endl;
	}
};
//音箱
class Audio {
public:
	void On() {
		cout << "音响打开..." << endl;
	}
	void Off() {
		cout << "音响关闭.." << endl;
	}
};
//麦克风
class Microphone {
public:
	void On() {
		cout << "麦克风打开..." << endl;
	}
	void Off() {
		cout << "麦克风关闭.." << endl;
	}
};
//DVD播放器
class DVDPlayer {
public:
	void On() {
		cout << "DVD播放器打开..." << endl;
	}
	void Off() {
		cout << "DVD播放器关闭..." << endl;
	}
};
/***************************************************/
class KTVMode
{
public:
	Television* pTv;
	Light* pLight;
	Audio* pAudio;
	Microphone* pMicrophone;
	DVDPlayer* pDvd;
public:
	KTVMode()
	{
		pTv = new Television;
		pLight = new Light;
		pAudio = new Audio;
		pMicrophone = new Microphone;
		pDvd = new DVDPlayer;
	}
	~KTVMode()
	{
		delete pTv;
		delete pLight;
		delete pAudio;
		delete pMicrophone;
		delete pDvd;
	}
	void OnKTV() {
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMicrophone->On();
		pDvd->On();
	}
	void UnKTV() {
		pTv->Off();
		pLight->On();
		pAudio->Off();
		pMicrophone->Off();
		pDvd->Off();
	}
};
void test01()
{
	KTVMode* ktv = new KTVMode;
	ktv->OnKTV();
	delete ktv;
}
int main()
{
	test01();
	return 0;
}