#include <stdio.h>
#include <stdlib.h>


#define TRUE	1
#define FALSE	0

typedef struct rect{
	int width;
	int height;
}Rect;

int* input(int*, Rect*);

int main(void){

	int* piboArr;
	int num, i, caseCnt;
	Rect rect;

	for(caseCnt = 1; ; caseCnt++)
	{
		piboArr = input(&num, &rect);
		if(piboArr==NULL)
			break;

		for(i=1; i<num; i++)
		{
			if(rect.height == piboArr[i])
				rect.width += piboArr[i];
			else
				rect.height += piboArr[i];
		}
		printf("Case #%d:\n",i);
		printf("%d, %d\n",rect.width, rect.height);
	
		free(piboArr);
	}

	return 0;
}

int* input(int* arr_num, Rect* rect)
{
	int i, num;
	int* piboArr;
	scanf("%d",&num);

	if(num<2)
		return NULL;

	*arr_num = num;

	piboArr = (int*)malloc(num*sizeof(int));
	piboArr[0] = 1; piboArr[1] = 1;

	for(i=2; i<num; i++)
		piboArr[i] = piboArr[i-2] + piboArr[i-1];

	rect->height = 1;
	rect->width = 1;

	return piboArr;
}