// Programmer: Areeba Hasnain
// Description: fidning volume of the parallelepiped box if it can pass through a 41 feet tunnel (???)

#include <stdio.h>
#include <string.h>

typedef struct {
	int CourseId;
	char CourseName[20];
} Register;

typedef struct {
	Register course; // inherit Register
	int StudentId;
	char FirstName[20];
	char LastName[20];
	char cellno[15];
	char email[30];
} Student;


void input(Student students[5])
{
	 for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);

        printf("Enter student id: ");
        scanf("%d", &students[i].StudentId);

        printf("Enter first name: ");
        fgets(students[i].FirstName, sizeof(students[i].FirstName), stdin);
        students[i].FirstName[strlen(students[i].FirstName) - 1] = '\0';

        printf("Enter last name: ");
        fgets(students[i].LastName, sizeof(students[i].LastName), stdin);
        students[i].LastName[strlen(students[i].LastName) - 1] = '\0';

        printf("Enter cell number: ");
        fgets(students[i].cellno, sizeof(students[i].cellno), stdin);
        students[i].cellno[strlen(students[i].cellno) - 1] = '\0';

        printf("Enter email: ");
        fgets(students[i].email, sizeof(students[i].email), stdin);
        students[i].email[strlen(students[i].email) - 1] = '\0';

        printf("Enter student's course id: ");
        scanf("%d", &students[i].course.CourseId);

        printf("Enter student's course name: ");
        fgets(students[i].course.CourseName, sizeof(students[i].course.CourseName), stdin);
        students[i].course.CourseName[strlen(students[i].course.CourseName) - 1] = '\0';

		printf("\n");
	}
} // end input()

void output(Student students[5])
{
	for (int i = 0; i < 5; i++) {
		printf("\nStudent %d\n", i+1);
		printf("\nStudent id: %d\nFirst name: %s\nLast name: %s\nCell number: %s\nEmail: %s\nCourse ID: %d\nCourse name: %s\n", 
			students[i].StudentId,
			students[i].FirstName,
			students[i].LastName,
			students[i].cellno,
			students[i].email,
			students[i].course.CourseId,
			students[i].course.CourseName
		);
	}
} // end output()

int main()
{
	Student students[5];

	input(students);

	output(students);

	return 0;
} // end main()