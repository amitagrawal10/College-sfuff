#include<stdio.h>
#include<omp.h>
#include<time.h>
void main()
{
clock_t start, end;
double cpu_time_used;
start = clock();
omp_set_num_threads(4);
int a=0;
#pragma omp parallel for
for(int i=0;i<=100000000;i++)
{
a = a+i;
}
printf("sum=%d\n",a);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Time=%f\n",cpu_time_used);
}

