#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "functions/insert.c"
#include "functions/delete.c"
#include "functions/view.c"

int insert_student();
int student_profile();
int delete_student();

int start_menu(){
	printf("************************************** \n");
	printf("WELCOME TO STUDENT MANAGEMENT SYSTEM");
	printf("\n");

	printf("1. Student Profile \n");
	printf("2. Student Attendance \n");
	printf("3. Exit \n");
	printf("************************************** \n");

    printf("Your Choice: ");
	int choice;
	scanf("%d", &choice);

	if(choice == 1){
		student_profile();
	}
	else if(choice == 2){
		// student_attendance();
	}
	else if(choice == 3){
		exit(0);
	}
	else{
		printf("Invalid Choice! \n");
		start_menu();
	}
	return 0;
}

int insert_student(){
	printf("************************************** \n");
	printf("Student Profile \n");

	printf("Student ID: ");
	int id;
	scanf("%d", &id);

	printf("Student's First Name: ");
	char first_name[20];
	scanf("%s", first_name);

	printf("Student's Last Name: ");
	char last_name[20];
	scanf("%s", last_name);

	printf("Student's Age: ");
	int age;
	scanf("%d", &age);

	printf("Student's Gender(M/F/T): ");
	char gender[1];
	scanf("%s", gender);
	printf("************************************** \n");
	printf("Would you like to confirm the entry?(y/n): ");
	char choice[1];
	scanf("%s", choice);
	//if choice is y then call insert() function
	if(choice[0] == 'y'){
		insert(id, first_name, last_name, age, gender);
		student_profile();
	}else{
		student_profile();
	}
}

int delete_student(){
	printf("Please enter the ID of student u wish to delete: \n");
	int id;
	printf("Your Choice: ");
	scanf("%d", &id);

	printf("Would you like to confirm the deletion?(y/n): ");
	char choice[1];
	scanf("%s", choice);
	//if choice is y then call delete() function
	if(choice[0] == 'y'){
		delete(id);
		student_profile();
		}else{
		student_profile();
		}
		
}

int student_profile(){
	printf("************************************** \n");
	printf("1. Insert \n");
	printf("2. Delete \n");
	printf("3. View \n");
	printf("4. Search \n");
	printf("5. Previous Menue \n");
	printf("6. Exit \n");
	printf("************************************** \n");

	printf("Your Choice: ");
	int choice;
	scanf("%d", &choice);

	if(choice == 1){
		insert_student();
	}
	// else if(choice == 2){
	// 	delete_student();
	// }
	// else if(choice == 3){
	// 	view_student();
	// }
	// else if(choice == 4){
	// 	search_student();
	// }
	// else if(choice == 5){
	// 	start_menu();
	// }
	else if(choice == 6){
		return 0;
	}
	else{
		printf("Invalid Choice! \n");
		student_profile();
		return 0;
	}
	return 0;
	}

int main(){
	start_menu();
	return 0;
}
