#include <stdio.h>

int main()
{
    int num = 0;
    printf("Enter a number between 1 - 10: ");
    scanf("%d", &num);
    if(num > 0 && num <= 10)
    {
        printf("Input accepted!\n");
    }
    else
    {
        printf("Error: number must be between 1 - 10.\n");
        return 1;
    }

    return 0;
}
