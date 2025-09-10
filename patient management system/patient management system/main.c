#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialization[50];
} Doctor;

typedef struct {
    int appointmentId;
    int patientId;
    int doctorId;
    char date[20];
} Appointment;

Patient patients[MAX];
Doctor doctors[MAX];
Appointment appointments[MAX];
int patientCount = 0, doctorCount = 0, appointmentCount = 0;

// Add patient function
void addPatient() {
    Patient p;
    p.id = patientCount + 1;
    printf("Enter patient name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter gender: ");
    scanf(" %s", p.gender);
    patients[patientCount++] = p;
    printf("Patient registered successfully! ID = %d\n", p.id);
}

// Add doctor function
void addDoctor() {
    Doctor d;
    d.id = doctorCount + 1;
    printf("Enter doctor name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter specialization: ");
    scanf(" %[^\n]", d.specialization);
    doctors[doctorCount++] = d;
    printf("Doctor registered successfully! ID = %d\n", d.id);
}

// Book appointment
void bookAppointment() {
    if (patientCount == 0 || doctorCount == 0) {
        printf("Please register at least 1 patient and 1 doctor first!\n");
        return;
    }
    Appointment a;
    a.appointmentId = appointmentCount + 1;
    printf("Enter Patient ID: ");
    scanf("%d", &a.patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctorId);
    printf("Enter date (DD/MM/YYYY): ");
    scanf(" %s", a.date);
    appointments[appointmentCount++] = a;
    printf("Appointment booked successfully! Appointment ID = %d\n", a.appointmentId);
}

// View appointments
void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments found!\n");
        return;
    }
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment ID: %d\n", appointments[i].appointmentId);
        printf("Patient: %s\n", patients[appointments[i].patientId - 1].name);
        printf("Doctor: %s (%s)\n", doctors[appointments[i].doctorId - 1].name,
               doctors[appointments[i].doctorId - 1].specialization);
        printf("Date: %s\n\n", appointments[i].date);
    }
}

// Cancel appointment
void cancelAppointment() {
    int id;
    printf("Enter Appointment ID to cancel: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].appointmentId == id) {
            found = 1;
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            printf("Appointment ID %d cancelled successfully!\n", id);
            break;
        }
    }
    if (!found) printf("Appointment not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Patient Appointment Management System ---\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. Book Appointment\n");
        printf("4. View Appointments\n");
        printf("5. Cancel Appointment\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addPatient(); break;
            case 2: addDoctor(); break;
            case 3: bookAppointment(); break;
            case 4: viewAppointments(); break;
            case 5: cancelAppointment(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
