#include "includes/libasm.h"

void printTitle(char *str)
{
	printf("\n%s\n===================================\n", str);
}

void printStrlen(char *txt)
{
	printf("[\e[38;5;82m%3zu\033[0m]-[\e[38;5;196m%3zu\033[0m]\t'\e[38;5;226m%s\033[0m'\n", ft_strlen(txt), strlen(txt), txt);
}

void printStrcmp(char *s1, char *s2)
{
	printf("[\e[38;5;82m%3d\033[0m]-[\e[38;5;196m%3d\033[0m]\t'\e[38;5;226m%s\033[0m', '\e[38;5;226m%s\033[0m'\n", ft_strcmp(s1, s2), strcmp(s1, s2), s1, s2);
}

void printStrcpy(char *s1, char *s2)
{

	char *is1 = strdup(s1);
	char *is2 = strdup(s2);
	char *imp = ft_strcpy(is1, is2);

	printf("[\e[38;5;242m%s\033[0m]-[\e[38;5;82m%s\033[0m]-[\e[38;5;196m%s\033[0m]\t\t'\e[38;5;226m%s\033[0m'\t(\e[38;5;39m%p - %p - ", s1, is1, is2, imp, is1, imp);
	char *tmp = strcpy(is1, is2);
	printf("%p\033[0m)\n", tmp);
	printf(">>>>>>>>>>>>>>>>>>\n");
	free(is1);
	free(is2);
}

void printWrite(int fd, char *s, size_t len)
{
	errno = 0;
	int val1 = ft_write(fd, s, len);
	printf("[\e[38;5;82m%d\033[0m]\t'\e[38;5;196m%s\033[0m'\t[\e[38;5;82m%zu\033[0m] = [\e[38;5;196m%d\033[0m]\t(\e[38;5;242m%d\033[0m)-(\e[38;5;242m%s\033[0m)\n", fd, s, len, val1, errno, strerror(errno));

	errno = 0;
	int val2 = write(fd, s, len);
	printf("[\e[38;5;82m%d\033[0m]\t'\e[38;5;196m%s\033[0m'\t[\e[38;5;82m%zu\033[0m] = [\e[38;5;196m%d\033[0m]\t(\e[38;5;242m%d\033[0m)-(\e[38;5;242m%s\033[0m)\n", fd, s, len, val2, errno, strerror(errno));
}

void printRead(int fd, char *s, size_t len)
{
	errno = 0;
	int val1 = ft_read(fd, s, len);
	printf("[\e[38;5;82m%d\033[0m]\t'\e[38;5;196m%s\033[0m'\t[\e[38;5;82m%zu\033[0m] = [\e[38;5;196m%d\033[0m]\t(\e[38;5;242m%d\033[0m)-(\e[38;5;242m%s\033[0m)\n", fd, s, len, val1, errno, strerror(errno));

	errno = 0;
	int val2 = read(fd, s, len);
	printf("[\e[38;5;82m%d\033[0m]\t'\e[38;5;196m%s\033[0m'\t[\e[38;5;82m%zu\033[0m] = [\e[38;5;196m%d\033[0m]\t(\e[38;5;242m%d\033[0m)-(\e[38;5;242m%s\033[0m)\n", fd, s, len, val2, errno, strerror(errno));
	free(s);
}

void printStrdup(char *s1)
{

	char *s2 = ft_strdup(s1);
	char *s3 = strdup(s1);
	printf("[\e[38;5;242m%s\033[0m] (\e[38;5;82m%lu\033[0m)\t[\e[38;5;196m%s\033[0m]\t(\e[38;5;226m%lu\033[0m) {\e[38;5;242m%p - %p - %p\033[0m}\n", s1, sizeof(s1), s2, sizeof(s2), s1, s2, s3);
	errno = 0;
	printf("%d %s\n", errno, strerror(errno));
	printf(">>>>>>>>>>>>>>>>>>\n");
	free(s2);
	free(s3);
}

int main(int ac, char **av)
{
	int type = 0;
	(ac < 2) ? av[1] = av[0] : 0;
	if (ft_strcmp(av[1], "strlen") == 0)
		type = 1;
	else if (ft_strcmp(av[1], "strcmp") == 0)
		type = 2;
	else if (ft_strcmp(av[1], "strcpy") == 0)
		type = 3;
	else if (ft_strcmp(av[1], "write") == 0)
		type = 4;
	else if (ft_strcmp(av[1], "read") == 0)
		type = 5;
	else if (ft_strcmp(av[1], "strdup") == 0)
		type = 6;
	if (type == 1 || type == 0)
	{
		printTitle("Strlen");
		printStrlen("ballon");
		printStrlen("dgascon");
		printStrlen("42 Lyon Auvergne Rhone Alpes");
		printStrlen("Bob");
		printStrlen("t");
		printStrlen("");
		printStrlen(av[1]);
	}
	if (type == 2 || type == 0)
	{
		printTitle("Strcmp");
		printStrcmp("balA", "bala");
		printStrcmp("a", "A");
		printStrcmp("A", "a");
		printStrcmp("abcd", "abcD");
		printStrcmp("abcd", "ab");
		printStrcmp("A", "A");
		printStrcmp("", "");
		printStrcmp("Olivier de carglass !", av[1]);
		printStrcmp("\xff\xfe", "\xff");
	}
	if (type == 3 || type == 0)
	{
		printTitle("Strcpy");
		printStrcpy("Pokemon", "bala");
		printStrcpy("Baz", "Baz");
		printStrcpy("Pos", "Ballon Rouge");
		printStrcpy("Ballon Rouge", "Pos");
		printStrcpy("Ballon Rouge", "");
		printStrcpy("", "Ballon Rouge");
		printStrcpy("", "");
		printStrcpy("", av[1]);
	}
	if (type == 4 || type == 0)
	{
		printTitle("Write");
		int fd1 = open("test/test1.txt", O_CREAT | O_WRONLY, 0777);
		char *s1 = "Ballon rouge";
		printWrite(fd1, s1, ft_strlen(s1));
		printf(">>>>>>>>>>>>>>>>>>\n");
		close(fd1);
		int fd2 = open("test/test2.txt", O_CREAT | O_WRONLY, 0777);
		char *s2 = "";
		printWrite(fd2, s2, ft_strlen(s2));
		close(fd2);
		printf(">>>>>>>>>>>>>>>>>>\n");
		int fd3 = open("test/test3.txt", O_CREAT | O_WRONLY, 0777);
		char *s3 = "";
		close(fd3);
		printWrite(fd3, s3, ft_strlen(s3));
	}
	if (type == 5 || type == 0)
	{
		printTitle("Read");
		int fd1 = open("srcs/ft_strlen.s", O_RDONLY);
		char *s1 = malloc(sizeof(char) * 255);
		printRead(fd1, s1, 5);
		close(fd1);

		printf(">>>>>>>>>>>>>>>>>>\n");
		int fd2 = open("", O_RDONLY);
		char *s2 = malloc(sizeof(char) * 255);
		printRead(fd2, s2, ft_strlen(s2));
		close(fd2);

		printf(">>>>>>>>>>>>>>>>>>\n");
		int fd3 = open("srcs/ft_strcmp.s", O_RDONLY);
		char *s3 = "";
		printRead(fd3, s3, 5);
		close(fd3);
	}
	if (type == 6 || type == 0)
	{
		printTitle("Strdup");
		printStrdup("Pokemon");
		printStrdup("Baz");
		printStrdup("Pos");
		printStrdup(av[1]);
		printStrdup("x");
	}
	return (0);
}