#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef int element;

typedef struct {
  element array[SIZE];
  int size;
} list;

void init(list* l) {
  l->size = 0;
}

void add(list* l, element item) {
  int i = l->size - 1;
  while ((i >= 0) && (l->array[i] > item)) {
    l->array[i+1] = l->array[i];
    i--;
  }
  l->array[i + 1] = item;
  l->size++;
}

void delete(list* l, element item) {
  int i = 0;
  while ((i < l->size) && (l->array[i] != item))
    i++;

  for (int j = i; j < l->size - 1; j++)
    l->array[i] = l->array[i + 1];
  l->size--;
}

void clear(list* l) {
  l->size = 0;
}

int is_in_list(list* l, element item) {
  int c = 0;

  for (int i = 0; i < l->size; i++) {
    if (l->array[i] == item)
      c++;
  }
  return c;
}

int get_length(list* l) {
  return l->size;
}

int is_empty(list* l) {
  return (!l->size);
}

int full(list* l) {
  return (l->size == SIZE);
}

void display(list* l) {
  for (int i = 0; i < l->size; i++) {
    printf("%d->", l->array[i]);
  }
  puts("");
}

int main(void) {
  int num, value;
  list* l = (list*)malloc(sizeof(list));
  init(l);

  while (1) {
    printf("삽입(0), 삭제(1), 그만두기(2): ");
    scanf("%d", &num);
    if (num==2) break;
    printf("값: ");
    scanf("%d", &value);

    if (num)
      delete(l, value);
    else
      add(l, value);
    display(l);
  }
}