#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int value;
    struct stack* next;
} stack_node;
typedef struct {
    stack_node* top;
} stack;

void init_stack (stack* s);
void push (stack* s, int input_value);
int pop (stack* s);
int peek_stack (stack* s);

/*====================================*/
typedef struct queue_node {
    int value;
    struct queue_node* next;
} queue_node;
typedef struct queue {
    queue_node* front;
    queue_node* back;
} queue;

void init_queue (queue* q);
void enqueue (queue* q, int input_value);
int dequeue (queue* q);
int peek_queue (queue* q);

/*====================================*/
typedef struct deque_node {
    int value;
    struct deque_node* prev;
    struct deque_node* next;
} deque_node;
typedef struct deque {
    deque_node* front;
    deque_node* back;
} deque;

void init_deque (deque* dq);
void push_front (deque* dq, int input_value);
void push_back (deque* dq, int input_value);
int pop_front (deque* dq);
int pop_back (deque* dq);
int peek_front (deque* dq);
int peek_back (deque* dq);

/*====================================*/
int main(int argc, char* argv[]) {

    return 0;
}

/*====================================*/

void init_stack (stack* s) {
    s->top = NULL;
}

void push (stack* s, int input_value) {
    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
    if (!new_node) {
        fprintf(stderr, "push(): allocation error\n");
        return;
    }

    new_node->value = input_value;
    new_node->next = s->top;
    s->top = new_node;
}

int pop (stack* s) {
    if (s->top == NULL) {
        fprintf(stderr, "pop(): stack is empty\n");
        return -1;
    }

    int result = s->top->value;
    stack_node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return result;
}

int peek_stack (stack* s) {
    if (s->top == NULL) {
        fprintf(stderr, "peek_stack(): stack is empty\n");
        return -1;
    }

    return s->top->value;
}

/*====================================*/

void init_queue (queue* q) {
    q->front = NULL;
    q->back = NULL;
}

void enqueue (queue* q, int input_value) {
    queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
    if (!new_node) {
        fprintf(stderr, "enqueue(): allocation error\n");
        return;
    }
    new_node->next = NULL;
    new_node->value = input_value;

    if (!q->front) {
        q->front = new_node;
        q->back = new_node;
    } else {
        q->back->next = new_node;
        q->back = new_node;
    }
}

int dequeue (queue* q) {
    if (!q->front) {
        fprintf(stderr, "dequeue(): queue is empty\n");
        return -1;
    }

    int result = q->front->value;
    queue_node* temp = q->front;
    q->front = temp->next;
    if (!q->front) {
        q->back = NULL;
    }
    free(temp);
    return result;
}

int peek_queue (queue* q) {
    if (!q->front) {
        fprintf(stderr, "peek_queue(): queue is empty\n");
        return -1;
    }

    return q->front->value;
}

/*====================================*/

void init_deque (deque* dq) {
    dq->front = NULL;
    dq->back =NULL;
}

void push_front (deque* dq, int input_value) {
    deque_node* new_node = (deque_node*)malloc(sizeof(deque_node));
    if (!new_node) {
        fprintf(stderr, "push_front(): allocation error\n");
        return;
    }
    new_node->value = input_value;
    new_node->prev = NULL;
    new_node->next = dq->front;
    if (dq->front != NULL) {
        dq->front->prev = new_node;
    }
    dq->front = new_node;
    if (dq->back == NULL) {
        dq->back = new_node;
    }
}

void push_back (deque* dq, int input_value) {
    deque_node* new_node = (deque_node*)malloc(sizeof(deque_node));
    if (!new_node) {
        fprintf(stderr, "push_back(): allocation error\n");
        return;
    }
    new_node->value = input_value;
    new_node->prev = dq->back;
    new_node->next = NULL;
    if (dq->back != NULL) {
        dq->back->next = new_node;
    }
    dq->back = new_node;
    if (dq->front == NULL) {
        dq->front = new_node;
    }
}

int pop_front (deque* dq) {
    if (!dq->front) {
        fprintf(stderr, "pop_front(): deque is empty\n");
        return -1;
    }

    int result = dq->front->value;
    deque_node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->back = NULL;
    }
    free(temp);
    return result;
}

int pop_back (deque* dq) {
    if (!dq->front) {
        fprintf(stderr, "pop_back(): deque is empty\n");
        return -1;
    }

    int result = dq->back->value;
    deque_node* temp = dq->back;
    dq->back = dq->back->prev;
    if (dq->back != NULL) {
        dq->back->next = NULL;
    } else {
        dq->front = NULL;
    }
    free(temp);
    return result;
}

int peek_front (deque* dq) {
    if (!dq->front) {
        fprintf(stderr, "peek_front(): deque is empty\n");
        return -1;
    }
    return dq->front->value;
}

int peek_back (deque* dq) {
    if (!dq->front) {
        fprintf(stderr, "peek_back(): deque is empty\n");
        return -1;
    }
    return dq->back->value;
}

