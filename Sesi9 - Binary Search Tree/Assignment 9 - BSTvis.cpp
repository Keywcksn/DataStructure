#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	char matkul[30];
	char konten[30];
	char deadline[30];
	struct Node *left;
	struct Node *right;
};

char newMatkul[30], newKonten[30], newDeadline[30];

struct Node *newNode(char matkul[30], char konten[30], char deadline[30]){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(node->deadline, newDeadline);
	strcpy(node->matkul, newMatkul);
	strcpy(node->konten, newKonten);
	
	node->left = NULL;
	node->right = NULL;
	
	printf("\n--- Data successfully added. ---\n\n");
	
	return node;
}

struct Node *addNode(struct Node *node, char matkul[30], char konten[30], char deadline[30], int maxHeight){
	int height = 1;
	
	if(node == NULL){
		node = newNode(matkul, konten, deadline);
	}
	
	else if(height >= maxHeight){
		printf("--- Maximum height reached ---");
		return node;
	}
		
	else if(strcmp(konten, node->konten) < 0){
		node->left = addNode(node->left, newMatkul, newKonten, newDeadline, maxHeight);
		height++;
	}
		
	else if(strcmp(konten, node->konten) > 0){
		node->right = addNode(node->right, newMatkul, newKonten, newDeadline, maxHeight);
		height++;
	}
	return node;
}

struct Node *minValueNode(struct Node *node){
	struct Node *temp = node;
	
	while(temp != NULL && temp->left != NULL)
		temp = temp->left;
		
	return temp;
}

struct Node *delNode(struct Node *node, char key[30]){
	if(node == NULL){
		printf("--- Key not found. ---\n");
		return node;
	}
	else if(strcmp(key, node->konten) < 0)
		node->left = delNode(node->left, key);
		
	else if(strcmp(key, node->konten) > 0)
		node->right = delNode(node->right, key);
		
	else if(node->left == NULL){
		struct Node *temp = node->right;
		free(node);
		
		return temp;
	}
	else if(node->right == NULL){
		struct Node *temp = node->left;
		free(node);
		
		return temp;
	}
	else{
		struct Node *temp = minValueNode(node->right);
		
		strcpy(node->deadline, temp->deadline);
		strcpy(node->matkul, temp->matkul);
		strcpy(node->konten, temp->konten);
		
		node->right = delNode(node->right, temp->deadline);
	}
};

void preOrder(struct Node *node){
	if(node != NULL){
		printf("| %-15s    | %-33s       | %-14s	     |\n", node->deadline, node->konten, node->matkul);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(struct Node *node){
	if(node != NULL){
		inOrder(node->left);
		printf("| %-15s    | %-33s       | %-14s	     |\n", node->deadline, node->konten, node->matkul);
		inOrder(node->right);
	}
}

void postOrder(struct Node *node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("| %-15s    | %-33s       | %-14s	     |\n", node->deadline, node->konten, node->matkul);
	}
}

void printVisual(struct Node *root, int space){
	int COUNT = 3;
	if(root == NULL){
		return;
	}
	space += COUNT;
	printVisual(root->right, space);
	printf("\n");
	
	for(int i = COUNT; i<space; i++){
		printf("  ");
	}
	printf("%s\n", root->matkul);
	printVisual(root->left, space);
}

void print2d(struct Node *root){
	printVisual(root, 0);
}

int main(){
	struct Node *root = NULL;
	int maxHeight = 3;
	int menu;
	
	do{
		system("cls");
		print2d(root);
		printf("\n");
		printf("1. Add data\n");
		printf("2. Delete data\n");
		printf("3. View data by PreOrder transversal\n");
		printf("4. View data by InOrder transversal\n");
		printf("5. View data by PostOrder transversal\n");
		printf("6. Exit\n\n");
		printf("Choice: "); scanf("%d", &menu);
		
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
				system("pause");
				
				break;
			}
			
			case 2:{
				char del[30];
				printf("Input assignment to delete: "); scanf("%s", del);
				
				root = delNode(root, del);
				system("pause");
				
				break;
			}
			
			case 3:{
				printf("+====================+=========================================+=====================+\n");
				printf("|      Due Date	     |               Assignment                |        Course       |\n");
				printf("+====================+=========================================+=====================+\n");
				preOrder(root);
				printf("+====================+=========================================+=====================+\n");
				system("pause");
				
				break;
			}
			
			case 4:{
				printf("+====================+=========================================+=====================+\n");
				printf("|      Due Date	     |               Assignment                |        Course       |\n");
				printf("+====================+=========================================+=====================+\n");
				inOrder(root);
				printf("+====================+=========================================+=====================+\n");
				system("pause");
				
				break;
			}
			
			case 5:{
				printf("+====================+=========================================+=====================+\n");
				printf("|      Due Date	     |               Assignment                |        Course       |\n");
				printf("+====================+=========================================+=====================+\n");
				postOrder(root);
				printf("+====================+=========================================+=====================+\n");
				system("pause");
				
				break;
			}
		}
	} while(menu != 6);
	
	return 0;
}
