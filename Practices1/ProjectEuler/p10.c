#include<stdio.h>
#include<stdbool.h>
bool isPrime(int num) {
    if(num > 1) {
        for(int i = 2; i < num; i++) {
            if(num % i == 0)
                return false;
        }
        return true;
    }
    else return false;
}
int main(void) {
    int total = 0;
    for(int i=0; i < 2000000; i++) {
        if(isPrime(i) == true)
            total += i;
    }
    printf("%d\n", total);
}