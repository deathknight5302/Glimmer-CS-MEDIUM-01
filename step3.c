#include <stdio.h>
#include <string.h>
char a[128]={0},b[128]={0},a1[128]={0},b1[128]={0};
int lena=0,lenb=0,lenc=0,c[128]={0},flag=0,flag1=0,flag2=0,flag3=0,flag4=0,t1[128]={0};
void plus(){
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
}
void minute(){
    if(lenb>lena){//判断两个数的大小
        for(int i=0;i<=lenc-1;i++){
            t1[i]=a[i];
            a[i]=b[i];
            b[i]=t1[i];
            flag4=1;
        }
    }else if(lenb==lena){
        for(int i=lenc-1;i>=0;i--){
            if(b[i]>a[i]){
                t1[i]=a[i];
                a[i]=b[i];
                b[i]=t1[i];
                flag4=1;
            }
        }
    }
    for(int i=0;i<=lenc-1;i++){
        c[i]=a[i]-b[i];
        if(flag==1){
            c[i]--;
            flag=0;
        }
        if(c[i]<0){
            c[i]=c[i]+10;
            flag=1;
        }
    }
    if(flag1==1&&flag4==0){//判断是否为负数

        printf("-");
    }else if(flag1==0&&flag4==1){
        printf("-");
    }
    for(int i=lenc-1;i>=0;i--){
        if(c[i]==0&&flag3==0){
            continue;
        }
        flag3=1;
        printf("%d",c[i]);
    }

}
int main(){
    scanf("%s%s",a1,b1);
    if(a1[0]=='-'){
        flag1=1;
        for(int i=1;i<=strlen(a1)-1;i++){
            a[i-1]=a1[i];
        }
    }else{
        strcpy(a,a1);
    }
    if(b1[0]=='-'){
        flag2=1;
        for(int i=1;i<=strlen(b1)-1;i++){
            b[i-1]=b1[i];
        }
    }else{
        strcpy(b,b1);
    }
    lena=strlen(a);
    lenb=strlen(b);
    for(int i=0;i<=lena-1;i++){//将字符数组转化为数字数组
        a[i]=a[i]-'0';
    }
    for(int i=0;i<=lenb-1;i++){
        b[i]=b[i]-'0';
    }
    for(int i=0;i<lena/2;i++){//倒置数组，方便进退位
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
    if(flag1==0&&flag2==0){
        plus();
        for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
        }
    }else if(flag1==1&&flag2==1){
        plus();
        printf("-");
        for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
        }
    }else{
        minute();
    }
    return 0;
}