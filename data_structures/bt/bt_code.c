
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define WORD  unsigned short
#define BYTE  unsigned char
#define u8    unsigned char
#define u16   unsigned short
#define u32   unsigned int

#ifndef TRUE
  #define TRUE  1
#endif

#ifndef FALSE
  #define FALSE 0
#endif

#ifndef FMR_BOOL
  #define FMR_BOOL    signed int  /** As defined by SDHB */
#endif

typedef struct
{
  u16 add_off;
  u8  mode;
  u8  length;
  u8  *data;
} T_HCI_INTEL_FMR_WRITE;

typedef struct
{
  u16 add_off;
  u8  mode;
  u8  length;
} T_HCI_INTEL_FMR_READ;

typedef struct
{
  u8 pow_en;  /* 0x0 - Disable Pow 0x1 - Enable Pow */
} T_HCI_INTEL_FMR_SET_POW;

typedef struct
{
  u8 aud_en;  /* 0x0 - Disable aud 0x1 - Enable aud */
} T_HCI_INTEL_FMR_SET_AUD;

typedef union
{
  T_HCI_INTEL_FMR_WRITE   fmr_hci_write_cmd;
  T_HCI_INTEL_FMR_READ    fmr_hci_read_cmd;
  T_HCI_INTEL_FMR_SET_POW fmr_hci_set_pow;
  T_HCI_INTEL_FMR_SET_AUD fmr_hci_set_aud;
} T_FMR_HCI_CMD_PARAMS;

typedef struct
{
  u16 opcode;        /* OCF (10 bit) and OGF (6 bit) */
} T_FMR_HCI_CMD_HDR_1;

typedef struct
{
  u8 param_tot_len;  /* VMD Todo: mem write; param tot length */
  T_FMR_HCI_CMD_PARAMS params;
} T_FMR_HCI_CMD_HDR_2;

/** Compact FMR HCI Command packet description */
typedef struct
{
  T_FMR_HCI_CMD_HDR_1 cmd_hdr1;
  T_FMR_HCI_CMD_HDR_2 cmd_hdr2;
} T_FMR_HCI_CMD;


#define FMR_HCI_CMD_HDR_1_LEN sizeof(T_FMR_HCI_CMD_HDR_1)
#define FMR_HCI_CMD_HDR_2_LEN sizeof(T_FMR_HCI_CMD_HDR_2)

#define FMR_HCI_WRITE_CMD_LEN 7
#define FMR_HCI_READ_CMD_LEN  7
#define FMR_HCI_SET_POW_CMD_LEN  4
#define FMR_HCI_SET_AUD_CMD_LEN  4
#define FMR_HCI_CONFIRM_IRQ_CMD_LEN  3

/* FMR Command packet length */

#define FMR_HCI_WRITE_CMD_TOT_PARAM_MIN_LEN 4
#define FMR_HCI_WRITE_CMD_TOT_PARAM_MAX_LEN 68

#define FMR_HCI_READ_CMD_TOT_PARAM_LEN      4
#define FMR_HCI_SET_POW_CMD_TOT_PARAM_LEN   1
#define FMR_HCI_SET_AUD_CMD_TOT_PARAM_LEN   1
#define FMR_HCI_CONFIRM_IRQ_CMD_TOT_PARAM_LEN   0

#define FMR_HCI_CMD_HDR1_OP_POS      1
#define FMR_HCI_CMD_HDR2_TOT_LEN_POS FMR_HCI_CMD_HDR1_OP_POS      + sizeof(u16)
#define FMR_HCI_CMD_HDR2_ADDR_POS    FMR_HCI_CMD_HDR2_TOT_LEN_POS + sizeof(u8)
#define FMR_HCI_CMD_HDR2_MODE_POS    FMR_HCI_CMD_HDR2_ADDR_POS    + sizeof(u16)
#define FMR_HCI_CMD_HDR2_LEN_POS     FMR_HCI_CMD_HDR2_MODE_POS    + sizeof(u8)

#define FMR_HCI_WRITE_CMD_DATA_POS   FMR_HCI_CMD_HDR2_LEN_POS     + sizeof(u8)

/* Mode Value defines */
#define FMR_HCI_ACCESS_MODE0 0x0  /* 08 bit read access */
#define FMR_HCI_ACCESS_MODE1 0x1  /* 16 bit read access */
#define FMR_HCI_ACCESS_MODE2 0x2  /* 32 bit read access */

/**
 * Packet types
 */
#define HCI_COMMAND_PKT   0x01
#define HCI_EVENT_PACKET  0x04

#define HCI_INTEL_FMR_WRITE                0xFC58  /* OGF: 0x3F, OCF: 0x0058 */
#define HCI_INTEL_FMR_READ                 0xFC59  /* OGF: 0X3F, OCF: 0x0059 */
#define HCI_INTEL_FMR_SET_POWER            0xFC5A  /* OGF: 0x3F, OCF: 0x005A */
#define HCI_INTEL_FMR_SET_AUDIO            0xFC5B  /* OGF: 0X3F, OCF: 0x005B */
#define HCI_INTEL_FMR_IRQ_CONFIRM          0xFC5C  /* OGF: 0x3F, OCF: 0x005C */

#define HCI_Intel_OTP_Burn_BT_Data            0xFC9C /* OGF: 3FH, OCF: 009C */
#define HCI_Intel_OTP_Write_BT_Base_Address   0xFC9D /* OGF: 3FH, OCF: 009D */
#define HCI_Intel_OTP_Read_Si_Production_Data 0xFC9E /* OGF: 3FH, OCF: 009E */
#define HCI_Intel_SW_RF_Kill                  0xFC3F /* OGF: 3FH, OCF: 003F */
#define HCI_Reset_CMD                         0x0C03

#define OGF_MASK            0xfc00                       // 6 bits
#define OCF_MASK            0x03ff                       // 10 bits  ~OGF_MASK
#define CMD2OGF(cmd)        ((cmd & OGF_MASK) >> 10)     // cmdommand to OGF
#define CMD2OCF(cmd)        (cmd & OCF_MASK)             // Command to OCF

#define BE2LE(val)        (val << 8) | (val >> 8 )
#define LSB_DATA(val)     (val & 0x00FF)
#define MSB_DATA(val)     ((val & 0xFF00) >> 8)

/* calculate combined ogf/ocf value */
#define OPCODE(ogf, ocf) (ocf | ogf << 10)

#if 0
#if DBG_ASSERTIONS == TRUE
#define ASSERT(X)                                                          \
  if(!(X))                                                                 \
  {                                                                        \
    printf("ERROR: Assertion failed! (%s : %s : %d)\n",
__FILE__, __FUNCTION__, __LINE__);
\
exit(0);
\
}                                                                        \
#else
#define ASSERT(X)
#endif
#endif

#define ASSERT(X)                                                          \
  if(!(X))                                                                 \
  {                                                                        \
    printf("ERROR: Assertion failed! (%s : %s : %d)\n", __FILE__, __FUNCTION__, __LINE__);                             \
    exit(0);                                                               \
  }                                                                        \


void print_hex_char(unsigned char n)
{
  if (n <= 0xF)
  {
    printf("0%X ", (unsigned char)n);
  }
  else
  {
    printf("%X ", (unsigned char)n);
  }
}

void data_to_send(unsigned short opcode)
{
  unsigned char n = LSB_DATA(opcode);
  print_hex_char(n);
  n = 0;
  n = MSB_DATA(opcode);
  print_hex_char(n);
}
void print_opcode_fields(unsigned short opcode)
{
  unsigned char n = 0;
  n = CMD2OCF(opcode);
  printf("OCF : ");
  print_hex_char(n);
  n = 0;
  n = (opcode >> 10);
  printf("OGF : ");
  print_hex_char(n);
  printf("\tData to send : ");
  data_to_send(opcode);
  printf("\n");
}

/*Store (little-endian) 16bits*/
FMR_BOOL store_le16(WORD value, BYTE *data, u32 offset)
{
  if (NULL == data)
  {
    return FALSE;
  }
  
  data[offset + 1] = (value & 0xff00) >> 8;
  data[offset]     = value & 0x00ff;
  return TRUE;
}

void fmr_hci_send_cmd(u8 *cmd_buff, u8 len)
{
  int i = 0;
  
  for (i = 0; i <= len ; i++)
  {
    print_hex_char(cmd_buff[i]);
  }
}


int fmr_hci_write_cmd_assembly(u8 *cmd_buff, T_FMR_HCI_CMD fmr_hci_cmd, u8 plen)
{
  int index = 0;
  /* Validate the input arguments */
  ASSERT(cmd_buff != NULL);
  ASSERT(plen != 0);
  ASSERT(fmr_hci_cmd.cmd_hdr2.param_tot_len >= FMR_HCI_WRITE_CMD_TOT_PARAM_MIN_LEN);
  ASSERT(fmr_hci_cmd.cmd_hdr2.param_tot_len <= FMR_HCI_WRITE_CMD_TOT_PARAM_MAX_LEN);
  /* Store the command header 2, Parameter Total Len field */
  cmd_buff[FMR_HCI_CMD_HDR2_TOT_LEN_POS] = fmr_hci_cmd.cmd_hdr2.param_tot_len;
  /* Store the command header 2, Address field */
  store_le16(fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.add_off, cmd_buff, FMR_HCI_CMD_HDR2_ADDR_POS);
  /* Store the command header 2, Mode field */
  cmd_buff[FMR_HCI_CMD_HDR2_MODE_POS] = fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.mode;
  /* Store the command header 2, Length field */
  cmd_buff[FMR_HCI_CMD_HDR2_LEN_POS] = fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length;
  
  switch (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.mode)
  {
    case FMR_HCI_ACCESS_MODE0:
      {
        if (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length % 1)
        {
          printf("Invalid Length or mode\n");
          return -1;
        }
      }
      break;
      
    case FMR_HCI_ACCESS_MODE1:
      {
        if (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length % 2)
        {
          printf("Invalid Length or mode\n");
          return -1;
        }
      }
      break;
      
    case FMR_HCI_ACCESS_MODE2:
      {
        if (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length % 4)
        {
          printf("Invalid Length or mode\n");
          return -1;
        }
      }
      break;
      
    default:
      {
        printf("Invalid Mode\n");
        return -1;
      }
      break;
  }
  
  for (index = 0; index <= fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length; index++)
  {
    cmd_buff[FMR_HCI_WRITE_CMD_DATA_POS + index] = fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.data[index];
  }
  
  /* Write the command */
  fmr_hci_send_cmd(cmd_buff, FMR_HCI_WRITE_CMD_LEN + plen);
  return 0;
}

int fmr_hci_read_cmd_assembly(u8 *cmd_buff, T_FMR_HCI_CMD fmr_hci_cmd)
{
  /* Validate the input arguments */
  ASSERT(cmd_buff != NULL);
  ASSERT(fmr_hci_cmd.cmd_hdr2.param_tot_len == FMR_HCI_READ_CMD_TOT_PARAM_LEN);
  /* Store the command header 2, Parameter Total Len field */
  cmd_buff[FMR_HCI_CMD_HDR2_TOT_LEN_POS] = fmr_hci_cmd.cmd_hdr2.param_tot_len;
  /* Store the command header 2, Address field */
  store_le16(fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.add_off, cmd_buff, FMR_HCI_CMD_HDR2_ADDR_POS);
  /* Store the command header 2, Mode field */
  cmd_buff[FMR_HCI_CMD_HDR2_MODE_POS] = fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.mode;
  /* Store the command header 2, Length field */
  cmd_buff[FMR_HCI_CMD_HDR2_LEN_POS] = fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length;
  
  switch (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.mode)
  {
    case FMR_HCI_ACCESS_MODE0:
      {
        if (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length % 1)
        {
          printf("Invalid Length or mode\n");
          return -1;
        }
      }
      break;
      
    case FMR_HCI_ACCESS_MODE1:
      {
        if (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length % 2)
        {
          printf("Invalid Length or mode\n");
          return -1;
        }
      }
      break;
      
    case FMR_HCI_ACCESS_MODE2:
      {
        if (fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length % 4)
        {
          printf("Invalid Length or mode\n");
          return -1;
        }
      }
      break;
      
    default:
      {
        printf("Invalid Mode\n");
        return -1;
      }
      break;
  }
  
  /* Write the command */
  fmr_hci_send_cmd(cmd_buff, FMR_HCI_READ_CMD_LEN);
  return 0;
}

int fmr_hci_set_pow_cmd_assembly(u8 *cmd_buff, T_FMR_HCI_CMD fmr_hci_cmd)
{
  /* Validate the input arguments */
  ASSERT(NULL != cmd_buff);
  ASSERT(FMR_HCI_SET_POW_CMD_TOT_PARAM_LEN == fmr_hci_cmd.cmd_hdr2.param_tot_len);
  /* Store the command header 2, Parameter Total Len field */
  cmd_buff[FMR_HCI_CMD_HDR2_TOT_LEN_POS] = fmr_hci_cmd.cmd_hdr2.param_tot_len;
  /* Store the command header 2, Pow enable/disable */
  cmd_buff[FMR_HCI_CMD_HDR2_ADDR_POS] = fmr_hci_cmd.cmd_hdr2.params.fmr_hci_set_pow.pow_en;
  /* Write the command */
  fmr_hci_send_cmd(cmd_buff, FMR_HCI_SET_POW_CMD_LEN);
  return 0;
}

int fmr_hci_set_aud_cmd_assembly(u8 *cmd_buff, T_FMR_HCI_CMD fmr_hci_cmd)
{
  /* Validate the input arguments */
  ASSERT(NULL != cmd_buff);
  ASSERT(FMR_HCI_SET_AUD_CMD_TOT_PARAM_LEN == fmr_hci_cmd.cmd_hdr2.param_tot_len);
  /* Store the command header 2, Parameter Total Len field */
  cmd_buff[FMR_HCI_CMD_HDR2_TOT_LEN_POS] = fmr_hci_cmd.cmd_hdr2.param_tot_len;
  /* Store the command header 2, Pow enable/disable */
  cmd_buff[FMR_HCI_CMD_HDR2_ADDR_POS] =
    fmr_hci_cmd.cmd_hdr2.params.fmr_hci_set_aud.aud_en;
  /* Write the command */
  fmr_hci_send_cmd(cmd_buff, FMR_HCI_SET_AUD_CMD_LEN);
  return 0;
}

int fmr_hci_confirm_irq_cmd_assembly(u8 *cmd_buff, T_FMR_HCI_CMD fmr_hci_cmd)
{
  /* Validate the input arguments */
  ASSERT(NULL != cmd_buff);
  ASSERT(FMR_HCI_CONFIRM_IRQ_CMD_TOT_PARAM_LEN == fmr_hci_cmd.cmd_hdr2.param_tot_len);
  /* Store the command header 2, Parameter Total Len field */
  cmd_buff[FMR_HCI_CMD_HDR2_TOT_LEN_POS] = fmr_hci_cmd.cmd_hdr2.param_tot_len;
  /* Write the command */
  fmr_hci_send_cmd(cmd_buff, FMR_HCI_CONFIRM_IRQ_CMD_LEN);
  return 0;
}

int fmr_hci_cmd_assembly(T_FMR_HCI_CMD fmr_hci_cmd, u8 plen)
{
  u8 *cmd_buff = NULL;
  u8 res = 0;
  cmd_buff = (u8 *) malloc(FMR_HCI_WRITE_CMD_LEN + plen);
  /* Store the packet type */
  cmd_buff[0] = HCI_COMMAND_PKT;
  /* Store the command header 1 */
  store_le16(fmr_hci_cmd.cmd_hdr1.opcode, cmd_buff, FMR_HCI_CMD_HDR1_OP_POS);
  
  switch (fmr_hci_cmd.cmd_hdr1.opcode)
  {
    case HCI_INTEL_FMR_WRITE:
      {
        res = fmr_hci_write_cmd_assembly(cmd_buff, fmr_hci_cmd, plen);
      }
      break;
      
    case HCI_INTEL_FMR_READ:
      {
        res = fmr_hci_read_cmd_assembly(cmd_buff, fmr_hci_cmd);
      }
      break;
      
    case HCI_INTEL_FMR_SET_POWER:
      {
        res = fmr_hci_set_pow_cmd_assembly(cmd_buff, fmr_hci_cmd);
      }
      break;
      
    case HCI_INTEL_FMR_SET_AUDIO:
      {
        res = fmr_hci_set_aud_cmd_assembly(cmd_buff, fmr_hci_cmd);
      }
      break;
      
    case HCI_INTEL_FMR_IRQ_CONFIRM:
      {
        res = fmr_hci_confirm_irq_cmd_assembly(cmd_buff, fmr_hci_cmd);
      }
      break;
      
    default:
      {
        res = -1;
        printf("\n Recieved Cmd: 0x%X\n", fmr_hci_cmd.cmd_hdr1.opcode);
      }
      break;
  }
  
  free(cmd_buff);
  cmd_buff = NULL;
  return res;
}


int main(int argc, char *argv[])
{
#if 0 /* Opcode from OCF and OGF */
  int ogf = 0, ocf = 0;
  
  if (3 != argc)
  {
    printf("Prg usage : bt_code.exe ocf ogf\n");
    return -1;
  }
  
  ocf = strtoul(argv[1], NULL, 16);
  ogf = strtoul(argv[2], NULL, 16);
  printf("ocf : 0x%x\n", ocf);
  printf("ogf : 0x%x\n", ogf);
  printf("OpCode : 0x%x\n", (ocf | (ogf << 10)));
#endif
#if 0 /* OCF and OGF from Opcode */
  print_opcode_fields((unsigned short) HCI_INTEL_FMR_WRITE);
  print_opcode_fields((unsigned short) HCI_INTEL_FMR_READ);
  print_opcode_fields((unsigned short) HCI_INTEL_FMR_SET_POWER);
  print_opcode_fields((unsigned short) HCI_INTEL_FMR_SET_AUDIO);
  print_opcode_fields((unsigned short) HCI_INTEL_FMR_IRQ_CONFIRM);
  print_opcode_fields((unsigned short) HCI_Intel_OTP_Burn_BT_Data);
  print_opcode_fields((unsigned short) HCI_Intel_OTP_Write_BT_Base_Address);
  print_opcode_fields((unsigned short) HCI_Intel_OTP_Read_Si_Production_Data);
  print_opcode_fields((unsigned short) HCI_Intel_SW_RF_Kill);
#endif
#if 0 /* OCF and OGF from the given opcode */
  unsigned short opcode = 0;
  
  if (2 != argc)
  {
    printf("Prg usage : bt_code.exe <HCI Opcode>\n");
    return -1;
  }
  
  opcode = strtoul(argv[1], NULL, 16);
  printf("OCF : 0x0%X\n", (unsigned char)(CMD2OCF(opcode)));
  printf("OGF : 0x0%X\n", (unsigned char)(CMD2OGF(opcode)));
  printf("Opcode : 0x0%X\n", opcode);
  //printf("BE2LE Data: 0x%X\n", (unsigned short)BE2LE(opcode));
  printf("Data to send : 0%X 0%X\n", (unsigned char)LSB_DATA(opcode),
         (unsigned char)MSB_DATA(opcode));
#endif
#if 0 /* Opcode from OCF and OGF and verification*/
  unsigned char ogf = 0, ocf = 0;
  unsigned long opcode = 0;
  unsigned char n = 0;
  
  if (3 != argc)
  {
    printf("Prg usage : bt_code.exe ogf ocf\n");
    return -1;
  }
  
  ogf = strtoul(argv[1], NULL, 16);
  ocf = strtoul(argv[2], NULL, 16);
  print_hex_char(ocf);
  print_hex_char(ogf);
  opcode = (((unsigned long) ogf << 10) | ocf);
  printf("OpCode : 0x%X\n", (unsigned short) opcode);
  ocf = (unsigned char)(CMD2OCF(opcode));
  ogf = (unsigned long) opcode >> 10;
  print_hex_char(ocf);
  print_hex_char(ogf);
  opcode = ((ogf << 10) | ocf);
  printf("OpCode : 0x%X\n", (unsigned short)(opcode));
  n = LSB_DATA(opcode);
  printf("Data to send :");
  print_hex_char(n);
  n = 0;
  n = MSB_DATA(opcode);
  print_hex_char(n);
#endif
#if 1 /* HCI Write Command */
  T_FMR_HCI_CMD fmr_hci_cmd;
  memset(&fmr_hci_cmd, 0, sizeof(T_FMR_HCI_CMD));
  u8 write_cmd_data[] = {0x8d, 0xfc, 0x06, 0xAA, 0xBB, 0xCC, 0xDD, 0x04};
  fmr_hci_cmd.cmd_hdr1.opcode = OPCODE(0x3F, 0x58);
  fmr_hci_cmd.cmd_hdr2.param_tot_len                    = 12;
  fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.add_off = 0x7ef0;
  fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.mode    = 0x2; /* 32 bit write access */
  fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.length  = 8;   /* no of bytes to write */
  fmr_hci_cmd.cmd_hdr2.params.fmr_hci_write_cmd.data    = write_cmd_data;
  fmr_hci_cmd_assembly(fmr_hci_cmd, 8);
#endif
#if 1 /* FMR HCI Read command */
  T_FMR_HCI_CMD fmr_hci_read_cmd;
  memset(&fmr_hci_read_cmd, 0, sizeof(T_FMR_HCI_CMD));
  fmr_hci_read_cmd.cmd_hdr1.opcode = OPCODE(0x3F, 0x59);
  fmr_hci_read_cmd.cmd_hdr2.param_tot_len                    = 4;
  fmr_hci_read_cmd.cmd_hdr2.params.fmr_hci_read_cmd.add_off  = 0x7ef0;
  fmr_hci_read_cmd.cmd_hdr2.params.fmr_hci_read_cmd.mode     = 0x2; /* 32 bit read access */
  fmr_hci_read_cmd.cmd_hdr2.params.fmr_hci_read_cmd.length   = 4;   /* no of bytes to read */
  putch('\n');
  fmr_hci_cmd_assembly(fmr_hci_read_cmd, 0);
#endif
#if 1 /* FMR HCI Set Power command */
  T_FMR_HCI_CMD fmr_hci_set_pow_cmd;
  memset(&fmr_hci_set_pow_cmd, 0, sizeof(T_FMR_HCI_CMD));
  fmr_hci_set_pow_cmd.cmd_hdr1.opcode = OPCODE(0x3F, 0x5A);
  fmr_hci_set_pow_cmd.cmd_hdr2.param_tot_len                    = 1;
  fmr_hci_set_pow_cmd.cmd_hdr2.params.fmr_hci_set_pow.pow_en    = 0x1; /* enable pow */
  putch('\n');
  fmr_hci_cmd_assembly(fmr_hci_set_pow_cmd, 0);
#endif
#if 1 /* FMR HCI Set Audio command */
  T_FMR_HCI_CMD fmr_hci_set_aud_cmd;
  memset(&fmr_hci_set_aud_cmd, 0, sizeof(T_FMR_HCI_CMD));
  fmr_hci_set_aud_cmd.cmd_hdr1.opcode = OPCODE(0x3F, 0x5B);
  fmr_hci_set_aud_cmd.cmd_hdr2.param_tot_len                    = 1;
  fmr_hci_set_aud_cmd.cmd_hdr2.params.fmr_hci_set_aud.aud_en    = 0x1; /* enable aud */
  putch('\n');
  fmr_hci_cmd_assembly(fmr_hci_set_aud_cmd, 0);
#endif
#if 1 /* FMR HCI Confirm IRQ */
  T_FMR_HCI_CMD fmr_hci_confirm_irq;
  memset(&fmr_hci_confirm_irq, 0, sizeof(T_FMR_HCI_CMD));
  fmr_hci_confirm_irq.cmd_hdr1.opcode = OPCODE(0x3F, 0x5C);
  fmr_hci_confirm_irq.cmd_hdr2.param_tot_len = 0;
  putch('\n');
  fmr_hci_cmd_assembly(fmr_hci_confirm_irq, 0);
#endif
  return 0;
}

u8 *cmd_buff = NULL;
u8 res = 0;


