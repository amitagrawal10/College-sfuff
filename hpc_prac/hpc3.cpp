#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <stdlib.h>
int main(){
        omp_set_num_threads(4);
        clock_t start, end;
        int i, j, changes = 0;
        //printf("Enter the number of elements : ");
        //scanf("%d", &n);
        int n = 20000;
        int arr[n], arr2[n];
        //printf("\nEnter the contents of the array :\n");
        for( i = 0; i < n; i ++)
                arr[i] = rand()%n;
        for( i = 0; i < n; i ++)
                arr2[i] = arr[i];
        //Part without using parallel computing
        start = clock();
        double cpu_time_used;
        for(i = 0; i < n; i ++)
                for(j = i; j < n; j ++)
                        if(arr[j]<arr[i]){
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                                changes++;
                        }
        end = clock();
        /*for( i = 0; i < n; i ++)
                printf("%d", arr[i]);
        */      
        printf("Number of changes are %d\n", changes);
        cpu_time_used = ((double) (difftime(end,start))) /CLOCKS_PER_SEC;
        printf("\nTime taken for Bubble Sort without parallel computing : %f\n",cpu_time_used);
        
        //Part with implementing parallel computing
        start = clock();
        changes = 0;
        int temp;
        //#pragma omp parallel private(temp)
        for(j = 0; j < n/2; j++){   
            #pragma omp parallel for private(temp) reduction(+:changes)
            for(i = 0; i < n - 1; i = i + 2)
                    if(arr2[i] > arr2[i+1] ){
                            temp = arr2[i];
                            arr2[i] = arr2[i+1];
                            arr2[i+1] = temp;
                            changes++;
                            //printf("change number %d in thread %d\n", changes, omp_get_thread_num());
                    }
            #pragma omp parallel for private(temp) reduction(+:changes)
            for(i = 1; i < n - 1; i = i + 2)
                    if( arr2[i] > arr2[i+1] ){
                            temp = arr2[i];
                            arr2[i] = arr2[i+1];
                            arr2[i+1] = temp;
                            changes++;
                            //printf("change number %din thread %d\n", changes, omp_get_thread_num());
                    }
        }

        end = clock();
        /*for( i = 0; i < n; i ++)
                printf("%d", arr2[i]);
        */
        printf("\nNumber of changes are %d\n", changes);
        cpu_time_used = ((double) (difftime(end,start))) /CLOCKS_PER_SEC;
        printf("\nTime taken for Bubble Sort with parallel computing : %f\n",cpu_time_used);
        
        return 0;

}
