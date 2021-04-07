#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include"cpphttplib/httplib.h"
#include"../searcher/searcher.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

int main()
{
	using namespace httplib;
	//1、创建searcher对象
	searcher::Searcher searcher;
	bool ret = searcher.Init("../data/tmp/raw_input");
	if (!ret)
	{
		std::cout << "Searcher初始化失败" << std::endl;
		return 1;
	}
	//创建server对象
	Server server;
	server.Get("/searcher", [&searcher](const Request& req, Response& resp){
		(void)req;
		if (!req.has_param("query")){
			resp.set_content("您发的请求参数错误", "text/plain; charset=utf-8");
			return;
		}
		string query = req.get_param_value("query");
		string results;
		searcher.Search(query, &results);

		resp.set_content(results, "application/json; charset=utf-8");
	});
	//告诉服务器，静态资源存放在wwwroot目录下（html，css，js，图片）
	//服务器启动之后，就可以通过http://192.168.61.128:10001/index.html 的方式来访问到该页面了

	server.set_base_dir("./wwwroot");
	//启动服务器
	server.listen("0.0.0.0", 10001);//0.0.0.0是当前主机所有网卡ip，10001是端口
	return 0;
}