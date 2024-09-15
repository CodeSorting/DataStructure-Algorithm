#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode { //트리 노드 : 가중치,문자,왼쪽,오른쪽서브트리 포인터
    int weight;
    char ch;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct { //요소 1개 당 트리노드 포인터 1개, 문자, 키 값이 있다.
    TreeNode *ptree; // 가중치,문자,서브트리포인터를 가리킬 수 있는 포인터다.
    char ch; //문자
    int key; //키 값
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//히프 만들기(할당)
HeapType* create() {
	return (HeapType *)malloc(sizeof(HeapType));
}

//히프 초기화
void init(HeapType *h) {
	h->heap_size = 0;
}

//최소 힙의 삽입연산
void insert_min_heap(HeapType *h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;   
}

//최소 힙의 삭제연산
element delete_min_heap(HeapType *h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key) 
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//왼쪽,오른쪽 가리킨 노드 만들고 반환
TreeNode* make_tree(TreeNode *left,TreeNode *right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

//재귀로 트리 전체 파괴
void destroy_tree(TreeNode *root) {
	if (root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

//단말노드인지 아닌지 판별
int is_leaf(TreeNode *root) {
	return !(root->left) && !(root->right);
}

//배열 출력
void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

//트리 출력
void print_tree(TreeNode *root) {
	if (root != NULL) {
		printf("[%d] ", root->weight); 
		print_tree(root->left);
		print_tree(root->right);
	}
}

//문자의 인코딩된 결과 출력
void print_codes(TreeNode *root, int codes[], int top) {
	if (root->left) { //1을 저장하고 순환호출한다.
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) { //0을 저장하고 순환호출한다.
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	} 
	if (is_leaf(root)) { //쭉 내려가다가 단말노드이면 코드(인코딩된 문자열)를 출력한다.
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

void huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode *node, *x;
	HeapType *heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

    //히프 만들고 초기화
	heap = create();
	init(heap);

	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e); //최소힙에 e(문자,빈도,서브트리포인터) 넣기
	}

	for (i = 1; i < n; i++) {
        //최솟값을 지니는 노드 2개 삭제
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
        //두 개의 노드를 합친다.
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key; //값은 2개 더한 것
		e.ptree = x; //서브트리는 x(e1,e2)로 둔다.
		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e); //다시 최소 힙에 넣기
	}

	e = delete_min_heap(heap); //최종 트리 
	print_codes(e.ptree, codes, top);

    //동적할당 다 닫기
	destroy_tree(e.ptree);
	free(heap);
}

int main() {
	char ch_list[] = { 's', 'i', 'n', 't', 'e' }; //문자 사용 리스트
	int freq[] = { 4, 6, 8, 12, 15 }; //문자 빈도
	huffman_tree(freq, ch_list, 5);
	return 0;
}