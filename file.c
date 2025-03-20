#include "file.h"
#include <stdio.h>
#include <stdlib.h>


Directory *createDirectory(Directory *parent, char *name) {
   Directory *dir = (Directory *)malloc(sizeof(Directory));
   if(dir == NULL) {
      printf("Could not allocate memory");
      return NULL;
   }
   
   dir->name = strdup(name);
   dir->parent = parent;
   dir->child = NULL;
   dir->siblings = NULL;
   
   if(parent != NULL) {
      if(parent->child != NULL) {
         parent->child = dir;
      }
      else {
         Directory *dirSib = parent->child;
         
         
      }
   
   
   
   }
   
   return dir;
   
   

}

File createFile(Directory *parent, char *name, int size) {
   File *file = (File *)malloc(sizeof(File));
   if(file == NULL) {
      printf("Could not allocate memory");
      return NULL;
   }
   
   file->name = strdup(name);
   file->parent = parent;
   file->size = size;
   
   return file;

}

void listDirectory(Directory dir, int depth) {

}

void searchDirectory(Directory dir, char *targetName) {


}

void freeDirectory(Directory dir) {

}

void freeFile(File *file) {
   free(file->name);
   free(file);
}



