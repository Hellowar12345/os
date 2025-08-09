#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool flag[2] = {false, false};
int turn;

void *process_i(void *arg) {
    int id = 0;
    int other = 1;
    while (1) {
        flag[id] = true;
        turn = other;
        while (flag[other] && turn == other);
        
        // critical section
        printf("Process %d in critical section\n", id);
        
        flag[id] = false;
        // remainder section
    }
}

void *process_j(void *arg) {
    int id = 1;
    int other = 0;
    while (1) {
        flag[id] = true;
        turn = other;
        while (flag[other] && turn == other);
        
        // critical section
        printf("Process %d in critical section\n", id);
        
        flag[id] = false;
        // remainder section
    }
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, process_i, NULL);
    pthread_create(&t2, NULL, process_j, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
