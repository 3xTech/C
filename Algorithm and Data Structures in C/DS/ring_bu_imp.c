#include <stdio.h>
#include <string.h>

#define MAX 256    // Fixed size of the buffer

typedef struct{
     unsigned char buf[MAX];
     int head;
     int tail;
     int size;
} ringBuf;


// Modulo Helper function

int modulo(int val, int mod){
        return (val + 1) % mod;
}


void rBuf_Init(ringBuf *rBuf){
    memset(rBuf, 0, sizeof(*rBuf));
}

int rBuf_Empty(ringBuf *rBuf){
    return (rBuf->size == 0);
}


int rBuf_Full(ringBuf *rBuf){
    return (rBuf->size >= MAX);
}

void rBuf_put(ringBuf *rBuf, const unsigned char data){
        if(rBuf->size < MAX){
                  rBuf->buf[rBuf->head] = data;
                  rBuf->head = modulo(rBuf->head, MAX);
                  rBuf->size++;
        }else{
            printf("Data discard %d\n", data);
        }
}


int rBuf_get(ringBuf *rBuf){
       int data;
       if(rBuf->size > 0){
                data = rBuf->buf[rBuf->tail];
                rBuf->tail = modulo(rBuf->tail, MAX);
                rBuf->size--;
       }else{
           //Buffer is empty
           data = -1;
       }
       return data;
}


void rBuf_flush(ringBuf *rBuf, const int clr){
       rBuf->head = 0;
       rBuf->tail = 0;
       rBuf->size = 0;
       //can clear the actual buffer 
       if(clr){
             memset(rBuf->buf,0,sizeof(rBuf->buf));
       }
}


int main(void){
    ringBuf myBuf;
    rBuf_Init(&myBuf);

    printf("Putting elements 'B', 'D', 'F', 'H' into the buffer:\n");

    rBuf_put(&myBuf, 'B');
    rBuf_put(&myBuf, 'D');
    rBuf_put(&myBuf, 'F');
    rBuf_put(&myBuf, 'H');
 
    printf("Buffer status: head=%d, tail=%d, count=%d\n", myBuf.head, myBuf.tail, myBuf.size);

    while(!rBuf_Empty(&myBuf)){
           int data = rBuf_get(&myBuf);
           if(data != -1){
                 printf("Data %c\n", data);
           }else{
                printf("Buffer is empty!");
           }
    }


    return 0;
}