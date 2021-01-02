#include<stdio.h>
#include<omp.h>
#include<time.h>
void main()
{
clock_t start, end;
double cpu_time_used;
start = clock();
int a=0;
for(int i=0;i<=100000000;i++)
{
a = a+i;
}
printf("sum=%d",a);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Time=%f\n",cpu_time_used);
}
