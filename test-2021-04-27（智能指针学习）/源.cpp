#include<iostream>
#include<memory>
#include<string>
#include<list>
#include<vector>
using namespace std;

int main()
{
	shared_ptr<string> p1;
	shared_ptr<list<int>>p2;
	if (p1 && p1->empty())
		*p1 = "hi girl";
	shared_ptr<string >p3(p1);
	int num = p1.use_count();
	cout << "p1�����ü���Ϊ" << p3.use_count() << endl;
	//ָ��һ��ֵΪ42��int ��shared_ptr
	shared_ptr<int >p4 = make_shared<int>(42);
	auto r = make_shared<int>(42);//rָ���intֻ��һ��������
	r = p4;//��r��ֵ������ָ����һ����ַ
	//����p4ָ��Ķ�������ü���
	//�ݼ�rԭ��ָ���������ü���

	//rԭ��ָ��Ķ�����û�������ߣ����Զ��ͷ�
	shared_ptr<int >p5 = make_shared<int>();
	//p6ָ��һ��ֵΪ"9999999999"��string
	shared_ptr<string>p6 = make_shared<string>(10,'9');
	//p7ָ��һ����̬����Ŀ�vector<string>

	auto p7 = make_shared<vector<string>>();

	return 0;
}