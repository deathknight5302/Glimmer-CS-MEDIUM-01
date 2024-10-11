#include <stdio.h>
#include <string.h>
int main(){
    char a[128]={0},b[128]={0};
    int lena=0,lenb=0,lenc=0,flag=0,c[128]={0};
    scanf("%s%s",a,b);
    lena=strlen(a);
    lenb=strlen(b);
    for(int i=0;i<=lena-1;i++){//将字符数组转化为数字数组
        a[i]=a[i]-'0';
    }
    for(int i=0;i<=lenb-1;i++){
        b[i]=b[i]-'0';
    }
    for(int i=0;i<lena/2;i++){//倒置数组，方便进位
        int t=a[i];
        a[i]=a[lena-1-i];
        a[lena-1-i]=t;
    }
    for(int i=0;i<lenb/2;i++){
        int t=b[i];
        b[i]=b[lenb-1-i];
        b[lenb-1-i]=t;
    }
    if(lena>lenb){
        lenc=lena;
    }else{
        lenc=lenb;
    }
    for(int i=0;i<=lenc-1;i++){
        c[i]=a[i]+b[i];
        if(flag==1){
            c[i]++;
            flag=0;
        }
        if(c[i]>9){
            c[i]=c[i]-10;
            flag=1;
        }
    }
    if(flag==1){
        lenc++;
        c[lenc-1]++;
    }
    for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
    }
    return 0;
}