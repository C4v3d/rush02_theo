#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "dictionary.h"

#define BUFFER_SIZE 1024

static char *trim(char *str) {
    char *end;
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
        str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r'))
        end--;
    end[1] = '\0';
    return str;
}

static t_dict_entry *create_entry(const char *number, const char *word) {
    t_dict_entry *entry = malloc(sizeof(t_dict_entry));
    if (!entry) return NULL;
    entry->number = strdup(trim((char *)number));
    entry->word = strdup(trim((char *)word));
    entry->next = NULL;
    return entry;
}

static void add_entry(t_dict_entry **head, t_dict_entry *new_entry) {
    if (*head == NULL) {
        *head = new_entry;
    } else {
        t_dict_entry *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

t_dict_entry *load_dictionary(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) return NULL;
    
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    t_dict_entry *head = NULL;

    char *line = NULL;
    size_t len = 0;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        char *start = buffer;
        char *newline = NULL;
        
        while ((newline = strchr(start, '\n')) != NULL) {
            *newline = '\0';
            if (line == NULL) {
                line = strdup(start);
            } else {
                line = realloc(line, len + (newline - start) + 1);
                strcat(line, start);
            }
            len = 0;
            char *colon = strchr(line, ':');
            if (colon) {
                *colon = '\0';
                t_dict_entry *entry = create_entry(line, colon + 1);
                if (entry) add_entry(&head, entry);
            }
            free(line);
            line = NULL;
            start = newline + 1;
        }
        if (*start != '\0') {
            len = strlen(start);
            line = malloc(len + 1);
            strcpy(line, start);
        }
    }
    if (line) free(line);
    close(fd);
    return head;
}

char *get_word(t_dict_entry *dict, const char *number) {
    while (dict) {
        if (strcmp(dict->number, number) == 0)
            return dict->word;
        dict = dict->next;
    }
    return NULL;
}

void free_dictionary(t_dict_entry *dict) {
    while (dict) {
        t_dict_entry *temp = dict;
        dict = dict->next;
        free(temp->number);
        free(temp->word);
        free(temp);
    }
}
