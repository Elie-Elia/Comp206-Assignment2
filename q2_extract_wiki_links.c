#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    size_t sz;
    fseek(file, 0L, SEEK_END);
    sz = ftell(file);
    rewind(file);

    char file_data_array[sz + 1];
    fread(file_data_array, 1, sz + 1, file);
    file_data_array[sz] = '\0';

    char *link = strstr(file_data_array, "<a href=\"/wiki/");
    char *endoflink = strstr(link, "</a>");

    char *entirefile = file_data_array;
    char *links = strstr(entirefile, "<a href=\"/wiki/");
    while (links != NULL) {
        entirefile = strstr(links, "</a>");
        char *title = strstr(links, "\" ");

        if (title == NULL || (title - links) > (entirefile - links)) {
            links = strstr(entirefile, "<a href=\"/wiki/");
        continue;
    }
    int i = 15;
    while (links[i] != '\"') {
        printf("%c", links[i]);
        i++;
    }
    printf("\n");
    links = strstr(entirefile, "<a href=\"/wiki/");
}
    fclose(file);
return 0;
}

