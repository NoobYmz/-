#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef char VertexType;
typedef int EdgeType;


typedef struct Mat_grph{
	VertexType a[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int VNum;
	int ENum;
}Mat_grph;

int visted[MAXSIZE];
VertexType queue[MAXSIZE];
int rear = 0;
int front = 0;

Mat_grph* Initialize(){
	Mat_grph* p;
	p = (Mat_grph*)malloc(sizeof(Mat_grph));
	
	p->ENum = 15;
	p->VNum = 9;
	p->a[0] = 'A';
	p->a[1] = 'B';
	p->a[2] = 'C';
	p->a[3] = 'D';
	p->a[4] = 'E';
	p->a[5] = 'F';
	p->a[6] = 'G';
	p->a[7] = 'H';
	p->a[8] = 'I';
	
	// A->B  A->f
	p->arc[0][1] = 1;
	p->arc[0][5] = 1;
	
	// B->C B->I B->G
	p->arc[1][2] = 1;
	p->arc[1][8] = 1;
	p->arc[1][6] = 1;
	
	// C->D C->I
	p->arc[2][3] = 1;
	p->arc[2][8] = 1;
	
	//D->E D->H D->G
	p->arc[3][4] = 1;
	p->arc[3][7] = 1;
	p->arc[3][6] = 1;
	
	//E->H E->F 
	p->arc[4][5] = 1;
	p->arc[4][7] = 1;
	
	//F->G
	p->arc[5][6] = 1;
	
	//G->H
	p->arc[6][7] = 1;
	
	for ( int i = 0; i < p->VNum; i++ ){
		for ( int j = 0; j < p->VNum; j++ )
			p->arc[j][i] = p->arc[i][j];
	}
	
	for ( int i = 0; i < MAXSIZE; i++ ) visted[i] = 0;
	
	return p;
}

void bfs(Mat_grph* G){
	int i = 0;
	queue[rear] = G->a[i];
	rear++;
	
	while ( front != rear ){
		printf("%c ",queue[front]);
		i = queue[front] - 'A';
		front++;
		visted[i] = 1;
		
		for ( int j = 0; j < G->VNum; j++ ){
			if ( G->arc[i][j] == 1 && visted[j] == 0 ){
				queue[rear++] = G->a[j];
			}
		}
		
		//printf("%d  %d",rear, front);
	}
}

int main(){
	
	Mat_grph* G;
	G = Initialize();
	
//	for ( int i = 0; i < G->VNum; i++ ){
//		for ( int j = 0; j < G->VNum; j++ )
//			printf("%d ",G->arc[i][j]);
//		printf("\n");
//	}
	
	bfs(G);
	
	return 0;
}
