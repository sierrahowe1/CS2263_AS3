#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Directory *createDirectory(Directory *parent, char *name);
File *createFile(Directory *parent, char *name, int size);
void listDirectory(Directory *dir, int depth);
void searchDirectory(Directory *dir, char *targetName);
Directory *findDirectory(Directory *dir, char *targetName);
void freeDirectory(Directory *dir);

int main(int argc, char * * argv) {

    Directory *root = createDirectory(NULL, "root");
    int choice;
    char name[MAXSIZE];
    char pname[MAXSIZE];
    int size;
    char targetName[MAXSIZE];
    int depth = 0;
    Directory *parent;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create New Directory\n");
        printf("2. Create New File\n");
        printf("3. List Directory\n");
        printf("4. Search Directory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter Directory Name: ");
                scanf(" %s", name);   
                printf("Enter Parent Directory Name: ");
                scanf(" %s", pname);
                parent = findDirectory(root, pname);
                if (parent == NULL) {
                   printf("Error: Parent directory '%s' not found.\n", pname);
                } 
                else {
                   createDirectory(parent, name);s
                }
                break;

            case 2:
                printf("Enter File Name: ");
                scanf(" %s", name);
                printf("Enter Parent Directory Name: ");
                scanf(" %s", pname);
                printf("Enter File Size: ");
                scanf("%d", &size);
                parent = findDirectory(root, pname);
                if(parent == NULL) {
                   printf("Error: Parent directory '%s' not found.\n", pname);
                }
                else {
                   createFile(parent, name, size);
                }
                break;

            case 3:
                printf("Enter Directory Name: ");
                scanf(" %s", name);
                parent = findDirectory(root, name);
                listDirectory(parent, 0);
                break;

            case 4:
                printf("Enter Target Name: ");
                scanf("%s", targetName);
                searchDirectory(root, targetName);
                break;

            case 5:
                freeDirectory(root);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}  
