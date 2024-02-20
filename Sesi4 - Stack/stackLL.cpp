#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//using linked list

struct Node{
	char name[30];
	int score;
	struct Node *next;
};

char name[30];
int score;

bool isEmpty(struct Node* top){
//	if(top == NULL)
//		return true
//	else
//		return false

	return (top == NULL);
}

bool isOverflow(struct Node *top, int max){
	struct Node *ptr;
	ptr = top;
	if(isEmpty(top)) return false;
	else{
		int count = 1;
		while(ptr->next != NULL){
			count++;
			ptr = ptr->next;
		}
		if(count == max) return true;
		else return false;
    }
}

struct Node *push(struct Node *top, char newName[30], int newScore){
	if(isEmpty(top)){
		top = (struct Node*)malloc(sizeof(struct Node));
		strcpy(top->name, newName);
		top->score = newScore;
		top->next = NULL;
	}
	else{
		struct Node *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy(newNode->name, newName);
		newNode->score = newScore;
		newNode->next = top;
		top = newNode;
	}
  
	return top;
}

struct Node* pop(struct Node *top){
	if(isEmpty(top)) printf("--- No Data to delete ---");
	else if(isEmpty(top->next)){
		free(top);
		top = NULL;
		printf("--- Data successfully deleted ---");
	}
	else{
		struct Node* ptr;
		ptr = top;
		top = ptr->next;
		free(ptr);
		printf("--- Data successfully deleted ---");
	}
  
	return top;
}

int peekTop(struct Node *top){
	struct Node *ptr = top;
	printf("+--------------------------------+-------+\n");
	printf("| %-30s | %4d  |\n", ptr->name, ptr->score);
	printf("+--------------------------------+-------+\n");
}

void display(struct Node *top){
	struct Node *ptr = top;
	int i=0;
	
	if(top == NULL) printf("--- Data doesn't exist---\n");
	else{
		printf("              ---STUDENT LIST---\n");
		printf("+-----+--------------------------------+-------+\n");
		while(ptr != NULL){
			if(ptr == top) printf("|  %d. | %-30s | %4d  | --> top \n", ++i, ptr->name, ptr->score);
			else printf("|  %d. | %-30s | %4d  |\n", ++i, ptr->name, ptr->score);
      		ptr = ptr->next;
		}
		
		printf("+=====+================================+=======+\n");
		printf("| No. |          Student Name          | Score |\n");
		printf("+=====+================================+=======+\n");
	}
}

int main(){
	struct Node *top;
	top = NULL;
	int max;
	printf("Maximum capacity = ");
	scanf("%d", &max);
	
	int menu;
	do{
		system("cls");
		printf("1. Push data\n");
		printf("2. Pop data\n");
		printf("3. Peek data\n");
		printf("4. View All data\n");
		printf("5. Exit\n");
		scanf("%d",&menu);
		system("cls");
		switch(menu)
		{
			case 1:
				if(isOverflow(top, max)){
					printf("Stack Overflow\nPlease pop first!");
					getch();
					break;
				}
				else
				{
					printf("Input Name: "); getchar();
					scanf("%[^\n]s", name);
					printf("Input Score: ");
					scanf("%d", &score);
					top = push(top, name, score);
					printf("--- Data saved successfully ---");
					getch();
					break;
				}
      
			case 2:
				top = pop(top);
				getch();
				break;
			
			case 3:
				if(isEmpty(top))
					printf("--- Stack is empty! ---");
				else
				{
					int dataTop = peekTop(top);
				}
					getch();
				break;
			
			case 4:
				printf("\n");
				display(top);
				getch();
				break;	
		}
	} while(menu != 5);
	
  return 0;
}
