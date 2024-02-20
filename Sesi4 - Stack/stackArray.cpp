#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//using array

struct Node{
	char name[30];
	int score;
}Nd[100];

char name[30];
int score;
int max;

bool isEmpty(){
//	if(top == NULL)
//		return true
//	else
//		return false

	return (Nd[0].score == NULL);
}

bool isOverflow(int max){
	if(isEmpty()) return false;
	else{
		if(Nd[max-1].score != NULL){
			
			return true;
		}
		else
			return false;
	}
}

void push(char newName[30], int newScore){
	if(isEmpty()){	
		strcpy(Nd[0].name, newName);
		Nd[0].score = newScore;
	}
	else{
		for(int i=0;i<max;i++){
			if(Nd[i].score==NULL){
				strcpy(Nd[i].name, newName);
				Nd[i].score = newScore;
				return;
			}
		}
	}
	return;
}

void pop(){
	if(isEmpty()){
		printf("--- No Data to delete ---");
		return;
	}
	else{
		for(int i=max;i>=0;i--){
			if(Nd[i].score != NULL){
			strcpy(Nd[i].name, " ");
		Nd[i].score = NULL;
		printf("--- Data successfully deleted ---");
		return;
			}
		}	
	}
}

void peekTop(){
	for(int i=max;i>=0;i--){
		if(Nd[i].score != NULL){
	    printf("+--------------------------------+-------+\n");
	    printf("| %-30s | %4d  |\n", Nd[i].name, Nd[i].score);
    	printf("+--------------------------------+-------+\n");
    	return;
    }
  }
}

void display(){
	int i=max;
	int j=1;
	
	if(Nd[0].score == NULL) printf("--- Data doesn't exist---\n");
	else{
		printf("+-----+--------------------------------+-------+\n");
		for(int i=max;i>=0;i--){
			if(Nd[i].score != NULL){
        		if(i == max) printf("|  %d. | %-30s | %4d  | --> top\n",j++ , Nd[i].name, Nd[i].score);
				else printf("|  %d. | %-30s | %4d  |\n",j++ , Nd[i].name, Nd[i].score);
			}
		}
		
		printf("+=====+================================+=======+\n");
		printf("| No. |          Student Name          | Score |\n");
    	printf("+=====+================================+=======+\n");
	}
}

int main(){
	printf("Maximum capacity = ");
	scanf("%d", &max);
//	struct Node Nd[max+1]; //kalo begini harus tambah di func parameter.
	
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
		switch(menu){
			case 1:
				if(isOverflow(max)){
					printf("Stack Overflow\nPlease pop first!");
					getch();
					break;
				}
				else{
					printf("Input Name: "); getchar();
					scanf("%[^\n]s", name);
					printf("Input Score: ");
					scanf("%d", &score);
					push(name, score);
					printf("--- Data saved successfully ---");
					getch();
					break;
				}
			
			case 2:
				pop();
				getch();
				break;
			
			case 3:
				if(isEmpty())
					printf("--- Stack is empty! ---\n");
				else{
				peekTop();
				}
					getch();
				break;
			
			case 4:
				printf("\n");
				display();
				getch();
				break;
			
		}
	} while(menu != 5);
  
	return 0;
}
