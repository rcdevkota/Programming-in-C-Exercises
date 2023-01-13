#include <math.h>

// Gegeben sei folgendes Programm :

int func1(int a)
{
    a *= -2;
    return a;
}
  int main(void)
{
    int a = 2;
    a = (func1(a = 7), a > 0);
    printf("%d\n", a); //____1____________________
      int b = 7;
    b = (b && 2) << (b | 2);
    1 >> 111 printf("%d\n", b); //_____________14___________
      char *str1 = "hallo";
    char *str2 = "du"
                 "da";
    char *str3 = str1 + str2;
    printf("%p\n", str3); //________________________
     
}