/* DO NOT TOUCH */
#include <stdio.h>

#define MAX_LENGTH 5

void printTitle(int);

typedef struct Song {
    int id;
    int duration;
    int play_count;
} Song;

/* YOUR CODE STARTS HERE */

void printSong(Song song);
void printTopFive(Song songs[MAX_LENGTH]);
void playSong(Song songs[MAX_LENGTH], int position);
void printUnplayedSongs(Song songs[MAX_LENGTH]);
void addNewSongToTopFive(Song songs[MAX_LENGTH], Song song, int position);
void exchangePosition(Song songs[MAX_LENGTH], int positionSong1, int positionSong2);


/* DO NOT TOUCH */
int main(void) {
    Song songs[5] = {
        {1, 220, 0},
        {2, 216, 0},
        {3, 194, 0},
        {4, 180, 5},
        {5, 211, 0}
    };
    Song song;

    int option = 0;
    int position1 = 0;
    int position2 = 0;

    do {
        printf("------------\n");
        printf("1 = Display song\n");
        printf("2 = Display current Top 5 hits\n");
        printf("3 = Play song\n");
        printf("4 = Display songs, that haven't been played\n");
        printf("5 = Add new song\n");
        printf("6 = Swap position of 2 songs\n");
        printf("-1 = Exit program\n");
        printf("------------\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Position: ");
                scanf("%d", &position1);
                if (position1 > 0 && position1 <= MAX_LENGTH) {
                    printSong(songs[position1-1]);
                }
                break;
            case 2:
                printTopFive(songs);
                break;
            case 3:
                printf("Position: ");
                scanf("%d", &position1);
                if (position1 > 0 && position1 <= MAX_LENGTH) {
                    playSong(songs, position1);
                }
                break;
            case 4:
                printUnplayedSongs(songs);
                break;
            case 5:
                printf("Position: ");
                scanf("%d", &position1);
                printf("ID: ");
                scanf("%d", &song.id);
                printf("Duration (in seconds): ");
                scanf("%d", &song.duration);
                song.play_count = 0;

                if (position1 > 0 && position1 <= MAX_LENGTH) {
                    addNewSongToTopFive(songs, song, position1);
                }
                break;
            case 6:
                printf("Position Song 1: ");
                scanf("%d", &position1);
                printf("Position Song 2: ");
                scanf("%d", &position2);
                if (position1 > 0 && position1 <= MAX_LENGTH && position2 > 0 && position2 <= MAX_LENGTH) {
                    exchangePosition(songs, position1, position2);
                }
                break;
        }
    } while (option != -1);

    return 0;
}

void printTitle(int id)
{
    printf("\"");
    switch (id) {
        case 1:
            printf("Atemlos durch die Nacht");
            break;
        case 2:
            printf("Mama Laudaaa");
            break;
        case 3:
            printf("Das rote Pferd");
            break;
        case 4:
            printf("Hulapalu");
            break;
        case 5:
            printf("Die immer lacht");
            break;
        default:
            printf("(New release)");
            break;
    }
    printf("\"");
}

void printSong(Song song)
{
    printf("ID: %d\n", song.id);
    printf("Title: ");
    printTitle(song.id);
    printf("\n");
    int minutes = song.duration / 60;
    int seconds = song.duration % 60;
    printf("Duration: %02d:%02d\n", minutes, seconds);
    printf("Played today: %d\n\n", song.play_count);
}

void printTopFive(Song songs[MAX_LENGTH])
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        printf("### %d ###\n", i+1);
        printSong(songs[i]);
    }
}


void playSong(Song songs[MAX_LENGTH], int position)
{
    int i = position-1;
    if (songs[i].play_count >= 5)
    {
        printTitle(songs[i].id);
        printf(" was played too often today...\n");
        printf("Play another song!\n");
    }
    else
    {
        songs[i].play_count++;
        printTitle(songs[i].id);
        printf(" will be played next.\n");
    }
}

void printUnplayedSongs(Song songs[MAX_LENGTH])
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (songs[i].play_count == 0)
        {
            printSong(songs[i]);
        }
    }
}

void addNewSongToTopFive(Song songs[MAX_LENGTH], Song song, int position)
{
    int i = position-1;
    songs[i].id = song.id;
    songs[i].duration = song.duration;
    songs[i].play_count = 0;
}

void exchangePosition(Song songs[MAX_LENGTH], int positionSong1, int positionSong2)
{
    int i1 = positionSong1-1;
    int i2 = positionSong2-1;
    int duration1 = songs[i1].duration;
    int duration2 = songs[i2].duration;
    int play_count1 = songs[i1].play_count;
    int play_count2 = songs[i2].play_count;

    songs[i1].id = positionSong2;
    songs[i2].id = positionSong1;
    songs[i1].duration = duration2;
    songs[i2].duration = duration1;
    songs[i1].play_count = play_count2;
    songs[i2].play_count = play_count1;

}
