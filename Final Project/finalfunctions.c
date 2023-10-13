
#include "finalfunctions.h"


    char* availableTimes[] = {
        "2pm to 2:30pm",
        "2:30pm to 3pm",
        "3pm to 3:30pm",
        "4pm to 4:30pm",
        "4:30pm to 5pm"
    };
// Function to add a new patient record to the linked list
Patient * addPatient(Patient * head, int id, char name[], int age, char gender[])
{
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->gender, gender);
    newPatient->next = head;
    return newPatient;
}

// Function to check if a patient ID exists in the linked list
int isPatientIDExists (Patient* head, int id)
{
    Patient* current = head;
    while (current != NULL) 
    {
        if (current->id == id)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to add a new reservation to the linked list
// Function to reserve a slot
Slot* reserveSlot(Slot* head, int patientID, int slot) {
    Slot* current = head;
    int patientExists = 0;

    // Reset current pointer and search for the slot
    current = head;
    while (current != NULL) {
        if (current->slot == slot) {
            if (current->reserved == 0) {
                current->reserved = 1;
                current->patientID = patientID;
                printf("Slot reserved successfully.\n");
                return head;
            } else {
                printf("Slot is already reserved.\n");
                return head;
            }
        }
        current = current->next;
    }

    printf("Slot not available or invalid slot number.\n");
    return head;
}


// Function to cancel a reservation by patient ID
Slot* cancelReservation(Slot* head, int patientID)
{
    Slot* current = head;
    while (current != NULL)
    {
        if (current->patientID == patientID)
        {
            current->reserved = 0;
            current->patientID = 0;
            return head;
        }
        current = current->next;
    }
    printf("Reservation not found for the given patient ID.\n");
    return head;
}

// Function to display patient information by patient ID
void viewPatientRecord(Patient* head, int patientID)
{
    Patient* current = head;
    while (current != NULL)
    {
        if (current->id == patientID) 
        {
            printf("Patient ID: %d\n", current->id);
            printf("Name: %s\n", current->name);
            printf("Age: %d\n", current->age);
            printf("Gender: %s\n", current->gender);
            return;
        }
        current = current->next;
    }
    printf("Patient not found with the given ID.\n");
}

// Function to display today's reservations
void viewTodaysReservations(Slot* head)
{
    Slot* current = head;
    while (current != NULL) 
    {
        for (int i = 0; i < 5; i++)
        {
               if (current->reserved == 1) 
                {
                    printf("Reserved Slots %s", availableTimes[i]);
                }
        }
        current = current->next;
    }
}
// Function to initialize a list of available slots
Slot* initializeSlots() {
    Slot* head = NULL;

    // Initialize available slots (slots 1 to 5)
    for (int i = 1; i <= 5; i++) {
        Slot* newSlot = (Slot*)malloc(sizeof(Slot));
        newSlot->slot = i;
        newSlot->reserved = 0;
        newSlot->patientID = -1;
        newSlot->next = head;
        head = newSlot;
    }

    return head;
}

// Function to display available slots
void displaySlots(Slot* head) {
    printf("Available slots:\n");
    Slot* current = head;
    int i = 4;
    while (current != NULL) {
        printf("%d. Slot %s\n", current->slot, availableTimes[i]);
        current = current->next;
        i--;
    }
}