#include"header.h"

int main()
{
	int ret,sfd,count;
	char c='A',buff;
	struct sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(16457);
	dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	ret = connect(sfd, (struct sockaddr *) &dest_addr, sizeof(struct sockaddr_in));
	printf("client connect ret = %d\n", ret);
	count = write(sfd, &c, 1);
	read(sfd, &buff, 1);
	printf("New Character = %c", buff);
}
