#include<stdio.h>
#include<string.h>

struct dob{
    int date;
    int month;
    int year;
};

struct student_info{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void callbyvalue(struct student_info student){
    printf("Data of Students:\n");
    printf("Roll Number: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("DOB: %d %d %d\n", student.age.date, student.age.month, student.age.year);
}

void callbyaddress(struct student_info* student2, int count){
    printf("\nData of Students:\n");
    for(int i = 0; i < count; i++){
        printf("Roll Number: %d\n", student2[i].roll_no);
        printf("Name: %s\n", student2[i].name);
        printf("CGPA: %.2f\n", student2[i].CGPA);
        printf("DOB: %d %d %d\n", student2[i].age.date, student2[i].age.month, student2[i].age.year);
    }
}

int main(){
    printf("Enter number of students: ");
    int count;
    scanf("%d", &count);
    struct student_info student1[count];
    for(int i = 0; i < count; i++){
        printf("Enter the data of the student (Roll No, Name, CGPA, Age(dd, mm, yyyy)): ");
        scanf("%d", &student1[i].roll_no);
        scanf(" %49[^\n]", student1[i].name);
        scanf("%f", &student1[i].CGPA);
        scanf("%d", &student1[i].age.date);
        scanf("%d", &student1[i].age.month);
        scanf("%d", &student1[i].age.year);
    }
    for(int i = 0; i < count; i++){
        callbyvalue(student1[i]);
    }
    callbyaddress(student1, count);
    return 0;
}