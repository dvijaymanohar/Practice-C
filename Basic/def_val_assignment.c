#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  uint32_t ch_bitmask[2];
} Ch_Mask_t;

/** MTT matching rule key/mask data structure */
typedef struct
{
  /** One bit per channel number */
  Ch_Mask_t ChannelMask;
  
  /** Is packet IPv6 */
  bool fIPv6;
  
  /** VLAN tag label */
  uint16_t TagLabel1;
} CfyE_MTT_KeyMask_t;

/** MTT matching rule data structure */
typedef struct
{
  /** Sets matching values as specified in CfyE_MTT_KeyMask_t */
  CfyE_MTT_KeyMask_t Key;
  
  /** Mask for matching values, can be used to mask out irrelevant Key bits */
  CfyE_MTT_KeyMask_t Mask;
  
  /** IP address (source for egress, destination for ingress) to match.*/
  uint32_t IPAddr [4];
  
  /** Mask for data values, can be used to mask out irrelevant Data bits */
  uint32_t IPAddrMask [4];
} CfyE_MTT_t;

int main(int argc, const char **argv)
{
  CfyE_MTT_t CfyE_MTT_Entries_CloudSec_Egress[2] =
  {
    {
      {
        {{0x00000001, 0x00000000},}, /* channel mask */
        
        true,       /* IPv6 */
        
        0           /* TagLabel */
      },
      {
        {{0xffffffff, 0xffffffff},}, /* mask bits for matching */
        1,
        0,
      },
      {   /* IP address */
        0x220cff59,
        0xd0669d37,
        0x25a803bc,
        0xea684bff,
      },
      {   /* Address mask */
        0xffffffff,
        0xffffffff,
        0xffffffff,
        0xffffffff,
      }
    },
    
    {
      {
        {{0x00000080, 0x00000000},},  /* channel mask */
        
        true,       /* IPv6 */
        
        0           /* TagLabel */
      },
      {
        {{0xffffffff, 0xffffffff},}, /* mask bits for matching */
        1,
        0,
      },
      {
        0, 0, 0, 0
      },
      {
        0, 0, 0, 0
      }
    },
  };
  (void) CfyE_MTT_Entries_CloudSec_Egress;
  return 0;
}