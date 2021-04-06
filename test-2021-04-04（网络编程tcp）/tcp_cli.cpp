//实现tcp客户端流程
//描述:实现tcp客户端流程
//1．创建套接字
//2．绑定地址信息.(不推荐)
//3．向服务端发起连接请求
//4．收发数据
//5．关闭套接字
#include<iostream>
#include<signal.h>
#include"tcpsocket.hpp"
void  sigcb(int no){
	printf("recv no : %d \n", no);
}
int main(int argc, char *argv[])

{
	if (argc != 3)
	{
		std::cout << "Usage: ./tcp_cli ip port\n";
		return -1;
	}
	signal(SIGPIPE, sigcb);
	std::string  srv_ip = argv[1];//获取服务端地址
	uint16_t srv_port = std::stoi(argv[2]);

	TcpSocket sock;//listen 套接字
	CHECK_RET(sock.Socket());//创建套接字
	CHECK_RET(sock.Connect(srv_ip, srv_port));

	while (1)
	{
		std::string buf;
		std::cout << "client say: ";
		std::cin >> buf;
		sock.Send(buf);

		buf.clear();
		sock.Recv(&buf);
		std::cout << "server say: " << buf << std::endl;
	}
	sock.Close();
	return 0;
}