#ifndef RING_H
#define RING_H

#define RETVAL1         -1      //For Failure
#define RETVAL0          0      //For Success

#define BUFFER_SIZE    14

#define ONE              1
#define ZERO             0
#define ARGCOUNT         2
#define CONTINUE         1

//Switch Cases

#define INSERT           1
#define DELETE           2
#define DISPLAY          3
#define EXIT             4

#define DEBUG            1

#define TEST       1
#define RING_SIGNATURE   14

typedef struct RingBuffer
{
  long Signature;
  unsigned char *Rear;
  unsigned char *Front;
  char Buffer[BUFFER_SIZE];
} RingBuffer_t;

extern int RingBufferInit(RingBuffer_t *Ring);
extern int RingBufferRead(RingBuffer_t *Ring, unsigned char *Buf, int Count);
extern int RingBufferWrite(RingBuffer_t *Ring, unsigned char *Buf, int Count);

#endif
