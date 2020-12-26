#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <unistd.h>
/******************************************************************************
  This program is used to set challenges for password cracking programs. 
  Encrypts using SHA-512.
  
  Compile with:
    cc -o EncryptSHA512 EncryptSHA512.c -lcrypt
    
  To encrypt the password "pass":
    ./EncryptSHA512 pass
    
  It doesn't do any checking, just does the job or fails ungracefully.

  Dr Kevan Buckley, University of Wolverhampton, 2017. Modified by Dr. Ali Safaa 2019
  SD12 = $6$AS$Qjk9EnDYBg6b8cNMbXtgJIzD36VUeaTYt0kyUrUVR1.BNTBa1kCbySoXDdkQUuijYCGKTcSKQBzBYei7HrLcE.
  SD13 = $6$AS$26YFI9p8AycZ/NAyYglYgqYaJO6w2jOQNAVCJrGQfZmh//5GQHs7Uw.B9d3PVAgjndnxlfRizskmCr5qqzycE/
  SD14 = $6$AS$jxQxboOeX.D0B4hh7wytcw1YS7x/EKETufL6L1z.tOsvaICLSF9C5weOsXYCRyjS2gyRCflY2Vw.U1PvK/Jwa.
  SD15 = $6$AS$NRkpxMLVR4wnnqv..GLho7HL.fqRnQVkdSRJX3lvx/GBmcbgf5gJkjZN6JqSYtO5W00hOdRhaFusjTnNaqAqL0

  
******************************************************************************/

#define SALT "$6$AS$"

int main(int argc, char *argv[]){
  
  printf("%s\n", crypt(argv[1], SALT));

  return 0;
}
