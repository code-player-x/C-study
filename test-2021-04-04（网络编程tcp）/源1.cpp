#include<cstdio>
#include<string>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>

//listen�ĵڶ�����������ͬһʱ���ܹ����ն��ٿͻ�������
//������������ͨ���ܹ����ն��ٿͻ�������
#define MAX_LISTEN 5
#define CHECK_RET(q) if((q)==false){return -1;}

typedef struct{
	int num1;
	int num2;
	char op;
}cal_t;
class TcpSocket {
public:
	TcpSocket() :_sockfd(-1){}
	int GetFd()
	{
		return _sockfd;
	}
	void SetFd(int fd){
		_sockfd = fd;
	}



	bool Socket()
	{
		//socket(��ַ���׽������ͣ�Э������)
		_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (_sockfd<0)
		{
			perror("socket error");
			return false;
		}
		return true;
	}
	bool Bind(const std::string &ip, uint16_t port){
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = bind(_sockfd, (struct sockaddr*)& addr, len);
		if (ret<0)
		{
			perror("bind error");
			return false;
		}
		return true;
	}
	bool Listen(int backlog = MAX_LISTEN){
		//listen���׽�������������󲢷���������
		int ret = listen(_sockfd, backlog);
		if (ret<0)
		{
			perror("listen error");
			return false;
		}

		return true;
	}
	bool Accept(TcpSocket *new_sock, std::string *ip = NULL, uint16_t *port = NULL){
		//�½��׽���������=accept�������׽������������ͻ��˵�ַ��Ϣ����ַ���ȣ�
		struct sockaddr_in addr;
		socklen_t len = sizeof(struct sockaddr_in);
		int new_fd = accept(_sockfd, (struct sockaddr*)& addr, &len);
		if (new_fd<0)
		{
			perror("accept error");
			return false;
		}
		new_sock->_sockfd = new_fd;
		if (ip != NULL)
		{
			(*ip) = inet_ntoa(addr.sin_addr);
		}
		if (port != NULL)
		{
			(*port) = ntohs(addr.sin_port);
		}
		return true;
	}
	bool Recv(std::string *buf){
		//recv(ͨ���׽������������������׵�ַ���������ݳ��ȣ���־λ--0����)
		char tmp[4096] = { 0 };
		int ret = recv(_sockfd, tmp, 4096, 0);
		if (ret<0)
		{
			perror("recv error");
			return false;
		}
		else if (ret == 0)//recvĬ��������û�����ݾͻ�ȴ�������0����ʾ���ӶϿ�
		{
			printf("connection broken\n");
			return false;
		}
		buf->assign(tmp, ret);
		return true;
	}
	bool Send(const std::string &data)
	{//send(��������Ҫ���������׵�ַ��Ҫ���͵����ݳ��ȣ���־λ-0����)
		int ret = send(_sockfd, data.c_str(), data.size(), 0);
		if (ret<0)
		{
			perror("send error");
			return false;
		}
		return true;
	}

	bool Close(){
		if (_sockfd>0)
		{
			close(_sockfd);
			_sockfd = -1;
		}
		return true;
	}
	bool Connect(const std::string &ip, uint16_t port){
		//�����˷�������
		//connect��������������˵�ַ��Ϣ����ַ��Ϣ���ȣ�
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = connect(_sockfd, (struct sockaddr*)& addr, len);
		if (ret<0)
		{
			perror("connect error");
			return false;
		}
		return true;
	}
private:
	int _sockfd;
};
