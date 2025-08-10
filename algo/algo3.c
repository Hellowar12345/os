#include<stdio.h>
#include<stdbool.h>
#include<pthread.h>
#include <unistd.h>
#define Pi 0
#define Pj 1
int turn=Pi;
bool flag[2]={false,false};//flag[0] for Pi, flag[1] for Pj
  //process i
void *process_i(void *arg) {
   while(1){
    flag[Pi]=true;//我想進去
    while(flag[Pj]&&turn==Pj);//鑰匙在Pj身上且Pj有意願進去
    //critical section
    printf("Process i in critical section\n");
    usleep(500000);//用sleep模擬正在跑這段section的程式
    turn=Pj;出來後把鑰匙給Pj
    flag[Pi]=false;//出來後改成沒意願
    //remainder section
    usleep(500000);
  }
}
//process j
void *process_j(void *arg) {
  while(1){
    flag[Pj]=true;
    while(flag[Pi]&&turn==Pi);
    //critical section
    printf("Process j in critical section\n");
    usleep(500000);
    turn=Pi;
    flag[Pj]=false;
    //remainder section
    usleep(500000);
  }
}
int main(){
  pthread_t t1,t2;
  pthread_create(&t1, NULL, process_i, NULL);
  pthread_create(&t2, NULL, process_j, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
