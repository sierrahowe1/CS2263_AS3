#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


void *createDirectory(Directory *parent, char *name) {
   Directory *dir = (Directory *)malloc(sizeof(Directory));
   if(dir == NULL) {
      printf("Could not allocate memory");
      return NULL;
   }
   
   if(parent->childCount >= 20) {
   	printf("Not today");
   }
   else {
        dir->name = strdup(name);
        dir->parent = parent;
        dir->child = NULL;
        dir->siblings = parent->child;
   }
   parent->child[parent->childCount] = dir;
   parent->childCount++;
}

void createFile(Directory *parent, char *name, int size) {
   File *file = (File *)malloc(sizeof(File));
   if(file == NULL) {
      printf("Could not allocate memory");
      return NULL;
   }

   if(parent->fileCount >= 20) {
   	printf("Not today");
   }
   else {
        file->name = strdup(name);
        file->parent = parent;
        file->size = size;
   }
   parent->file[parent->fileCount] = file;
   parent->fileCount++;
}


void listDirectory(Directory *dir) {
   printf("%s\n", dir->name);
   for (int i = 0; i < dir->childCount; i++) {
      printf(" -");
      listDirectory(dir->child[i]);
   }
   for (int i = 0; i < dir->fileCount; i++) {
      printf(" -%s\n", dir->file[i]->name);
   } 
}

void searchDirectory(Directory dir, char *targetName) {


}

void freeDirectory(Directory dir) {

}

void freeFile(File *file) {
   free(file->name);
   free(file);
}



