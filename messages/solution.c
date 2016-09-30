#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word {
    long start_pos;
    long end_pos;
    char *word;
};

int cmp_end(const void *w1, const void *w2)
{
    return (((struct Word *)w1)->end_pos - ((struct Word *)w2)->end_pos);
}

int build_msg(char *msg)
{
    char c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '#') {
            return EOF;
        }
        if (c == '|') {
            msg[i] = '\0';
            return i;
        }
        if (c != '\n') {
            msg[i] = c;
            i++;
        }
    }

    return EOF;
}

int main()
{

    char dict[100][11];
    int r = 0;

    // build dictionary
    while (scanf("%s\n", dict[r]) != EOF && dict[r][0] != '#')
        r++;
    //printf("Found %d words in dict\n", r);

    // loop messages
    char msg[50001] = {0};
    int msg_len = 0;
    struct Word words[50000];
    while ((msg_len = build_msg(msg)) != EOF) {
        int words_found = 0;
        // find each occurence of each word
        for (int i = 0; i < r; i++) {
            char *remainder = msg;
            //printf("%d searching: %s in %s\n", i, dict[i], remainder);
            int word_len = strlen(dict[i]);
            char *found;
            while ((found = strstr(remainder, dict[i]))) {
                //printf("Found %s in %s\n", dict[i], remainder);
                long start = (long) (found - msg);
                words[words_found].start_pos = start;
                words[words_found].end_pos = start + word_len;
                words[words_found].word = dict[i];
                //printf("%s Start: %ld, End: %ld\n", words[words_found].word, words[words_found].start_pos, words[words_found].end_pos);
                remainder = found + word_len;
                words_found++;
            }
            //printf("Done search %d\n", i);
        }
        //printf("Words found %d\n", words_found);
        qsort(words, words_found, sizeof(struct Word), cmp_end);
        long non_overlapping = 0;
        long cursor = 0;
        for (long i = 0; i < words_found; i++) {
            long end = words[i].end_pos;
            long start = words[i].start_pos;
            //printf("%ld %ld", start, end);
            if (end > cursor && start >= cursor) {
                cursor = end;
                non_overlapping++;
                //printf("%s cursor: %d non_overlapping: %d", words[i].word, cursor, non_overlapping); 
            }
        }
        printf("%ld\n", non_overlapping);
        
    }

    return 0;
}
