#include<stdio.h> 
#include<pthread.h> 
 //function prototype. 
void * add(void *); 
 //Variable to count the executed thread. 
int end; 
 //main function. 
int main() 
{
pthread_t tid1,tid2; 
 pthread_attr_t attribute; 
 pthread_attr_init(&attribute); 
 //function to set detach property of the thread. 
pthread_attr_setdetachstate(&attribute,PTHREAD_CREATE_DETACHED); 
 pthread_create(&tid1,&attribute,add,(void *)1); 
 pthread_create(&tid2,&attribute,add,(void*)2); 
 //to wait for the thread to finish execution. 
 while(end<2) 
 { 
 } 
} 
 //function prototype for the thread function. 
void * add(void * args) 
{ 
 int a,b; 
 printf("\nEntered into %d thread\n",args); 
 
 printf("\nEnter the first number for thread %d\n",args); 
 scanf("%d",&a); 
 printf("\nEnter the second number for thread %d\n",args); 
 scanf("%d",&b); 
 printf("The average computed by thread %d:\t%d\n",args,(a+b)/2); 
 end++; 
}
