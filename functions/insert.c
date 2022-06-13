#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback1(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


void insert(int id, char *first_name, char *last_name, int age, char *gender) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   /* Open database */
   rc = sqlite3_open("/Volumes/yet_another/Development/student_management /data/students.db", &db);

   /* Create SQL statement */
   const char *sql = "INSERT INTO STUDENTS (ID, FIRST_NAME, LAST_NAME, AGE, GENDER) VALUES (?, ?, ?, ?, ?);";
   const char *pzTail;
   sqlite3_stmt *stmt;
   sqlite3_prepare_v2(db, sql, 512, &stmt, &pzTail);
   sqlite3_bind_int(stmt, 1, id);
   sqlite3_bind_text(stmt, 2, first_name, -1, SQLITE_STATIC);
   sqlite3_bind_text(stmt, 3, last_name, -1, SQLITE_STATIC);
   sqlite3_bind_int(stmt, 4, age);
   sqlite3_bind_text(stmt, 5, gender, -1, SQLITE_STATIC);

   while (sqlite3_step(stmt) != SQLITE_DONE) {}
   sqlite3_finalize(stmt);


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback1, 0, &zErrMsg);
   if(rc != SQLITE_OK) {
      fprintf(stdout, "Records created successfully\n");
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
}

