#include <stdio.h>


int main(){

int num;
   scanf("%d",&num);
   int a = 0;
   int b = 0;
   int countBit = 0;//used to see how many 1 bits have been found and then further decides


   int i;
   for(i = 0; i < 31; i++) {
       if(num & (1<<i)) {
           if(countBit%2==0){
           		a|=(1<<i);
           }
           else{
           		b|=(1<<i);
           }
           countBit++;
       }
   }
   printf("%d %d\n",a,b);
   return 0;
}
