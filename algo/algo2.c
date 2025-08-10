#include<stdio.h>
#include<stdbool.h>
#include<pthread.h>
#include <unistd.h>
#define Pi 0
#define Pj 1
bool flag[2]={false,false};//flag[0] for pi, flag[1] for pj
  //process i
void *process_i(void *arg) {
   while(1){
    flag[Pi]=true;//我想進去
    while(flag[j]);//先等j沒意願（在remainder section）
    //critical section
    printf("Process i in critical section\n");
    usleep(500000);//用sleep模擬正在跑這段section的程式
    flag[Pi]=false;//出來後改成沒意願
    //remainder section
    usleep(500000);
  }
}
//process j
void *process_j(void *arg) {
  while(1){
    flag[Pj]=true;
    while(flag[Pi]);
    //critical section
    printf("Process j in critical section\n");
    usleep(500000);
    flag[Pj]=false;
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
