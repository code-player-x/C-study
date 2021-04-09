//这个代码用于实现预处理模块
//核心功能就是要读取并分析boost文档的.html内容
//解析出每个文档的标题，url，正文（去除html标签）
//最终把结果输出成一个行文本文件
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

//定义一些相关的变量和结构体
//这个变量表示从那个目录中读取boost文档的html
string g_input_path = "../data/input";

//这个变量对应预处理模块输出结果放到哪里
string g_output_path = "../data/tmp/raw_input";

//创建一个重要的结构体，表示一个文档（一个html）
struct DocInfo
{
	//文档的标题
	string title;
	//文档的URL
	string url;
	//文档的正文
	string content;
};


//一个函数的输入参数,使用const &来表示
//一个函数的输出参数，使用指针来表示.
//一个函数的输入输出参数,使用引用来表示.

bool EnumFile(const string &input_path, vector<string>* file_list)
{
	//枚举目录需要使用boost来完成
	//需要包含相关的头文件
	//把boost::filesystem这个命名空间定义一个别名
	namespace fs = boost::filesystem;
	fs::path root_path(input_path);
	if (!fs::exists(root_path))
	{
		std::cout << "当前的目录不存在" << std::endl;
		return false;
	}
	//递归遍历的时候使用到一个核心的类
	//迭代器使用循环实现的时候可以自动完成递归
	//c++中的一种常见做法，把迭代器的默认构造函数生成的迭代器作为一个“哨兵”：
	fs::recursive_directory_iterator end_iter;

	for (fs::recursive_directory_iterator iter(root_path);
		iter != end_iter; ++iter)
	{
		//当前路径对应的是不是一个普通文件，如果是目录，直接跳过
		if (!fs::is_regular_file(*iter))
		{
			continue;
		}
		//当前路径对应的文件是不是一个html文件，如果是其他文件也跳过
		if (iter->path().extension() != ".html")
		{
			continue;
		}
		//把得到的路径加入到最终结果的vector中去
		file_list->push_back(iter->path().string());
	}
	return true;

}
//找到html中的title标签
bool ParseTitle(const string &html, string* title)
{
	size_t beg = html.find("<title>");
	if (beg == string::npos)
	{
		std::cout << "标题未找到！" << std::endl;
		return false;
	}
	size_t end = html.find("</title>");
	if (end == string::npos)
	{
		std::cout << "标题未找到！" << std::endl;
		return false;
	}
	beg += string("<title>").size();
	if (beg >= end)
	{
		std::cout << "标题位置不合法！" << std::endl;
		return false;
	}
	*title = html.substr(beg, end - beg);
	return true;
}
//根据本地路径获取到在线文档的路径
//本地路径形如：
//../data/input/html/thread.html
//在线路径形如：
//https://www.boost.org/doc/libs/1_53_0/doc/html/thread.htm
//把本地路径的后半部分截取出来，再拼装上在线路径的前缀就可以了
bool ParseUrl(const string &file_path, string* url)
{
	string url_head = "https://www.boost.org/doc/libs/1_53_0/doc/";
	string url_tail = file_path.substr(g_input_path.size());
	*url = url_head + url_tail;
	return true;
}