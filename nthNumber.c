#include <stdio.h>
#include <math.h>

#define TRUE	1
#define FALSE	0

int multi(int);

int main(void){
	char num[1000000];
	int n, exp=0, i=0, temp =0, location =0;
	scanf("%d",&n);

	if(n<10)
	{
		printf("%d",n);
		return 0;
	}
	
	temp = n;
	

	for(exp = 1; ;exp++)
	{
		if((temp - multi(exp))<0)
		{
			exp--;
			break;
		}
	}
	
	
	location = (n-multi(exp))%exp;

	temp = n%exp;

	if((n%exp)!=0)
		n-=(n%exp);

	sprintf(num,"%d\n",(n - multi(exp))/exp + (int)pow(10.0,exp-1));
	printf("%c\n",num[location]);
		
	return 0;
}


int multi(int exp)
{
	int result = 0, i =0;

	for(i=1; i<exp; i++)
		result+= 9*(int)pow(10.0,i-1)*i;
	result++;
	return result;
}