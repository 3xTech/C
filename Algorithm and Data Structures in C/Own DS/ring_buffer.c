#include <stdio.h>
#include <string.h>

#define MAX 256

typedef struct ring_{
             unsigned char el[MAX];
             int head;
             int tail;
             int size;
}ring;

int mod_op(int val, int mod)
{
       return (val + 1) % mod;
}

void ring_init(ring *r_buf)
{
      memset(r_buf, 0, sizeof(ring));
}

void put(ring *r_buf, const unsigned char data)
{
      if(r_buf->size < MAX)
      {
                r_buf->el[r_buf->head] = data;
                r_buf->head = mod_op(r_buf->head, MAX);
                r_buf->size++;
      }else{
            printf("FUlll!!!!");
      }
}

int get(ring *r_buf)
{
      int data;
      if(r_buf->size > 0)
      {
             data = r_buf->el[r_buf->tail];
             r_buf->tail = mod_op(r_buf->tail, MAX);
             r_buf->size--;
      }else{
            data = -1;
      }
      return data;
}


void flush(ring *r_buf)
{
      r_buf->head = 0;
      r_buf->tail = 0;
      r_buf->size = 0;
      //Destroy
      memset(r_buf, 0, sizeof(ring));

}




int main()
{
    ring myCirBuffer;
    ring_init(&myCirBuffer);

    put(&myCirBuffer, 'B');
    put(&myCirBuffer, 'C');
    put(&myCirBuffer, 'D');
    put(&myCirBuffer, 'E');
    put(&myCirBuffer, 'F');

    printf("Size: %d\n", myCirBuffer.size);
    
    while(myCirBuffer.size > 0)
    {
          int d = get(&myCirBuffer);
          printf("Data: %c, %d\n", d, myCirBuffer.size);
    }

    



     return 0;
}
