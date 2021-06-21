#include<stdio.h>
#include<unistd.h>
void main(){
int pi_id;
int pid;
pi_id = fork();
if(pi_id==0){
printf("child process B : \npid : %d\nppid : %d\n",getpid(),getppid());
}
if(pi_id>0){
pid = fork();
if(pid>0){
printf("parent process  : \npid : %d\nppid : %d\n",getpid(),getppid());
}
else if(pid==0){
printf("child process A : \npid : %d\nppid : %d\n",getpid(),getppid());
}

}

}
