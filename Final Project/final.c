#include "finalfunctions.h"

#define ADMIN_PASS 1234

int main() 
{
    Patient* patientList = NULL;
    Slot* slotList = initializeSlots();
    int adminMode = 0;
    int loginAttempts = 0;
    int editID;
    printf("Welcome to the Clinic Management System!\n");
    while (1)
    {
        printf("Choose mode: 1 for Admin, 2 for User, 3 to Exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (adminMode == 0)
            {
                int password;
                do 
                {
                    printf("Enter admin password: ");
                    scanf("%u", &password);
                    if (password == ADMIN_PASS)
                    {
                        adminMode = 1;
                        printf("Admin mode activated.\n");
                    }
                    else 
                    {
                        loginAttempts++;
                        printf("Incorrect password. Attempts remaining: %d\n", 3 - loginAttempts);
                        printf("Entered password: %u\n", password);
                        if (loginAttempts >= 3)
                        {
                            printf("Too many incorrect attempts. Exiting...\n");
                            break;
                        }
                    }
                } while (adminMode == 0);
            }

            if (adminMode == 1)
            {
                printf("Admin Menu:\n");
                printf("1. Add new patient record\n");
                printf("2. Edit patient record\n");
                printf("3. Reserve a slot with the doctor\n");
                printf("4. Cancel reservation\n");
                printf("5. Exit Admin Mode\n");
                printf("");printf("");printf("");
                printf("Enter your choice: ");
                int adminChoice;
                scanf("%d", &adminChoice);

                switch (adminChoice)
                {
                    case 1:
                    {
                        int newID;
                        char newName[50];
                        int newAge;
                        char newGender[10];
                        int inputIsValid = 0;

                        do
                        {
                            char input[100];
                            printf("Enter patient ID (a number): ");
                            if (scanf("%s", input) != 1)
                            {
                                printf("Invalid input. Please enter a valid number.\n");
                                while (getchar() != '\n'); // Clear the input buffer
                            }
                            else
                            {
                                int inputLength = strlen(input);
                                int isNumeric = 1;

                                for (int i = 0; i < inputLength; i++)
                                {
                                    if (!isdigit(input[i]))
                                    {
                                        isNumeric = 0;
                                        break;
                                    }
                                }

                                if (!isNumeric)
                                {
                                    printf("Invalid input. Please enter a valid number.\n");
                                }
                                else
                                {
                                    newID = atoi(input);
                                    if (isPatientIDExists(patientList, newID))
                                    {
                                        printf("Patient with the same ID already exists.\n");
                                    }
                                    else
                                    {
                                        inputIsValid = 1;
                                    }
                                }
                            }
                        } while (!inputIsValid);
                        int isaAlpha;
                        do
                        {
                            printf("Enter patient name: ");
                            scanf("%s", newName);
                            int inputLength = strlen(newName);
                            isaAlpha = 1;

                            for (int i = 0; i < inputLength; i++)
                            {
                                if (!isalpha(newName[i]))
                                {
                                    isaAlpha = 0;
                                    break;
                                }
                            }

                            if (inputLength == 0 || !isaAlpha)
                            {
                                printf("Name cannot be empty and must contain only characters. Please enter a valid name.\n");
                                while (getchar() != '\n');
                            }
                        } while (strlen(newName) == 0 || !isaAlpha);
                        int ageIsValid; 
                        do
                        {
                            printf("Enter patient age: ");
                            if (scanf("%d", &newAge) != 1)
                            {
                                printf("Invalid input. Please enter a valid number for age.\n");
                                while (getchar() != '\n'); 
                                ageIsValid = 0; 
                            }
                            else if (newAge < 0 || newAge > 150)
                            {
                                printf("Invalid age. Please enter a valid age between 0 and 150.\n");
                                ageIsValid = 0; 
                            }
                            else
                            {
                                ageIsValid = 1; 
                            }
                        } while (!ageIsValid);
                        int genderIsValid;

                        do
                        {
                            printf("Enter patient gender (Male/Female/Other): ");
                            scanf("%s", newGender);

                            for (int i = 0; i <= strlen(newGender); i++)
                            {
                                newGender[i] = toupper(newGender[i]);
                            }

                            if (strcmp(newGender, "MALE") != 0 && strcmp(newGender, "FEMALE") != 0 && strcmp(newGender, "OTHER") != 0) 
                            {
                                printf("Invalid gender. Please enter a valid gender (Male/Female/Other).\n");
                                genderIsValid = 0; 
                            }
                            else
                            {
                                genderIsValid = 1; 
                            }
                        } while (!genderIsValid);

                        patientList = addPatient(patientList, newID, newName, newAge, newGender);
                        printf("Patient record added successfully.\n");
                        break;

                    }
                    case 2:
                    {
                        // Edit patient record
                        printf("Enter patient ID to edit: ");
                        scanf("%d", &editID);
                        if (isPatientIDExists(patientList, editID))
                        {
                            // Find the patient to edit by their ID
                            Patient* currentPatient = patientList;
                            while (currentPatient != NULL)
                            {
                                if (currentPatient->id == editID)
                                {
                                    printf("Editing patient record for %s (ID: %d):\n", currentPatient->name, currentPatient->id);
                                    printf("1. Edit Name\n");
                                    printf("2. Edit Age\n");
                                    printf("3. Edit Gender\n");
                                    printf("Enter your choice: ");
                                    int editChoice;
                                    scanf("%d", &editChoice);

                                    switch (editChoice)
                                    {
                                        case 1:
                                            // Edit Name
                                            do 
                                            {
                                                printf("Enter new name: ");
                                                scanf("%s", currentPatient->name);
                                                if (strlen(currentPatient->name) == 0)
                                                {
                                                    printf("Name cannot be empty. Please enter a valid name.\n");
                                                }
                                            } 
                                            while (strlen(currentPatient->name) == 0);

                                            printf("Name updated successfully.\n");
                                            break;
                                        case 2:
                                            // Edit Age
                                            do
                                            {
                                                printf("Enter new age: ");
                                                scanf("%d", &currentPatient->age);
                                                if (currentPatient->age < 0 || currentPatient->age > 150)
                                                {
                                                    printf("Invalid age. Please enter a valid age between 0 and 150.\n");
                                                }
                                            }
                                            while (currentPatient->age < 0 || currentPatient->age > 150);

                                            printf("Age updated successfully.\n");
                                            break;
                                        case 3:
                                            // Edit Gender
                                            do 
                                            {
                                                printf("Enter new gender: ");
                                                scanf("%s", currentPatient->gender);
                                                if (strcmp(currentPatient->gender, "Male") != 0 && strcmp(currentPatient->gender, "Female") != 0 && strcmp(currentPatient->gender, "Other") != 0)
                                                {
                                                    printf("Invalid gender. Please enter a valid gender (Male/Female/Other).\n");
                                                }
                                            } 
                                            while (strcmp(currentPatient->gender, "Male") != 0 && strcmp(currentPatient->gender, "Female") != 0 && strcmp(currentPatient->gender, "Other") != 0);

                                            printf("Gender updated successfully.\n");
                                            break;
                                        default:
                                            printf("Invalid choice. No changes made.\n");
                                    }
                                    break; // Exit the loop since we found the patient to edit
                                }
                                currentPatient = currentPatient->next;
                            }
                        }
                        else
                        {
                            printf("Patient not found with the given ID.\n");
                        }
                        break;
                    }
                    case 3:
                    {
                        displaySlots(slotList);
                        int patientID;
                        printf("Enter patient ID: ");
                        scanf("%d", &patientID);
                       if ( !isPatientIDExists (patientList, patientID))
                       {
                        printf("No such ID\n");
                        break;
                       }
                        int slotNumber;
                        printf("Enter the slot number you want to reserve: ");
                        scanf("%d", &slotNumber);
                        slotList = reserveSlot(slotList, patientID, slotNumber);
                        break;
                    }
                    case 4:
                    {
                        // Cancel reservation
                        int cancelID;
                        printf("Enter patient ID to cancel reservation: ");
                        scanf("%d", &cancelID);
                        slotList = cancelReservation(slotList, cancelID);
                        printf("Reservation canceled successfully.\n");
                        break;
                    }
                    case 5:
                    {
                        // Exit Admin Mode
                        adminMode = 0;
                        printf("Exiting Admin Mode.\n");
                        break;
                    }
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        }
        else if (choice == 2)
        {
            printf("User Mode:\n");
            printf("1. View patient record\n");
            printf("2. View today's reservations\n");
            printf("3. Exit User Mode\n");
            printf("Enter your choice: ");
            int userChoice;
            scanf("%d", &userChoice);

            switch (userChoice)
            {
                case 1:
                {
                    // View patient record
                    int viewID;
                    printf("Enter patient ID to view: ");
                    scanf("%d", &viewID);
                    viewPatientRecord(patientList, viewID);
                    break;
                }
                case 2:
                    // View today's reservations
                    printf("Today's Reservations:\n");
                    viewTodaysReservations(slotList);
                    break;

                case 3:
                    // Exit User Mode
                    printf("Exiting User Mode.\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } 
        else if (choice == 3)
        {
            printf("Exiting the Clinic Management System.\n");
            break;
        } 
        else 
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Free allocated memory
    Patient* currentPatient = patientList;
    while (currentPatient != NULL) 
    {
        Patient* temp = currentPatient;
        currentPatient = currentPatient->next;
        free(temp);
    }

    Slot* currentSlot = slotList;
    while (currentSlot != NULL)
    {
        Slot* temp = currentSlot;
        currentSlot = currentSlot->next;
        free(temp);
    }

    return 0;
}
