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
	//1������searcher����
	searcher::Searcher searcher;
	bool ret = searcher.Init("../data/tmp/raw_input");
	if (!ret)
	{
		std::cout << "Searcher��ʼ��ʧ��" << std::endl;
		return 1;
	}
	//����server����
	Server server;
	server.Get("/searcher", [&searcher](const Request& req, Response& resp){
		(void)req;
		if (!req.has_param("query")){
			resp.set_content("�����������������", "text/plain; charset=utf-8");
			return;
		}
		string query = req.get_param_value("query");
		string results;
		searcher.Search(query, &results);

		resp.set_content(results, "application/json; charset=utf-8");
	});
	//���߷���������̬��Դ�����wwwrootĿ¼�£�html��css��js��ͼƬ��
	//����������֮�󣬾Ϳ���ͨ��http://192.168.61.128:10001/index.html �ķ�ʽ�����ʵ���ҳ����

	server.set_base_dir("./wwwroot");
	//����������
	server.listen("0.0.0.0", 10001);//0.0.0.0�ǵ�ǰ������������ip��10001�Ƕ˿�
	return 0;
}