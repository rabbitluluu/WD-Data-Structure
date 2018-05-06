#include<iostream>
#define ELEMTYPE char
#define MAXSIZE 50
#define END 9999
#define NOP -1
using namespace std;
typedef struct BiNode{
    ELEMTYPE data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
typedef struct ListNode{
    int lchild;
    int rchild;
    ELEMTYPE data;
}List;

void fun_start(BiTree &T);
string fun(BiTree &T){
    if(!T->lchild&&!T->rchild){
        if(T)return string(1,T->data);
    }else{
        if(T){
            string str="",tmp="";
            if(T->lchild)tmp=fun(T->lchild);
            str+="("+tmp+string(1,T->data);
            if(T->rchild)tmp=fun(T->rchild);
            str+=tmp+")";
            return str;
        }
    }
    return "";
}





//不使用第一项
void InitList(List L[]){
    int x=0,y=0,n=0;
    ELEMTYPE d;
    L[0]={0,0,0};
    cout<<"input numbers of tree node:"<<endl;
    cin>>n;
    for(int i=1;n<MAXSIZE&&i<=n;i++){
        cin>>x>>y>>d;
        L[i].lchild=x;
        L[i].rchild=y;
        L[i].data=d;
    }
}
void InitTreeWithList(BiTree &T,List L[],int index){
    if(index!=NOP){
        BiTree nd=(BiTree)malloc(sizeof(BiNode));
        nd->data=L[index].data;
        T=nd;
        InitTreeWithList(T->lchild,L,L[index].lchild);
        InitTreeWithList(T->rchild,L,L[index].rchild);
    }else{
        T=NULL;
    }
}
// 1 for PreOrder,2 for InOrder,3 for PostOrder
void PrintTree(BiTree T,int x){
    if(T){
        if(x==1){
            cout<<T->data<<" ";
        }
        PrintTree(T->lchild,x);
        if(x==2){
            cout<<T->data<<" ";
        }
        PrintTree(T->rchild,x);
        if(x==3){
            cout<<T->data<<" ";
        }
        free(T);
    }
}
void fun_start(BiTree &T){
    //以下是一个预置的初始化数组
    //不使用第一项
    List L0[10]={{0,0,0},{2,3,'+'},{4,5,'*'},{NOP,6,'-'},{NOP,NOP,'a'},{NOP,NOP,'b'},{7,8,'-'},{NOP,NOP,'c'},{NOP,NOP,'d'},{NOP,NOP,19}};
    List L[MAXSIZE];
    //InitList(L);
    InitTreeWithList(T,L0,1);
    string str=fun(T);
    for(int i=1;i<(str.size()-1);i++){
        cout<<str[i];
    }
    cout<<endl;
    PrintTree(T,1);
}



int main(){
    BiTree T;
    fun_start(T);
    cout<<endl;
    return 0;
}
