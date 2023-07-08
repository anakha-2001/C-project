
#include<stdio.h>
#include<stdlib.h>

 struct acc_node
 {
	char name[20];
	int pin;
    long long int adhar;
	char job[20];
	char address[100];
	long long int phno;
	int balance;
	int ac_no;
	struct acc_node *next;	
 };	
typedef struct acc_node node;
node *head=NULL;
void insert()                               
{
	node *temp;
	temp=(node*)malloc(sizeof(node));        
	int p_value1,p_value2;
	long long int adhar,phno;
	printf("\n\t\tEnter the name:- ");
	scanf("%s",temp->name);
	printf("\n\t\tEnter the pin no:- ");
	scanf("%d",&p_value1);
	printf("\n\t\tRe-enter the pin no:- ");
	scanf("%d",&p_value2);
	if(p_value1!=p_value2)                  
	{  
	     printf("\nSorry, The pin u entered doesn't matches....!!");
	}
	else
	{
	 int flag=0;                         
	 node *search;
	 search=head;
	 if(head==NULL)
	 { 
	  flag=0;
	 }	
	 else
	 {
		while(search!=NULL)
		{
			if(p_value1==search->pin)      
			{
				flag=1;
				printf("\n\t\tPin already exists");
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}   
	if(flag==0)        
	{	
		temp->pin=p_value1;
		printf("\n\t\tEnter the adhar no:- ");
		scanf("%lld",&temp->adhar);	
		printf("\n\t\tEnter the address:- ");
		scanf("%s",temp->address);
		printf("\n\t\tEnter the profession:- ");
		scanf("%s",temp->job);
		printf("\n\t\tEnter the mobile no:- ");
		scanf("%lld",&temp->phno);	
		printf("\n\t\tEnter the amount u want to deposit:- ");
		scanf("%d",&temp->balance);
		int acc=rand()%989785;                                      
		printf("\n\t\tUr unique bank ac id. is %d\n",acc);
		temp->ac_no=acc;
		temp->next=NULL;
		printf("\n\n\t\tACCOUNT CREATED SUCCESSFULLY...!!");
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			node *t;
			t=head;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=temp;
	
	}	
	printf("\n\n\tYour account details are:");        
	    printf("\n\n\t\tName :- ");
		printf("%s",temp->name);
		printf("\n\t\tAccount number:- ");
		printf("%d",temp->ac_no);
		printf("\n\t\tPin no. :- ");
		printf("%d",temp->pin);
		printf("\n\t\tAdhar:- ");
		printf("%lld",temp->adhar),
		printf("\n\t\tAddress:- ");
		printf("%s",temp->address),
		printf("\n\t\tProfession:- ");
		printf("%s",temp->job);
		printf("\n\t\tPhone:- ");
		printf("%lld",temp->phno);
		printf("\n\t\tBalance:- ");
		printf("%d",temp->balance);
	                       	
	}	
   } 
}
void withdraw()       
{
	int p_value;
	printf("\n\t\tEnter the pin no.:- ");
	scanf("%d",&p_value);
	int flag=0;             
	node *search;
	search=head;
	if(head==NULL)
	{ 
	flag=0; 
	}	
	else
	{
		while(search!=NULL)
		{
			if(p_value==search->pin)
			{
				flag=1;      
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}	
	if(flag==1)   
	{
		node *t=search;
		int limit;
		printf("\n\t\tEnter the amount:-");
		scanf("%d",&limit);
		if(limit>0 && limit<t->balance)
		{
			t->balance-=limit;
			printf("\n\t\t%d debited from account no. %d\n",limit,t->ac_no);
			printf("\n\t\tYour current balance is %d\n",t->balance);
		}
		else
		{
			printf("\n\t\tSorry, Insufficient balance....!!\n");
			printf("\n\t\tYour current balance is %d\n",t->balance);   	
	    } 
	}
	else
	{
		printf("\nSorry, No account exists....!!\n");
	}	
}

void deposit()         
{
	int p_value;
	printf("\n\t\tEnter the pin no.:- ");
	scanf("%d",&p_value);
	int flag=0;           
	node *search;
	search=head;
	if(head==NULL)
	{
		flag=0;
	}
	else
	{
		while(search!=NULL)
		{
			if(p_value==search->pin)
			{
				flag=1;       
				break;
			}
			else
			{
				search=search->next;
			}
		}
	}	
	if(flag=1)                                  
	{
		node *t=search;
		int limit;
		printf("\n\t\tEnter the amount:-");
		scanf("%d",&limit);
		if(limit>0)
		{
			t->balance+=limit;
			printf("\n\t\t%d credited to account no %d\n",limit,t->ac_no);
			printf("\n\t\tYour current balance is %d\n",t->balance);
		}
		else
			printf("\n\t\tEnter a valid limit\n");
			
	}
	else
	{
		printf("\nSorry, No account exists....!!\n");
		
	}
}
void display()              
{
	node *view;
	int count=1;
	if(head==NULL)
	{
		printf("\n\t\tList is empty.\n");
	}
	else
	{   
	    printf("\n");
		view=head;
		while(view!=NULL)
		{
		printf("\n\n\t\t[*Information of Client no. %d]",count);
		printf("\n\n\t\tName :- ");
		printf("%s",view->name);
		printf("\n\t\tAccount number:- ");
		printf("%d",view->ac_no);
		printf("\n\t\tPin no. :- ");
		printf("%d",view->pin);
		printf("\n\t\tAdhar number:- ");
		printf("%lld",view->adhar);
		printf("\n\t\tAddress:- ");
		printf("%s",view->address),
		printf("\n\t\tProfession:- ");
		printf("%s",view->job);
		printf("\n\t\tPhone:- ");
		printf("%lld",view->phno);
		printf("\n\t\tBalace:- ");
		printf("%d",view->balance);
		printf("\n");
		
		count++;                            
		view=view->next;
		}
		count--;
		printf("\n\n\t\t Total no of accounts = %d\n",count);
	}
}
void close_acc()                     
{     
      int flag=0;
      
       node *temp;                  
      int p_value;
	printf("\n\t\tEnter the pin no.:- ");
	scanf("%d",&p_value);

      if(head->pin == p_value)
      {
          temp = head;            
          head = head->next;
          flag=1;
          free(temp);              
      }
      else
      {
          node *current  = head;
          while(current->next != NULL)
          {
              if(current->next->pin == p_value)           
              {
			      temp = current->next;
                  current->next = current->next->next;        
                  flag=1;
                  free(temp);                           
                  break;
              }
      
              else
                  current = current->next;
          }
      }
      if(flag==0)
        {
        	printf("\nSorry, No account exists....!!\n");
		}
	  else
	  {
	  	    printf("\nAccount deleted successfully....!!\n");
	  }
}
int menu()
   {
	int choice;
	printf("\n");
	printf("\n<1> Account creation\n<2>Withdraw money\n<3>Deposit money\n<4>View all accounts\n<5>Close account\n<6>Exit\nENTER YOUR CHOICE:-");
	scanf("%d",&choice);
	return(choice);
   }
int main()
{    
     printf("\n==================================================================================================================================================================================================================");
                          printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBANKING SYSTEM");
     printf("\n==================================================================================================================================================================================================================\n");
	while(1)
	{
		switch(menu())
		{
			case 1:	insert();        break;
			case 2: withdraw();      break;
			case 3: deposit();       break;
			case 4: display();       break;
			case 5: close_acc();     break;
            case 6:exit(1);
				    break;
	       default: printf("INVALID Choice...!!");
		}
	}
	return(0);
}
