#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void print(int *c,int cl)
{
    for(int i=0;i<cl;i++)
        printf("%d",c[i]);
    printf("\n");
}
int *add_numb(int *a,int al,int *b,int bl,int *l)
{
    int cl = (al>bl) ? al:bl;
    int *fn_ar = (int *)malloc(sizeof(int)*(cl+1));
    int c=0;
    for(int i=0;i<cl;i++)
    {
        fn_ar[i]=c;
        if(i<al)
            fn_ar[i]+=a[i];
        if(i<bl)
            fn_ar[i]+=b[i];
        c = fn_ar[i]/10;
        fn_ar[i]=fn_ar[i]%10;
    }
    if(c)
    {
        fn_ar[cl]=c;
        *l=cl;
    }
    return fn_ar;
}
void add_store(int *a,int *al,int *b,int bl)
{
    
    int c=0;
    for(int i=0;i<bl;i++)
    {
        if(i>=*al)
            a[i]=0;
        a[i]+=b[i]+c;
        c= a[i]/10;
        a[i]=a[i]%10;
    }
    while(c)
    {
       if(bl>=*al)
           a[bl]=0;
       a[bl]+=c;
       c=a[bl]/10;
       a[bl]%=10;
       bl++;
    }
    if(bl>=*al)
        *al=bl;
}

int multiply_by_numb(int *a,int al,int x,int *s)
{
    //int *fn_ar = (int *)malloc(sizeof(int)*(al+1));
    int c=0;
    for(int i=0;i<al;i++)
    {
        *s=a[i]*x + c;
        c=*s/10;
        *s%=10;s++;
    }
    if(c)
    {
        *s=c;
        al++;   
    }
    return al;
}

int *reverse(int *a,int al)
{
    int *tmp = (int *)malloc(sizeof(int)*al);
    for(int i=0;i<al;i++)
        tmp[i]=a[al-i-1];
    return tmp;
}
int multiply_by_arr(int *a,int al,int *b,int bl,int **ans_ref)
{
    int *ans = (int *)malloc(sizeof(int)*(al+bl+1));
    int ans_l=0;
    for(int i=0;i<(al+bl+1);i++)
        ans[i]=0;
    for(int i=0;i<bl;i++)
    {
        int *tmp1 = (int *)malloc(sizeof(int)*(al+i+1));
        for(int j=0;j<i;j++)
            tmp1[j]=0;
        int *ptr = &tmp1[i];
        int l = multiply_by_numb(a,al,b[i],ptr) + i;
        add_store(ans,&ans_l,tmp1,l);
        free(tmp1);
    }
    *ans_ref = reverse(ans,ans_l);
    return ans_l;
}       
int big_number_multiplication(int *a,int al,int *b,int bl,int **ans_ref)
{
    int *dup_a = reverse(a,al);
    int *dup_b = reverse(b,bl);
    int ans_l = multiply_by_arr(dup_a,al,dup_b,bl,ans_ref);
    return ans_l;
}

char *multiply(char *a,char *b)
{
    int al=strlen(a);
    int bl=strlen(b);
    int dup_a[al];
    int dup_b[bl];
    for(int i=0;i<al;i++)
        dup_a[i]=a[i]-'0';
    for(int i=0;i<bl;i++)
        dup_b[i]=b[i]-'0';
    int *ans;
    int ans_l = big_number_multiplication(dup_a,al,dup_b,bl,&ans);
    
    char *cans = (char *)malloc(sizeof(char)*(ans_l+1));
    int f=0;
    //print(ans,ans_l);
    for(int i=0;i<ans_l;i++)
    {
        if(ans[i]==0&&f==0)
            continue;
        f=1;
        cans[i]=ans[i]+'0';
        //printf("%c%d\n",cans[i],ans[i]);
    }
    if(f==0)
    {
        cans[0]='0';
        cans[1]='\0';
    }
    else
        cans[ans_l]='\0';
    return cans;
}       
      
int main()
{
    char a[5000];
    char b[5000];
    scanf("%s%s",a,b);
    char *c = multiply(a,b);
    printf("\n\n\n length of number-1 %lu",strlen(a));
    printf("\n\n\n length of number-2 %lu",strlen(b));
    printf("\n\n\n %s",c);
    return 0;
}

