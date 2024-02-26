#include <stdbool.h>
#include <stdio.h>
#define MAX_QUEUE 10000

typedef long long int ll;
typedef unsigned long long int ull;

typedef struct {
  int first;
  int last;
  int data[MAX_QUEUE];
} Queue;

/*
 * @brief Inisialisasi Queue
 *
 * @param Queue *queue - queue yang akan diinisialisasi
 * */
void init_queue(Queue *queue) { queue->first = queue->last = -1; }

/*
 * @brief Mengembalikan ukuran queue
 *
 * @param Queue *queue - queue
 * */
int size(Queue *queue) {
  if (queue->first == -1 || queue->last == -1)
    return 0;
  return queue->last - queue->first;
}

/*
 * @brief Mengembalikan nilai 1 apabila Queue penuh
 *
 * @param Queue *queue - queue yang akan dicek
 * */
int isFull(Queue *queue) { return size(queue) + 1 == MAX_QUEUE; }

/*
 * @brief Mengembalikan nilai 1 apabila Queue kosong
 *
 * @param Queue *queue - queue yang akan dicek
 * */
int isEmpty(Queue *queue) { return queue->first == -1; }

/*
 * @brief Mengembalikan data terdepan dari Queue
 *
 * @param Queue *queue - queue
 * */
int front(Queue *queue) {
  if (isEmpty(queue))
    return -1;
  else
    return queue->data[queue->first];
}

/*
 * @brief Menghapus data terdepan dari Queue
 *
 * @param Queue *queue - queue
 * */
void dequeue(Queue *queue) {
  if (queue->first == queue->last)
    init_queue(queue);
  else if (queue->first == size(queue) - 1)
    queue->first = 0;
  else
    queue->first++;
}

/*
 * @brief Mengentri data dari depan Queue
 *
 * @param Queue *queue - queue
 * */
void enqueue(Queue *queue, int input) {
  if (!isFull(queue)) {
    if (queue->last == size(queue) - 1 || queue->last == -1) {
      queue->data[0] = input;
      queue->last = 0;
      if (queue->first == -1)
        queue->first = 0;
    } else
      queue->data[++queue->last] = input;
  }
}

int main() {
  Queue queue;
  init_queue(&queue);
  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  dequeue(&queue);
  printf("%d", front(&queue));
}
