
__sfr __at 0x80 PORT0;
void delay(void);
int main()
{
  PORT0 = 0xFF;
  
  while (1)
  {
    //if(PORT0 < 0xFF)
    //{
    delay();
    PORT0 = PORT0 << 1;
    delay();
    //}
  }
}
void delay(void)
{
  int i;
  
  for (i = 0; i < 30000; i++);
}
