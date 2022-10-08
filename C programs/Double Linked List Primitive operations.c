#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node* next;
	struct node* prev;
};

struct node* start = NULL;

void InsertAnyPos(){
    int i, pos, c=0;
    struct node *temp, *nw;
    printf("Enter the position where you want to insert\n");
    scanf("%d", &pos);
    for(temp = start; temp!=NULL; temp = temp -> next)
    c++;
    if(pos>c+1)
    printf("Invalid Position");
    else{
        nw= (struct node *)malloc(sizeof(struct node));
        if(nw==NULL)
        printf("Can't allocate memory\n");
        else{
            nw->next=NULL;
            nw->prev=NULL;
            printf("Enter the info part: ");
            scanf("%d", &nw->info);
            if(pos==1){
                if(start!=NULL){
                    nw->next=start;
                    start->prev=nw;
                }
                start=nw;
            }
            else if(pos==c+1){
                for(temp=start; temp->next!=NULL; temp=temp->next);
                temp->next=nw;
                nw->prev=temp;
            }
            else{
                for(temp = start, i=1; i<pos-1; temp=temp->next, i++)
                nw->next = temp->next;
                (temp->next)->prev=nw;
                nw->prev=temp;
                temp->next=nw;
            }
        }
    }
}

void traverse()
{
	struct node* temp;

	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->next;
		}
	}
}
void deleteFirst(){
    struct node *temp;
    if(start==NULL)
    printf("List is empty: Underflow\n");
    else if(start->next==NULL){
        temp=start;
        start=NULL;
        free(temp);
        printf("\nFirst node deleted successfully\n");
    }
    else{
        temp=start;
        start = start->next;
        (temp->next)->prev=NULL;
        temp->next=NULL;
        free(temp);
        printf("\nFirst node deleted successfully\n");

    }
}

void deleteLast(){
    struct node *temp;
    if(start==NULL)
    printf("List is empty: Underflow\n");
    else if(start->next==NULL){
        temp=start;
        start=NULL;
        free(temp);
        printf("\nLast node deleted successfully\n");
    }
    else{
        for(temp=start; temp->next!=NULL; temp=temp->next);
        (temp->prev)->next=NULL;
        temp->prev=NULL;
        free(temp);
        printf("\nLast node deleted successfully\n");

    }
}

void deleteAnyPos(){
    int i, pos, c=0;
    struct node *temp;
    if(start==NULL){
        printf("Underflow");
    }
    else{
    printf("Enter the position where you want to insert\n");
    scanf("%d", &pos);
    }
    for(temp = start; temp!=NULL; temp = temp -> next)
    c++;
    if(pos>c+1)
    printf("Invalid Position");
    else if(pos==1){
        deleteFirst();
    }
    else if(pos==c+1){
        deleteLast();
    }
    else{
        for(i=1, temp=start; i<pos; temp=temp->next, i++);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}

int main()
{
	int choice;
	while (1) {
		printf("\n1 To print the list\n");
		printf("2 For insertion at any position\n");
		printf("3 For Deletion of First Node\n");
		printf("4 For Deletion of Last Node\n");
		printf("5 For Deletion at Any Position\n");
		printf("8 Exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
		InsertAnyPos();
		break;
		case 3:
		deleteFirst();
		break;
		case 4:
		deleteLast();
		break;
		case 5:
		deleteAnyPos();
		break;
		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}



