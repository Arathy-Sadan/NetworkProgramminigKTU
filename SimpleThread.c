#include<stdio.h> 
#include<pthread.h> 
#include<stdlib.h>
void* add(void*); //prototype of the thread function. 
int main() //main function (return type should be int in linux). 
{ 
int error; //variable to check error (optional)
pthread_t thread_id; //variable to store thread id.
pthread_attr_t thread_attribute; //variable to store properties of thread.
pthread_attr_init(&thread_attribute); //function call for setting the default properties.
error=pthread_create(&thread_id,&thread_attribute,add,NULL); //function for thread 


 //error checking (optional) 
 if(error!=0) 
 { 
 printf("\nError in thread creation.\n"); 
 exit(0); 
 } 
error=pthread_join(thread_id,NULL); //function for thread calling. 
//error checking (optional) 
if(error!=0) 
 { printf("\nError in thread joining.\n"); 
 exit(0); 
 } 
} //function definition for the thread function. 
void * add(void *args) 
{ int a,b; 
 printf("\nEnter the first number.\n"); 
 scanf("%d",&a); 
 printf("\nEnter the second number.\n"); 
 scanf("%d",&b); 
 printf("\nThe sum is:\t%d\n",a+b); 
}
