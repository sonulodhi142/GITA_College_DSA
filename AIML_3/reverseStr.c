#include<stdio.h>
#include<string.h>
#define max 10

void Reverse(char str[]){
    int size = strlen(str), i;
    for(i = 0; i<size/2; i++){
        char temp = str[i];
        str[i] = str[size-1-i];
        str[size-1-i] = temp;
    }
}
int main(){
    char str[max];
    printf("Enter string : ");
    scanf("%s", str);
    printf("str = %s\n", str);
    Reverse(str);
    printf("reverse = %s", str);
}