
#include "actdb.h"
#include "show.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"

MYSQL *cons;
char *DB_NAME = "test";
char *DB_PASS = "12345";

int main(void) {
	MYSQL_RES *myresult;
	MYSQL_ROW row;
	
	int select_menu = 0;
	unsigned int num_fields;
	unsigned int num_rows;

	char query[256];
	connect_db_server(&cons, DB_NAME, DB_PASS);
	show_enter_window();
	scanf("%d", &select_menu);
	switch (select_menu) {
		case 1:
			if(access_login(&cons)) {
				printf("login error\n");
				return 0;
			}
			break;
		case 2:
			if(access_make_account(&cons)) {
				printf("Cannot make Account\n");
				return 0;
			}
			break;
		case 3:
			return 0;
			break;

	}
	//connect_db_server(&cons);
	sprintf(query, "SELECT id, name FROM mytable");

	mysql_query(cons,query);
	myresult = mysql_store_result(cons);
	while(row = mysql_fetch_row(myresult))
		printf("%s\t %s\n", row[0], row[1]);
	mysql_free_result(myresult);
	mysql_close(cons);

	return 0;
}