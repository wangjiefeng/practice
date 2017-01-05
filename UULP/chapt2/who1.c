#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

void show_indo(struct utmp *utbufp);

int main()
{
	struct utmp current_record;
	int utmpfd;
	int reclean = sizeof(current_record);
	
	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
		perror(UTMP_FILE);
		exit(1);
	}
	while (read(utmpfd, &current_record, reclean) == reclean) {
		show_info(&current_record);
	}
	close(utmpfd);
	return 0;
}

void show_info(struct utmp *utbufp)
{
	printf("%-8.8s", utbufp->ut_name);
	printf(" ");
	printf("%-8.8s", utbufp->ut_line);
	printf(" ");
	printf("%10ld", utbufp->ut_time);
	printf(" ");
	
	#ifndef SHOWHOST
	printf("(%s)", utbufp->ut->host);
	#endif
	printf("\n");
}
