#include<stdlib.h>

#include<stdio.h>

struct list

{

   int count;

   char item[51];

   int quantity;

   struct list* next;

};

struct list* start=NULL;

void seelist()

{

   if(start==NULL)

   {

       printf("List is empty");

       return;

   }

   else

   {

       struct list* t;

       t=start;

       while(t!=NULL)

       {

           printf("\nNo.");

           printf(" %d ",t->count);

           printf(" item ");

           puts(t->item);

           printf(" quantity ");

           printf("%d",t->quantity);

           t=t->next;

       }

   }

}

void add()

{



   if(start==NULL)

   {

       struct list* t=(struct list*)malloc(sizeof(struct list));

       t->count=1;

       printf("\nEnter product\n");

       scanf("\n");

       fgets(t->item,51,stdin);

       printf("Enter quantity\n");

       scanf("%d",&t->quantity);

       t->next=NULL;

       start=t;

   }

   else

   {

       struct list* t1,*t2;

       t1=start;

       while(t1->next!=NULL)

           t1=t1->next;

       t2=(struct list*)malloc(sizeof(struct list));

       printf("\nEnter item\n");

       scanf("\n");

       fgets(t2->item,51,stdin);

       printf("Enter Quantity\n");

       scanf("%d",&t2->quantity);

       t2->count=(t1->count)+1;

       t1->next=t2;

   }

}

void adjustcount()

{

   struct list *t;

   int i=1;

   t=start;

   while(t!=NULL)

   {

       t->count=0;

       t=t->next;

   }

   t=start;

   while(t!=NULL)

   {

       t->count=(t->count)+i;

       t=t->next;

       i++;

   }

}

void removel()

{

   if(start==NULL)

   {

       printf("list is empty\n");

   }

   else

   {

       int d;

       struct list* t,*t1,*t2;

       t=start;

       printf("Enter no. to delete");

       scanf("%d",&d);

       if(start->count==d)

       {

           t2=start;

           start=start->next;

           free(t2);

       }

       else

       {

           while(t->next->count!=d)

               t=t->next;

           t1=t->next;

           t->next=t1->next;

           free(t1);

       }



   }

   adjustcount();

}

int main()

{

   int a;

   while(1)

   {

       printf("\n");

       printf("1.See your list items.\n");

       printf("2.Add items to your list.\n");

       printf("3.Remove item from list.""\n");

       printf("4.Want to Exit.\n");

       printf("Please Enter your choice.\n");

       scanf("%d",&a);

       switch(a)

       {

       case 1:

           seelist();

           break;

       case 2:

           add();

           break;

       case 3:

           removel();

           break;

       case 4:

           exit(1);

       default:

           printf("\n Invalid choice please correct.\n");

       }

   }

}
