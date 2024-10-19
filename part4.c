#include <stdio.h>
#include <string.h>
char a[128]={0},b[128]={0},a1[128]={0},b1[128]={0};
int lena=0,lenb=0,lenc=0,len=0,c[128]={0},flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,t1[128]={0},s[128]={0};
//flag12代表两个数的正负判断，flag4表示两个数的大小判断，flag表示进退位判断，flag3表示前导0判断，flag5表示当前被除数与除数的大小判断，s[]表示商
void plus(){
    for(int i=0;i<=lenc-1;i++){//处理加法，需要判断进位
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
    if(lenb>lena){//判断两个数的大小，并使得第一个数a[]更大
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
                break;
            }else if(b[i]<a[i]){
                break;
            }
            //此处if语句修改，之前判断大小出错XD
        }
        if(flag4==1){
            for(int i=0;i<=lenc-1;i++){
                t1[i]=a[i];
                a[i]=b[i];
                b[i]=t1[i];
            }
        }

    }
    for(int i=0;i<=lenc-1;i++){//处理加法，需要判断退位
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
    //此处修改，删去了多余的结果判断
    for(int i=lenc-1;i>=0;i--){//跳过前导0
        if(c[i]==0&&flag3==0){
            continue;
        }
        flag3=1;
        printf("%d",c[i]);
    }
}
void multiply(){
    for(int i=0;i<=lenc-1;i++){//处理乘法，模拟竖式运算
        for(int j=0;j<=lenc-1;j++){
            c[i+j]=c[i+j]+a[i]*b[j];
        }
    }
    //结果的位数不会超过最大数数的两倍
    for(int i=0;i<=lenc*2;i++){//所有竖式运算后，再处理进位
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
            len=lena;//此处与减法不同，lena和lenb会在后续运算中用到
            lena=lenb;
            lenb=len;
            flag4=1;
        }
    }else if(lenb==lena){
        for(int i=0;i>=lenc-1;i++){
            if(b[i]>a[i]){
                flag4=1;
                break;
            }else if(b[i]<a[i]){
                break;
            }
            //此处修改，同上(减法)
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
    //思路同样为竖式运算，实现方法为做n次减法运算以模拟除法，除数增加前导0以对齐被除数
    int p1=0,x=0,lenn=0,o=0,p=0;//p1表示商的位数，x表示当前被除数的第一位，o和p表示商的开始位与结束位
    lenn=lenb;//lenn表示前导0的个数+lenb，即目前运算到了哪一位
    while(lena>=lenn){//lena>=lenn说明已经相除到最后一位
        while(1){//此处while表明做一次除法，从中判断后break出循环（或许有更明了的写法？）
            flag5=0;
            for(int i=0;i<=lenn-lenb;i++){//得到每次运算后被除数不为0的第一位，即商的第一位
                if(a[i]!=0){
                    x=i;
                    break;
                }
                x=i;
            }
            for(int i=x;i<=lenn-1;i++){//判断当前被除数（与除数对齐）与除数的大小
                if(a[i]<b[i]){
                    flag5=1;
                    break;
                }else if(a[i]>b[i]){
                    break;
                }
            }
            if(flag5==1){//如果当前被除数小于除数，说明商为0，此时需要将除数后移一位，即增加前导0
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
            s[p1]++;//完成一次减法，此时商所在的位置中的元素加1
        }
        p1++;//商所在的位数加1
    }
    for(int i=0;i<=p1;i++){//得到商的开始位与结束位
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
    int t=0,Flag=0;//Flag代表运算符
    char n[128]={0};
    scanf("%s",&n);
    //根据输入格式可知，括号里的一定是负数，由此判断
    if(n[0]=='('){//处理括号
        flag1=1;
        for(int i=2;i<=strlen(n)-1;i++){
            if(n[i]==')'){//获取第一个数
                t=i+1;
                break;
            }
            a1[i-2]=n[i];
        }
    }else{
        for(int i=0;i<=strlen(n)-1;i++){
            if(n[i]<'0'||n[i]>'9'){//获取第二个数
                t=i;
                break;
            }
            a1[i]=n[i];
        }
    }
    if(n[t]=='+'){//获取运算符
        Flag=1;
    }else if(n[t]=='-'){
        Flag=2;
    }else if(n[t]=='*'){
        Flag=3;
    }else if(n[t]=='/'){
        Flag=4;
    }
    if(n[t+1]=='('){//处理括号
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
    if(a1[0]=='-'){//处理负号
        // flag1=1;
        for(int i=1;i<=strlen(a1)-1;i++){
            a[i-1]=a1[i];
        }
    }else{
        strcpy(a,a1);
    }
    if(b1[0]=='-'){
        // flag2=1;
        for(int i=1;i<=strlen(b1)-1;i++){
            b[i-1]=b1[i];
        }
    }else{
        strcpy(b,b1);
    }
    lena=strlen(a);//获取长度
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
    if(lena>lenb){//获取更大位数的长度
        lenc=lena;
    }else{
        lenc=lenb;
    }
    if(Flag==1&&flag1==0&&flag2==0){//根据flag以及Flag得出输出格式
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
    }else if(Flag==2&&flag1==0&&flag2==0){//减法运算时需要判断是否实际做的是加法
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