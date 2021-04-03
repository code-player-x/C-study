#include <iostream>
#include <string>
#include "udpsocket.hpp"


#define CHECK_RET(q) if((q)==false){return false;}
int main(int argc, char *argv[]){
	// argc��ʾ�������в����ĸ���
	//./udp_srv | 192.168.2.2 | 9000  ��������
	if (argc != 3) {
		std::cout << "Usage: ./udp_srv ip port\n";
		return -1;
	}
	uint16_t port = std::stoi(argv[2]);
	//stringת��Ϊ����// port�ǵ���������
	std::string ip = argv[1];

	UdpSocket srv_sock;
	//�����׽���
	// if(srv_sock.Socket()==false){
	//     return false;
	// }
	CHECK_RET(srv_sock.Socket());
	//�󶨵�ַ��Ϣ
	CHECK_RET(srv_sock.Bind(ip, port));
	while (1){
		//��������
		std::string buf;
		std::string peer_ip;
		uint16_t peer_port;
		CHECK_RET(srv_sock.Recv(&buf, &peer_ip, &peer_port));
		// client[192.168.2.2:9000] say:nihao
		std::cout << "client[" << peer_ip << ":" << peer_port << "] say:" << buf << std::endl;
		//��������
		buf.clear();
		std::cout << "server say:";
		std::cin >> buf;
		//˭���������ݾ͸�˭�ظ�
		CHECK_RET(srv_sock.Send(buf, peer_ip, peer_port));
	}
	//�ر��׽���
	srv_sock.Close();
	return 0;
}
