#include <stdio.h>
#include <stdlib.h>

struct queue {
    int n;
    struct queue *next;
};

typedef struct queue node;

node *r = NULL, *f = NULL;

void add(int x) {
    node *t = (node *)malloc(sizeof(node));
    if (t == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    t->n = x;
    t->next = NULL;
    if (f == NULL) {
        f = r = t;
    } else {
        r->next = t;
        r = t;
    }
}

void del() {
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("The deleted item is %d\n", f->n);
    if (f == r) {
        free(f);
        f = r = NULL;
    } else {
        node *temp = f;
        f = f->next;
        free(temp);
    }
}

void display() {
    node *h = f;
    if (h == NULL) {
        printf("Empty queue. Nothing to display\n");
        return;
    }
    printf("The elements of the queue are: ");
    while (h != NULL) {
        printf("%d ", h->n);
        h = h->next;
    }
    printf("\n");
}

int main() {
    int ch, m;
    while (1) {
        printf("\nProgram on Queue\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d", &m);
                add(m);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}

