int main(int argc, char * * argv) {


    while (1) {
        // Display menu
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
                scanf(" %[^\n]", name);  
          
                createDirectory();
				
                break;

            case 2: // Display pets
                displayAllAlienPets(pets, count);
                break;

            case 3: // Exit
                
                freeFile();
                return 0;

            default:
                
                break;
        }
    }

    return 0; 





}
