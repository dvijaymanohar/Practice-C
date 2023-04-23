#ifndef RING_H
#define RING_H


typedef struct Buffer
{
  struct Buffer *LLink;
  void *Data;
  struct Buffer *RLink;
} RingBuffer_t;

struct Ring
{
  long Signature;
  int Count;
  RingBuffer_t *Rear;
  RingBuffer_t *Front;
  RingBuffer_t *Head;
} Ring_t;




