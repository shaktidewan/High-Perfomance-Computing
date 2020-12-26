
#include <stdio.h>

int main()
{
	int A,B,C,D;
	A=2;
	B=4;
	C=6;
	D=8;
	
	int Btemp = B;
	int Ctemp = C;
	Btemp = A + C;
	B= Ctemp + D;
	C = B + D;
	
	printf("Output:\n");
	printf("%d %d %d %d", A, B, C, D);
	
	
}

