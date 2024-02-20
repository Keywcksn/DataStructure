#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node{
	char matkul[30];
	char konten[30];
	char deadline[30];
	struct Node *left;
	struct Node *right;
};

char newMatkul[30], newKonten[30], newDeadline[30];

//alokasi node baru
struct Node *newNode(char matkul[30], char konten[30], char deadline[30]){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(node->deadline, newDeadline);
	strcpy(node->matkul, newMatkul);
	strcpy(node->konten, newKonten);
	node->right = NULL;
	node->left = NULL;
	
	printf("--- Data saved successfully ---");
	return node;
}

//masukkin data baru
struct Node *addNode(struct Node *root, char matkul[30], char konten[30], char deadline[30], int maxHeight){
	if(root == NULL){
		root = newNode(matkul, konten, deadline);
	}
	else{
		struct Node *temp, *pretemp;
		int height = 1;
		int RL;
		temp = root;
		
		while(temp != NULL){
			if(height>=maxHeight){
				printf("--- Maximum height reached ---");
				return root;
			}
			printf("Insert new data in:\n");
			printf("1. Left\n");
			printf("2. Right\n");
			printf("Your answer: ");
			scanf("%d", &RL);
			
			switch(RL){
				case 1:{
					pretemp = temp;
					temp = temp->left;
					if(temp == NULL){
						pretemp->left = newNode(matkul, konten, deadline);
					}
					height++;
					break;
				}
				case 2:{
					pretemp = temp;
					temp = temp->right;
					if(temp == NULL){
						pretemp->right = newNode(matkul, konten, deadline);
					}
					height++;
					break;
				}
				default:{
					printf("--- Input Invalid. Please enter the available choice ---\n");
					break;
				}
			}
		} 
	}
	return root;
}

struct Node *delAll(struct Node *node){
	if(node != NULL){
		delAll(node->left);
		delAll(node->right);
		free(node);
		return NULL;
	}
}

struct Node *delNode(struct Node *temp, struct Node *pretemp, char matkul[30]){
	if(temp != NULL){
		if(strcmp(temp->matkul,matkul)==0){
			if(pretemp == temp)
				pretemp = delAll(temp);
			else if(pretemp->left->matkul == temp->matkul)
				pretemp->left = delAll(temp);
			else 
				pretemp->right = delAll(temp);
				
			printf("--- Data deleted successfully ---");
		}
		else{
			delNode(temp->left, temp, matkul);
			delNode(temp->right, temp, matkul);
		}
	}
	return pretemp;
}

void inOrder(struct Node *node){
	if(node != NULL){
		inOrder(node->left);
		printf("| %-15s    | %-33s       | %-14s	     |\n", node->deadline, node->konten, node->matkul);
		inOrder(node->right);
	}
}

void preOrder(struct Node *node){
	if(node != NULL){
		printf("| %-15s    | %-33s       | %-14s	     |\n", node->deadline, node->konten, node->matkul);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void postOrder(struct Node *node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("| %-15s    | %-33s       | %-14s	     |\n", node->deadline, node->konten, node->matkul);
	}
}

int main(){
	struct Node *root;
	root = NULL;
	int maxHeight = 4;
	int menu;
	do{
		system("cls");
		printf("1. Add data\n");
		printf("2. Delete a data\n");
		printf("3. View data by inOrder traversal\n");
		printf("4. View data by preOrder traversal\n");
		printf("5. View data by postOrder traversal\n");
		printf("6. exit\n");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:{
				system("cls");
				printf("Input Matkul: "); getchar();
				scanf("%[^\n]", newMatkul);
				printf("Input Assignment: "); getchar();
				scanf("%[^\n]", newKonten);
				printf("Input Deadline: "); getchar();
				scanf("%[^\n]", newDeadline);
				
				root = addNode(root, newMatkul, newKonten, newDeadline, maxHeight);
				getch();
				
				break;
			}
			case 2:{
			 	char delMatkul[30];
			 	printf("Input matkul you want to delete: ");getchar();
			 	scanf("%[^\n]", delMatkul);
			 	root = delNode(root, root, delMatkul);
			 	getch();
				break;
			}
			case 3:{
				printf("+====================+=========================================+=====================+\n");
				printf("|  Due Date 	     |               Assignment                |        Course       |\n");
				printf("+====================+=========================================+=====================+\n");
				inOrder(root);
				printf("+====================+=========================================+=====================+\n");
				getch();
				break;
			}
			case 4:{
				printf("+====================+=========================================+=====================+\n");
				printf("|  Due Date 	     |               Assignment                |        Course       |\n");
				printf("+====================+=========================================+=====================+\n");
				preOrder(root);
				printf("+====================+=========================================+=====================+\n");
				getch();
				break;
			}
			case 5:{
				printf("+====================+=========================================+=====================+\n");
				printf("|  Due Date 	     |               Assignment                |        Course       |\n");
				printf("+====================+=========================================+=====================+\n");
				postOrder(root);
				printf("+====================+=========================================+=====================+\n");
				getch();
				break;
			}
		}
	}
	while(menu != 6);
	return 0;
}
