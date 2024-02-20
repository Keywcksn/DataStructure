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

struct Student *createStart(struct Student *start, char newName[30], int newNum, int newScore){
	if(start==NULL){
		start = (struct Student*)malloc(sizeof(struct Student));
		strcpy(start->name, newName);
		start->num = newNum;
		start->score = newScore;
		start->next = start;
	}
	else if(start->next == start){
		struct Student *newNode;
		newNode = (struct Student*)malloc(sizeof(struct Student));
		strcpy(newNode->name, newName);
		newNode->num = newNum;
		newNode->score = newScore;
		newNode->next = start;
		start->next = newNode;
		start = newNode;
	}
	else{
		struct Student *newNode;
		struct Student *ptr;
		ptr = start;
		while(ptr->next != start){
			ptr = ptr->next;
		}
		newNode = (struct Student*)malloc(sizeof(struct Student));
		strcpy(newNode->name, newName);
		newNode->num = newNum;
		newNode->score = newScore;
		newNode->next = start;
		ptr->next = newNode;
		start = newNode;
	}
	
	return start;
}

struct Student *createEnd(struct Student *start, char newName[30], int newNum, int newScore){
	if(start == NULL){
    	start = (struct Student*)malloc(sizeof(struct Student));
    	strcpy(start->name, newName);
    	start->num = newNum;
		start->score = newScore;
		start->next = start;
  }
	else{
    struct Student *newNode, *ptr;
    ptr = start;

    newNode=(struct Student*)malloc(sizeof(struct Student));
    strcpy(newNode->name, newName);
    newNode->num = newNum;
    newNode->score = newScore;
    newNode->next = start;

    while(ptr->next != start) ptr = ptr->next;
    
    ptr->next = newNode;
  }
  
	return start;
}

int size(Student *start){
	int count=0;
	struct Student *ptr;
	ptr = start;
	do{
		ptr = ptr->next;
		count++;
	}while(ptr != start);
/*	while(start != NULL){
		start = start->next;
		count++;
*/	}
	return count;
}

struct Student *createCustom(struct Student *start, int loc){
//  struct Student *ptr;
	int a = size(start);
	
	if(loc==1){
		getchar();
		printf("Input Name: "); gets(name);
		printf("Input Roll Number: "); scanf("%d", &num);
		printf("Input Score: "); scanf("%d", &score);
		
		start = createStart(start, name, num, score);
		printf("---Data saved successfully.---\n");
	}
	else if(loc==a+1){
		getchar();
		printf("Input Name: "); gets(name);
		printf("Input Roll Number: "); scanf("%d", &num);
		printf("Input Score: "); scanf("%d", &score);
		
		start = createEnd(start, name, num, score);
		printf("---Data saved successfully.---\n");
	
	}
	else if(loc <=0 || loc>a){
		printf("---Position Invalid. Please try again---\n");
	}
	else if(loc>0){
		char name[30];
		int num, score;
		
		getchar();
		printf("Input Name: "); gets(name);
		printf("Input Roll Number: "); scanf("%d", &num);
		printf("Input Score: "); scanf("%d", &score);

    //ptr = start;
		for(int i=1;i<loc-1;i++) start = start->next;
		Student *newNode = (Student*)malloc(sizeof(Student));
		strcpy(newNode->name, name);
		newNode->num = num;
		newNode->score = score;
		
		newNode->next = start->next;
		start->next = newNode;
		printf("---Data saved successfully.---\n");
	}
	
	return start;
}

struct Student *delStart(struct Student *start){
  struct Student *ptr;
  
	if(start == NULL){
		printf("--- No data to delete.---\n");
	}
    
  else if(start->next == start){
    printf("---Data %d has been deleted.---\n", ptr->num);
    free(start);
    start = NULL;
  }
    
	else{
		ptr = start;
    
    while(ptr->next != start){
      ptr = ptr->next;
    }
    
		start = start->next;
		printf("---Data %d has been deleted.---\n", ptr->next->num);
		free(ptr->next);
    ptr->next = start;
	}
  
	return start;
}

struct Student *delEnd(struct Student *start){
	struct Student *ptr = start, *preptr;;
	
	if(start == NULL){
		printf("--- No data to delete.---\n");
	}

  else if(start->next == start){
    printf("---Data %d has been deleted.---\n", ptr->num);
    free(start);
    start = NULL;
  }
    
	else{
		while(ptr->next != start){
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = start;
		
		printf("---Data %d has been deleted.---\n", ptr->num);
		free(ptr);
	}
	
	return start;
}

struct Student *delLoc(struct Student *start, int loc){
	int a = size(start);   
	
	if(loc==1){
		start = delStart(start);
	}
	else if(loc==a+1){
		delEnd(start);
	}
	else if(loc <=0 || loc>a){
		printf("---Position Invalid. Please try again---\n");
	}
	else if(loc>1){
		struct Student *ptr = start;
		for(int i=1;i<loc-1;i++) ptr = ptr->next;
		
		struct Student *del = ptr->next;
		ptr->next = ptr->next->next;
		printf("---Data %d has been deleted.---\n", del->num);
		del->next = NULL;
		
		free(del);
	}
	
	return start;
}

struct Student *delSpec(struct Student *start, int node){
	struct Student *ptr, *preptr;
	
	if(start==NULL){
		printf("---No data to delete.---\n");
		return start;
	}
	else{
		ptr = start;
		if(ptr->num == node){
			start = delStart(start);
			return start;
		}
		else{
			while(ptr->num != node){
				preptr = ptr;
				ptr = ptr->next;
			}
			
			preptr->next = ptr->next;
			printf("---Data %d has been deleted.---\n", node);
			free(ptr);
			
			return start;
		}
	}
}

void display(struct Student *start){
	struct Student *ptr = start;
	int no = 1;
	
	if(start == NULL) printf("---Data doesn't exist.---\n");
	else{
		printf("+-----+--------------------------------+-------------+-------+\n");
		printf("| No. |          Student Name          | Roll Number | Score |\n");
		printf("+-----+--------------------------------+-------------+-------+\n");
    do{
      char temp[25];
      strcpy(temp, ptr->name);
      int length = strlen(temp);
      if(length != 24){
        for(int i = length; i<24; i++){
          strcat(temp, " ");
        }
      }
			printf("|  %d. | %-30s | %7d     | %4d  |\n", no++, ptr->name, ptr->num, ptr->score);
			ptr = ptr->next;
		}
    while(ptr != start);
		printf("+-----+--------------------------------+-------------+-------+\n");
	}
}

struct Student *bubbleSort(struct Student *start){
	struct Student *ptr = start, *preptr = NULL;
	int temp, temp1;
	char tempchar[30];
	
	if(start == NULL) printf("");
	else{
		do{
			preptr = ptr->next;
			while(preptr != start){
				if(ptr->num > preptr->num){
					strcpy(tempchar, ptr->name);
					strcpy(ptr->name, preptr->name);
					strcpy(preptr->name, tempchar);
					
					temp = ptr->num;
					ptr->num = preptr->num;
					preptr->num = temp;
					
					temp1 = ptr->score;
					ptr->score = preptr->score;
					preptr->score = temp1;
				}
				preptr = preptr->next;
			}
			ptr = ptr->next;
		} while(ptr->next != start);
	}
	
	display(start);
}

int main(){
	struct Student *start = NULL;
    int n, menu=0;     	
    
    do{
    	system("cls");
    	printf("--- Student List ---\n\n");
    	display(start);
	    printf("Menu:\n");
	    printf("1. Add a node at the beginning\n");
	    printf("2. Add a node at the end\n");
	    printf("3. Add a node at a specified position\n");
	    printf("4. Delete the first node\n");
	    printf("5. Delete the last node\n");
	    printf("6. Delete a node at a specified position\n");
	    printf("7. Delete a specific node\n");
	    printf("8. Display table data\n");
	    printf("9. Display sorted table data\n");
	    printf("10. Exit\n");
	    choice:
       		printf("\nInput choice: "); scanf("%d", &n);

        switch(n){
            case 1:
            	getchar();
				printf("Input Name: "); gets(name);
				printf("Input Roll Number: "); scanf("%d", &num);
				printf("Input Score: "); scanf("%d", &score);
				
				start = createStart(start, name, num, score);
				printf("---Data saved successfully.---\n");
				
                break;

            case 2:
            	getchar();
				printf("Input Name: "); gets(name);
				printf("Input Roll Number: "); scanf("%d", &num);
				printf("Input Score: "); scanf("%d", &score);
				
				start = createEnd(start, name, num, score);
				printf("---Data saved successfully.---\n");
				
                break;
            
            case 3:
				getchar();
				printf("Input Position: "); scanf("%d", &loc);
            	start = createCustom(start, loc);
            	
            	
            	break;
            	
            case 4:
            	start = delStart(start);
            	break;
            
            case 5:
            	start = delEnd(start);
            	break;
            
            case 6:
            	printf("Input Postition: "); scanf("%d", &loc);
            	start = delLoc(start, loc);
            	break;
            	
            case 7:
            	printf("Input Roll Number: "); scanf("%d", &num);
            	start = delSpec(start, num);
            	break;
            	
            case 8:
            	printf("STUDENTS LIST\n");
            	display(start);
            	break;
            	
            case 9:
            	bubbleSort(start);
            	break;
            	
            case 10:
            	printf("Thank you.\n");
            	break;

            default:
                printf("Menu invalid. Please input valid menu.\n\n");
        }
        puts("");
        system("pause");
        
    }while(n!=10);
    
    return 0;
}
