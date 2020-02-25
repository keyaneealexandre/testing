#include <stdio.h>

/*
 * This program reads a value of n and produces two values a and b
 * splitting a binary number n into two numbers a, b
 * Author: Keyanee Alexandre
 *
 */


int main(){

int num;
   scanf("%d",&num);
   int a = 0;
   int b = 0;
   int countBit = 0;//used to see how many 1s have been found and then further decides


   int i;
   for(i = 0; i < 31; i++) {
       if(num & (1<<i)) { //n&(1<<i) produces a non zero number when the ith bit of the number n is set else it will produce 0.
           if(countBit%2==0){//
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
