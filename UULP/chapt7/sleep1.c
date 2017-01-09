#include <stdio.h>
#include <signal.h>

void wakeup(int signum)
{
	#ifndef SHHH
	printf("After received from kernel\n");
	#endif
}
int main()
{
	printf("about to sleep for 4 seconds\n");
	signal(SIGALRM, wakeup);
	alarm(4);
	pause();
	printf("MOrning so soon?\n");
}
