#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int filled[MAX_SIZE];
int rear = -1;

void add_element(int data);
void remove_element(int position);
int find_element(int data);
void print_queue();

int main() {
    int choice, data, position, found;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element by Index\n");
        printf("3. Find and Remove Element\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                add_element(data);
                break;
            case 2:
                printf("Enter the position of the element to remove: ");
                scanf("%d", &position);
                remove_element(position);
                break;
            case 3:
                printf("Enter the element to find and remove: ");
                scanf("%d", &data);
                found = find_element(data);
                if (found != -1)
                    remove_element(found);
                else
                    printf("Element not found in the queue.\n");
                break;
            case 4:
                print_queue();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void add_element(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    rear++;
    queue[rear] = data;
    filled[rear] = 1;
    printf("Element added to the queue: %d\n", data);
}

void remove_element(int position) {
    if (position < 0 || position > rear) {
        printf("Invalid position.\n");
        return;
    }
    if (filled[position]) {
        for (int i = position; i < rear; i++) {
            queue[i] = queue[i + 1];
            filled[i] = filled[i + 1];
        }
        rear--;
        printf("Element at position %d removed from the queue.\n", position);
    } else {
        printf("No element at position %d.\n", position);
    }
}

int find_element(int data) {
    for (int i = 0; i <= rear; i++) {
        if (queue[i] == data && filled[i])
            return i;
    }
    return -1;
}

void print_queue() {
    if (rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= rear; i++) {
        if (filled[i])
            printf("%d ", queue[i]);
    }
    printf("\n");
}
