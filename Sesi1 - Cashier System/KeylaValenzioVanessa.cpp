#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dolls{
	char code[8];
	char name[55];
	int stock;
	int price;
} doll[15];

struct temporary{
	int size;
} temp;

void sell(){
	char intcode[10];
	int quantity, sum, i, found=0;
	
	dollC:
  printf("Type \"EXIT\" To Return");
		printf("\nInput Doll Code [5 chars]: "); 
		scanf("%s", intcode);
  if(strcmp(intcode, "EXIT")==0){
    printf("Going to main menu......\n\n");
    return;
  }
		for(i=1;i<temp.size;i++){
			if(strcmp(doll[i].code, intcode)==0){
				found=1;
				dollQ:
				printf("Input Quantity [0...%d]: ", doll[i].stock); 
				scanf("%d", &quantity);
				if(quantity>doll[i].stock){
					printf("---The quantity of doll is not enough---\n");
					printf("Doll Quantity: %d\n", doll[i].stock);
					goto dollQ;
				}
				else{
					sum = doll[i].price * quantity;
					printf("Total Price is: Rp. %d,- x %d = Rp. %d,-\n", doll[i].price, quantity, sum);
					doll[i].stock-=quantity;
					printf("\n---Thank You---\n\n");
					
					FILE *fp;
					fp = fopen("data1.txt", "w");
					for(i=1; i<temp.size; i++){
						fprintf(fp, "%s %s\n%d %d\n", doll[i].code, doll[i].name, doll[i].stock, doll[i].price);
					}
					fclose(fp);
					
					int cont;
					printf("Press Enter to continue..."); 
					scanf("%c", &cont); getchar();
					puts("");
				}
				break;
			}
		}
		
		if(found==0){
			printf("---The doll code doesn't exist---\n\n");
			goto dollC;
		}
}

void addStock(){
	char intcode[10];
	int quantity, sum, i, found=0;
	
	dollC:
  printf("Type \"EXIT\" To Return");
		printf("\nInput Doll Code [5 chars]: "); 
		scanf("%s", intcode);
  if(strcmp(intcode, "EXIT")==0){
    printf("Going to main menu......\n\n");
    return;
  }
		for(i=1;i<temp.size;i++){
			if(strcmp(doll[i].code, intcode)==0){
				found=1;
				dollQ:
				printf("Input Quantity [1...100]: "); scanf("%d", &quantity);
				if(quantity>100){
					printf("---Please enter a number between 1 and 100---\n\n");
					goto dollQ;
				}
				else{
					doll[i].stock+=quantity;
					FILE *fp;
					fp = fopen("data1.txt", "w");
					for(i=1; i<temp.size; i++){
						fprintf(fp, "%s %s\n%d %d\n", doll[i].code, doll[i].name, doll[i].stock, doll[i].price);
					}
					fclose(fp);
					printf("\n---Adding Stock Success---\n\n");
					
					int cont;
					printf("Press Enter to continue..."); 
					scanf("%c", &cont); getchar();
					puts("");
				}
				break;
			}
		}
		
		if(found==0){
			printf("---The doll code doesn't exist---\n\n");
			goto dollC;
		}
}

void readFile(){
	FILE *fp;
	fp = fopen("data1.txt", "r");
	
	if(fp==NULL){
		printf("[!] Data not found.\n");
	}
	else{
		int i=1;
		while(fscanf(fp, "%s %[^\n]%d %d", doll[i].code, doll[i].name, &doll[i].stock, &doll[i].price) != EOF){
			i++;
		}
		temp.size = i;
	}
	fclose(fp);
}

void tableData(){
	int i;
	printf("No. |  Code  |            Doll Name    	      | Available |    Price\n");
	printf("-------------------------------------------------------------------------\n");
	for(i=1; i<temp.size; i++){
		if(i<=9){
			printf("0%d. | %.5s  | %-30s | %6d    | Rp. %d,-\n", i, doll[i].code, doll[i].name, doll[i].stock, doll[i].price);
		}
		else if(i>9){
			printf("%d. | %.5s  | %-30s | %6d    | Rp. %d,-\n", i, doll[i].code, doll[i].name, doll[i].stock, doll[i].price);
		}
	}
	printf("-------------------------------------------------------------------------\n");
}

void addDoll(){
	FILE *fptr;
	fptr = fopen("data1.txt", "a");
	
	int n, i, j;
	char dollC[8];
	
	if(fptr==NULL){
		printf("[!] File doesn't exist.\n");
	}
	
	else{
		//printf("\nHow many data would you like to add? "); scanf("%d", &n);
		//for(i=1;i<=n;i++){
			//printf("Data #%d\n", i);
			dollC:
				printf("\nDoll Code [5 chars]: "); getchar(); scanf("%s", dollC);
				for(i=1;i<temp.size;i++){
					if(strcmp(doll[i].code, dollC)==0){
					printf("---New doll code cannot be the same as existing doll code.---\n\n");
					goto dollC;
					}
					else{
						continue;
					}
				}
			printf("Doll Name: "); getchar(); scanf("%[^\n]", doll[i].name);
			printf("Doll Stock: "); scanf("%d", &doll[i].stock);
			printf("Doll Price: "); getchar(); scanf("%d", &doll[i].price);
			puts("");
			
			fprintf(fptr, "%s %s\n%d %d\n", dollC, doll[i].name, doll[i].stock, doll[i].price);
		//}
		printf("--Data successfully added.----\n");
    
    int cont;
    printf("\nPress Enter to continue..."); 
    scanf("%c", &cont); getchar();
    puts("");
	}
	
	fclose(fptr);
}

void search(){
	readFile();
	int i,b=0;
	char a[10];
  dolla:
  printf("Type \"EXIT\" To Return\n");
	printf("Input Doll Code [5 chars]: ");
	scanf("%s", a);
  if(strcmp(a, "EXIT")==0){
    printf("Going to main menu......\n\n");
    return;
  }
	for(i=1;i<temp.size;i++){
	if(strcmp(doll[i].code, a)==0){
    b=1;
    printf("\n");
		printf("No. |  Code  | Doll Name             	      | Available | Price\n");
	printf("-------------------------------------------------------------------------\n");
		if(i<=9){
			printf("0%d. | %.5s  | %-30s | %9d | Rp. %d,-\n", i, doll[i].code, doll[i].name, doll[i].stock, doll[i].price);
		}
		else if(i>9){
			printf("%d. | %.5s  | %-30s | %9d | Rp. %d,-\n", i, doll[i].code, doll[i].name, doll[i].stock, doll[i].price);
		}
    int cont;
		printf("\nPress Enter to continue..."); 
		scanf("%c", &cont); getchar();
		puts("");
	}
}
  if(b==0){
    printf("---The doll code doesn't exist---\n\n");
    goto dolla;
  }
}

int main(){
    int n, menu=0;
    //while(menu==0){
    do{
    	system("cls");
    	printf("PUI CUTIE STUFFED ANIMAL DOLL CASHIER\n");
    	printf("=====================================\n\n");
    	
     	readFile();
    	tableData();
	    printf("\nMenu:\n");
	    printf("1. Sell\n");
	    printf("2. Add Stock\n");
	    printf("3. Add Doll\n");
	    printf("4. Search\n");
	    printf("5. Exit\n");
        printf("Input choice: "); 
		scanf("%d", &n);

        switch(n){
            case 1:
            	sell();
                break;

            case 2:
            	addStock();
                break;
            
            case 3:
            	addDoll();
            	break;
            	
            case 4:
            	search();
            	break;
            	
            case 5:
                printf("---Thank you.---\n");
                exit(1);

            default:
                printf("Menu invalid. Please input valid menu.\n\n");
        }
    }
    while(menu==0);
    return 0;
}
