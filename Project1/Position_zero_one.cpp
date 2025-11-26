#include<iostream>
#define mask1 0x21
#define mask2 0x0C

int main()
{
	unsigned char reg_data = 23;
	printf("十六进制: 0x%x\n", reg_data);

	reg_data &= ~mask1;
	reg_data |= mask2;

	printf("十六进制: 0x%x\n", reg_data);
	return 0;
}