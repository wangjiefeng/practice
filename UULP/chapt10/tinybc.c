#include	<stdio.h>

#define	oops(m,x)	{ perror(m); exit(x); }

main()
{
	int	pid, todc[2], fromdc[2];

	if ( pipe(todc) == -1 || pipe(fromdc) == -1 )
		oops("pipe failed", 1);

	if ( (pid = fork()) == -1 )
		oops("cannot fork", 2);
	if ( pid == 0 )				/* child is dc	*/
		be_dc(todc, fromdc);
	else {
		be_bc(todc, fromdc);		/* parent is ui	*/
		wait(NULL);			/* wait for child */
	}
}

be_dc(int in[2], int out[2])
{
    /* setup stdin from pipein	*/
	if ( dup2(in[0],0) == -1 )	/* copy read end to 0   */
		oops("dc: cannot redirect stdin",3);
	close(in[0]);			/* moved to fd 0	*/
	close(in[1]);			/* won't write here	*/

    /* setup stdout to pipeout	*/
	if ( dup2(out[1], 1) == -1 )	/* dupe write end to 1	*/
		oops("dc: cannot redirect stdout",4);
	close(out[1]);			/* moved to fd 1	*/
	close(out[0]);			/* won't read from here	*/

    /* now execl dc with the - option */
	execlp("dc", "dc", "-", NULL );
	oops("Cannot run dc", 5);
}

be_bc(int todc[2], int fromdc[2])
{
	int	num1, num2;
	char	operation[BUFSIZ], message[BUFSIZ], *fgets();
	FILE	*fpout, *fpin, *fdopen();

	/* setup */
	close(todc[0]);			/* won't read from pipe to dc  */
	close(fromdc[1]);		/* won't write to pipe from dc */

	fpout = fdopen( todc[1],   "w" );	/* convert file desc-  */
	fpin  = fdopen( fromdc[0], "r" );	/* riptors to streams  */
	if ( fpout == NULL || fpin == NULL )
		fatal("Error convering pipes to streams");

	/* main loop */
	while ( printf("tinybc: "), fgets(message,BUFSIZ,stdin) != NULL ){

		/* parse input */
		if ( sscanf(message,"%d%[-+*/^]%d",&num1,operation,&num2)!=3){
			printf("syntax error\n");
			continue;
		}

		if ( fprintf( fpout , "%d\n%d\n%c\np\n", num1, num2, 
				*operation ) == EOF )
					fatal("Error writing");
		fflush(  fpout );
		if ( fgets( message, BUFSIZ, fpin ) == NULL )
			break;
		printf("%d %c %d = %s", num1, *operation , num2, message);
	}
	fclose(fpout);		/* close pipe		*/
	fclose(fpin);		/* dc will see EOF	*/
}

fatal( char *mess )
{
	fprintf(stderr, "Error: %s\n", mess);
	exit(1);
}
