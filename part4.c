#include <stdio.h>
#include <string.h>
char a[128]={0},b[128]={0},a1[128]={0},b1[128]={0};
int lena=0,lenb=0,lenc=0,len=0,c[128]={0},flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,t1[128]={0},s[128]={0};
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
                flag4=1;
            }
        }
        if(flag4==1){
            for(int i=0;i<=lenc-1;i++){
                t1[i]=a[i];
                a[i]=b[i];
                b[i]=t1[i];
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
void multiply(){
    for(int i=0;i<=lenc-1;i++){
        for(int j=0;j<=lenc-1;j++){
            c[i+j]=c[i+j]+a[i]*b[j];
        }
    }
    for(int i=0;i<=lenc*2;i++){
        if(c[i]/10){
            c[i+1]=c[i+1]+c[i]/10;
            c[i]=c[i]%10;
        }
    }
    for(int i=lenc*2;i>=0;i--){
        if(c[i]==0&&flag3==0){
            continue;
        }
        flag3=1;
        printf("%d",c[i]);
    }
}
void divide(){
    if(lenb>lena){//判断两个数的大小
        for(int i=0;i<=lenc-1;i++){
            t1[i]=a[i];
            a[i]=b[i];
            b[i]=t1[i];
            len=lena;
            lena=lenb;
            lenb=len;
            flag4=1;
        }
    }else if(lenb==lena){
        for(int i=0;i>=lenc-1;i++){
            if(b[i]>a[i]){
                flag4=1;
                break;
            }
        }
        if(flag4==1){
            for(int i=0;i<=lenc-1;i++){
                t1[i]=a[i];
                a[i]=b[i];
                b[i]=t1[i];
                len=lena;
                lena=lenb;
                lenb=len;
            }
            
        }
    }
    int p1=0,x=0,lenn=0,o=0,p=0;
    lenn=lenb;
    while(lena>=lenn){
        while(1){
            flag5=0;
            for(int i=0;i<=lenn-lenb;i++){
                if(a[i]!=0){
                    x=i;
                    break;
                }
                x=i;
            }
            for(int i=x;i<=lenn-1;i++){
                if(a[i]>b[i]){
                    break;
                }else if(a[i]<b[i]){
                    flag5=1;
                    break;
                }
            }
            if(flag5==1){
                for(int i=lenn-1;i>=lenn-lenb;i--){
                    b[i+1]=b[i];
                }
                b[lenn-lenb]=0;
                lenn++;
                break;
            }
            for(int i=lenn-1;i>=lenn-lenb;i--){
                a[i]=a[i]-b[i];
                if(flag==1){
                    a[i]--;
                    flag=0;
                }
                if(a[i]<0){
                    a[i]=a[i]+10;
                    flag=1;
                }
            }
            if(flag==1){
                a[lenn-lenb-1]--;
                flag=0;
            }
            s[p1]++;
        }
        p1++;
    }
    for(int i=0;i<=p1;i++){
        if(s[i]!=0){
            o=i;
            break;
        }
    }
    for(int i=p1;i>=0;i--){
        if(s[i]!=0){
            p=i;
            break;
        }
    }
    for(int i=o;i<=p;i++){
        printf("%d",s[i]);
    }
}
int main(){
    int t=0,Flag=0;
    char n[128]={0};
    scanf("%s",&n);
    if(n[0]=='('){
        flag1=1;
        for(int i=2;i<=strlen(n)-1;i++){
            if(n[i]==')'){
                t=i+1;
                break;
            }
            a1[i-2]=n[i];
        }
    }else{
        for(int i=0;i<=strlen(n)-1;i++){
            if(n[i]<'0'||n[i]>'9'){
                t=i;
                break;
            }
            a1[i]=n[i];
        }
    }
    if(n[t]=='+'){
        Flag=1;
    }else if(n[t]=='-'){
        Flag=2;
    }else if(n[t]=='*'){
        Flag=3;
    }else if(n[t]=='/'){
        Flag=4;
    }
    if(n[t+1]=='('){
        flag2=1;
        for(int i=t+2;i<=strlen(n)-1;i++){
            if(n[i]==')'){
                t=i+1;
                break;
            }
            b1[i-t-2]=n[i];
        }
    }else{
        for(int i=t+1;i<=strlen(n)-1;i++){
            b1[i-t-1]=n[i];
        }
    }
    
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
    if(Flag==1&&flag1==0&&flag2==0){
        plus();
        for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
        }
    }else if(Flag==1&&flag1==1&&flag2==1){
        plus();
        printf("-");
        for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
        }
    }else if(Flag==1&&flag1==1&&flag2==0){
        minute();
    }else if(Flag==1&&flag1==0&&flag2==1){
        minute();
    }else if(Flag==2&&flag1==0&&flag2==0){
        minute();
    }else if(Flag==2&&flag1==1&&flag2==1){
        minute();
    }else if(Flag==2&&flag1==0&&flag2==1){
        plus();
        for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
        }
    }else if(Flag==2&&flag1==1&&flag2==0){
        plus();
        printf("-");
        for(int i=lenc-1;i>=0;i--){
        printf("%d",c[i]);
        }
    }else if(Flag==3&&flag1==0&&flag2==0){
        multiply();
    }
    else if(Flag==3&&flag1==1&&flag2==1){
        multiply();
    }else if(Flag==3&&flag1==1&&flag2==0){
        printf("-");
        multiply();
    }else if(Flag==3&&flag1==0&&flag2==1){
        printf("-");
        multiply();
    }else if(Flag==4){
        for(int i=0;i<lena/2;i++){//除法无需倒置
            int t=a[i];
            a[i]=a[lena-1-i];
            a[lena-1-i]=t;
        }
        for(int i=0;i<lenb/2;i++){
            int t=b[i];
            b[i]=b[lenb-1-i];
            b[lenb-1-i]=t;
        }
        if(flag1==0&&flag2==0){
            divide();
        }else if(flag1==1&&flag2==1){
            divide();
        }else{
            printf("-");
            divide();
        }
    }
    return 0;
}