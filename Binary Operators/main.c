#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f_operate(char op[],int a,int b)
{




    if(strcmp(op,"XOR")==0)
    {
        printf("Operation is XOR\n");
        return a^b;

    }
    else if (strcmp(op,"AND")==0)
    {
        return a&b;
    }
    else if (strcmp(op,"OR")==0)
    {
        return a|b;
    }


}



int main()
{
    char operate[3];
    scanf("%s",operate);

    int x= f_operate(operate,3,4);
    printf("%d",x);
}
