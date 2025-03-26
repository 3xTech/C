#include <stdio.h>
#include <string.h>

#define RBUF_SIZE 256

typedef struct{
       unsigned char buf[RBUF_SIZE];
       int head;
       int tail;
       int size;
} ringBuf;

//HELPER FUNCTION MODULO
int modulo(int val, int mod){
    return (val + 1) % mod;
}

void rBuf_Init(ringBuf *rBuf){
          memset(rBuf->buf, 0 , sizeof(*rBuf));
}

int is_empty(ringBuf *rBuf){
          return (rBuf->size == 0);
}

int is_full(ringBuf *rBuf){
        return (rBuf->size >= RBUF_SIZE);
}


void rBuf_put(ringBuf *rBuf, const unsigned char data){
            if(rBuf->size < RBUF_SIZE){
                      rBuf->buf[rBuf->head] = data;
                      rBuf->head = modulo(rBuf->head, RBUF_SIZE);
                      rBuf->size++;
            }else{
                    printf("Buffer is full!!!");
            }
}

int rBuf_get(ringBuf *rBuf){
          int data;
          if(rBuf->size > 0){
                  data = rBuf->buf[rBuf->tail];
                  rBuf->tail = modulo(rBuf->tail, RBUF_SIZE);
                  rBuf->size--;
          }else{
             data = -1;
          }
          return data;
}


void rBuf_flush(ringBuf *rBuf, const int clr){
              rBuf->head = 0;
              rBuf->tail = 0;
              rBuf->size = 0;
              if(clr){
                    memset(rBuf->buf, 0 , sizeof(rBuf->buf));
              }
}


int main(void){
    ringBuf myBuf;
    rBuf_Init(&myBuf);

    rBuf_put(&myBuf, 'A');
    rBuf_put(&myBuf, 'B');
    rBuf_put(&myBuf, 'C');
    rBuf_put(&myBuf, 'D');


    while(!is_empty(&myBuf)){
        int data = rBuf_get(&myBuf);
        printf("Data %c\n", data);
    }

    printf("Finished!!");


    return 0;
}
