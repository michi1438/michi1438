#include <stdio.h>
void main(){char s[]={102,108,97,103,52,50,123,51,49,115,121,95,48,98,102,117,115,99,52,116,51,125,0};for(int i=0;s[i]!=0;i++){s[i]=s[i]^42;}printf("The hidden message is: %s\n",s);return;}
