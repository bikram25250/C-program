#include <stdio.h>
#include <stdlib.h> // for exit()

int mutex = 1, full = 0, empty = 3, x = 0;

void producer();
void consumer();
int wait(int);
int signal(int);

int main() {
    int n;

    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    while(1) {
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) 
                    producer();
                else 
                    printf("BUFFER IS FULL\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else 
                    printf("BUFFER IS EMPTY\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produces item %d\n", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

