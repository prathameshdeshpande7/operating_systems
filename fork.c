#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t	pid, my_pid, cpid;
	pid_t tcpid;
	int status;

	pid = getpid();	/* Parent pid */
	printf("[%d] Parent pid \n", pid);

	cpid = fork();

	if (cpid > 0) {	/* Running in parent */
		my_pid = getpid();
		printf("[%d] pid is parent of [%d] pid\n", my_pid, cpid);
		tcpid = wait(&status);
		printf("[%d] bye %d\n", my_pid, tcpid);
	} else if(cpid == 0) {	/* Running in child process */
		my_pid = getpid();
		printf("[%d] Child pid \n", my_pid);
	} else {
		perror("Fork failed\n");
		exit(1);
	}

	exit(0);
}
