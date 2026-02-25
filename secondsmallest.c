#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int secondSmallest = arr[1];

    if (smallest > secondSmallest) {
        int temp = smallest;
        smallest = secondSmallest;
        secondSmallest = temp;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Second smallest element is: %d\n", secondSmallest);

    return 0;
}
