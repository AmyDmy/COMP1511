#include <stdio.h>

/*int main(void)
{
    int a;
    printf("Enter integer:");
    scanf("%d", &a);
    int b;
    printf("Enter integer:");
    scanf("%d", &b);
    int c = a*(a>=b)+ b*(b>a);
    b = a*(a<=b)+b*(b<a);
    a=c ;
    printf("Enter integer:");
    scanf("%d", &c);
    b=b+c;

    c = (b-c)*(b-2*c>0)+c*(c+c-b>=0);
    b=b-c;
    a=a+c;
    c=(a-c)*(a-2*c>0)+c*(c+c-a>=0);
    a=a-c;*/

    
    /*int a ;
    printf("Enter integer:");
    scanf("%d", &a);
    
    printf("Enter integer:");
    scanf("%d", &b);
    int b;
    printf("Enter integer:");
    scanf("%d", &c);
    int c;*/

int main(void) {
    
    int first;
    printf("Enter integer:");
    scanf("%d", &first);
    int second;
    printf("Enter integer:");
    scanf("%d", &second);
    int third;
    printf("Enter integer:");
    scanf("%d", &third);
    int index = first||second||third;
    

    if (first >= second) {
        index = first;
        first = second;
        second = index;
    }      
    if (first >= third ) {
        index = first;
        first = third;
        third = index;
    }    
    if (second >= third) {
        index = second;
        second = third;
        third = index;
    }   
    printf("The integers in order are:%d %d %d\n", first, second, third);
    return 0;
}
    

    /*int x = a*(a>b && a>c) + b*(b>a && b>c) +c*(c>a && c>b);
    int y = a*(a<b && a<c) + b*(b<a && b<c) +c*(c<a && c<b);
    int z = a+b+c-x-y;

    printf("%d %d %d",a,b,c);

    return 0;    
}*/