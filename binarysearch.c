#include <stdio.h>

int binarysearch(int arr[], int start, int end, int search_element) {
    int mid = (start+end)/2;

    if(end >= start) {
        if(arr[mid] == search_element)
            return mid;
        else if(arr[mid] > search_element)
            return binarysearch(arr, start, mid-1, search_element);
        else if(arr[mid] < search_element)
            return binarysearch(arr, mid+1, end, search_element);
    }
    return -1;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n) {
    int min;

    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}
int main() {
    int n, search_element;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &search_element);

    selection_sort(arr, n);

    int flag = binarysearch(arr, 0, n, search_element);

    if(flag == -1)
        printf("Element was not found\n");
    else
        printf("Element was found\n");
}
