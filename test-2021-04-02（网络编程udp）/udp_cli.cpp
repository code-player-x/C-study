#include <iostream>
#include <unistd.h>
#include <string.h>
#include"udpsocket.hpp"


#define CHECK_RET(q) if((q)==false){return -1;}
int main(int argc, char* argv[])
{
	//�ͻ��˲�����ȡ��IP��ַ�Ƿ���˰󶨵ĵ�ַ��Ҳ���ǿͻ��˷������ݵ�Ŀ���ַ����Ϊ���Լ��󶨵�
	if (argc != 3) {
		std::cout << "Usage: ./udp_cli ip port\n";
		return -1;
	}
	std::string srv_ip = argv[1];
	uint16_t srv_port = std::stoi(argv[2]);

	UdpSocket cli_sock;
	//�����׽���
	CHECK_RET(cli_sock.Socket());
	//�󶨵�ַ�����Ƽ���
	while (1)
	{
		//��������
		std::cout << "client say: ";
		std::string buf;
		std::cin >> buf;
		CHECK_RET(cli_sock.Send(buf, srv_ip, srv_port));
		//��������
		buf.clear();
		CHECK_RET(cli_sock.Recv(&buf));//Ĭ�ϲ������Բ��ø���
		std::cout << "server say: " << buf << std::endl;

	}
	//�ر��׽���
	cli_sock.Close();

	return 0;
}