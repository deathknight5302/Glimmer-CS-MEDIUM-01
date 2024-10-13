#include <stdio.h>
#include <string.h>
int main(){
    int lena=0,lenb=0;
    char a[128]={0},b[128]={0},c[128]={0};
    scanf("%s",&a);
    scanf("%s",&c);
    scanf("%s",&b);
    lena=strlen(a);
    lenb=strlen(b);
    for(int i=0;i<=lena-1;i++){
        if(a[i]=='('||a[i]==')'){
            continue;
        }
        printf("%c",a[i]);
    }
    printf("\n");
    for(int i=0;i<=lenb-1;i++){
        if(b[i]=='('||b[i]==')'){
            continue;
        }
        printf("%c",b[i]);
    }
    printf("\n");
    printf("%c",c[0]);
    return 0;
}