#include <stdio.h> //fuer
printf()
#include <string.h>
    int main(int argc, char *argv[])
{
    char str1a[] = "Der String %s hat
                   "
                   "keine Bedeutung";
    char str1b[] = "%s ersetzt %s";
    char str2a[] = "1";
    char str2b[] = "12";
    char str2c[] = "lang";
#if 0 // EinebeliebigeGanzzahl(bspw.4711, ‐0,3000000000)ineinenStringwandeln(ohneNutzungvonsprintf())
int i = 0;
int tempVar = var;
while (tempVar){
tempVar = tempVar/10;
    i++;
    //printf("\nConcatenated string: %i", i);
}
//printf("\nConcatenated string: %i", i);
tempVar = var;
char newString[i+1];
newString[i]=0;
int t =i-1;
for(int j= 0;j<i;j++){

   int k= tempVar%10;
    tempVar/=10;
     printf("\n %i", k);

   newString[t]='0'+k;
   
   printf("\nConcatenated string: %s", newString);
    t--;
}
#endif

#if 0 // EinebeliebigeGanzzahlineinen String wandeln(aufBasisvonsprintf())

int strInt =0;

int i=0, j=strlen(str4)-1,k=1;



for(i;i<strlen(str4);i++){
    int temp =str4[j]  - '0';

    printf("\nintval: %i", temp);
    strInt = strInt +(temp*k);

    k=k*10;
   
    j--;
    
  
}
}