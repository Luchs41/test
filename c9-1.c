#include <stdio.h>

int main()
{
	char strA[16] = "The quick brown";
	char strB[] = "fox jumps";
	char* strC = "over the";
	char strD[10] = {'l', 'a', 'z', 'y', ' ', 'd', 'o', 'g', '.', '\0'};

	printf("strA: %s\n", strA);
	printf("strB: %s\n", strB);
	printf("strC: %s\n", strC);
	printf("strD: %s\n", strD);
	
	/*
	printf("%p\n", &strA);
	printf("%p\n", strA);
	printf("%p\n", &strC);
	printf("%p\n", strC);
	*/

	//strA = strB;
	//strA와 strB모두 배열로 초기화된 문자열이다. 즉 둘 다 배열의 이름에 해당해서 다른 주소값으로 변경할 수 없으므로 error가 발생하게 된다. 
	strC = strD;

	return 0;

}
