//描述: tcp服务端程序流程
//1．创建套接字
//2．绑定地址信息
//3．开始监听
//4．获取新连接
//5．收发数据
//6．关闭套接字

#include<iostream>
#include"tcpsocket.hpp"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: ./tcp_srv ip port\n";
		return -1;
	}
	std::string ip = argv[1];
	uint16_t port = std::stoi(argv[2]);

	TcpSocket lst_sock;//listen 套接字
	CHECK_RET(lst_sock.Socket());//创建监听套接字
	CHECK_RET(lst_sock.Bind(ip, port));//为监听套接字绑定地址
	CHECK_RET(lst_sock.Listen());//开始监听
	while (1)
	{
		TcpSocket new_sock;
		bool ret = lst_sock.Accept(&new_sock);//通过监听套接字获取新建连接
		if (ret == false){
			continue;//服务端不能因为一个新建套接字失败就退出

		}
		std::string buf;
		new_sock.Recv(&buf);//通过新建连接与指定客户端进行通信
		std::cout << "client say: " << buf << std::endl;

		buf.clear();
		std::cout << "server say: ";
		std::cin >> buf;
		new_sock.Send(buf);

	}

	lst_sock.Close();
	return 0;
}