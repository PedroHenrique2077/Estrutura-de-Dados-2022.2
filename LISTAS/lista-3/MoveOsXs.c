#include <stdio.h>
#include <string.h>

void moveX(char *p)
{
    if(p[0] == '\0')
    {
        return;
    }

    if(p[0] != 'x')
    {
        printf("%c", p[0]);
        moveX(p+1);
    }

    if(p[0] == 'x')
    {
        moveX(p+1);
        printf("%c", p[0]);
    }
}

int main()
{
    char entrada[101];
    scanf("%s", entrada);
    
    moveX(&entrada);

    return 0;
}