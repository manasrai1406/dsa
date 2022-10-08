/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h> 
 
#include<stdlib.h> 
 
struct Node 
 { 
 
int data; 
 
struct Node *next; 
 };  
 
 
int calcSize(struct Node* head); 
 
 
 
void deleteFront(struct Node** head){ 
 
 
 
struct Node* temp = *head; 
 
 
 
 
 
if(*head == NULL){ 
 
printf("Linked List Empty, nothing to delete"); 
 
return; 
 
}  
 
 
 
 
if(temp->next == *head){ 
 
*head = NULL; 
 
return; 
 
}  
 
 
struct Node* curr = *head; 
 
 
 
 
 
while(curr->next != *head) 
curr = curr->next; 
 
 
 
 
 
curr->next = (*head)->next; 
 
 
 
 
 
*head = (*head)->next; 
 
free(temp); 
 }  
 
 
void deleteEnd(struct Node** head){ 
 
struct Node* temp = *head; 
 
struct Node* previous; 
 
 
 
if(*head == NULL){ 
 
printf("Linked List Empty, nothing to delete"); 
 
return; 
 
}  
 
 
if(temp->next == *head){ 
 
*head = NULL; 
 
return; 
 
} 
 
while (temp->next != *head) 
 
{ 
 
previous = temp; 
 
temp = temp->next; 
 
} 
 
previous->next = *head; 
 
free(temp); 
}  
 
 
void deletePos(struct Node** head, int n){ 
 
int size = calcSize(*head); 
 
if(n < 1 || size < n) 
 
{ 
 
printf("Can't delete, %d is not a valid position\n", n); 
 
} 
 
else if(n == 1) 
 
deleteFront(head); 
 
else if(n == size) 
 
deleteEnd(head); 
 
else 
 
{ 
 
struct Node* temp = *head; 
 
struct Node* previous; 
 
while (--n) 
 
{ 
 
previous = temp; 
 
temp = temp->next; 
 
} 
 
previous->next = temp->next; 
 
 
 
free(temp); 
 
} 
 } 
 
void insert(struct Node** head, int data) 
 { 
 
struct Node* newNode = (struct Node*) malloc(sizeof(struct 
Node)); newNode->data = data; 
 
 
if(*head == NULL){ 
 
*head = newNode; 
 
(*head)->next = *head; 
 
return; 
 
}  
 
 
struct Node* curr = *head; 
 
 
 
while(curr->next != *head){ 
 
curr = curr->next; 
 
}  
 
 
curr->next = newNode; 
 
newNode->next = *head; 
 
*head = newNode; 
 }  
 
 
int calcSize(struct Node* head){ 
 
int size = 0; 
 
struct Node* temp = head; 
 
 
 
if(temp == NULL) 
 
return size; 
 
 
 
do{ 
 
size++; 
 
temp = temp->next; 
 
 
 
}while(temp!=head); 
 
 
return size; 
 }  
 
 
void display(struct Node* head){ 
 
 
 
if(head == NULL) 
 
return; 
 
 
 
struct Node* temp = head; 
 
 
 
 
 
do{ 
 
printf("%d ", temp->data); 
 
temp = temp->next; 
 
 
 
}while(temp!=head); 
 
printf("\n"); 
 }  
 
 
int main(){ 
 
int n; 
 
 
 
struct Node* head = NULL; 
 
 
 
insert(&head,10); 
 
insert(&head,20); 
 
insert(&head,30); 
 
insert(&head,40); 
 
insert(&head,50); insert(&head,60); 
 
insert(&head,70); 
 
 
 
display(head); 
 
printf("delete at beiginin"); 
 
printf("\n"); 
 
 
 
deleteFront(&head); 
 
display(head); 
 
printf("delete at end"); 
 
printf("\n"); 
 
deleteEnd(&head);
 
display(head); 
 
deletePos(&head, 3); 
 
printf("delete at given position"); 
 
printf("\n"); 
 
 
 
display(head); 
 
 
 
return 0; 
 }
