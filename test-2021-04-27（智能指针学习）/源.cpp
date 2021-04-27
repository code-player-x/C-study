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
	cout << "p1的引用计数为" << p3.use_count() << endl;
	//指向一个值为42的int 的shared_ptr
	shared_ptr<int >p4 = make_shared<int>(42);
	auto r = make_shared<int>(42);//r指向的int只有一个引用者
	r = p4;//给r赋值，令他指向另一个地址
	//递增p4指向的对象的引用计数
	//递减r原来指向对象的引用计数

	//r原来指向的对象已没有引用者，会自动释放
	shared_ptr<int >p5 = make_shared<int>();
	//p6指向一个值为"9999999999"的string
	shared_ptr<string>p6 = make_shared<string>(10,'9');
	//p7指向一个动态分配的空vector<string>

	auto p7 = make_shared<vector<string>>();

	return 0;
}