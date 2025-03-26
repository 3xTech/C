#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
/* add any other prototypes as needed */

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

void freeStudents(struct student * start){
    struct student * myPTR;
    struct student * tmp;
    myPTR = start;
    while(myPTR != NULL){
        tmp = myPTR->next;
        free(myPTR);
        myPTR = tmp;
    }
}

void printStudents(struct student * start){
            struct student *myPtr;
            myPtr = start;
            while(myPtr != NULL){
                     printf("%s is %d years old.\n", myPtr->name, myPtr->age);
                     myPtr = myPtr->next;
            }
}

struct student *createStudent(char studentName[], int studentAge){
    struct student * myptr;
    myptr = (struct student *) malloc(sizeof(struct student));
    copySTR(myptr, studentName);
    myptr->age = studentAge;
    myptr->next = NULL;
    return myptr;
}

struct student *append(struct student * end, struct student * newStudptr){
       end->next = newStudptr;
       end = end->next;
       return (end);
}

void copySTR(struct student * disPtr, char stdNme[]){
    int i = 0;
    while (stdNme[i]!= '\0'){
        disPtr->name[i] = stdNme[i];
        i++;
    }
    disPtr->name[i] = '\0';
}

