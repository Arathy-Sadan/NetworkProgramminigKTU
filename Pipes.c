#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{ int n,f1,f2,f3,p1,p2,p3,fd1[2],fd2[2],fd3[2],a[10],i,j=0,rlt1[10],k=0,rlt2[10];
  printf("Enter n:");
  scanf("%d",&n);
  printf("Enter %d elements:\n",n);
  for(i=0;i<n;i++)
  scanf("%d",&a[i]); 
 p1=pipe(fd1);
 f1=fork();
 if(f1!=0)
 write(fd1[1],a,n);
 if(f1==0)
  {read(fd1[0],a,n);
  for(i=0;i<n;i++)
   if(a[i]%2==0)
    {
    rlt1[j]=a[i];
    j=++j;
    }
    p2=pipe(fd2);
    f2=fork();
    if(f2!=0)
    write(fd2[1],rlt1,n);
    if(f2==0)
    { read(fd2[0],rlt1,n);
      for(i=0;i<j;i++)
      if(rlt1[i]%5==0)
      {  rlt2[k]=rlt1[i];
       k=++k;
      }
     p3=pipe(fd3);
     f3=fork();
     if (f3!=0)
     write(fd3[1],rlt2,n);
     if(f3==0)
     { read(fd3[0],rlt2,n);
       printf("Resulting numbers are:\n");
       for(i=0;i<k;i++)
       {
        printf("\n %d",rlt2[i]);
       }
     } 
    }
 }
}
