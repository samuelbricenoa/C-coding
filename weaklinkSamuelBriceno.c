#include <stdio.h>
#include <stdlib.h>
//define structs for easier calling.
typedef struct link link;
typedef struct linkedlist linkedlist;
typedef struct stack stack;

//link struct.
struct link{
	link * next;
	link * prev;
	int height;
	int value;
	int limit;
};
//linked list struct.
struct linkedlist{
	link * front;
	link * end;
};
//stack struct
struct stack{
	linkedlist * list;
};

//struct for input values.
typedef struct node node;
struct node{
	int grade;
	node * next;
	node * prev;
};
//global variables to count the number of broken links and whole links that fell.
int breaknum = 0;
int wholenum = 0;
//initializing functions.
link * insertfront(link *, int value);
link * removefront(link *);
void limitcalc(link *);
link * breakcalc(link*, int grade, int count);
link * afterbreakcalc(link*);
node* insertback(node*, int grade);
stack * createstack();
linkedlist * createlinkedlist();
void freeStack(stack *);
void freeLinkedList(linkedlist *);

int main(){
	node * tail = NULL;
	node * head2 = NULL;
	int grade = 0, count = 0;
	//scans in the links into a linked list
	while ( grade >= 0)
	{
		scanf("%d", &grade);
		
			if(grade >= 0)
			{
			tail = insertback(tail, grade);
			if(tail->prev == NULL)
				head2 = tail;
			}
	}
	//create stack.
	stack * linkstack = createstack();
	linkstack->list->front = NULL;
	//for each link in the linked list, input it into the functions to change the linked list in case of breaks.	
	while(head2 != NULL)
	{
		//count variable tells me what number link is being added.
	count++;
	linkstack->list->front = insertfront(linkstack->list->front, head2->grade);
	limitcalc(linkstack->list->front);
	linkstack->list->front = breakcalc(linkstack->list->front, head2->grade, count);
	head2 = head2->next;	
	}
	
	// if the stack ends up empty then the ending chain height will be 0.
	if(linkstack->list->front == NULL)
	{
		printf("Ending chain height is 0.\n");
	}
	else	
	//prints out the chain height and the ammount of broken links and whole links that fell using the global variables.
		printf("Ending chain height is %d.\n", linkstack->list->front->height);
	printf("There are %d broken links and %d whole links on the floor.\n", breaknum, wholenum);
	//frees the stack.
	freeStack(linkstack);
return 0;
}


//this function inserts the current link at the end of the chain.
link * insertfront(link * front, int value) {
	//allocates memory for link and initializes the grade and limit.
	link* newfront = calloc(1, sizeof(link));
	newfront -> value = value;
	newfront -> limit = value;
	newfront->next = front;
	//if the current link is not the only link in the chain, its height will be 1 plus the height of the next chain in the linked list.
	if (front != NULL){
		newfront->height = front->height +1;
	front->prev = newfront;
	}
	//if current link is the first link in the chain, then its height must be 1 and it should point to NULL.
	else
	{
		newfront->height = 1;
		newfront->next = NULL;
	}
	//the head of the linked list previous value is NULL.
	newfront->prev = NULL;
	//returns new head pointer.
	return newfront;	
}

//function to remove first value of the linked list.
link* removefront(link* front)
{
	if (front == NULL)
	return NULL;
	link* newfront = front->next;
	if (newfront!=NULL)
		newfront->prev = NULL;
	free(front);
	return newfront;
}

//this function is used to change the limits of each link after a new link is added to the chain.
void limitcalc(link * front){
	//if there is only one link, then there is no change needed.
	if(front->next == NULL)
		return;
	else 
	{
		//subtracts the limit of each link in the chain by 1 after the lowest link.
		front->next->limit--;
		limitcalc(front->next);
	}
}

//function detects a break in the chain.
link * breakcalc(link * front, int grade, int count)
{
// breaknum2 counts the ammount of broken links in the current chain whereas brokenum counts the total number of broken links total.
	int breaknum2 = 0;
	//temporary value used to check the highest broken link in the chain.
	 link* temp = NULL;
	 link * funcfront = front;
	 //this while loop loops through the whole linked list to find a link with limit of -1 (when the link breaks) and sets it to the temporary pointer.
	 // the highest broken link will be stored in the temp pointer at the end of the loop.
	 while(funcfront != NULL)
	 {
	 	if(funcfront->limit == -1)
	 	{
	 		//counts the number of broken links and updates the variables.
		breaknum++;
		breaknum2++;
	 	temp = funcfront;
	 	}
		
		funcfront = funcfront->next;
	 }
	 //since temp is initially set to NULL, if a broken link was found, it would have changed to a non NULL value.
	if (temp != NULL)
	{
		//if the temp value is the only chain in the link, the height will be zero after it breaks.
		if(temp->next == NULL)
		{
			printf("Chain broken at link %d. New height is 0.\n", count);	
		}
		else
		{	
		//the new height of the chain will be the height of the next value from the broken link.
		printf("Chain broken at link %d. New height is %d.\n", count, temp->height-1);
		}
		//calculates the number of whole links that were dropped.
		wholenum+= (front->height - temp->height + 1 - breaknum2);
		//removes nodes leading up to the highest broken link.
		while(front!= temp)
		{
			front = removefront(front);
		}
		//removes the highest broken link.
		link * newfront = removefront(front);
		// after emptying the linked list up untill the new front, uses the afterbreakcalc to readjust the limits of the linked list to coincide with the new height.
		return afterbreakcalc(newfront);
	
		
	}
	//if there is no broken link, then there is no change needed and the front pointer is returned.
	else
		return front;
}

//this function adjusts the limits of the chain after a broken link was detected and the dropped links were removed from the linked list.
link * afterbreakcalc(link*front)
{
	//if the list is empty, return NULL.
	if(front==NULL)
		return NULL;
	//store variable for height of the inputed node.
	int baseheight = front->height;
	//temporary pointer for the linked list traversal.
	link * temp = front;
	//the lowest link (first value of linked list) will have its limit set to its grade.
	temp->limit = temp->value;
	temp = temp->next;
	//traverses the linked list while adjusting limits for each value.
	while(temp!= NULL)
	{
		//the limit of the link will depend on the difference of its grade and the difference of the height of the lowest link and the current height.
		temp->limit = temp->value - (baseheight - temp->height);
		temp = temp->next;	
	}
	//returns the front pointer of adjusted linked list.
	return front;
}

//function for inserting at the back of a linked list.
node * insertback(node * back, int grade)
{
	node* newback = calloc(1, sizeof(node));
	newback->grade = grade;
	newback->prev = back;
	if (back != NULL)
		back->next = newback;
	newback->next = NULL;
	return newback;
}

// Function to create a stack
stack * createstack()
{
   // Create the memory for the stack
   stack * ret = (stack *) calloc(1, sizeof(stack));

   // In this implementation a linked list represents the stack
   // Create the linked list for this stack
   ret->list = createlinkedlist();

   // Return the created stack
   return ret;
}

// Function to create a linked list
linkedlist * createlinkedlist()
{
   // Create the memory for the linked list
   linkedlist * ret = 
      (linkedlist *) calloc(1, sizeof(linkedlist));

   // Set the front to NULL to signify the list is empty
   ret->front = NULL;

   // Return the created linked list
   return ret;
}

// Function to free a linked list and all its nodes
void freeLinkedList(linkedlist * list)
{
   // Free nodes until the list is empty
   while (list->front != NULL)
   {
      // Get the pointer to the next front 
      // (post removing current front)
      link * newFront = list->front->next;
      
      // Free the old front and update the front of the list
      free(list->front);
      list->front = newFront;
   }

   // Free the full list
   free(list);
}

// Function to free a stack
void freeStack(stack * stk)
{
   // Free the linked list that represents the stack
   freeLinkedList(stk->list);   

   // Free the stack memory
   free(stk);
}
