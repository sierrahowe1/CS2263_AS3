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
                printf("Enter species: ");
                scanf(" %[^\n]", species);
                printf("Enter Planet Name: ");
                scanf(" %[^\n]", planet_name);
                printf("Enter Age: ");
                scanf("%d", &age);
                addAlienPet(pets, &count, name, species, age, planet_name);

				
				
				
				
				
				
				
				
				
				
				
				
				
                break;

            case 2: // Display pets
                displayAllAlienPets(pets, count);
                break;

            case 3: // Exit
                
                freeAllAlienPets(pets, &count);
                return 0;

            default:
                
                break;
        }
    }

    return 0; 





}
