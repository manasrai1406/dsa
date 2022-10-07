/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h> 
 
#include<stdlib.h> 
 
struct Node 
 
{  
int data; 
 
struct Node *next; 
 
}; 
 
int calcSize(struct Node* head); 
 
 
 
void insertFront(struct Node** head, int data) 
 
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
 
 
void insertEnd(struct Node** head, int data){ 
 
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
 
newNode->data = data; 
 
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
 } 
 
void insertAfterPosition(int pos, int data, struct Node** head) 
 { 
 
int size = calcSize(*head); 
 
 
 
if(pos < 0 || size < pos) { 
 
printf("Can't insert, %d is not a valid position\n",pos); 
 
} 
 
else if(pos == 0) 
 
insertFront(head, data); 
 
else 
{ 
struct Node* newNode = (struct Node*) malloc(sizeof(struct 
Node)); newNode->data = data; 
 
 
struct Node* temp = *head; 
 
while(--pos) 
 
temp = temp->next; 
 
newNode->next= temp->next; 
 
temp->next = newNode; 
 
 
 
} 
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
 
 
void display(struct Node* head) 
 
{ 
if(head == NULL) 
return; 
 
struct Node* temp = head; 
 
do{ 
 
printf("%d ", temp->data); 
 
temp = temp->next; 
 
 
 
}while(temp!=head); 
 
printf("\n"); 
 } 
 
int main() 
 { 
 
struct Node* head = NULL; 
 
insertFront(&head,200); 
 
insertFront(&head,100); 
 
display(head); 
 
insertEnd(&head, 300); 
 
insertEnd(&head, 4000); 
 
display(head); 
 
insertAfterPosition(3,0,&head);
 
display(head); 
 
return 0; 
 }  
