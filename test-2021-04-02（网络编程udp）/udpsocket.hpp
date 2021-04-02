#include<cstdio>
#include<string>
#include<unistd.h>//close ��ͷ�ļ�
#include<netinet/in.h>//������ַ�ṹ��Ϣ
#include<arpa/inet.h>//�ֽ���ת���ӿ�
#include<sys/socket.h>//�׽��ֽӿ���Ϣ


class UdpSocket {
public:
	UdpSocket() :_sockfd(-1)
	{}
	bool Socket() //�����׽���
		//Ϊ�׽��ְ󶨵�ַ��Ϣ
	{
		//socket(��ַ���׽������ͣ�Э������)
		_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (_sockfd<0){
			perror("socket error");
			return false;
		}
		return true;
	}
	bool Bind(const std::string &ip, uint16_t port)
	{
		//����Ipv4��ַ�ṹ struct sockaddr_in
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;//��ַ������
		addr.sin_port = htons(port);//htons�������ֽ������������ת��Ϊ�����ֽ�������
		addr.sin_addr.s_addr = inet_addr(ip.c_str());//���ַ���ip��ַת��Ϊ�����ֽ���ip��ַ
		//bind(����������ַ��Ϣ����ַ��Ϣ����)
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
		if (ret<0)
		{
			perror("bind error");
			return false;
		}
		return true;
	}
	//�������ݣ���ȡ���Ͷ˵�ַ��Ϣ
	//Recv(&buf,&ip,&port)
	//Recv(buf);
	bool Recv(std::string *buf, std::string *ip = NULL, uint16_t *port = NULL)
	{//buf���ڷ��������յ����ݣ�ip���ڷ���Դ�˵ĵ�ַ��Ϣ
		//recfrom(�׽��־�������ջ����������ݳ��ȣ���־��Դ�˵�ַ����ַ����)
		struct sockaddr_in peer_addr;
		socklen_t len = sizeof(struct sockaddr_in);
		char tmp[4096] = { 0 };
		int ret = recvfrom(_sockfd, tmp, 4096, 0, (struct sockaddr*)&peer_addr, &len);
		if (ret<0){
			perror("recvfrom error");
			return false;
		}
		buf->assign(tmp, ret);//assign��ָ���ַ����н�ȡָ�����ȵ����ݵ�buf��
		//��tmp�н�ȡret���ȵ����ݷ���buf��
		if (port != NULL){//���ݵ�ַ�ж��û��Ƿ���Ҫ��ȡ��ַ��Ϣ
			*port = ntohs(peer_addr.sin_port);//�������ֽ��������ֽ����ת��
		}
		if (ip != NULL){
			*ip = inet_ntoa(peer_addr.sin_addr);
			//�����ֽ��������ֽ����ת��
		}
		return true;
	}

	//�������ݣ���ȡ���Ͷ˵�ַ��Ϣ
	bool Send(const std::string &data, const std::string &ip, const uint16_t port){
		// sendto(�׽��־���������׵�ַ�����ݳ��ȣ���־���Զ˵�ַ��Ϣ����ַ��Ϣ����)
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;//��ַ������
		addr.sin_port = htons(port);//htons�������ֽ������������ת��Ϊ�����ֽ�������
		addr.sin_addr.s_addr = inet_addr(ip.c_str());//���ַ���ip��ַת��Ϊ�����ֽ���ip��ַ
		//bind(����������ַ��Ϣ����ַ��Ϣ����)
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = sendto(_sockfd, data.c_str(),
			data.size(), 0, (struct sockaddr*)&addr, len);
		if (ret<0)
		{
			perror("sendto error");
			return false;
		}
		return true;

	}
	//��������
	bool Close() //�ر��׽���
	{
		if (_sockfd>0)
		{
			close(_sockfd);
			_sockfd = -1;
		}
		return true;
	}
private:
	int _sockfd;
};
