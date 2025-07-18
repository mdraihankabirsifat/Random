#include<stdio.h>
int main(){
    float a, tax;
    printf ("Enter a number:");
    scanf ("%f", &a);

    if (a<0){
    printf ("Error");
    }

    else if (a<350000) {
    printf ("income tax:0");
    }
    
    else if (350000<a & a<450000) {
        tax= (a-350000)*5/100;
        printf ("income tax:%f", tax);
        }

    else if (450000<a & a<750000) {
        tax=5000+(a-450000)*10/100;
        printf ("income tax:%f", tax);
        }

    else if (750000<a & a<1150000) {
        tax=35000+(a-750000)*15/100;
        printf ("income tax:%f", tax);
        }
    else if (1150000<a & a<1650000) {
        tax=95000+(a-1150000)*20/100;
        printf ("income tax:%f", tax);
        }

    else if (1650000<a) {
        tax=195000+(a-1650000)*25/100;
        printf ("income tax:%f", tax);
        }

    return 0;
}
