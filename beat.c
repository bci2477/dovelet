#include <stdio.h>

int main(void){

	int sum, differ;
	int x,y;

	scanf("%d %d",&sum, &differ);

	if(!checkPossible((sum+differ)%2)){
		printf("impossible");
		return 0;
	}

	x = (sum+differ)/2 ;
	y = sum - x;

	if(x< 0 || y<0)
		printf("impossibile");
	else
		printf("%d %d",x,y);

	return 0;
}

int checkPossible(int x)
{
	if (x == 1)
		return 0;
	else
		return 1;
}