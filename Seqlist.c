//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
#include <stdio.h> 
#include <string.h>
#include <iostream.h>

#define MAX_SIZE 20;
typedef int ElemType;
typedef struct{
    ElemType data[MAX_SIZE];
    int length;
}Seqlist;

//顺序表初始化
bool SeqInit(Seqlist *L){
    int i = 0;
    for(i=0;i<MAX_SIZE;i++){
        L->data[i] = 0;
    }
    L->length = 0;
    return true;
}
//打印顺序表
void SeqPrint(Seqlist L){
    int i = 0;
    for(i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
//在第i个位置插入数据
bool SeqInsert(Seqlist *L,int i,ElemType elem){
    if(i<1||i>L->length+1){
        return false;
    }
    if(L->length>=MAX_SIZE){
        return false;
    }
    for(int j=L->length;j>=i;j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = elem;
    L->length++;
    return true;
}
//删除第i个位置的数据
bool SeqDelete(Seqlist *L,int i){
    if(i<1||i>L->length+1){
        return false;
    }
    if(L->length==0){
        return false;
    }
    for(;i<L->length;i++){
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return true;
}
//按值查找（在顺序表中查找第1个等于e的元素，并返回其位置）
int Find(Seqlist L,ElemType e){
    int i = 0;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}
//王道P17
//1.从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
bool MinDelete(Seqlist *L,ElemType &value){
    if(L->length==0){
        return false;
    }
    int i = 0;
    int pos = 0;
    value = L->data[0];
    for(i=1;i<L->length;i++){
        if(L->data[i]<value){
            value = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[L->length-1];
    L->length--;
    return true;
}
//2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度O（1）。
bool Reverse(Seqlist *L){
    if(L->length==0){
        return false;
    }
    int temp = 0;
    for(int i=0,j=L->length-1;i<j;i++,j--){
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
    return true;
}
//3.对长度为n的顺序表L，编写一个时间复杂度为O（n），空间复杂度为O（1）的算法，该算法删除线性表中所有值为x的数据元素。
bool DeleteX(Seqlist *L,ElemType x){
    if(L->length==0){
        return false;
    }
    for(int cur=0,pos=0;cur<L->length;cur++){
        if(L->data[cur]!=x){
        L->data[pos] = L->data[cur];
        pos++;
        }
    }
    L->length = pos;
    return true;
}
//4.从有序顺序表中删除其值在给定值s与t之间（要求s<t），如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
bool DeleteS_T(Seqlist *L,ElemType value,ElemType s,ElemType t){
    if(s>=t||L->length==0){
        return false;
    }
    int cur = 0;
    for(cur=0;cur<L->length&&L->data[cur]<s;cur++); //先找出s所在位置
    if(cur>=L->length){
        return false;
    }
    int j = 0;
    for(j=cur;cur<L->length&&L->data[cur]<=t;cur++){//删除s-t中的给定值valve
    
        if(L->data[cur]!=value){
            L->data[j++] = L->data[cur];
        }
    }
    if(cur>=L->length){
        return true;
    }
    for(;cur<L->length;cur++,j++){
        L->data[j] = L->data[cur];
    }
    L->length = j;
    return true;
}

//5.从顺序表中删除其值在给定值s与t之间（包含s和t、要求s<t）的所有元素，如果s与t不合理顺序表为空，则显示出错信息并退出运行。
bool DeleteInS_T(Seqlist *L,ElemType s,ElemType t){
    if(s>=t||L->length==0){
        return false;
    }
    int cur = 0;
    for(cur=0;cur<L->length&&L->data[cur]<s;cur++);
    if(cur>=L->length){
        return false;
    }
    int j = cur;
    for(;cur<L->length&&L->data[cur]<=t;cur++);
    if(cur>=L->length){
        return false;
    }
    while(cur<L->length){
        L->data[j++] = L->data[cur++];
    }
    L->length = j;
    return true;
}
//6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
bool DeleteAllSame(Seqlist *L){
    if(L->length==0){
        return false;
    }
    int cur = 0;
    int i = 0;
    while(cur<L->length){
        L->data[i] = L->data[cur];
        if(L->data[cur+1]!=L->data[i]){
            i++;
        }
        cur++;
    }
    L->length = i;
    return true;
}
//7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
bool Merge(Seqlist A,Seqlist B,Seqlist *C
){
    if(A.length==0&&B.length==0){
        return false;
    }
    if(A.length+B.length>MAX_SIZE){
        return false;
    }
    int a = 0,b = 0,c = 0;
    while(a<A.length&&b<B.length){
        if(A.data[a]<=B.data[b]){
            C->data[c++] = A.data[a++];
        }
        else{
            C->data[c++] = B.data[b++];
        }
    }
    while(a<A.length){
        C->data[c++] = A.data[a++];
    }
    while(b<B.length){
        C->data[c++] = B.data[b++];
    }
    C->length = c;
    return true;
}
//8.已知在一维数组A[m+n]中依次存放两个线性表（a1,a2,a3,...,am）和（b1,b2,b3,...,bn），试编写一个函数，将数组中两个顺序表的位置互换，即将（b1,b2,b3,...,bn）放在（a1,a2,a3,...,am）的前面。

void main(){
    Seqlist s;
    SeqInit(&s);
    SeqInsert(&s,1,1);
    SeqInsert(&s,2,2);
    SeqInsert(&s,3,2);
    SeqInsert(&s,4,4);
    SeqInsert(&s,5,4);
    SeqInsert(&s,6,6);
    SeqPrint(s);
    Seqlist a;
    SeqInit(&a);
    SeqInsert(&a,1,3);
    SeqInsert(&a,2,3);
    SeqInsert(&a,3,5);
    SeqInsert(&a,4,5);
    SeqInsert(&a,5,7);
    SeqInsert(&a,6,9);
    SeqInsert(&a,7,10);
    SeqPrint(a);
    printf("合并两个顺序表之后结果为：");
    Seqlist c;
    SeqInit(&c);
    Merge(s,a,&c);
    SeqPrint(c);
    printf("删除所有重复元素之后的顺序表为：");
    DeleteAllSame(&s);
    SeqPrint(s);
    printf("删除给定值s-t中的后顺序表为：");
    DeleteS_T(&s,4,1,5);
    SeqPrint(s);
    printf("删除给定值s-t(包含s-t)中的后顺序表为：");
    DeleteInS_T(&s,2,4);
    SeqPrint(s);
    DeleteX(&s,2);
    SeqPrint(s);
    printf("将元素逆置后为：");
    Reverse(&s);
    SeqPrint(s);
    printf("元素%d的位置在：%d\n",4,Find(s,4));
    SeqDelete(&s,2);
    SeqPrint(s);
    ElemType e;
    MinDelete(&s,e);
    printf("删除的最小元素是：%d \n",e);
    SeqPrint(s);
    
}


