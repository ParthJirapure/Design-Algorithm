#include <stdio.h>

int linearSearch(int a[], int index, int n, int key);
void readArray(int a[], int n);

int main() {
    int a[20], n, key, pos;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    readArray(a, n);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    pos = linearSearch(a, 0, n - 1, key);

    if (pos == -1) {
        printf("Key element %d not found.\n", key);
    } else {
        printf("Key element %d found at position: %d\n", key, pos);
    }

    return 0;
}

void readArray(int a[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int linearSearch(int a[], int index, int n, int key) {
    if (index > n) {
        return -1;
    }
    if (a[index] == key) {
        return index;
    }
    return linearSearch(a, index + 1, n, key);
}