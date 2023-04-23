#include "Ring.h"
#define TEST
#include <stdio.h>
#endif

extern int RingBufferInit(RingBuffer *Ring)
{
  Ring -> Signature = RING_SIGNATURE;
  Ring -> Rear    = NULL; //Initial Condition: Both pointing to -1
  Ring -> Front   = NULL;
}

extern int RingBufferRead(RingBuffer_t *Ring, unsigned char *Buf, int Count)
{
  if (Ring -> Signature != RING_SIGNATURE)
  {
    if (DEBUG) { printf("\n\tRingBufferRead : Ring Buffer \n"); }
    
    return 0;
  }
  
  if (Ring -> Rear == NULL)
  {
    if (DEBUG) { printf("\n\tRingBufferRead : Empty Buffer\n"); }
    
    return 0;
  }
  
  //When the whole data is read, point the front of the buffer to INIT i.e., -1
  
  if ((Ring -> Rear + 1) % BUFFER_SIZE ==)
  
    //Reading is similar to that of delete, where we are reading from the current
    //front pos and then advancing it to point to its next location
    
    //Writing is similar to that of inserting, where we are writing at the current
    //rear position and then advancing. When rear reaches the end, we have to test
    //whether it points to the 0th location on advancing.
    
    // Buffer is full when rear + 1 == front
    //When front + 1 == rear
    
    //When adding data, add at the rear position, then increament the rear
    //pointer to point to the next location
    
    //When reading data,
    if (Ring -> Rear)
      if ((Ring -> Rear + 1) % BUFFER_SIZE == Ring -> Front)
      {
        if (DEBUG) { printf("\n\tRingBufferRead : Ring Buffer Full\n"); }
        
        return 0;
      }
      
  if (Ring -> Rear == Ring -> Front)
  {
    extern int RingBufferWrite(RingBuffer_t *Ring, unsigned char *Buf, int Count);