/***************************************************************************
 bmp2lcd: BMP coded graphic file to 128X64 LCD module C source converter.

 Vijay Manohar Dogiparthi
 email2vmd@yahoo.com

      **********************
Description:
   bmp2lcd converts from a 1bpp BMP coded image into a C source code
   composed of an array,describing the data on the LCD screen

   If you find any bug or you have some suggestions, feel free to
   write me at the email address specified above.
      **********************
***************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

byte arrayBMP[SIZELCD], arrayLCD[SIZELCD], arrayRotated[SIZELCD];

int main(int argc, char *argv[])
{
  BITMAPFILEHEADER file_header;
  BITMAPINFOHEADER info_header;
  FILE *fin, *fout;
  int i;
  //  char flag_silent = 0;
  
  if (argc < 2)
  {
    perror("\nbitmap <bmp image name> <output filename>");
    return -1;
  }
  
  if (argc < 3) { printf("\nOutput file containing bitmap data is default to the file: bmpdata.c"); }
  
  if ((fin = fopen(argv[1], "rb")) == NULL)
  {
    printf("\nUnable to open the file: %s", argv[1]);
    return -1;
  }
  
  if ((fread(&file_header, sizeof(file_header), 1, fin)) < 0)
  {
    printf("\nCouldn't read the file header.........exitintg");
    fclose(fin);
    return -1;
  }
  
  //  printf ("\n\tMake sure that, U are operating an 128 x 64 Monochrome with bit depth 1\n");
  printf("\nFile Statistics:\n");
  
  if (file_header.bfType != 'MB')
  {
    printf("\n\tInvalid Fileformat. This program cannot deal with the given file\n");
    fclose(fin);
    return -1;
  }
  else { printf("\n\tFile type: Bitmap File"); }
  
  printf("\n\tSize of bitmap file, U are working : %u kb", file_header.bfSize / 1024);
  
  if (file_header.bfSize != SIZEBMP)
  {
    printf("\nA monochrome 1 bit per pixel image should has size : %d, But the file : %s has size %d bytes, So ......exiting", SIZEBMP, argv[1], file_header.bfSize);
    printf("\nSo the output so obtained may not be the correct LCD data");
  }
  
  printf("\n\tOffset to bitmap data in the file: %u bytes", file_header.bfOffBits);
  
  if ((fread(&info_header, sizeof(info_header), 1, fin)) < 0)
  {
    printf("\n\tCouldn't read the file header.........exiting");
    fclose(fin);
    return -1;
  }
  
  printf("\n\n\nFields of Inf0_header:\n\n\tSize of Info Header: %u", info_header.biSize);
  printf("\n\tWidth of the Image                  : %d pixels", info_header.biWidth);
  printf("\n\tHeight of the Image                 : %d pixels", info_header.biHeight);
  printf("\n\tNo-of Color Planes or Frame Count    : %d", info_header.biPlanes);
  printf("\n\tCompresion Type                     : %u", info_header.biCompression);
  printf("\n\tSize of Image Data                  : %u", info_header.biSizeImage);
  printf("\n\tNo-of Colors Used                   : %u", info_header.biClrUsed);
  printf("\n\tNo-of Important Colors              : %u", info_header.biClrImportant);
  printf("\n\tNo-of Bits per pixel	             : %u", info_header.biBitCount);
  printf("\n\tHorizontal Resolution               : %ld dpi", (long)(info_header.biXPelsPerMeter * 2.54) / 100);
  printf("\n\tVertical Resolution                 : %ld dpi", (long)(info_header.biYPelsPerMeter * 2.54) / 100);
  /*
   *Formula:
   *  Inches * DPI[Dots per Sq inch] = Pixels
   *  1 inch = 2.54 * (.01) meters
   */
  printf("\n\n\tSize of the palette table	: %d bytes\n", file_header.bfOffBits \
         - (sizeof(file_header) + sizeof(info_header)));
         
  if (DEBUG) { printf("\n\tPosition of file pointer: %ld", ftell(fin)); }
  
  fseek(fin, file_header.bfOffBits, SEEK_SET);
  
  if (DEBUG) { printf("\n\tPosition of file pointer: %ld\n", ftell(fin)); }
  
#if 0
  
  if ((bit_size = info_header.biSizeImage) == 0)
  {
    bit_size = info_header.biWidth * ((info_header.biBitCount + 7) / 8) * abs(info_header.biHeight);
  }
  
#endif
  printf("\n\tNo of Bitmap pixels: %d\t No. of Bytes need to send to lcd: %d\n", 128 * 16, (128 / 8) * 64);
  
  if (DEBUG) { printf("\n\tPosition of file pointer: %ld\n", ftell(fin)); }
  
  if (fread(arrayBMP, sizeof(unsigned char), SIZELCD, fin) !=  SIZELCD)
  {
    fprintf(stderr, "\n\tError reading the image data from the file : %s", argv[1]);
    return -1;
  }
  
#if 0
  
  for (i = 0; argv[i] != NULL; i++)
  {
    if (strcpy("-s", argv[i])) { flag_silent = 1; }
  }
  
#endif
  
  //  if (flag_silent == 1) {
  for (i = 0; i < SIZEBMP; i++)
  {
    if (i % 10 == 0) { putchar('\n'); }
    
    printf("0x%x,\t", (byte) arrayBMP[i]);
  }
  
  //  }
  
  //  If everything went good, then start,creating a bitmap array file to be displayed on the LCD
  if (argc == 3)
  {
    if ((fout = fopen(argv[2], "wb")) == NULL)
    {
      perror("\n\tUnable to open the specified file\n");
      fclose(fin);
      return -1;
    }
  }
  else
  {
    if ((fout = fopen("bmpdata.c", "wb")) == NULL)
    {
      perror("\n\tUnable to open the specified file\n");
      fclose(fin);
      return -1;
    }
  }
  
  /*  Now convert the data in arrayBMP to arrayLCD  */
  convert_1bpp();
  fprintf(fout, "/*\n* Description:\n* \tAutomagically generated with bmp2lcd Ver 1.0\n* \tThis produces an array of bytes representing a bitmap on LCD");
  fprintf(fout, "\n*\n* Author: By Vijay Manohar Dogiparthi (email2vmd@yahoo.com), 2007\n*/\n\n\n");
  fprintf(fout, "const unsigned char arrayLCD[] = {");
#if 0
  
  /*  arrayLCD contains the data corresponds to optrex sed 1335 controller  */
  if (fwrite(arrayLCD, 1, SIZELCD, fout) != SIZELCD)
  {
    fprintf(stderr, "Error writing to file.");
    fclose(fin);
    fclose(fout);
    return -1;
  }
  
#endif
  
  for (i = 0; i < SIZELCD; i++)
  {
    if (i % 8 == 0) { fputc('\n', fout); }
    
    fprintf(fout, "\t0x%x,\t", arrayLCD[i]);
  }
  
  fprintf(fout, "\n};");
  fclose(fin);
  fclose(fout);
  return 0;
}

void convert_1bpp(void)
{
  int i, j, k, f;
  
  /* Re-order the bmp and set the correct black value */
  for (i = 0; i < SIZELCD; i += 16)
    for (j = 0; j < 16; j++) { arrayRotated[i + j] = ~arrayBMP[SIZEBMP - i - 16 + j]; }
    
  /* Now ( ugly ) set the params for the comp_byte and call it 128 times */
  k = j = 0;
  
  for (i = 0; i < SIZELCD; i += 8)
  {
    for (f = 0; f < 8; f++) { arrayLCD[i + f] = comp_byte(k, j, (1 << 7) - f, f); }
    
    j++;
    
    if (j == 16)
    {
      k += 128;
      j = 0;
    }
  }
}

byte comp_byte(int k, int j, byte mask, int s)
{
  return ((((arrayRotated[k + j]    & mask) << s) >> 7)  |
          (((arrayRotated[k + j + 16] & mask) << s) >> 6)  |
          (((arrayRotated[k + j + 32] & mask) << s) >> 5)  |
          (((arrayRotated[k + j + 48] & mask) << s) >> 4)  |
          (((arrayRotated[k + j + 64] & mask) << s) >> 3)  |
          (((arrayRotated[k + j + 80] & mask) << s) >> 2)  |
          (((arrayRotated[k + j + 96] & mask) << s) >> 1)  |
          ((arrayRotated[k + j + 112] & mask) << s))  ;
}

