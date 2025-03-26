#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAXSIZE 20

Directory *createDirectory(Directory *parent, char *name) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    if (dir == NULL) {
        printf("Could not allocate memory\n");
        return NULL;
    }

    dir->name = strdup(name); 
    if(dir->name == NULL) {
       free(dir);
       printf("Could not allocate memory.\n");
    }
    dir->parent = parent;     
    dir->childCount = 0;      
    dir->fileCount = 0;  
        

    if (parent != NULL) {
        if (parent->childCount >= MAXSIZE) {
            printf("Cannot add any more directories");
            free(dir->name);
            free(dir);
            return NULL;
        }
        
        for (int i = 0; i < parent->childCount; i++) {
        	if (strcmp(parent->child[i]->name, name) == 0) {
        		printf("Directory already exist\n");
        		free(dir->name);
                        free(dir);
                        return NULL;
        	}
        }
        parent->child[parent->childCount] = dir;
        parent->childCount++;
    }

    return dir; 
}

Directory *findDirectory(Directory *dir, char *targetName) {
    if (dir == NULL) {
        return NULL;
    }
    if (strcmp(dir->name, targetName) == 0) {
        return dir;
    }
    for (int i = 0; i < dir->childCount; i++) {
        Directory *found = findDirectory(dir->child[i], targetName);
        if (found != NULL) {
            return found;
        }
    }
    return NULL;  
}


File *createFile(Directory *parent, char *name, int size) {
   File *file = (File *)malloc(sizeof(File));
   if(file == NULL) {
      printf("Could not allocate memory");
      return NULL;
   }

   if(parent->fileCount >= MAXSIZE) {
      free(file);
      printf("Cannot add any more files to this directory ");
   	
   }
   else {
        file->name = strdup(name);
        file->parent = parent;
        file->size = size;
   }
   
   for (int i = 0; i < parent->fileCount; i++) {
        	if (strcmp(parent->file[i]->name, name) == 0) {
        		printf("File already exist\n");
                        free(file);
                        return NULL;
        	}
        }
   parent->file[parent->fileCount] = file;
   parent->fileCount++;

   return file;
}


void listDirectory(Directory *dir, int depth) {
   if (dir == NULL) {
       return;
   }   
   
   for (int i = 0; i < depth; i++) {
      printf(" "); 
   }
   printf("-%s\n", dir->name);
   
   for (int i = 0; i < dir->childCount; i++) {
      listDirectory(dir->child[i], depth + 1);
   }
   
   for (int i = 0; i < dir->fileCount; i++) {
        for (int j = 0; j < depth+1; j++) { 
            printf(" ");
        }
        printf("-%s\n", dir->file[i]->name);
    }
}

void pathTo(Directory *dir) {
   if (dir == NULL) {
      return;
   }
   if (dir->parent != NULL) {
      pathTo(dir->parent);
      printf("/%s", dir->name);
   }
   else {
      printf("%s", dir->name);
   }
}

void searchDirectory(Directory *dir, char *targetName) {

   if(dir == NULL) {
      return;
   }
   if(strcmp(dir->name, targetName) == 0) {
      printf("The directory has been found. ");
      pathTo(dir);
      printf("\n");
   }
   
   for(int i = 0; i < dir->fileCount; i++) {
      if(strcmp(dir->file[i]->name, targetName) == 0) {
       printf("This file has been found: %s\n", dir->file[i]->name);
       pathTo(dir);
       printf("\n");
      }
   }

   for(int i = 0; i < dir->childCount; i++) {
      searchDirectory(dir->child[i], targetName);
   }

}

void freeDirectory(Directory *dir) {
    if(dir == NULL) {
      return;
    }
    for(int i = 0; i < dir->fileCount; i++) {
       if(dir->file[i] != NULL) {
          free(dir->file[i]->name);
          free(dir->file[i]);
       }
    }

    for(int i = 0; i < dir->childCount; i++) {
       if(dir->child[i] != NULL) {
          freeDirectory(dir->child[i]);
       }
    }
    free(dir->name);
    free(dir);
}
