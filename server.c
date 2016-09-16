#include"header.h"
int main()
{
	int sfd, cfd, ret, count;
	char buff;
	char* path;
	struct sockaddr_in sock_addr, client_addr;
	socklen_t sock_addr_size;

	sfd = socket(AF_INET, SOCK_STREAM, 0);

	printf("fd = %d\n", sfd);

 	sock_addr.sin_family = AF_INET;

	sock_addr.sin_port = htons(2644);

	sock_addr.sin_addr.s_addr = inet_addr("192.168.43.70");

	ret = bind(sfd, (struct sockaddr *) &sock_addr, sizeof(struct sockaddr_in));

	printf("bind ret = %d\n", ret);

	ret = listen(sfd, LISTEN_BACKLOG);

	printf("listen ret = %d\n", ret);

	sock_addr_size = sizeof(struct sockaddr_in);

	cfd = accept(sfd, (struct sockaddr *)&client_addr, &sock_addr_size);

	printf("fd = %d\n", cfd);

	count = read(cfd, &buff, 1);

	printf("character from client = %c", buff);

	buff = buff +1;

	write(cfd, &buff, 1);
}
