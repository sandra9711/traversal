/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
# define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

/*Begin of insert_right*/
void insert_right()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	printf("Queue Overflow\n");
		return;}
	if (left == -1)  /* if queue is initially empty */
	{	left = 0;
		right = 0;}
	else
	if(right == MAX-1)  /*right is at last position of queue */
		right = 0;
	else
		right = right+1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[right] = added_item ;
	display_queue();
}
/*End of insert_right*/

/*Begin of insert_left*/
void insert_left()
{	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	printf("Queue Overflow \n");
		return;	 }
	if (left == -1)/*If queue is initially empty*/
	{	left = 0;
		right = 0;	 }
	else
	if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[left] = added_item ;	
	display_queue();}
/*End of insert_left*/

/*Begin of delete_left*/
void delete_left()
{	if (left == -1)
	{	printf("Queue Underflow\n");
		return ;	}
	printf("Element deleted from queue is : %d\n",deque_arr[left]);
	if(left == right) /*Queue has only one element */
	{	left = -1;
		right=-1;	 }
	else
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
	display_queue();
}
/*End of delete_left*/

/*Begin of delete_right*/
void delete_right()
{if (left == -1)
	{printf("Queue Underflow\n");
		return ;	 }
	printf("Element deleted from queue is : %d\n",deque_arr[right]);
	if(left == right) /*queue has only one element*/
	{	left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;
			display_queue();}
/*End of delete_right*/
/*Begin of input_que*/
void display_queue()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	printf("Queue is empty\n");
		return;	 }
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}
int main(){
    int c;
    do{
        printf("1.Insert at front\t2.Insert at rear\t2.Delete from front\t4.Delete from rear\n");
    printf("enter your choice: ");
    scanf("%d",&c);
    if(c==1){
        insert_left();
    }else if(c==2){
        insert_right();
    }else if(c==3){
        delete_left();
    }else if(c==4){
        delete_right();
    }else{
        printf("wrong input/choice\n");
    }
    }while(1);

}