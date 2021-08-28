#include <stdio.h>
struct Player {
    char name[10];
    int jerseyNumber;
    char strongFoot;
};
int main() {
    struct Player players[1];
    for(int i=0;i<5;i++) {
        printf("Player name Jersey No. Strong Foot\n");
        scanf("%s %d %c",players[i].name,&players[i].jerseyNumber,&players[i].strongFoot);
    }
    for(int i=0;i<5;i++) {
        printf("\n%s %d %c\n",players[i].name,players[i].jerseyNumber,players[i].strongFoot);
    }
    return 0;
}
