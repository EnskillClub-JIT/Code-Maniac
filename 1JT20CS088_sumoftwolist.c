/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typdef struct Listnode{
    struct Listnode *next;
    int val;
}

Listnode* add(Listnode* l1,Listnode* l2){
    Listnode* temp=(Listnode*)malloc(sizeof(Listnode));
    Listnode* p1=temp;
    int c=0;
    
    while(l1|| l2 || c){
        int sum=c;
        if(l1){
            sum=sum+l1->val;
            l1=l1->next;
        }
        if(l2){
             sum=sum+l2->val;
            l2=l2->next; 
        }
        c=sum/10;
        sum%=10;
        
        struct Listnode *new= (struct Listnode *)malloc(sizeof(Listnode));
        new-val = sum;
        new->next=NULL;
        p1->next=new;
        p1=p1->next;
        }
        return temp->next;
}
void pList(struct Listnode *node){
    while(node!=NULL){
        printf('%d->',node->val);
        node=node->next;
    }
    printf("NULL");
}

int main(){
    int m1,m2,no;
    struct Listnode*l1=NULL;
    struct Listnode*l2=NULL;
    printf("Enter the number of digits in the linked list");
    scanf("%d",&m1);
     printf("Enter the  digits in the linked list");
     for(int i =0;i<m1;i++){
         scanf("%d",no);
    struct Listnode *new = (struct Listnode *)malloc(sizeof(Listnode));
    new->val=no;
    new->next=l1;
    l1=new;
     }
      printf("Enter the number of digits in the linked list");
    scanf("%d",&m2);
     printf("Enter the  digits in the linked list");
     for(int i =0;i<m2;i++){
         scanf("%d",no);
    struct Listnode *new = (struct Listnode *)malloc(sizeof(Listnode));
    new->val=no;
    new->next=l2;
    l2=new;
     }
     printf("THE first number is");
     printlist(l1);
     printf("THE sec number is");
     printlist(l2);
     
     struct Listnode *summ =add(l1,l2);
     printf("The sum of two numbers is ")
     printlist(summ);
     return 0;
     
}
}
}


}

int main()
{
    printf("Hello World");

    return 0;
}
