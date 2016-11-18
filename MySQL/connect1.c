#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"

MYSQL my_connection;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;

void display_row()
{
	unsigned int field_count;
	field_count = 0;
	while(field_count < mysql_field_count(&my_connection)) {
		printf("%s", sqlrow[field_count++]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	
	int ret;
	
	mysql_init(&my_connection);
	
	if (mysql_real_connect(&my_connection, "localhost", "root", "9082160as", "rick", 0, NULL, 0)) {
		printf("Connection success\n");
		
		ret = mysql_query(&my_connection, "SELECT childno, fname, age FROM children WHERE age > 5");
		if (ret) {
			printf("SELECT error: %s\n", mysql_error(&my_connection));
		} else {
			res_ptr = mysql_use_result(&my_connection);
			if (res_ptr) {
				printf("Retrieved %lu rows\n", (unsigned long)mysql_num_rows(res_ptr));
				while((sqlrow = mysql_fetch_row(res_ptr))) {
					printf("Fetch data...\n");
					display_row();
				}
				if(mysql_errno(&my_connection)) {
					fprintf(stderr, "Retrieved error: %s\n", mysql_error(&my_connection));
				}
				mysql_free_result(res_ptr);
			} 
		 }
	} else {
				fprintf(stderr, "Connection failed\n");
				if (mysql_errno(&my_connection)) {
					fprintf(stderr, "Connection error %d : %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
				}
			  }
	return EXIT_SUCCESS;
}
