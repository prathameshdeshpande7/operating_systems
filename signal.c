#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void my_signal_handler(int signum)
{
	printf("Caught signal %d - phew!\n", signum);
	exit(1);
}
int main()
{
	signal(SIGINT, my_signal_handler);

	while (1)
	{
	}
}
