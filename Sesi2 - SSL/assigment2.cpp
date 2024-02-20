#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char name[30];
int num, score;
int loc;
    
typedef struct Student{
	char name[30];
	int num;
	int score;
	struct Student *next;
} Student;

struct Student *createStart(struct Student *head, char newName[30], int newNum, int newScore){
	if(head==NULL){
		head = (struct Student*)malloc(sizeof(struct Student));
		strcpy(head->name, newName);
		head->num = newNum;
		head->score = newScore;
		head->next = NULL;
	}
	else{
		Student *newNode = (struct Student*)malloc(sizeof(struct Student));
		strcpy(newNode->name, newName);
		newNode->num = newNum;
		newNode->score = newScore;
		newNode->next = head;
		head = newNode;
	}
	
	return head;
}

struct Student *createEnd(struct Student *head, char newName[30], int newNum, int newScore){
	struct Student *ptr;
	if(head==NULL){
		head = (struct Student*)malloc(sizeof(struct Student));
		strcpy(head->name, newName);
		head->num = newNum;
		head->score = newScore;
		head->next = NULL;
	}
	else{
		Student *newNode = (struct Student*)malloc(sizeof(struct Student));
		strcpy(newNode->name, newName);
		newNode->num = newNum;
		newNode->score = newScore;
		newNode->next = NULL;
		ptr = head;
		while(ptr->next != NULL) ptr = ptr->next;
		ptr->next = newNode;
	}
	
	return head;
}

int size(Student *head){
	int count=0;
	while(head != NULL){
		head = head->next;
		count++;
	}
	
	return count;
}

struct Student *createCustom(struct Student *head, int loc){
	int a = size(head);
	
	if(loc==1){
		getchar();
		printf("Input Name: "); gets(name);
		printf("Input Roll Number: "); scanf("%d", &num);
		printf("Input Score: "); scanf("%d", &score);
		
		head = createStart(head, name, num, score);
		printf("---Data saved successfully.---\n");
	}
	else if(loc==a+1){
		getchar();
		printf("Input Name: "); gets(name);
		printf("Input Roll Number: "); scanf("%d", &num);
		printf("Input Score: "); scanf("%d", &score);
		
		head = createEnd(head, name, num, score);
		printf("---Data saved successfully.---\n");
	
	}
	else if(loc <=0 || loc>a){
		printf("---Position Invalid. Please try again---\n");
		//goto position;
	}
	else if(loc>0){
		char name[30];
		int num, score;
		
		getchar();
		printf("Input Name: "); gets(name);
		printf("Input Roll Number: "); scanf("%d", &num);
		printf("Input Score: "); scanf("%d", &score);
		
		for(int i=1;i<loc-1;i++) head = head->next;
		Student *newNode = (Student*)malloc(sizeof(Student));
		strcpy(newNode->name, name);
		newNode->num = num;
		newNode->score = score;
		
		newNode->next = head->next;
		head->next = newNode;
		printf("---Data saved successfully.---\n");
	}
	
	return head;
}

struct Student *delStart(struct Student *head){
	struct Student *ptr = head;
	
	if(head == NULL){
		printf("--- No data to delete.---\n");
	}
	else{
		ptr = head;
		head = head->next;
		printf("---Data %d has been deleted.---\n", ptr->num);
		free(ptr);
	}
	
	return head;
}

struct Student *delEnd(struct Student *head){
	struct Student *ptr = head, *preptr;;
	
	if(head == NULL){
		printf("--- No data to delete.---\n");
	}
	else{ //cek data 1 ato lebih
		while(ptr->next != NULL){
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
		
		printf("---Data %d has been deleted.---\n", ptr->num);
		free(ptr);
	}
	
	return head;
}

struct Student *delLoc(struct Student *head, int loc){
	int a = size(head);   //ga reliable; pake ptr loop sampe akhir
	
	if(loc==1){
		head = delStart(head);
	}
	else if(loc==a+1){
		delEnd(head);
	}
	else if(loc <=0 || loc>a){
		printf("---Position Invalid. Please try again---\n");
		//goto position;
	}
	else if(loc>1){
		struct Student *ptr = head;
		for(int i=1;i<loc-1;i++) ptr = ptr->next;
		
		struct Student *del = ptr->next;
		ptr->next = ptr->next->next;
		printf("---Data %d has been deleted.---\n", del->num);
		del->next = NULL;
		
		free(del);
	}
	
	return head;
}

struct Student *delSpec(struct Student *head, int node){
	struct Student *ptr, *preptr;
	
	if(head==NULL){
		printf("---No data to delete.---\n");
		return head;
	}
	else{
		ptr = head;
		if(ptr->num == node){
			head = delStart(head);
			return head;
		}
		else{
			while(ptr->num != node){
				preptr = ptr;
				ptr = ptr->next;
			}
			
			preptr->next = ptr->next;
			printf("---Data %d has been deleted.---\n", node);
			free(ptr);
			
			return head;
		}
	}
}

/*
struct Student* delSpec(struct Student* head, int newInput){
	struct Student* ptr = head;
	
	if(head==NULL){
		printf("---No data to delete.---\n");
		return head;
	}
	if(head->next == NULL && head->num != newInput){
		printf("---Data %d doesn't exist.---\n", newInput);
		return head;
	}
	if(head->next == NULL && head->num == newInput){
		printf("---Data %d has been deleted.---\n", newInput);
		free(ptr);
		head = NULL;
		return head;
	}
	if(head->next != NULL){
		while(ptr->num != newInput) ptr = ptr->next;
		free(ptr);
		printf("---Data %d has been deleted.---\n", newInput);
		return head;
	}
}
*/

void display(struct Student *head){
	struct Student *ptr = head;
	int i=0;
	
	if(head == NULL) printf("---Data doesn't exist.---\n");
	else{
		printf("+-----+--------------------------------+-------------+-------+\n");
		printf("| No. |          Student Name          | Roll Number | Score |\n");
		printf("+-----+--------------------------------+-------------+-------+\n");
		while(ptr != NULL){
			printf("|  %d. | %-30s | %7d     | %4d  |\n", ++i, ptr->name, ptr->num, ptr->score);
			ptr = ptr->next;
		}
		printf("+-----+--------------------------------+-------------+-------+\n");
	}
}

int main(){
	struct Student *head = NULL;
    int n, menu=0;     	
    
    do{
    	system("cls");
    	printf("--- Student List ---\n\n");
    	display(head);
	    printf("Menu:\n");
	    printf("1. Add a node at the beginning\n");
	    printf("2. Add a node at the end\n");
	    printf("3. Add a node at a specified position\n");
	    printf("4. Delete the first node\n");
	    printf("5. Delete the last node\n");
	    printf("6. Delete a node at a specified position\n");
	    printf("7. Delete a specific node\n");
	    printf("8. Display table data\n");
	    printf("9. Exit\n");
	    choice:
       		printf("\nInput choice: "); scanf("%d", &n);

        switch(n){
            case 1:
            	getchar();
				printf("Input Name: "); gets(name);
				printf("Input Roll Number: "); scanf("%d", &num);
				printf("Input Score: "); scanf("%d", &score);
				
				head = createStart(head, name, num, score);
				printf("---Data saved successfully.---\n");
				
                break;

            case 2:
            	getchar();
				printf("Input Name: "); gets(name);
				printf("Input Roll Number: "); scanf("%d", &num);
				printf("Input Score: "); scanf("%d", &score);
				
				head = createEnd(head, name, num, score);
				printf("---Data saved successfully.---\n");
				
                break;
            
            case 3:
				getchar();
				printf("Input Position: "); scanf("%d", &loc);
            	head = createCustom(head, loc);
            	
            	
            	break;
            	
            case 4:
            	head = delStart(head);
            	break;
            
            case 5:
            	head = delEnd(head);
            	break;
            
            case 6:
            	printf("Input Postition: "); scanf("%d", &loc);
            	head = delLoc(head, loc);
            	break;
            	
            case 7:
            	printf("Input Roll Number: "); scanf("%d", &num);
            	head = delSpec(head, num);
            	break;
            	
            case 8:
            	printf("STUDENT LIST\n");
            	display(head);
            	break;
            	
            case 9:
            	printf("Thank you.\n");
            	break;

            default:
                printf("Menu invalid. Please input valid menu.\n\n");
        }
        puts("");
        system("pause");
        
    }while(n!=9);
    
    return 0;
}
