

#include <stdio.h>



int main(int argc, const char **argv)
{
  char ch, input[] =
    "version 2.0; \
         interface port<PortNo> { \
         macsec-validate strict; \
         macsec-protect true; \
         confidentiality-offset 0; # enable confidentiality \
         always-include-sci true; # SCI is included in the packet \
         default-network { \
         use-eap never; # no EAP => PSK CAK \
         } \
         preshared-key 00112233445566778899aabbccddeeff { \
         value ffeeddccbbaa99887766554433221100; \
         type group; \
         } \
         port-no <PortNo>; \
         secy-mac-address 00:00:00:00:<PortNo>:20; \
         }";
  FILE *fp = fopen("client.data.txt", "rw");
  fwrite(input, sizeof(char), sizeof(input) - 1, fp);
  //fclose(fp);
  //FILE *fp = fopen("client.data.txt", "wb");
  puts("\n");
  
  while ((ch = fgetc(fp)) != EOF)
  {
    printf("%c", ch);
  }
  
  fclose(fp);
  return 0;
}