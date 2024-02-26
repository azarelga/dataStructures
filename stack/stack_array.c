#include <stdbool.h>
#define MAX_STACK 10000

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct {
  int size;
  int data[MAX_STACK];
} Stack;

/*
 * @brief Inisialisasi Stack
 *
 * @param Stack *stack - stack yang akan diinisialisasi
 * */
void init_stack(Stack *stack) { stack->size = -1; }

/*
 * @brief Mengembalikan nilai 1 apabila Stack kosong
 *
 * @param Stack *stack - stack yang akan dicek
 * */
int isEmpty(Stack *stack) { return stack->size == -1; }

/*
 * @brief Mengembalikan ukuran stack
 *
 * @param Stack *stack - stack
 * */
int size(Stack *stack) { return stack->size + 1; }

/*
 * @brief Mengembalikan nilai 1 apabila Stack penuh
 *
 * @param Stack *stack - stack yang akan dicek
 * */
int isFull(Stack *stack) { return size(stack) == MAX_STACK; }

/*
 * @brief Mengembalikan data teratas dari Stack
 *
 * @param Stack *stack - stack
 * */
int top(Stack *stack) {
  if (isEmpty(stack))
    return -1;
  else
    return stack->data[stack->size];
}

/*
 * @brief Mengosongkan isi Stack
 *
 * @param Stack *stack - stack
 * */
void clear(Stack *stack) { stack->size = -1; }

/*
 * @brief Menghapus data terdepan dari Stack
 *
 * @param Stack *stack - stack
 * */
void pop(Stack *stack) { stack->size--; }

/*
 * @brief Mengentri data dari atas Stack
 *
 * @param Stack *stack - stack
 * */
void push(Stack *stack, int input) { stack->data[++stack->size] = input; }

int main() {
  Stack stack;
  init_stack(&stack);
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  pop(&stack);
  top(&stack);
}
