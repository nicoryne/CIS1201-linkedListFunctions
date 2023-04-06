#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}Node;

void displayNodes(Node* head, Node* current);
void insertRear(Node* head, int value);
void insertFront(Node **head, Node **current, int value);
void insertInto(Node **head, Node **current, int value, int pos);
void deleteFront(Node **head, Node **current);
void deleteRear(Node **head, Node **current);
void deleteInto(Node **head, Node **current, int pos);
void deleteValue(Node **head, Node **current, int value);
int main(){
	int option, user_input, pos;
	int i = 0;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* node2 = (Node*)malloc(sizeof(Node));
	Node* node3 = (Node*)malloc(sizeof(Node));
	
	head->data = 10;
	node2->data = 20;
	node3->data = 30;
	
	head->link = node2;
	node2->link = node3;
	node3->link = NULL;
	
	Node* current = (Node*)malloc(sizeof(Node));
	
	current = head;	
call_options:
	printf("Current Nodes: ");
	displayNodes(head,current);
	printf("\n");
	printf("===========================================\n");
	printf("1 | Insert Rear\n");
	printf("2 | Insert Front\n");
	printf("3 | Insert Into\n");
	printf("4 | Delete Rear\n");
	printf("5 | Delete Front\n");
	printf("6 | Delete Into\n");
	printf("7 | Delete Value\n");
	printf("8 | Exit Program\n");
	scanf("%d", &option);

switch(option){
	case 1:
		system("cls");
		printf("INSERTING VALUE TO REAR\n");
		printf("===========================================\n");
		printf("Please input value: ");
		scanf("%d", &user_input);
		insertRear(head, user_input);
		system("cls");
		goto call_options;
	case 2:
		system("cls");
		printf("INSERTING VALUE TO FRONT\n");
		printf("===========================================\n");
		printf("Please input value: ");
		scanf("%d", &user_input);
		insertFront(&head, &current, user_input);
		system("cls");
		goto call_options;
	case 3:
		system("cls");
		printf("INSERTING VALUE TO INTO\n");
		printf("===========================================\n");
		printf("Please input value: ");
		scanf("%d", &user_input);
		printf("Please input a position: ");
		scanf("%d", &pos);
		insertInto(&head, &current, user_input, pos);
		system("cls");
		goto call_options;
	case 4:
		system("cls");
		deleteRear(&head, &current);
		system("cls");
		goto call_options;
	case 5:
		system("cls");
		deleteFront(&head, &current);
		system("cls");
		goto call_options;
	case 6:
		system("cls");
		printf("DELETING INTO\n");
		printf("===========================================\n");
		printf("Please input a position: ");
		scanf("%d", &pos);
		deleteInto(&head, &current, pos);
		system("cls");
		goto call_options;
	case 7:
		system("cls");
		printf("DELETING VALUES\n");
		printf("===========================================\n");
		printf("Please input a value: ");
		scanf("%d", &user_input);
		deleteValue(&head,&current,user_input);
		system("cls");
		goto call_options;
	case 8:
		system("cls");
		break;
	default:
		system("cls");
		printf("PLEASE INPUT VALID NUMBER!\n");
		goto call_options;
}	

}
void displayNodes(Node* head, Node* current){
	int i;
	while(current!=NULL){
		printf("Value[%d]: %d\t", i+1, current->data);
		current = current->link;
		i++;
	}
	
}
void insertRear(Node* head, int value){
	Node* temp = (Node*)malloc(sizeof(Node));
	
	temp->data = value;
	temp->link = NULL;
	
	Node *current = (Node*)malloc(sizeof(Node));
	current = head;
	
	while(current->link != NULL){
		current = current->link;
	}
	
	current->link = temp;
}

void insertFront(Node** head, Node** current, int value){
	Node* temp = (Node*)malloc(sizeof(Node));
	
	temp->data = value;
	
	temp->link = *head;
	
	*head = temp;
	*current = *head;
}

void insertInto(Node** head, Node** current, int value, int pos){
	int i = 0;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	
	Node* temp = *head;
	
	for(i = 2; i < pos && temp->link!=NULL; i++){
		temp = temp->link;
	}
	
	newNode->link = temp->link;
	temp->link = newNode;
	
	*current = *head;	
}

void deleteFront(Node **head, Node **current){
	Node *temp = *head;
	*head = (*head)->link;
	free(temp);
	
	*current = *head;
}

void deleteRear(Node **head, Node **current){
	Node *temp = *head;
	
	while(temp->link->link!=NULL){
		temp = temp->link;
	}
	
	free(temp->link);
	temp->link = NULL;
	
	*current = *head;
}
void deleteInto(Node**head, Node**current, int pos){
	int i = 0;
	Node *temp = *head;
	Node *nextNode = temp->link->link;
	
	for(i = 2; i < pos && temp->link->link!=NULL; i++){
		temp = temp->link;
	}
	
	free(temp->link);
	temp->link = nextNode;
	
	*current = *head;
}

void deleteValue(Node **head, Node **current, int value){
    Node *temp = *head;
    Node *prevNode = NULL;
    
    if(temp->data == value){
        *head = temp->link;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != value){
        prevNode = temp;
        temp = temp->link;
    }
    
    if(temp == NULL){
        return;
    }
    
    prevNode->link = temp->link;
    free(temp);
    
    *current = *head;
}
