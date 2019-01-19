#include <stdio.h>
int main() {
	int dec, oct;
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &dec);
	printf("In octal, your number is: %05o\n", dec);
}