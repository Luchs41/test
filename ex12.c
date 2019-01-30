#include <stdio.h>

int Fibonacci(int*y);
int x = 1; // Fibonacci(n-1)
int main(void)
{
	int x = 0; // Fibonacci(n-2)
	printf("Fibo(2): %d\n", Fibonacci(&x));
	printf("Fibo(3): %d\n", Fibonacci(&x));
	printf("Fibo(4): %d\n", Fibonacci(&x));
	printf("Fibo(5): %d\n", Fibonacci(&x));
	printf("Fibo(6): %d\n", Fibonacci(&x));
	printf("Fibo(7): %d\n", Fibonacci(&x));
	printf("Fibo(8): %d\n", Fibonacci(&x));
	printf("Fibo(9): %d\n", Fibonacci(&x));

	return 0;
}
// in : x = Fibo(n-1), *y = Fibo(n-2)
int Fibonacci(int *y)
{
	int result = *y + x;
	*y = x; // Fibo(n-1) = x
	x = result; // Fibo(n) = Fibo(n-1) + Fibo(n-2) = result
	return result; //Fibo(n-2) + Fibo(n-1)
}
