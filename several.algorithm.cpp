#include <stdio.h>
#include <stdlib.h>

#define PATH_ARR_SIZE	5

typedef struct _node{
	int data;
	struct _node* next;
} Node;

Node* head = NULL, *tail;

void print_gray(int code[], int n, int idx);
void print_gray_reverse(int code[], int n, int idx);
int f_read();


typedef struct _point{
	int x;
	int y;
} Point;


static int path_arr[PATH_ARR_SIZE][PATH_ARR_SIZE];
static int from[PATH_ARR_SIZE][PATH_ARR_SIZE];
enum {LEFT, UP};

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void insertTail(int n)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->next = NULL;

	if(head==NULL)
	{
		head=newNode;
		tail=newNode;
	}
	else{
		tail->next = newNode;
		tail=newNode;
	}
}

int deleteTail(Node* head)
{
	Node* deleteNode;
	int r;
	if(head==NULL)
		return -1;

	deleteNode = head;
	head = head->next;
	if(head == NULL)
		tail = NULL;

	r = deleteNode->data;
	free(deleteNode);
	return r;
}

void print_list(Node* from)
{
	for(Node* i = from; i != NULL; i=i->next)
		printf("%d ", i->data);
}

void print_list2(int* cnt, Node* from)
{
	(*cnt)++;

	if(from == NULL)
		return;

	printf("%d ", from->data);
	print_list2(cnt, from->next);
}

void print_list_reverse(Node* from)
{
	if(from == NULL)
		return;

	print_list_reverse(from->next);	
	printf("%d ", from->data);
}

int choose(int n, int r)
{
	static int memo[100][100];

	if(memo[n][r] != 0 )
		return memo[n][r];

	if(r == 0 || n ==r)
		return memo[n][r] = 1;
	else
		return memo[n][r] = choose(n-1, r-1) + choose(n-1, r);
}

long long fibo(int n)
{
	static long long arr[100];

	if(arr[n]!=0)
		return arr[n];

	if(n ==1 || n==2)
		return arr[n] = 1;
	else
		return arr[n] = fibo(n-1) + fibo(n-2);
}

long long pay(int n)
{
	static long long pay_arr[100];

	if(n<0)
		return 0;

	if(pay_arr[n] !=0)
		return pay_arr[n];

	if(n==0)
		return 1;

	return pay_arr[n] = pay(n-1) + pay(n-2) + pay(n-5);// +pay(n-10)+pay(n-20)+ pay(n-50);
}

int partition(int n,int m)
{
	static int partition_memo[100][100];

	int count = 0;
	int i = 0;

	if(partition_memo[n][m] != 0)
		return partition_memo[n][m];

	if(n<m)
		m = n;

	if( n==0)
		//return 1;
		return partition_memo[0][m] = 1;

	for(i = 1; i<=m; i++)
		count += partition(n - i, i);

	return partition_memo[n][m] = count;
}

//int partition2(int n)
//{
//	int result = 0;
//
//	if(n==0)
//		return 1;
//	if(n<0)
//		return 0;
//
//	for(int i = 0 ; i<=n-1 ; i++)
//		result += partition2(i);
//
//	return result;
//}

int partition2(int n)
{
	int result = 0;

	for(int i = 1 ; i<=n-1 ; i++)
		result += partition2(i);

	return result +1 ;
}

int pow(int n, int k)
{
	if(k==0)
		return 1;

	return n*pow(n,k-1);
}

int pascal_tri(int n, int r)
{
	if(r==0 || n==r)
		return 1;

	return pascal_tri(n-1, r-1) + pascal_tri(n-1, r);
}

void print_pascal(int k)
{

	for(int i=0; i<=k; i++)
		printf("%d ", pascal_tri(k,i));
	printf("\n");
}

int max_joy(int x, int y)
{
	if(x ==0 && y==0)
		return path_arr[0][0];

	if(x >0 && y==0)
		return max_joy(x-1,y) + path_arr[x][y];

	if(x ==0 && y>0)
		return max_joy(x, y-1)+ path_arr[x][y];

	if(x>0 && y>0)
		return max(max_joy(x-1,y), max_joy(x,y-1)) + path_arr[x][y];
}

void print_path(int x, int y)
{
	if(x == 0, y==0)
		return;

	if(from[x][y] == LEFT)
	{
		printf("(%d  %d)", x-1 ,y );
		return print_path(x-1,y);
	}

	if(from[x][y] == UP){
		printf("(%d  %d)", x, y-1);
		return print_path(x, y-1);
	}
}

int calculate_joy(int x, int y)
{
	static int joy[PATH_ARR_SIZE][PATH_ARR_SIZE];
	

	for(int i=0; i<=x; i++)
	{
		for(int j = 0;j<=y; j++)
		{
			if(i == 0 && j==0)
			{
				joy[0][0] = path_arr[0][0];
				continue;
			}

			if( j ==0)
			{
				joy[i][j] = joy[i-1][j] + path_arr[i][j];
				from[i][j] = LEFT;
			}

			if( i==0){
				joy[i][j] = joy[i][j-1] + path_arr[i][j];
				from[i][j] = UP;
			}

			if(i>0 && j>0)
			{
				int max_value = max(joy[i-1][j], joy[i][j-1]) ;
				joy[i][j] = max_value + path_arr[i][j];

				if(max_value == joy[i-1][j])
					from[i][j] = LEFT;
				else
					from[i][j] = UP;
			}
		}
	}

	return joy[x][y];
}

int main(void){

	int bills[6] = {1,2,5,10,20,50};
	int count = 0, money = 100, i0, i1, i2, i3 ,i4;

	//	int code[100];

	//print_gray(code, 4,0);
	/*int result = 0;
	for(int i=1; i<=3; i++)
	result+=pow(i,3);

	printf("%d\n",result);*/

	/*for(int i = 0 ; i<=4 ; i++)
	print_pascal(i);*/

	f_read();
	//printf("%d\n",max_joy(4,4));
	printf("%d\n",calculate_joy(3,3));
	printf("%d\n",calculate_joy(4,2));
	printf("%d\n",calculate_joy(4,4));
	print_path(4,4);
	
	return 0;
}

void print_code(int code[], int len)
{
	for(int i=0; i<len; i++)
		printf("%d",code[i]);
	printf("\n");
}

void print_gray(int code[], int n, int idx)
{
	if(idx == n){
		print_code(code, n);
		return;
	}

	code[idx]=0;
	print_gray(code, n ,idx+1);
	code[idx]=1;
	print_gray_reverse(code, n ,idx+1);
}

void print_gray_reverse(int code[], int n, int idx)
{
	if(idx == n){
		print_code(code, n);
		return;
	}

	code[idx]=1;
	print_gray(code, n ,idx+1);
	code[idx]=0;
	print_gray_reverse(code, n ,idx+1);
}



int f_read (void)
{
	FILE* fp;
	fp = fopen("input.txt","r");
	if(fp==NULL)
	{
		printf("FIle open error\n");
		return 0;
	}

	int data;
	
	int path_arr_i = 0;
	int path_arr_j = 0;


	while(fscanf(fp, "%d", &data) != EOF){
	
		if(path_arr_j == PATH_ARR_SIZE)
		{
			path_arr_i++; path_arr_j = 0;
		}

		path_arr[path_arr_i][path_arr_j] = data;
		path_arr_j++;
	}
		
	if(fclose(fp)!=0)
	{
		printf("file close error\n");
		return 0;
	}
	return 1;
}

