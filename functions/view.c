#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback3(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void display_all(int argc, char* argv[]) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("data/students.db", &db);

    char *sql = "SELECT * FROM STUDENTS";
        
    rc = sqlite3_exec(db, sql, callback3, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
    } 
    
    sqlite3_close(db);

}
