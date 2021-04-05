//����: tcp����˳�������
//1�������׽���
//2���󶨵�ַ��Ϣ
//3����ʼ����
//4����ȡ������
//5���շ�����
//6���ر��׽���

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

	TcpSocket lst_sock;//listen �׽���
	CHECK_RET(lst_sock.Socket());//���������׽���
	CHECK_RET(lst_sock.Bind(ip, port));//Ϊ�����׽��ְ󶨵�ַ
	CHECK_RET(lst_sock.Listen());//��ʼ����
	while (1)
	{
		TcpSocket new_sock;
		bool ret = lst_sock.Accept(&new_sock);//ͨ�������׽��ֻ�ȡ�½�����
		if (ret == false){
			continue;//����˲�����Ϊһ���½��׽���ʧ�ܾ��˳�

		}
		std::string buf;
		new_sock.Recv(&buf);//ͨ���½�������ָ���ͻ��˽���ͨ��
		std::cout << "client say: " << buf << std::endl;

		buf.clear();
		std::cout << "server say: ";
		std::cin >> buf;
		new_sock.Send(buf);

	}

	lst_sock.Close();
	return 0;
}