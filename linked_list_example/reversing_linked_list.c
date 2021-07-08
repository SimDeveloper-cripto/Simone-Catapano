/*
 * Declaration of libraries we're gonna need.
 * This project shows comments only for the reversing algorithm. 
 * That is because I've already uploaded another file with all the basic functions you should know when working with linked lists.
*/
#include <stdio.h>
#include <stdlib.h>

// Here we define out list (a very simple list).
typedef struct node { 
	int val; 
	struct node *next;
} list;

void push_head(list **head, int val); // this procedure allows us to push at the head of the list.
void show(list *head); // print linked list by recursive approach.
void reverse(list **head); // this procedure is for reversing the linked list.

int main()
{
	list *l = NULL;
	push_head(&l, 20);
	push_head(&l, 10);
	show(l);
	reverse(&l);
	show(l);
	return 0;
}

void push_head(list **head, int val)
{
	list *node = (list*) malloc(sizeof(list));
	node->val = val;
	node->next = *head;
	*head = node;
}

void reverse(list **head)
{
	list *current = *head;
	list *prev = NULL;
	list *next = NULL;
	/*
	 * Iterate while the linked list is not finished.
	 * Save the next node.
	 * Reverse the current node's pointer.
	 * Move pointer one position ahead. (!!)
	 * At the end save the new head.
	*/
	while(current != NULL){
		next = current->next; 
		current->next = prev; 
		// !!
		prev = current;
		current = next;
		
		/*
		 * Here is a quick explanation of what is happening: 
		 * Assume we have this situation: [10] --> [20] --> NULL
		 * next = 20
		 * current->next (20) is going to be considered as prev.
		 * And then we just swap those two! (20 --> 10 && 10 --> 20).
		*/
	}
	*head = prev;  // new head.
}

void show(list *head)
{
	if(head != NULL){
		printf("[ %d ] --> ", head->val);
		show(head->next);
	} else {
		printf("NULL \n");
	}
}
