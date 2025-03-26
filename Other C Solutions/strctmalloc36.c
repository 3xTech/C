#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {
    struct point * poly;
    int num1 = 0;
    scanf("%d", &num1);
    poly = (struct point *) malloc(num * sizeof(struct point));
    initializePoly(poly, num1);
    printPoly(poly, num1);
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

void initializePoly(struct point * toS, int num){
      int i;
      for(i=0;i<num;i++){
          toS[i].x = -i;
          toS[i].y = i*i;
      }
}