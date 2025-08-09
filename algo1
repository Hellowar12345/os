#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#define Pi 0
#define Pj 1
int turn=Pi;
  //process i
void *process_i(void *arg) {
   while(1){
    while(turn==Pj);//現在Pj能進(鑰匙在Pj手上),要等到Pj出來把鑰匙給Pi才能進
    //critical section
    printf("Process i in critical section\n");
    usleep(500000);//用sleep模擬正在跑這段section的程式
    turn=Pj;//出來後把鑰匙給Pj
    //remainder section
    usleep(500000)
  }
}
//process j
void *process_j(void *arg) {
  while(1){
    while(turn==Pi);
    //critical section
    printf("Process j in critical section\n");
    usleep(500000);
    turn=Pi;
    //remainder section
    usleep(500000);
  }
}
int main(){
  pthread_t t1, t2;
  pthread_create(&t1, NULL, process_i, NULL);
  pthread_create(&t2, NULL, process_j, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
