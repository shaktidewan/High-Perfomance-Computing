#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <time.h>
#include <pthread.h>

int noOfPasswords = 1;

char *encryptedPasswords[] = {

"$6$AS$3geXjAVSaQZLWLz2NUF.JwY0GsFB6JHaXukmrX9z2Q08jy5RdJtvMyI0rVdCyf56qCfRH7h/fB4KAptcOPJm01"
};


void substr(char *dest, char *src, int start, int length){
  memcpy(dest, src + start, length);
  *(dest + length) = '\0';
}


void crackwithThread()
{
  int a;
pthread_t th1, th2;

    void *kernel_function_1();
    void *kernel_function_2();
for(a=0;a<noOfPasswords;a<a++) {
   
    
    pthread_create(&th1, NULL,kernel_function_1, encryptedPasswords[a]);
    pthread_create(&th2, NULL,kernel_function_2, encryptedPasswords[a]);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
 }
}

void *kernel_function_1(char *salt_and_encrypted){
  int s, a, n;     // Loop counters
  char salt[7];    // String used in hahttps://www.youtube.com/watch?v=L8yJjIGleMwshing the password. Need space
  char plain[7];   // The combination of letters currently being checked
  char *enc;       // Pointer to the encrypted password
  int count = 0;   // The number of combinations explored so far

  substr(salt, salt_and_encrypted, 0, 6);

  for(s='A'; s<='M'; s++){
    for(a='A'; a<='Z'; a++){
      for(n=0; n<=99; n++){
        /*sprintf(plain, "%c%c%02d", s,a,n);*/
        enc = (char *) crypt(plain, salt);
        count++;
        /*if(strcmp(salt_and_encrypted, enc) == 0){
          printf("#%-8d%s %s\n", count, plain, enc);
        }  else {
          printf(" %-8d%s %s\n", count, plain, enc);
        }*/
      }
    }
  }
  printf("%d solutions explored\n", count);
}


void *kernel_function_2(char *salt_and_encrypted){
  int x, y, z;     // Loop counters
  char salt[7];    // String used in hahttps://www.youtube.com/watch?v=L8yJjIGleMwshing the password. Need space
  char plain[7];   // The combination of letters currently being checked
  char *enc;       // Pointer to the encrypted password
  int count = 0;   // The number of combinations explored so far

  substr(salt, salt_and_encrypted, 0, 6);

  for(x='N'; x<='Z'; x++){
    for(y='A'; y<='Z'; y++){
      for(z=0; z<=99; z++){
        /*sprintf(plain, "%c%c%02d", x,y,z);*/
        enc = (char *) crypt(plain, salt);
        count++;
        /*if(strcmp(salt_and_encrypted, enc) == 0){
          printf("#%-8d%s %s\n", count, plain, enc);
        } else {
          printf(" %-8d%s %s\n", count, plain, enc);
        }*/
      }
    }
  }
  printf("%d solutions explored\n", count);
}


int time_difference(struct timespec *start, struct timespec *finish, long long int *difference)
 {
	  long long int ds =  finish->tv_sec - start->tv_sec; 
	  long long int dn =  finish->tv_nsec - start->tv_nsec; 

	  if(dn < 0 ) {
	    ds--;
	    dn += 1000000000; 
  } 
	  *difference = ds * 1000000000 + dn;
	  return !(*difference > 0);
}
int main(int argc, char *argv[])
{
  	
	struct timespec start, finish;   
  	long long int time_elapsed;

  	clock_gettime(CLOCK_MONOTONIC, &start);

  	
	
    		crackwithThread();
  	
	clock_gettime(CLOCK_MONOTONIC, &finish);
	  time_difference(&start, &finish, &time_elapsed);
	  printf("Time elapsed was %lldns or %0.9lfs\n", time_elapsed,
		                                 (time_elapsed/1.0e9)); 
  return 0;
}

