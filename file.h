#ifndef FILE_H
#define FILE_H

#define MAXSIZE 20

typedef struct Directory Directory;

typedef struct {
   char *name;
   int size;
   Directory *parent;
} File;

typedef struct Directory { 
   char *name;
   int childCount;
   int fileCount;
   Directory *parent;
   Directory *child[MAXSIZE];
   File *file[MAXSIZE];
} Directory;

#endif
