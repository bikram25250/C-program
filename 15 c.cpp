#include <stdio.h>
#include <stdlib.h> // for exit()

int f[50], i, k, j, inde[50], n, c, p;

int main() {
    // Initialize all blocks as free (0)
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    do {
        // Input index block
        printf("Enter index block: ");
        scanf("%d", &p);

        // Check if the block is already allocated
        if (f[p] == 0) {
            f[p] = 1;
            printf("Enter the number of files on the index: ");
            scanf("%d", &n);
        } else {
            printf("Block already allocated\n");
            continue;
        }

        // Input the blocks for the indexed file
        printf("Enter the blocks for the indexed file:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &inde[i]);
        }

        // Check if any of the blocks are already allocated
        int already_allocated = 0;
        for (i = 0; i < n; i++) {
            if (f[inde[i]] == 1) {
                printf("Block %d is already allocated\n", inde[i]);
                already_allocated = 1;
                break;
            }
        }

        // If no blocks are already allocated, mark them as allocated
        if (!already_allocated) {
            for (j = 0; j < n; j++) {
                f[inde[j]] = 1;
            }

            // Output the allocation details
            printf("\nAllocation successful");
            printf("\nFile indexed at block %d", p);
            for (k = 0; k < n; k++) {
                printf("\n %d -> %d: %d", p, inde[k], f[inde[k]]);
            }
        }

        // Ask if more files should be added
        printf("\nEnter 1 to enter more files and 0 to exit: ");
        scanf("%d", &c);
        
    } while (c == 1);

    return 0;
}

