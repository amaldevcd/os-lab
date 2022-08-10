#include <stdio.h>
#include <unistd.h>
void egfork()
{
	int x=9;
	printf("x = %d\n",x);
	if(fork()==0)
				printf("Child x = %d\n",++x)	;
	else
		printf("Parent x = %d\n",x);
}

int main()
{
	egfork();
	return 0;
}
