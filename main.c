#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Directory *createDirectory(Directory *parent, char *name);
File *createFile(Directory *parent, char *name, int size);
void listDirectory(Directory *dir);

int main(int argc, char * * argv) {

    Directory *root = createDirectory(NULL, "root");
    int choice;
    char name[MAXSIZE];
    int size;

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
                createDirectory(root, name);
                break;

            case 2:
                printf("Enter File Name: ");
                scanf(" %s", name);
                printf("Enter File Size: ");
                scanf("%d", &size);
                createFile(root, name, size);
                break;

            case 3:
                listDirectory(root);
                break;

            case 4:
                printf("Invalid choice. Please try again.\n");
                break;

            case 5:
                printf("Invalid choice. Please try again.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
