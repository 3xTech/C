#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *datePTR){
    scanf("%d", &(*datePTR).year);
    scanf("%d", &(*datePTR).month);
    scanf("%d", &(*datePTR).day);
    
}
void printDate(struct date todayP){
    if(todayP.day>9){
      printf("%d/%d/%d", todayP.month, todayP.day, todayP.year);
    }else{
        printf("%d/0%d/%d", todayP.month, todayP.day, todayP.year);
    }
}