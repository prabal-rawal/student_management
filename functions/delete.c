#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback2(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int delete(int id){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open("data/students.db", &db);

    /* Create SQL statement */
    const char *sql = "DELETE FROM STUDENTS WHERE ID = ?;";
    const char *pzTail;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, 512, &stmt, &pzTail);
    sqlite3_bind_int(stmt, 1, id);

    while (sqlite3_step(stmt) != SQLITE_DONE) {}
    sqlite3_finalize(stmt);


    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback2, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Records deleted successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

