#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}
void readDate(struct date *date2){
    scanf("%d", &date2->year);
    scanf("%d", &date2->month);
    scanf("%d", &date2->day);
}
void printDate(struct date date1){
    if(date1.day<10 && date1.month>10){
           printf("%d/0%d/%d", date1.month, date1.day, date1.year);
    }else if(date1.month<10 && date1.day>10){
           printf("0%d/%d/%d", date1.month, date1.day, date1.year);
    }else if(date1.day<10 && date1.day<10){
            printf("0%d/0%d/%d", date1.month, date1.day, date1.year);
    }else{
           printf("%d/%d/%d", date1.month, date1.day, date1.year);
    }
}
struct date advanceDay(struct date date3){
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    struct date tomo;
    if(date3.day == days_in_month[date3.month-1] && date3.month != 12){
           tomo.day = 01;
           tomo.month = date3.month+1;
           tomo.year = date3.year;
    }else{
           tomo.day = 01;
           tomo.month = 01;
           tomo.year = date3.year+1;
    }
    return tomo;
}