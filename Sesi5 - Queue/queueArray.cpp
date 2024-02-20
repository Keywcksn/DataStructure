#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

//Queue dengan Array

int front=0, rear=0,a=0,size=0;
struct Queue{

	char matkul[30];
	char konten[30];
	int dd, mm, yy;
};

bool isUnderflow(int max,struct Queue *assgn){
	a=0;
	return (assgn[front].dd == NULL);
}

bool isOverflow(int max,struct Queue *assgn){

	
	if(isUnderflow(max, assgn)){
		return false;
	}
	else{
		if(size==0){
			return true;
		}
		else{
			return false;
		}
	}
}

void enqueue(struct Queue *assgn, char newMatkul[30], char newKonten[30], int newDD, int newMM, int newYY, int max){
 	size--;
 	strcpy(assgn[rear].matkul, newMatkul);
	strcpy(assgn[rear].konten, newKonten);
	assgn[rear].dd = newDD;
	assgn[rear].mm = newMM;
	assgn[rear].yy = newYY;
	rear= (rear+1)%(max);
			
	return;
}

void dequeue(struct Queue *assgn, int max){

	if(isUnderflow(max, assgn)){
		printf("--- No data to delete ---");
		return;
	}
	else{	
		strcpy(assgn[front].matkul, " ");
		strcpy(assgn[front].konten, " ");
		assgn[front].dd = NULL;
		assgn[front].mm = NULL;
		assgn[front].yy = NULL;
		front=(front+1)%(max);
		//rear=(rear-1)%max;
		printf("--- Data deleted successfully ---");
		a++;
		size++;
		return;
	}
}

void viewfrontrear(int max, struct Queue *assgn){
	printf("\n");
	printf("Front = | %2d/%2d/%2d  | %-28s | %-14s |\n", assgn[front].dd, assgn[front].mm, assgn[front].yy, assgn[front].konten, assgn[front].matkul);
	printf("Rear  = | %2d/%2d/%2d  | %-28s | %-14s |\n", assgn[max-1].dd, assgn[max-1].mm, assgn[max-1].yy, assgn[max-1].konten, assgn[max-1].matkul);
}

void viewData(int max, struct Queue *assgn){
	if(assgn[front].dd == NULL){
		printf("--- No data ---\n\n");
	}
	else{
		printf("+=====+===============+==============================+================+\n");
		printf("| No. |    Due Date   |          Assignment          |     Course     |\n");
		printf("+=====+===============+==============================+================+\n");

		for(int i=0;i<max; i++){
			if(assgn[i].dd != NULL) printf("|  %d. |  %2d/%2d/%2d   | %-28s | %-14s |\n", i+1-a, assgn[i].dd, assgn[i].mm, assgn[i].yy, assgn[i].konten, assgn[i].matkul);
		}
		printf("+=====+===============+==============================+================+\n");
	}
} 

int main(){
	int max;
	printf("Maximum Capacity = ");
	scanf("%d", &max);
	size=max;
	struct Queue assgn[max+1];
	memset(assgn, 0, sizeof(assgn));
	system("cls");
	int menu;
	do{
		system("cls");
		printf("--- TO DO LIST ---\n");
		viewData(max,assgn);
		printf("1. Enqueue \n");
		printf("2. Dequeue \n");
		printf("3. See Front & Rear\n");
		printf("4. View all data\n");
		printf("5. exit\n");
		printf("\nInput menu: ");
		scanf("%d",&menu);
		system("cls");
		
		switch(menu){
			case 1:
				int dd, mm, yy;
				char matkul[30];
				char konten[30];
				if(isOverflow(max, assgn)){
				printf("Data Overflow!");
				getch();
				break;
				}
				printf("Input Deadline (DD/MM/YYYY): ");
				scanf("%d/%d/%d", &dd, &mm, &yy);
				printf("Input Subject: "); getchar();
				scanf("%[^\n]", matkul); getchar();
				printf("Input Content: "); 
				scanf("%[^\n]", konten);
				enqueue(assgn,matkul, konten, dd, mm, yy, max);
				printf("--- Data saved successfully ---\n");
			//	getchar();
				break;
				
			case 2:
				if(isUnderflow(max, assgn)){
					printf("--- No data ---\n");
					break;
				}
				else{
					dequeue(assgn, max);
					break;
				}
				
			case 3:
				viewfrontrear(max, assgn);
				getch();
				break;
				
			case 4:
				printf("\n");
				viewData(max, assgn);
				break;		
		}
	}
	while(menu != 5);
	return 0;
}
