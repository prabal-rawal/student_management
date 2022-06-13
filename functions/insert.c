#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("data/students.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char name[256], price[256];
    printf("Enter car name: ");
    scanf("%s", name);
    printf("Enter car price: ");
    scanf("%s", price);

    int offset = 0;
    //insert(id, first_name, last_name, age, gender);
    char sql_insert[1024];
    strcpy(sql_insert, (char *)"INSERT INTO STUDENTS VALUES(1, '");
    offset += strlen("INSERT INTO STUDENTS VALUES(1, '");
    strcpy(sql_insert + offset, name);
    offset += strlen(name);
    strcpy(sql_insert + offset, (char *)"', ");
    offset += strlen("', ");
    strcpy(sql_insert + offset, price);
    offset += strlen(price);
    strcpy(sql_insert + offset, ");"); 
    
    rc = sqlite3_exec(db, &sql_insert[0], 0, 0, &err_msg);
    
    sqlite3_close(db);

    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    }
    
    return 0;
}