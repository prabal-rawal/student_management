#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int insert(int id, char *first_name, char *last_name, int age) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   int str[100];

   /* Open database */
   rc = sqlite3_open("data/students.db", &db);

   /* Create SQL statement */
   const char *sql = "INSERT INTO STUDENTS (ID, FIRST_NAME, LAST_NAME, AGE) VALUES (?, ?, ?, ?);";
   const char *pzTail;
   sqlite3_stmt *stmt;
   sqlite3_prepare_v2(db, sql, 512, &stmt, &pzTail);
   sqlite3_bind_int(stmt, 1, id);
   sqlite3_bind_text(stmt, 2, first_name, -1, SQLITE_STATIC);
   sqlite3_bind_text(stmt, 3, last_name, -1, SQLITE_STATIC);
   sqlite3_bind_int(stmt, 4, age);
   while (sqlite3_step(stmt) != SQLITE_DONE) {}
   sqlite3_finalize(stmt);


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

int main(int argc, char *argv[]) {
   insert(1, "HHH", "SIJJJJNGH", 19);
   return 0;
}

