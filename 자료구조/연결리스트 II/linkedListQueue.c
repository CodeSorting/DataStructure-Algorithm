#include <stdio.h>
#include <stdlib.h>

typedef int element;	
typedef struct QueueNode {	
	element data;
	struct QueueNode *link;
} QueueNode;

typedef struct {		
	QueueNode *front, *rear; //앞과 뒤 모두 있어야 한다.
} LinkedQueueType;

void init(LinkedQueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(LinkedQueueType *q) {
	return (q->front == NULL);
}

int is_full(LinkedQueueType *q) {
	return 0;
}
/*
큐가 공백일때
front  rear  temp -> A NULL
=>
front  rear
  |    |
  \/   \/
  A  NULL
큐가 공백이 아닐 때
front        rear        temp -> D NULL
 |           |
 \/          \/
  A,값->B,값->C,NULL
  =>
front             rear        
 |                 |
 \/                \/
  A,값->B,값->C,값->D NULL
*/
void enqueue(LinkedQueueType *q, element data) {
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data; 		
	temp->link = NULL; 		
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else { 		
		q->rear->link = temp;  
		q->rear = temp;
	}
}
/*
노드가 1개 남았을 때
front  rear (동일한 곳 가리킴.)
  |    |
  \/   \/
  D  NULL
  =>
  front rear       temp -> D NULL
노드가 2개 이상일 때
front             rear        
 |                 |
 \/                \/
  A,값->B,값->C,값->D NULL
  =>
  temp-> A,값
front      rear        
 |          |
 \/         \/
 B,값->C,값->D NULL
*/
element dequeue(LinkedQueueType *q) {
	QueueNode *temp = q->front; //제일 앞에 삭제해야 큐다.
	element data;
	if (is_empty(q)) {		
		fprintf(stderr, "큐가 비어있습니다.\n");
		exit(1);
	}
	else {
		data = temp->data; 		
		q->front = q->front->link; 
		if (q->front == NULL) 	
			q->rear = NULL;
		free(temp); 			
		return data; 			
	}
}

void print_queue(LinkedQueueType *q) {
	QueueNode *p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main(void) {
	LinkedQueueType queue;
	init(&queue);		

	enqueue(&queue, 1);	
	print_queue(&queue);
	enqueue(&queue, 2);	
	print_queue(&queue);
	enqueue(&queue, 3);	
	print_queue(&queue);
	dequeue(&queue);		
	print_queue(&queue);
	dequeue(&queue);		
	print_queue(&queue);
	dequeue(&queue);		
	print_queue(&queue);
	return 0;
}