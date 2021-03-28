#define CRT SECURE NO WARNINGS
#include<iostream>
#include<string>
using namespace std;
//���ӻ�
class Television
{
public:
	void On()
	{
		cout << "���ӻ���..." << endl;
	}
	void Off()
	{
		cout << "���ӻ��ر�..." << endl;
	}
};
//��
class Light {
public:
	void On() {
		cout << "��..." << endl;
	}
	void Off() {
		cout << "�ƹر�..." << endl;
	}
};
//����
class Audio {
public:
	void On() {
		cout << "�����..." << endl;
	}
	void Off() {
		cout << "����ر�.." << endl;
	}
};
//��˷�
class Microphone {
public:
	void On() {
		cout << "��˷��..." << endl;
	}
	void Off() {
		cout << "��˷�ر�.." << endl;
	}
};
//DVD������
class DVDPlayer {
public:
	void On() {
		cout << "DVD��������..." << endl;
	}
	void Off() {
		cout << "DVD�������ر�..." << endl;
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