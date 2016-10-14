#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
int main(int argc, char *argv[])
{
	MYSQL my_connection;
	int ret;
	
	mysql_init(&my_connection);
	
	if(mysql_real_connect(&my_connection, "localhost", "root", "9082160as", "rick", 0, NULL, 0)) {
		printf("Connection success\n");
		/*ret = mysql_query(&my_connection, "INSERT INTO children(fname, age) VALUES('Ann', 3)");
		if(!ret) {
			printf("Insert %lu rwos\n", (unsigned long)mysql_affected_rows(&my_connection));
		} else {
			fprintf(stderr, "Insert error %d : %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
		}*/
		ret = mysql_query(&my_connection, "UPDATE children SET AGE = 4 WHERE fname = 'Ann'");
		if(!ret) {
			printf("Update %lu rows\n", (unsigned long)mysql_affected_rows(&my_connection));
		} else {
			fprintf(stderr, "Update error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
		}
	} else {
		fprintf(stderr, "Connection failed\n");
		if(mysql_errno(&my_connection)) {
			fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
		}
	}
	
	return EXIT_SUCCESS;
}
