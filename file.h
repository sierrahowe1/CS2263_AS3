#ifndef FILE_H
#define FILE_H
#define MAXSIZE 20

typedef struct {
   char *name;
   int size;
   Directory *parent;
}File;

typedef struct { 
   char *name;
   int *childCount
   int *sibCount
   int *fileCount
   Directory *parent;
   Dirctory *child[MAXSIZE];
   Directory *siblings[MAXSIZE];
   File *file[MAXSIZE];
}Directory;
#endif
