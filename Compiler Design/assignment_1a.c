#include<stdio.h>

//Check if number of 1s divisible by 2 and number of 3 divisible by 3
int func1(char s[], int n) {

    int count_0=0, count_1=0;

    for(int i=0; i<n; i++) {
        if(s[i] == '0')
            count_0++;
        else if(s[i] == '1')
            count_1++;
    }

    if(count_0%2 == 0 && count_1%3 == 0)
        return 1;
    return 0;
}

//Check if string contains substring '101' or '000'
int func2(char s[], int n, char sub[]) {
    if(n < 3)
        return 0;

    int i=0, j=0;
    while(i < n) {
        if(s[i] == sub[0]) {
            j=0;
            while(i < n) {
                if(s[i] != sub[j])
                    break;
                j++;
                i++;

                if(j == 3)
                    return 1;
            }
        }
        else
            i++;
    }

    return 0;
}

int main() {
    char str[] = "111101";
    int n = sizeof(str)/sizeof(char);

    if(func2(str, n, "101"))
        printf("True\n");
    else
        printf("False\n");

    if(func1(str, n))
        printf("True\n");
    else
        printf("False\n");
}