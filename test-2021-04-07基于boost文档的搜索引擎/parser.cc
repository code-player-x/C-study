//�����������ʵ��Ԥ����ģ��
//���Ĺ��ܾ���Ҫ��ȡ������boost�ĵ���.html����
//������ÿ���ĵ��ı��⣬url�����ģ�ȥ��html��ǩ��
//���հѽ�������һ�����ı��ļ�
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include"../common/util.hpp"
#include<boost/filesystem/operations.hpp>
#include<boost/filesystem/path.hpp>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

//����һЩ��صı����ͽṹ��
//���������ʾ���Ǹ�Ŀ¼�ж�ȡboost�ĵ���html
string g_input_path = "../data/input";

//���������ӦԤ����ģ���������ŵ�����
string g_output_path = "../data/tmp/raw_input";

//����һ����Ҫ�Ľṹ�壬��ʾһ���ĵ���һ��html��
struct DocInfo
{
	//�ĵ��ı���
	string title;
	//�ĵ���URL
	string url;
	//�ĵ�������
	string content;
};


//һ���������������,ʹ��const &����ʾ
//һ�����������������ʹ��ָ������ʾ.
//һ�������������������,ʹ����������ʾ.

bool EnumFile(const string &input_path, vector<string>* file_list)
{
	//ö��Ŀ¼��Ҫʹ��boost�����
	//��Ҫ������ص�ͷ�ļ�
	//��boost::filesystem��������ռ䶨��һ������
	namespace fs = boost::filesystem;
	fs::path root_path(input_path);
	if (!fs::exists(root_path))
	{
		std::cout << "��ǰ��Ŀ¼������" << std::endl;
		return false;
	}
	//�ݹ������ʱ��ʹ�õ�һ�����ĵ���
	//������ʹ��ѭ��ʵ�ֵ�ʱ������Զ���ɵݹ�
	//c++�е�һ�ֳ����������ѵ�������Ĭ�Ϲ��캯�����ɵĵ�������Ϊһ�����ڱ�����
	fs::recursive_directory_iterator end_iter;

	for (fs::recursive_directory_iterator iter(root_path);
		iter != end_iter; ++iter)
	{
		//��ǰ·����Ӧ���ǲ���һ����ͨ�ļ��������Ŀ¼��ֱ������
		if (!fs::is_regular_file(*iter))
		{
			continue;
		}
		//��ǰ·����Ӧ���ļ��ǲ���һ��html�ļ�������������ļ�Ҳ����
		if (iter->path().extension() != ".html")
		{
			continue;
		}
		//�ѵõ���·�����뵽���ս����vector��ȥ
		file_list->push_back(iter->path().string());
	}
	return true;

}
//�ҵ�html�е�title��ǩ
bool ParseTitle(const string &html, string* title)
{
	size_t beg = html.find("<title>");
	if (beg == string::npos)
	{
		std::cout << "����δ�ҵ���" << std::endl;
		return false;
	}
	size_t end = html.find("</title>");
	if (end == string::npos)
	{
		std::cout << "����δ�ҵ���" << std::endl;
		return false;
	}
	beg += string("<title>").size();
	if (beg >= end)
	{
		std::cout << "����λ�ò��Ϸ���" << std::endl;
		return false;
	}
	*title = html.substr(beg, end - beg);
	return true;
}
//���ݱ���·����ȡ�������ĵ���·��
//����·�����磺
//../data/input/html/thread.html
//����·�����磺
//https://www.boost.org/doc/libs/1_53_0/doc/html/thread.htm
//�ѱ���·���ĺ�벿�ֽ�ȡ��������ƴװ������·����ǰ׺�Ϳ�����
bool ParseUrl(const string &file_path, string* url)
{
	string url_head = "https://www.boost.org/doc/libs/1_53_0/doc/";
	string url_tail = file_path.substr(g_input_path.size());
	*url = url_head + url_tail;
	return true;
}