#include <stdio.h>
#include <string.h>
int main(){
    char a[128]={0};
    int lena=0;
    scanf("%s",a);
    lena=strlen(a);
    for(int i=0;i<=lena-1;i++){
        printf("%c",a[i]);
    }
    return 0;
}