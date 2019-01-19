#include <stdio.h>
int get_book5_price(int total_price, int book1, int book2, int book3, int book4);
int main() {
	int total, book1, book2, book3, book4,book5;
	printf("Total : ");
	scanf("%d", &total);
	printf("Book1 : ");
	scanf("%d", &book1);
	printf("Book2 : ");
	scanf("%d", &book2);
	printf("Book3 : ");
	scanf("%d", &book3);
	printf("Book4 : ");
	scanf("%d", &book4);
	book5 = get_book5_price(total, book1, book2, book3, book4);
	printf("Book5 price is %d\n", book5);
}
int get_book5_price(int total, int book1, int book2, int book3, int book4)
{
	int book5;
	book5 = total - book1 - book2 - book3 - book4;
	return book5;
}