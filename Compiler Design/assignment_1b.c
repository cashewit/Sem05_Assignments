#include<stdio.h>
#include<string.h>

//Check if string contains 'the' as substring
int func(char s[], int n) {
    char sub[] = "the";

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
    char str[10000];
    printf("Enter a string {a-z}: ");
    scanf("%s", str);

    int n = strlen(str);

    if(func(str, n))
        printf("True\n");
    else
        printf("False\n");

}