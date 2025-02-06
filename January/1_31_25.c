/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Netflix.

Implement a queue using a set of fixed-length arrays.

The queue should support enqueue, dequeue, and get_size operations.

Question from dailycodingproblem.com
*/
#include <stdio.h>
#define QUEUE_SIZE 10

//define the queue structure
typedef struct Queue{
    int queue[QUEUE_SIZE];
    int head;
    int tail;
    int length;
}Queue;

//define the functions
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void disp(Queue *q);

int main(void){

    //create a struct to hold the queue
    Queue x;
    x.head = 0;
    x.tail = 0;

    //enqueue some values
    enqueue(&x, 1);
    enqueue(&x, 2);
    enqueue(&x, 3);
    disp(&x);
    printf("\n%d",x.length);

    //dequeue some values
    dequeue(&x);
    disp(&x);
    printf("\n%d",x.length);

    //try to dequeue an empty queue
    dequeue(&x);
    dequeue(&x);
    dequeue(&x);
    disp(&x);

    //try to queue into a full queue
    for(int i = 0; i < QUEUE_SIZE+1; i++)
        enqueue(&x, i+10);
    disp(&x);
    return 0;
}

//add a value to the end of the queue
void enqueue(Queue *q, int value){
    //ensure the queue does not exceed array bounds
    if (q->tail >= QUEUE_SIZE){
        q->tail = 0;
    }
    //check if the queue is full
    if (q->tail == q->head && q->length != 0){
        printf("\nQueue is full\n");
        return;
    }
    //add the value to the end of the queue
    q->queue[q->tail] = value;
    //move the tail of the queue
    q->tail++;
    q->length++;
}

//pop the value at the head of the queue off and return it
int dequeue(Queue *q){
    //get the value at the head of the queue
    int val = q->queue[q->head];
    //check if queue is empty
    if(q->head == q->tail){
        printf("\nQueue is empty\n");
        return -1;
    }
    //move the head of the queue
    q->head++;
    q->length--;

    return val;
}

//display the queue by iterating through the array until the counter reaches the length, modulo the index if it goes out of bounds
void disp(Queue *q){
    printf("\n");
    int index = q->head;
    int counter = 0;
    while(counter != q->length){
        if (index == QUEUE_SIZE){
            index = index%QUEUE_SIZE;
        }
        printf("%d ", q->queue[index]);
        index++;
        counter++;
    }
}