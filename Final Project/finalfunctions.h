#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Structure to represent a patient
typedef struct patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    struct patient* next;
}Patient;

// Structure to represent a time slot
typedef struct slot {
    int slot;
    int reserved;
    int patientID;
    struct slot* next;
} Slot;



// Function to view today's reservations
void viewTodaysReservations(Slot* head);

// Function to view patient record by patient ID
void viewPatientRecord(Patient* head, int patientID);

// Function to cancel a reservation by patient ID
Slot* cancelReservation(Slot* head, int patientID);

// Function to reserve a slot with the doctor
Slot* reserveSlot(Slot* head, int patientID, int slot);

// Function to check if a patient ID exists in the linked list
int isPatientIDExists(Patient* head, int id);

// Function to add a new patient record to the linked list
Patient* addPatient(Patient* head, int id, char name[], int age, char gender[]);


// Function to initialize a list of available slots
Slot* initializeSlots();

// Function to display available slots
void displaySlots(Slot* head);
