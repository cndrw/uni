#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_elements = 0;

    printf("Give size:");
    scanf("%d", &num_of_elements);

    int* arr = (int*)malloc(num_of_elements * sizeof(int));
    
    if(arr == NULL)
    {
        printf("Memory not Allocated\n");
        exit(0);
    }

    for(int i = 0; i < num_of_elements; i++)
    {
        arr[i] = i + 1;
        printf("%d\n", arr[i]); 
    }

    free(arr);
    
    return 0;
}
