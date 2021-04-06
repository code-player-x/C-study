//ʵ��tcp�ͻ�������
//����:ʵ��tcp�ͻ�������
//1�������׽���
//2���󶨵�ַ��Ϣ.(���Ƽ�)
//3�������˷�����������
//4���շ�����
//5���ر��׽���
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
	std::string  srv_ip = argv[1];//��ȡ����˵�ַ
	uint16_t srv_port = std::stoi(argv[2]);

	TcpSocket sock;//listen �׽���
	CHECK_RET(sock.Socket());//�����׽���
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