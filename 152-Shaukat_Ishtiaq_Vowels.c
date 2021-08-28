#include <stdio.h>
#include <string.h>
int main() {
    int counter = 0;
    char str[100];
    char newStr[100];
    gets(str);
    int length = strlen(str);

    for(int i=0;i<length;i++) {
        if(str[i]== 'A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') {
            continue;
        }
        else {
            newStr[counter] = str[i];
            counter++;
        }
    }
    newStr[counter] = '\0';
    puts(newStr);

    return 0;
}
