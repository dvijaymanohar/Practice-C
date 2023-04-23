/*
 * bitmap.h
 * Vijay Manohar .D
 * 15 Nov 2007
 */

#ifndef __BITMAP_H__
#define __BITMAP_H__


/**** BMP file header structure ****/
#pragma pack(1)

typedef struct
{
  unsigned short bfType;           /* Magic number for file */
  unsigned int   bfSize;           /* Size of file */
  unsigned short bfReserved1;      /* Reserved */
  unsigned short bfReserved2;      /* ... */
  unsigned int   bfOffBits;        /* Offset to bitmap data */
} BITMAPFILEHEADER;


/**** BMP file info structure ****/
#pragma pack(2)
typedef struct
{
  unsigned int   biSize;           /* Size of info header */
  int            biWidth;          /* Width of image */
  int            biHeight;         /* Height of image */
  unsigned short biPlanes;         /* Number of color planes */
  unsigned short biBitCount;       /* Number of bits per pixel */
  unsigned int   biCompression;    /* Type of compression to use */
  unsigned int   biSizeImage;      /* Size of image data */
  int            biXPelsPerMeter;  /* X pixels per meter */
  int            biYPelsPerMeter;  /* Y pixels per meter */
  unsigned int   biClrUsed;        /* Number of colors used */
  unsigned int   biClrImportant;   /* Number of important colors */
} BITMAPINFOHEADER;

/*
 * Constants for the biCompression field...
 */

#define BI_RGB       0             /* No compression - straight BGR data */
#define BI_RLE8      1             /* 8-bit run-length compression */
#define BI_RLE4      2             /* 4-bit run-length compression */
#define BI_BITFIELDS 3             /* RGB bitmap with RGB masks */



/**** Colormap entry structure ****/

typedef struct
{
  unsigned char  rgbBlue;          /* Blue value */
  unsigned char  rgbGreen;         /* Green value */
  unsigned char  rgbRed;           /* Red value */
  unsigned char  rgbReserved;      /* Reserved */
} RGBQUAD;


/**** Bitmap information structure ****/
typedef struct                        /**** Bitmap information structure ****/
{
  BITMAPINFOHEADER bmiHeader;      /* Image header */
  RGBQUAD          bmiColors[256]; /* Image colormap */
} BITMAPINFO;

#define DEBUG 1
#define SIZELCD 1024    /*   128 x 64 1 bit monochrome images contains 1024 bytes for image data  */
#define SIZEBMP 1086    /*  sizeof [file header + info header + palette table + image data] */
typedef unsigned char byte;

void convert_1bpp(void) ;
byte comp_byte(int k, int j, byte mask, int s);

#endif
