#include <iostream>
#include <unistd.h>
#include <string.h>
#include"udpsocket.hpp"


#define CHECK_RET(q) if((q)==false){return -1;}
int main(int argc, char* argv[])
{
	//客户端参数获取的IP地址是服务端绑定的地址，也就是客户端发送数据的目标地址不是为了自己绑定的
	if (argc != 3) {
		std::cout << "Usage: ./udp_cli ip port\n";
		return -1;
	}
	std::string srv_ip = argv[1];
	uint16_t srv_port = std::stoi(argv[2]);

	UdpSocket cli_sock;
	//创建套接字
	CHECK_RET(cli_sock.Socket());
	//绑定地址（不推荐）
	while (1)
	{
		//发送数据
		std::cout << "client say: ";
		std::string buf;
		std::cin >> buf;
		CHECK_RET(cli_sock.Send(buf, srv_ip, srv_port));
		//接收数据
		buf.clear();
		CHECK_RET(cli_sock.Recv(&buf));//默认参数可以不用赋予
		std::cout << "server say: " << buf << std::endl;

	}
	//关闭套接字
	cli_sock.Close();

	return 0;
}