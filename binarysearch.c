#include <stdio.h>

int binarysearch(int arr[], int start, int end, int search_element) {
    int mid = (start+end)/2;

    if(arr[mid] == search_element)
        return mid;
    else if(arr[mid] > search_element)
        binarysearch(arr, start, mid-1, search_element);
    else
        binarysearch(arr, mid+1, end, search_element);
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

    int index = binarysearch(arr, 0, n, search_element);

    printf("Index of searched element is: %d\n", index);
}
