// copy a.txt b.txt

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define BUF_SIZE 1
 
#define DEBUG

int main(int argc, char *argv[])
{
#ifdef DEBUG
	printf("argc:%d\n", argc);
	printf("argv[1]:%s\n", argv[1]);
	printf("argv[2]:%s\n", argv[2]);
#endif
	int fd1, fd2, len;
	char buf[BUF_SIZE];

	fd1 = open("a.txt", O_RDONLY);
	fd2 = open("b.txt",O_WRONLY|O_CREAT|O_TRUNC);
	
	while((len = read(fd1, buf, sizeof(buf)))>0)
		write(fd2,buf,len);
	
	close(fd1);
	close(fd2);
	
	return 0;
}
