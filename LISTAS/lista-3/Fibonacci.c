#include <stdio.h>

long int fibmem[1001] = {[0 ... 1000] = -1};

long int fibonacci(long x)
{
    fibmem[1] = 1;
    fibmem[2] = 1;
    if(fibmem[x] != -1)
    {
        return fibmem[x];
    }
    fibmem[x] = fibonacci(x-1) + fibonacci(x-2);
    return fibmem[x];
}

int main()
{
    printf("%ld\n", fibonacci(80));
    
}