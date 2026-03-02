#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // Terminate if score is 1 or less
        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Nested loops to check every combination of scoring plays:
        // td2: TD + 2pt conversion (8 pts)
        // td1: TD + 1pt field goal (7 pts)
        // td:  Standard TD (6 pts)
        // fg:  3pt Field Goal (3 pts)
        // s:   Safety (2 pts)
        
        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td1 = 0; td1 * 7 <= score - (td2 * 8); td1++) {
                for (int td = 0; td * 6 <= score - (td2 * 8 + td1 * 7); td++) {
                    for (int fg = 0; fg * 3 <= score - (td2 * 8 + td1 * 7 + td * 6); fg++) {
                        for (int s = 0; s * 2 <= score - (td2 * 8 + td1 * 7 + td * 6 + fg * 3); s++) {
                            
                            // check if the current combination equals the target score
                            if ((td2 * 8 + td1 * 7 + td * 6 + fg * 3 + s * 2) == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                       td2, td1, td, fg, s);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}