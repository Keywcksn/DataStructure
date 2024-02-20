#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
	int vertex;
	struct Node *next;
};

struct Graph{
	int numVertices;
	int *visited;
	int *degree; 
	struct Node **adjList;
};

int vert, arr[105][105];

// Initiation
struct Node *createNode(int data){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->vertex = data;
	node->next = NULL;
	
	return node;
}

struct Graph *createGraph(int numVert){
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->numVertices = numVert;
	graph->degree = (int*)malloc(numVert * sizeof(int));
	graph->adjList = (struct Node**)malloc(numVert * sizeof(struct Node));
	graph->visited = (int*)malloc(numVert * sizeof(int));
	
	for(int i=0; i<graph->numVertices; i++){
		graph->adjList[i] = NULL;
		graph->visited[i] = 0;
		graph->degree[i] = 0;
	}
	
	return graph;
}

void displayAdjMatrix(struct Graph *graph){
	printf("\nAdjacency Matrix\n");
	printf("   ");
	for(int i = 0; i < graph->numVertices; i++)
		printf(" %d  ", i);
		
	printf("\n");
	for(int i = 0; i < graph->numVertices; i++){
		printf(" %d", i);
		for(int j = 0; j < graph->numVertices; j++){
			printf("|");
			printf(" %d ", arr[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
}

//Add Edge
void addEdge(struct Graph *graph, int src, int dst){
	struct Node *newNode = createNode(dst);
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;
	
	newNode = createNode(src);
	newNode->next = graph->adjList[dst];
	graph->adjList[dst] = newNode;
	
	arr[src][dst]=1;
	arr[dst][src]=1;
}

// View Adj List
void displayAdjList(struct Graph *graph){
	for(int v=0; v<graph->numVertices; v++)
	{
		struct Node *temp = graph->adjList[v];
		printf("\n Adjency List of Vertex %d :", v);
		while(temp != NULL)
		{
			printf(" -> %d", temp->vertex);
		//	graph->degree[v]++;
			temp = temp->next;
		}
		
	}
}

void Degree(struct Graph *graph){
	for(int v=0; v<graph->numVertices; v++)
	{
		struct Node *temp = graph->adjList[v];
		while(temp != NULL)
		{
			graph->degree[v]++;
			temp = temp->next;
		}
		
	}
	for(int i=0;i<graph->numVertices;i++){
		printf("Degree of %d = %d\n",i, graph->degree[i]);
	}
}
//Transversal
int checkNode(struct Node *key, struct Node *list){ // To Check if Node already at Queue or Output
	while(list != NULL){
		if(key->vertex == list->vertex)
			return 1;
		list = list->next;
	}
	return 0;
}

struct Node *push(int vertex, struct Node *list){ // To Push a Node to Queue or Output (Push Tail)
	if(list == NULL)
		return createNode(vertex);
	else{
		struct Node *temp;
		temp = list;
		while(temp != NULL && temp->next != NULL)
			temp = temp->next;
		
		temp->next = createNode(vertex);
		
		return list;	
	}
}

struct Node *pop(struct Node *queue){ // To Delete Node from Queue (Pop Head)
	if(queue->next == NULL){
		free(queue);
		queue = NULL;
	}
	else{
		struct Node *temp;
		temp = queue->next;
		free(queue);
		queue = temp;
	}
	
	return queue;
}

struct Node *BFS(struct Graph *graph, int vertex){ // BFS Function
	struct Node *queue, *output, *temp;
	output = NULL;
	queue = createNode(vertex);
	
	while(queue != NULL){
		temp = graph->adjList[queue->vertex];
		
		while(temp != NULL){
			if(checkNode(temp,queue) == 0 && checkNode(temp,output) == 0)
				push(temp->vertex, queue);
			temp = temp->next;
		}
		output = push(queue->vertex, output);
		queue = pop(queue);
	}
	
	return output;
}

void Depfirst(struct Graph *graph, int vertex){

	struct Node* adjList = graph->adjList[vertex];
	struct Node *temp = adjList;
	
	graph->visited[vertex] = 1;
	printf("Visited %d\n", vertex);
	
	while(temp != NULL){
		int connectedVertex = temp->vertex;
		if(graph->visited[connectedVertex] == 0)
			Depfirst(graph, connectedVertex);
		temp = temp->next;
	}
}

void addVertex(){
	vert++;
	for(int i=0; i<vert; i++){
		arr[i][vert-1] = 0;
		arr[vert-1][i] = 0;
	}
}

int main(){
	struct Graph *graph;
	
	printf("Number of vertices: ");
	scanf("%d", &vert);
	
	//Initialize the matrix to zero
	int arr[vert][vert];
	for(int i = 0; i < vert; i++)
		for(int j = 0; j < vert; j++)
			arr[i][j] = 0;
			
	graph = createGraph(vert);
	
	int menu;
	do{			
	 	system("cls");
	 	printf("Number of vertices: %d\n", vert);
		printf("1. Add Edge\n");
		printf("2. View Adjacency List\n");
		printf("3. View Adjacency Matrix\n");
		printf("4. View Degree of Vertex\n");
		printf("5. BFS Transversal\n");
		printf("6. DFS Transversal\n");
		printf("7. Add vertex\n");
		printf("8. Exit\n");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:{
				int newSrc, newDst;
				printf("Input data source : ");
				scanf("%d",&newSrc);
				printf("Input data destination : ");
				scanf("%d",&newDst);
				
				addEdge(graph, newSrc, newDst);
				printf("\n--- Edge successfully added. ---\n\n");
				
				getch();
				break;
			}
			
			case 2:{
				displayAdjList(graph);
				printf("\n");
				getch();
				break;
			}
			
			case 3:{
				displayAdjMatrix(graph);
				getch();
				break;
			}
			
			case 4:{
			Degree(graph);
				getch();
				break;
			}
			
			case 5:{
				struct Node *bfs;
				int first;
				printf("Starting vertex : ");
				scanf("%d", &first);
				bfs = BFS(graph, first);
				while(bfs != NULL)
				{
					printf("%d ", bfs->vertex);
					bfs = bfs->next;
				}
				printf("\n");
				getch();
				break;
			}
			
			case 6:{
				int first;
				printf("Starting vertex : ");
				scanf("%d", &first);
				Depfirst(graph, first);
				memset(graph->visited, 0, graph->numVertices * sizeof(int));
				getch();
				break;
			}
			
			case 7:{
				addVertex();
				graph = createGraph(vert);
				break;
			}
			
			case 8:{
				break;
			}
			
			default:{
				printf("\n--- Wrong input. ---");
				getch();
				break;
			}
		}
	} while(menu != 8);
	
	return 0;
}
