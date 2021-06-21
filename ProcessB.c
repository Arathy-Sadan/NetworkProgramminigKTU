#include<stdio.h>
#include<unistd.h>
void main(){
int pi_d;
int pid1,pid2,pid3;
pi_d=fork();
if(pi_d>0){
printf("parent process  : \npid : %d\nppid : %d\n",getpid(),getppid());
pid1=fork();
if(pid1==0){
printf("child process 1 : \npid : %d\nppid : %d\n",getpid(),getppid());
pid2=fork();
if(pid2==0){
printf("child process 2 : \npid : %d\nppid : %d\n",getpid(),getppid());
pid3=fork();
if(pid3==0){
printf("child process 3 : \npid : %d\nppid : %d\n",getpid(),getppid());
}
}


}

}

}
