#include <stdio.h>

char *game_play[5] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};
int game_play_score[5] = {8, 7, 6, 3, 2};

void print_possible_combinations(int score_to_reach, int *running_plays, int play_index, int parent_plays[2000][5], int *all_plays){

    if (score_to_reach == 0){

        int current_play[5] = {0, 0, 0, 0, 0};
        for (int _play_index = 0; _play_index < play_index; _play_index++){
            current_play[running_plays[_play_index]] += 1;
        }

        for (int _play_index = 0; _play_index < *all_plays; _play_index++){
            int is_present = ((parent_plays)[_play_index][0] == current_play[0])
                    && ((parent_plays)[_play_index][1] == current_play[1])
                    && ((parent_plays)[_play_index][2] == current_play[2])
                       && ((parent_plays)[_play_index][3] == current_play[3])
                          && ((parent_plays)[_play_index][4] == current_play[4]);
            if (is_present) return;
        }

        (parent_plays)[*all_plays][0] = current_play[0];
        (parent_plays)[*all_plays][1] = current_play[1];
        (parent_plays)[*all_plays][2] = current_play[2];
        (parent_plays)[*all_plays][3] = current_play[3];
        (parent_plays)[*all_plays][4] = current_play[4];

        for (int i = 0; i < 5; i++){
            printf("%d %s ", current_play[i], game_play[i]);
        }
        printf("\n");
        *all_plays = *all_plays + 1;
    }

    if (score_to_reach < 0) return;

    for (int i = 0; i < 5; i++){

        int score = game_play_score[i];
        if (score_to_reach >= score){
            running_plays[play_index++] = i;
            print_possible_combinations(score_to_reach - score, running_plays, play_index, parent_plays, all_plays);
            play_index--;
        }
    }

}


int main(){
    int score_to_reach = 2;
    printf("Enter 0 or 1 to STOP\n");
    int running_plays[2000];
    int parent_plays[2000][5];
    int play_index = 0;
    for (int outer = 0; outer < 2000; outer++){
        for (int inner = 0; inner < 5; inner++){
            parent_plays[outer][inner] = 0;
        }
    }

    while (1) {
        printf("Enter the NFL Score: ");
        scanf("%d", &score_to_reach);
        if (score_to_reach == 0 || score_to_reach == 1) break;
        print_possible_combinations(score_to_reach, running_plays, 0, parent_plays, &play_index);
    }
    return 0;
}