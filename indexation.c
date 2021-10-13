#include "push_swap.h"

static void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

static int get_index(int *arr, int item, int size)
{
    int i = 0;
    while (i < size)
    {
        if (arr[i] == item)
            break ;
        i++;
    }
    return (i);
}
void indexed(t_stack *stack)
{
    int *new_arr;
    int i = -1;

    new_arr = (int*)malloc(stack->size * sizeof(int));
    while (++i < stack->size)
        new_arr[i] = stack->arr[i]; 

    insertionSort(new_arr, stack->size);
    i = -1;
    while (++i < stack->size)
        stack->arr[i] = get_index(new_arr, stack->arr[i], stack->size);
    free(new_arr);
}