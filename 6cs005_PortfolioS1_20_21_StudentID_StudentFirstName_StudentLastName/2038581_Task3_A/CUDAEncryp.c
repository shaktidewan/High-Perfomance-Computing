#include <stdio.h>
#include <stdlib.h>
char *CudaCrypt(char *rawPassword)
{

  char *newPassword = (char *)malloc(sizeof(char) * 11);

  newPassword[0] = rawPassword[0] + 2;
  newPassword[1] = rawPassword[0] - 2;
  newPassword[2] = rawPassword[0] + 1;
  newPassword[3] = rawPassword[1] + 3;
  newPassword[4] = rawPassword[1] - 3;
  newPassword[5] = rawPassword[1] - 1;
  newPassword[6] = rawPassword[2] + 2;
  newPassword[7] = rawPassword[2] - 2;
  newPassword[8] = rawPassword[3] + 4;
  newPassword[9] = rawPassword[3] - 4;
  newPassword[10] = '\0';

  for (int i = 0; i < 10; i++)
  {
    if (i >= 0 && i < 6)
    { //checking all lower case letter limits
      if (newPassword[i] > 122)
      {
        newPassword[i] = (newPassword[i] - 122) + 97;
      }
      else if (newPassword[i] < 97)
      {
        newPassword[i] = (97 - newPassword[i]) + 97;
      }
    }
    else
    { //checking number section
      if (newPassword[i] > 57)
      {
        newPassword[i] = (newPassword[i] - 57) + 48;
      }
      else if (newPassword[i] < 48)
      {
        newPassword[i] = (48 - newPassword[i]) + 48;
      }
    }
  }
  return newPassword;
}

int main(int argc, char *argv[]){
  
  printf("%s\n", CudaCrypt(argv[1]));

  return 0;
}