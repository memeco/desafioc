#include <stdio.h>

int main() {
    int i, j;
    
    for (i = 0; i < 5; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    while (j > 0) {
        printf("%d ", j);
        j--; 
    }
    printf("\n");

    do {
        printf("%d ", i);
        i++;
    } while (i != 10);
    printf("\n");

    int nums[] = {1, 2, 3, 4, 5};
    for (i = 0; i <= 5; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
