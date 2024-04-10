#include "podisplay.h"
#include "polist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#define public extern
#define private static

const char *path = "./DotFiles/";
#define MAX_LEN 128

private void Create_Dotfiles();
private void Create_File(const char* restrict);
private void Append_File(const char *restrict, const char *restrict, ...);

public void 
Display_List(const list_t *t, const char *restrict src) {
    char *fn= (char *)malloc(MAX_LEN);
    strncpy(fn, path, strlen(path));
    strncpy(fn + strlen(path), src, strlen(src));
    Create_Dotfiles();
    Create_File(fn);
    
    Append_File(fn, "digraph G {\n");
    Append_File(fn, "rankdir = LR; \n");
    assert(t);
    node_t *curr = List_Begin(t);
    // define the node type
    int i = 0;
    while (curr) {
        Append_File(fn, "node%d[label=\"%d\"];\n", i, *(int *)curr->val);
        i++;
        curr = Node_Next(curr);
    }
    Append_File(fn, "\n");
    // define the link for the list
    curr = List_Begin(t); i = 0;
    while (curr) {
        if (Node_Next(curr)) {
            Append_File(fn, "node%d -> node%d;\n", i, i + 1);
        } else {
            Append_File(fn, "node%d -> TailNull;\n", i);
        }
        curr = Node_Next(curr); i++;
    }
    curr = List_End(t); i = List_Size(t) - 1;
    while (curr) {
        if (Node_Prev(curr)) {
            Append_File(fn, "node%d -> node%d;\n", i, i - 1);
        } else {
            Append_File(fn, "node%d -> HeadNull;\n", i);
        }
        curr = Node_Prev(curr); i--;
    }
    Append_File(fn, "}\n");
}

private void
Create_File(const char *restrict fn) {
    FILE *fp;

    fp = fopen(fn, "w");
    setbuf(fp, NULL);
    if (fp == NULL) {
        perror("File open error!\n");
        exit(1);
    }
    fprintf(fp, "\n");
}

private void 
Append_File(const char *restrict fn, const char *restrict ct, ...) {
    FILE *fp;

    fp = fopen(fn, "a");
    if (fp == NULL) {
        perror("File open error!\n");
        exit(1);
    }
    va_list args;
    va_start(args, ct);
    vfprintf(fp, ct, args);
    va_end(args);
    fclose(fp);
}

private void 
Create_Dotfiles() {
    int rc;

    struct stat buffer;
    rc = stat(path, &buffer);
    if (rc == 0 && S_ISDIR(buffer.st_mode)) { // Check the directory
        return;
    } 
    const char* command = "mkdir ./DotFiles";
    rc = system(command);
    assert(rc == 0);
}

#undef public

