/*奶牛们有一个习惯，那就是根据自己的编号选择床号。如果一头奶牛的编号是a，并且有k张床，床号为0 到 k-1，那么它就会选择a % k号床作为它睡觉的地点。
显然，2头牛不能睡在一张床上。现在输入一些奶牛的编号，请你为她们准备一间卧室，使得需要的床的数量最少。

输入格式:
共两行，第一行为一个整数n（0<n<=100)，代表奶牛的个数。第二行为n个用空格分隔的整数，代表这n个奶牛的编号。这些编号的取值范围是1-3000，且不存在编号相同的两头奶牛。

输出格式:
只有一行，为一个整数，代表所需最少的床位数k。

样例解释：
此方案下 0 号床分给 20 号牛、1 号床分给 1 号牛、7 号床分给 67 号牛、 8 号床分给 88号牛、9 号床分给 29 号牛、10 号床分给 490 号牛、12 号床
分给 32 号牛、 14 号床分给 34 号牛、15 号床分给 55 号牛、19 号床分给 99 号牛。可以证明当少于20张床时，都会出现2头牛睡一张床的情况。所以答案是20。

输入样例:
10
32 1 99 34 55 67 29 490 88 20

输出样例:
20*/

#include<stdio.h>

int judge(int cows[],int size,int numberofBed);
 
int main()
{
    int n,number,k,i;
    scanf("%d",&n);
    
    int cows[101]={0};
    int isenough=0;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&number);
        cows[i]=number;
    }
    
    for(k=n;!isenough;k++)
    {
        if(judge(cows,n,k)==1)
            isenough=1;
    }
    
    printf("%d\n",k-1);
    
    return 0;
}
 
int judge(int cows[],int size,int numberofBed) //判断当前床位够不够
{
    int i,isenough=1;
    int temp[500000]={0};
    
    for(i=0;i<size&&isenough;i++)
    {
        if(temp[cows[i]%numberofBed]==0) //若之前为0，则赋值为1；
            temp[cows[i]%numberofBed]=1;
        else isenough=0;                 //若此元素不为0，表示该床位已被占过，当前床位数不够
    }
    
    return isenough;
}
