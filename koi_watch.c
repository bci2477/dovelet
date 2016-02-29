#include <stdio.h>

int overLimit(int);

int main(void){
	int hour, minute, second;
	int time;

	scanf("%d %d %d",&hour, &minute, &second);
	scanf("%d",&time);

	if((time/3600) > 0)
	{
		hour += time/3600;
		time%= 3600;
	}

	if((time/60) > 0)
	{
		minute += time/60;
		time%= 60;
	}

	second += time;

	if(overLimit(second)){
		second-=60;
		minute++;
	}

	if(overLimit(minute)){
		minute-=60;
		hour++;
	}

	while(hour >=24)
		hour -= 24;

	printf("%d %d %d\n", hour, minute, second);

}

int overLimit(int num)
{
	if(num >= 60)
		return 1;
	else
		return 0;
}