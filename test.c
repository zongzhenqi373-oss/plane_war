#include<stdio>


int function(int num)
{
	int a = num;

	return a;

}


int main()
{
	int a = 10;
	
	int b = 0;
	b = function(a);

	printf("b 的值是：%d",b);
	printf("版本D\n");

	return 0;
}
