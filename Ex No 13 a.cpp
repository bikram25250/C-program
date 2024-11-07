#include <stdio.h>

int main() {
    int i = 0, j = 0, k = 0, i1 = 0, m, n, rs[30], flag = 1, p[30];
    
    // Clear the screen (in Linux/Unix systems). 
    // On Windows, use system("cls"); instead.
    system("clear");  
    
    printf("FIFO page replacement algorithm...\n");
    
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    
    printf("Enter the reference string (end with 0):\n");
    while (1) {
        scanf("%d", &rs[i]);
        if (rs[i] == 0) 
            break; // Exit the loop when 0 is encountered.
        i++;
    }
    m = i; // The length of the reference string.
    
    // Initialize all frame slots to 0 (empty).
    for (j = 0; j < n; j++) {
        p[j] = 0;
    }

    for (i = 0; i < m; i++) {
        flag = 1;
        
        // Check if the reference string value is already in the frames.
        for (j = 0; j < n; j++) {
            if (p[j] == rs[i]) {
                printf("Data already in page...\n");
                flag = 0;
                break;
            }
        }

        // If not in the frames, replace the page using FIFO.
        if (flag == 1) {
            p[i1] = rs[i];  // Replace page in frame.
            i1++;
            k++;  // Increment the page fault count.
            
            if (i1 == n) {
                i1 = 0;  // Circularly move to the next frame.
            }

            // Display the current state of the frames.
            for (j = 0; j < n; j++) {
                printf("Page %d: %d", j + 1, p[j]);
                if (p[j] == rs[i]) {
                    printf(" *");  // Mark the most recent page replacement.
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    
    // Output the total number of page faults.
    printf("Total number of page faults = %d\n", k);

    return 0;
}

