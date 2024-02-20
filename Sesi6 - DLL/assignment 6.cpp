#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//Double Linked List

struct Node{
	char matkul[30];
	char konten[30];
	char deadline[30];
	struct Node *prev;
	struct Node *next;
};

struct Node *tail = NULL;
char matkul[30], konten[30], deadline[30];
int loc;

int size(struct Node *head){
	int count = 0;
	struct Node *ptr;
	ptr = head;
	if(loc<=1){
		return 1;
	}
	do{
		ptr = ptr->next;
		count++;
	}
	while(ptr != NULL);
	return count;
}

struct Node *pushHead(struct Node *head, char newMatkul[30], char newKonten[30], char newDeadline[30]){
	if(head == NULL){
		head = (struct Node*)malloc(sizeof(struct Node));
		strcpy(head->deadline, newDeadline);
		strcpy(head->konten, newKonten);
		strcpy(head->matkul, newMatkul);
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}
	else{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy(newNode->deadline, newDeadline);
		strcpy(newNode->konten, newKonten);
		strcpy(newNode->matkul, newMatkul);
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = NULL;
		
		head = newNode;
	}
	return head;
}

struct Node *pushTail(struct Node *head, char newMatkul[30], char newKonten[30], char newDeadline[30]){
	struct Node *ptr;
	ptr = head;
	if(head == NULL){
		head = (struct Node*)malloc(sizeof(struct Node));
		strcpy(head->deadline, newDeadline);
		strcpy(head->konten, newKonten);
		strcpy(head->matkul, newMatkul);
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}
	else{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy(newNode->deadline, newDeadline);
		strcpy(newNode->konten, newKonten);
		strcpy(newNode->matkul, newMatkul);
		newNode->next = NULL;
		while(ptr->next != NULL) ptr = ptr->next;
		ptr->next = newNode;
		newNode->prev = ptr;
	}
	return head;
}

struct Node *pushCustom(struct Node *head, int loc){
	
	int a = size(head);
	if(loc == 1){
		printf("Input Deadline: "); getchar();
	    scanf("%[^\n]", deadline);
	    printf("Input Assignment: "); getchar();
	    scanf("%[^\n]", konten);
	    printf("Input Subject: "); getchar();
	    scanf("%[^\n]", matkul);
	    		
	    head = pushHead(head,matkul, konten, deadline);
	    printf("--- Data saved successfully ---");
	}
	else if(loc == a+1){
		printf("Input Deadline: "); getchar();
	    scanf("%[^\n]", deadline);
	    printf("Input Assignment: "); getchar();
	    scanf("%[^\n]", konten);
	    printf("Input Subject: "); getchar();
	    scanf("%[^\n]", matkul);
	    		
	    head = pushTail(head, matkul, konten, deadline);
	    printf("--- Data saved successfully ---");
	}
	else if(loc <= 0 || loc > a){
		printf("--- Position Invalid. Please try again ---");
	}
	else if(loc > 0){
		struct Node *ptr;
		char newDeadline[30], newKonten[30], newMatkul[30];
		printf("Input Deadline: "); getchar();
	    scanf("%[^\n]", newDeadline);
	    printf("Input Assignment: "); getchar();
	    scanf("%[^\n]", newKonten);
	    printf("Input Subject: "); getchar();
	    scanf("%[^\n]", newMatkul);
	    	ptr= head;
	    for(int i=1; i<loc-1; i++){
	    	printf("tes");
	    	ptr = ptr->next;
		}
		 struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	    	strcpy(newNode->deadline, newDeadline);
			strcpy(newNode->konten, newKonten);
			strcpy(newNode->matkul, newMatkul);
			
			newNode->next = ptr->next;
			newNode->prev = ptr;
			ptr->next = newNode;
			ptr->next->prev = newNode;
			printf("--- Data saved successfully ---");
	}
	return head;
}

struct Node *popHead(struct Node *head){
	struct Node *ptr;
	
	if(head == NULL){
		printf("--- No data to delete ---");
	}
	else if(head->next == NULL){
		free(head);
		printf("--- Data deleted successfully ---");
		head = NULL;
	}
	else{
		ptr = head;
		head = head->next;
		free(ptr);
		printf("--- Data deleted successfully ---");
	}
	return head;
}

struct Node *popTail(struct Node *head){
	struct Node *ptr, *temp = head;
	
	if(head == NULL){
		printf("--- No data to delete ---");
	}
	else if(head->next == NULL){
		free(head);
		printf("--- Data deleted successfully ---");
		head = NULL;
	}
	else{
		while(temp->next != NULL) temp = temp->next;
		ptr = temp->prev;
		ptr->next = NULL;
		free(temp);
		printf("--- Data deleted successfully ---");
	}
	return head;
}

struct Node *popCustom(struct Node *head, int loc){
	int a = size(head);
	
	if(loc == 1) popHead(head);
	else if(loc == a+1) popTail(head);
	else if(loc <= 0 || loc > a) printf("--- Position Invalid ---\n");
	else if(loc>1){
		struct Node *ptr = head;
		for(int i=1; i<loc-1; i++) ptr = ptr->next;
		struct Node *del = ptr->next;
		ptr->next = ptr->next->next;
		ptr->prev->prev = del->prev;
		del->next = NULL;
		free(del);
		printf("--- Data deleted successfully ---");
	}
	return head;
}

void display(struct Node *head){
	struct Node *ptr;
	ptr = head;
	int i = 0;
	
	if(head == NULL){
		printf("--- No data ---\n\n");
	}
	else{
		printf("+=====+====================+=========================================+=====================+\n");
		printf("| No. |  Due Date 	   |               Assignment                |        Course       |\n");
		printf("+=====+====================+=========================================+=====================+\n");
		while(ptr != NULL){
			//	if(ptr == head && ptr->next == NULL) printf("|  %d. | %-15s    | %-33s       | %-12s	   | --> Front, Rear\n", ++i, ptr->deadline, ptr->konten, ptr->matkul);
			if(ptr == head) printf("|  %d. | %-15s    | %-33s       | %-12s	   | --> Front\n", ++i, ptr->deadline, ptr->konten, ptr->matkul);
			else if(ptr->next == NULL) printf("|  %d. | %-15s    | %-33s       | %-12s	   | --> Rear\n", ++i, ptr->deadline, ptr->konten, ptr->matkul);
			else printf("|  %d. | %-15s    | %-33s       | %-12s	   |\n", ++i, ptr->deadline, ptr->konten, ptr->matkul);
			ptr = ptr->next;
		}
		printf("+=====+====================+=========================================+=====================+\n");
	}
}

int main(){
	struct Node *head = NULL;
	int n, menu = 0;
	do{
		system("cls");
		printf("                		      --- Assignment List ---\n");
		display(head);
		printf("Menu:\n");
	    printf("1. Add a node at the beginning\n");
	    printf("2. Add a node at the end\n");
	    printf("3. Add a node at a specified position\n");
	    printf("4. Delete the first node\n");
	    printf("5. Delete the last node\n");
	    printf("6. Delete a node at a specified position\n");
	    printf("7. Display table data\n");
	    printf("8. Exit\n");
	    
	    choice:
	    	printf("\nInput choice: ");
	    	scanf("%d", &n);
	    	system("cls");
	    	
	    switch(n){
	    	case 1:
	    		printf("Input Deadline: "); getchar();
	    		scanf("%[^\n]", deadline);
	    		printf("Input Assignment: "); getchar();
	    		scanf("%[^\n]", konten);
	    		printf("Input Subject: "); getchar();
	    		scanf("%[^\n]", matkul);
	    		
	    		head = pushHead(head,matkul, konten, deadline);
	    		printf("--- Data saved successfully ---");
	    		
	    		break;
	    		
	    	case 2:
	    		printf("Input Deadline: "); getchar();
	    		scanf("%[^\n]", deadline);
	    		printf("Input Assignment: "); getchar();
	    		scanf("%[^\n]", konten);
	    		printf("Input Subject: "); getchar();
	    		scanf("%[^\n]", matkul);
	    		
	    		head = pushTail(head, matkul, konten, deadline);
	    		printf("--- Data saved successfully ---");
	    		
	    		break;
	    	
	    	case 3:
	    		printf("Input Position: "); 
	    		scanf("%d", &loc);
            	head = pushCustom(head, loc);
            	getch();
	    		break;
	    		
	    	case 4:
	    		head = popHead(head);
	    		getch();
	    		break;
	    		
	    	case 5:
	    		head = popTail(head);
	    		getch();
	    		break;
	    		
	    	case 6:
	    		printf("Input Position: "); 
	    		scanf("%d", &loc);
	    		head = popCustom(head, loc);
	    		getch();
	    		break;
	    		
	    	case 7:
	    		display(head);
	    		break;
	    		
	    	case 8:
	    		printf("--- Thank you ---");
	    		break;
	    		
	    	default:
	    		printf("Menu invalid. Please input valid menu.\n\n");
		}
	}
	while(n!=8);
		return 0;
}
