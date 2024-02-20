#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//Queue dengan Single Linked List

char asg[30], course[15];
int dd, mm, yy;

struct Queue{
	char asg[30];
	char course[15];
	int dd, mm, yy;
	struct Queue *next;
} Queue;

bool isEmpty(struct Queue* front){
	return (front == NULL);
}

bool isOverflow(struct Queue *front, int max){
	struct Queue *ptr = front;
	
	if(isEmpty(front)) return false;
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

struct Queue *enqueue (struct Queue *front, char newAsg[30], char newCourse[15], int dd2, int mm2, int yy2){
	struct Queue *ptr;
	if(front == NULL){
		front = (struct Queue*)malloc(sizeof(struct Queue));
		strcpy(front->asg, newAsg);
		strcpy(front->course, newCourse);
		front->dd = dd2;
		front->mm = mm2;
		front->yy = yy2;
		front->next = NULL;
	}
	else{
		struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
		strcpy(newNode->asg, newAsg);
		strcpy(newNode->course, newCourse);
		newNode->dd = dd2;
		newNode->mm = mm2;
		newNode->yy = yy2;
		newNode->next = NULL;
		
		ptr = front;
		while(ptr->next != NULL) ptr = ptr->next;
		ptr->next = newNode;
	}
	
	return front;
};

struct Queue *dequeue(struct Queue *front){
	struct Queue *ptr = front;
	if(front == NULL) printf("--- No data to delete ----\n");
	else{
		ptr = front;
		front = front->next;
		printf("--- Data has been deleted. ---\n");
		free(ptr);
	}
	
	return front;
}

void viewData(struct Queue *front){
	struct Queue *ptr = front;
	int i=0;
	
	//if(front == NULL) printf("--- Data doesn't exist. ---\n");
	//else{
		//printf("                      --- Assignment List ---\n");
  printf("+=====+===============+==============================+================+\n");
	printf("| No. |    Due Date   |          Assignment          |     Course     |\n");
	printf("+=====+===============+==============================+================+\n");
		while(ptr != NULL){
			printf("|  %d. |  %2d/%2d/%2d   | %-28s | %-14s |\n", ++i, ptr->dd, ptr->mm, ptr->yy, ptr->asg, ptr->course);
			ptr = ptr->next;
		}
		printf("+=====+===============+==============================+================+\n");
	//}
}

void viewFrontRear(struct Queue *front){
	struct Queue *ptr = front;
	int i=0;
	
	//if(front == NULL) printf("--- Data doesn't exist. ---\n");
	//else{
		//printf("                      --- Assignment List ---\n");
	printf("+=====+===============+==============================+================+\n");
	printf("| No. |    Due Date   |          Assignment          |     Course     |\n");
	printf("+=====+===============+==============================+================+\n");
		while(ptr != NULL){
			if(ptr == front) printf("|  %d. |   %2d/%2d/%2d  | %-28s | %-14s | --> front\n", ++i, ptr->dd, ptr->mm, ptr->yy, ptr->asg, ptr->course);
			else if (ptr->next == NULL) printf("|  %d. |   %2d/%2d/%2d  | %-28s | %-14s | --> rear\n", ++i, ptr->dd, ptr->mm, ptr->yy, ptr->asg, ptr->course);
			else printf("|  %d. |   %2d/%2d/%2d  | %-28s | %-14s |\n", ++i, ptr->dd, ptr->mm, ptr->yy, ptr->asg, ptr->course);
			ptr = ptr->next;
		}
		printf("+=====+===============+==============================+================+\n");
	//}
}

int main(){
	struct Queue *queue = NULL;
	int max, n, menu=0;
	//GA MASUK KONSEP QUEUE
	
	printf("--------------------------------------------------------------------\n");
	printf("                             TO DO LIST\n");
	printf("--------------------------------------------------------------------\n\n");
	printf("Input queue's maximum capacity: "); scanf("%d", &max);
	
	do{
		system("cls");
		printf("--------------------------------------------------------------------\n");
		printf("                             TO DO LIST\n");
		printf("--------------------------------------------------------------------\n");
		//viewData(queue);
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display Table\n");
		printf("4. Display current front and rear position\n");
		printf("5. Exit\n\n");
		printf("Input Menu: "); scanf("%d", &n);
		
		switch(n){
			case 1:
				if(isOverflow(queue, max)) printf("--- Queue overflow. Please dequeue first. ---\n");
				else{
					printf("Input Due Date (DD/MM/YY): "); scanf("%d/%d/%d", &dd, &mm, &yy); getchar();
					printf("Input Assignment: "); gets(asg);
					printf("Input Course: "); gets(course);
					
					queue = enqueue(queue, asg, course, dd, mm, yy);
					printf("--- Data saved successfully. ---\n");
				}
				
				break;
			
			 case 2:
			 	queue = dequeue(queue);
			 	break;
			 	
			case 3:
				if(isEmpty(queue)) printf("--- Data doesn't exist. ---\n");
				else viewData(queue);
				
				break;
				
			case 4:
				if(isEmpty(queue)) printf("--- Data doesn't exist. ---\n");
				else viewFrontRear(queue);
				
				break;
		}
		puts("");
		system("pause");
		
	} while(n != 5);
	
	return 0;
}
