
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------
 * Definitions and macros
 */
#define HIGH_CH_BIT(ChannelCount)  (1 << ((ChannelCount + 31) % 32))
#define PREP_MASK(ChannelCount)   ((HIGH_CH_BIT(ChannelCount))| (HIGH_CH_BIT(ChannelCount) - 1))
#define MASK_UNUSED_CH_BITS(ChannelCount, ChannelMask) (PREP_MASK(ChannelCount) & (ChannelMask))

#define NO_OF_CHANNEL_WORDS 4

/** Channel Mask */
typedef struct
{
  uint32_t ch_bitmask[4];
} EIP163_Ch_Mask_t;

/*----------------------------------------------------------------------------
 * Local variables
 */

/*----------------------------------------------------------------------------
 * Local Functions
 */

static void
MaskUnusedChBits(EIP163_Ch_Mask_t *const ChMask_p,
                 const uint16_t ChannelCount)
{
  uint8_t i, index = (ChannelCount + 31) / 32;
  /** Get the Channel Mask representing the higher channels */
  uint32_t val = ChMask_p->ch_bitmask[index - 1];
  ChMask_p->ch_bitmask[index - 1] = MASK_UNUSED_CH_BITS(ChannelCount, val);
  
  for (i = index; i < NO_OF_CHANNEL_WORDS; i++) { ChMask_p->ch_bitmask[i] = 0; }
}

int main(int argc, char *argv [ ])
{
  EIP163_Ch_Mask_t ch_mask;
  EIP163_Ch_Mask_t *ch_mask_p;
  //memset(&ch_mask, 0, sizeof(EIP163_Ch_Mask_t));
  ch_mask.ch_bitmask[0] = 0xFFFFFFFF;
  ch_mask.ch_bitmask[1] = 0xFFFFFFFF;
  ch_mask_p = malloc(sizeof(EIP163_Ch_Mask_t));
  ch_mask_p->ch_bitmask[0] = 0xFFFFFFFF;
  ch_mask_p->ch_bitmask[1] = 0xFFFFFFFF;
  MaskUnusedChBits(&ch_mask, 60);
  MaskUnusedChBits(ch_mask_p, 16);
  printf("Lower Channel bits: 0x%x\n", ch_mask.ch_bitmask[0]);
  printf("Higher Channel bits: 0x%x\n", ch_mask.ch_bitmask[1]);
  printf("Higher Channel bits: 0x%x\n", ch_mask.ch_bitmask[2]);
  printf("Higher Channel bits: 0x%x\n", ch_mask.ch_bitmask[3]);
  printf("Lower Channel bits: 0x%x\n",  ch_mask_p->ch_bitmask[0]);
  printf("Higher Channel bits: 0x%x\n", ch_mask_p->ch_bitmask[1]);
  printf("Higher Channel bits: 0x%x\n", ch_mask_p->ch_bitmask[2]);
  printf("Higher Channel bits: 0x%x\n", ch_mask_p->ch_bitmask[3]);
  return 0;
}
