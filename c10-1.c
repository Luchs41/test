#include <stdio.h>

int main()
{
	char s[] = "i love c programming!!";
	char* sptr = s;

	//40칸에 맞춰서 출력
	printf("[%-40s]\n", s);
	printf("[%40s]\n", s);

	//15칸에 맞춰서 8글자만 출력
	printf("[%-15.8s]\n", s);
	printf("[%15.8s]\n", s);

	//programming!! 만 출력
	fputs(s+9, stdout);
	fputs("\n", stdout);

	return 0;
}
