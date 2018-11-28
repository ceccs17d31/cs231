/*Lena Grace Joseph
  S3 D 31
  Stack Using LL*/




#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node
{
    int data;
    struct node *next;

}*header;

struct node *newnode()
{
    struct node* newn=malloc(sizeof(struct node));
    if(newn==NULL)
    {


        printf("\nMemory overflow");
    exit(0);
    }
     else
     {
         return (newn);
     }
}
int push()
{
    int data;
  struct node *new=newnode();
  printf("enter data :");
  scanf("%d",&data);
  new->data=data;
  new->next=header->next;
  header->next=new;
  c++;
  return 0;
}
int pop()
{
    struct node *new=header->next,*cnode=header;
   if(header->next==NULL)
   {
              printf("\n empty stack ");

   }
    else
   {
       cnode=new;
     new=new->next ;
     header->next=cnode->next;
     header->next=new;
     printf("\npopped elem is %d  ",cnode->data);
     free(cnode);
     c--;

    }
return 0;
}
int delete()
{
    struct node *new=header->next,*cnode=header;




    while(new!=NULL)
    {
        cnode=new;
     new=new->next;
     free(cnode);
     ;


    }
    header->next=NULL;
    c=0;

return 0;
}
int  display()
{

    struct node *new=header->next;
    if(header->next==NULL)
        printf("\nempty");
    else{
        while(new->next!=NULL)
        {

            printf("  ->%d",new->data);
            new=new->next;
        }
        printf("  ->%d",new->data);

    }
    return 0;
}
int main()
{

    int ch,data;
    printf("\n1.push\n2.pop\n3.display\n4.count\n5.delete_all\n6.exit\nenter choice:");
    scanf("%d",&ch);
    header=newnode();
    header->next=NULL;

    while(1)
    {
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("no of elem in stack is %d",c);
            break;
        case 5:
            delete();
            break;
        case 6:
            exit(0);
        default:
            printf("wrong choice");
        }
        printf("\n1.push\n2.pop\n3.display\n4.count\n5.delete_all\n6.exit\nenter choice:");
    scanf("%d",&ch);
    }
    return 0;

}
