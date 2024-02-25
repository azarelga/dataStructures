#include <stdbool.h>
#include <stdlib.h>

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct node {
  int data;
  struct node *next;
} StackNode;

typedef struct stack_t {
  int size;
  StackNode *top;
} Stack;

/*
 * @brief Inisialisasi Stack
 *
 * @param Stack *stack - stack yang akan diinisialisasi
 * */
void init(Stack *stack) {
  stack->top = NULL;
  stack->size = -1;
}

/*
 * @brief Mengembalikan nilai 1 apabila Stack kosong
 *
 * @param Stack *stack - stack yang akan dicek
 * */
int isEmpty(Stack *stack) { return stack->size == -1; }

/*
 * @brief Mengembalikan data teratas dari Stack
 *
 * @param Stack *stack - stack
 * */
int top(Stack *stack) {
  if (isEmpty(stack))
    return -1;
  else
    return stack->top->data;
}

/*
 * @brief Mengosongkan isi Stack
 *
 * @param Stack *stack - stack
 * */
void clear(Stack *stack) {
  stack->top = NULL;
  stack->size = -1;
}

/*
 * @brief Mengembalikan ukuran stack
 *
 * @param Stack *stack - stack
 * */
int size(Stack *stack) { return stack->size; }

/*
 * @brief Menghapus data terdepan dari Stack
 *
 * @param Stack *stack - stack
 * */
void pop(Stack *stack) {
  StackNode *temp = stack->top;
  free(temp);
  stack->top = stack->top->next;
  stack->size--;
}

/*
 * @brief Mengentri data dari atas Stack
 *
 * @param Stack *stack - stack
 * */
void push(Stack *stack, int input) {
  StackNode *newNode = malloc(sizeof(StackNode));
  newNode->data = input;
  newNode->next = stack->top;
  stack->top = newNode;
  stack->size++;
}

int main() {}
