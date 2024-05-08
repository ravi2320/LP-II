#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class HospitalManagementSystem {
private:
    map<string, string> appointments; // Map to store appointments (patient name -> appointment details)
public:
    void bookAppointment(string patientName, string appointmentDetails) {
        appointments[patientName] = appointmentDetails;
        cout << "Appointment booked successfully for " << patientName << endl;
    }

    void cancelAppointment(string patientName) {
        if (appointments.find(patientName) != appointments.end()) {
            appointments.erase(patientName);
            cout << "Appointment canceled successfully for " << patientName << endl;
        } else {
            cout << "No appointment found for " << patientName << endl;
        }
    }

    void viewAppointment(string patientName) {
        if (appointments.find(patientName) != appointments.end()) {
            cout << "Appointment details for " << patientName << ": " << appointments[patientName] << endl;
        } else {
            cout << "No appointment found for " << patientName << endl;
        }
    }

    void viewAllAppointments() {
        cout << "All Appointments:" << endl;
        for (auto& appointment : appointments) {
            cout << appointment.first << ": " << appointment.second << endl;
        }
    }

    void provideAssistance(string query) {
        cout << "Assistance: " << query << endl;
        // Add logic to provide assistance based on the query
    }
};

int main() {
    HospitalManagementSystem hms;
    string input;

    cout << "Welcome to the Hospital Management System Chatbot!" << endl;
    cout << "How can I assist you today?" << endl;

    while (true) {
        cout << "Enter your query (book/view/cancel/view all appointments/assistance): ";
        getline(cin, input);

        if (input == "book") {
            string patientName, appointmentDetails;
            cout << "Enter patient name: ";
            getline(cin, patientName);
            cout << "Enter appointment details: ";
            getline(cin, appointmentDetails);
            hms.bookAppointment(patientName, appointmentDetails);
        } else if (input == "cancel") {
            string patientName;
            cout << "Enter patient name: ";
            getline(cin, patientName);
            hms.cancelAppointment(patientName);
        } else if (input == "view") {
            string patientName;
            cout << "Enter patient name: ";
            getline(cin, patientName);
            hms.viewAppointment(patientName);
        } else if (input == "view all appointments") {
            hms.viewAllAppointments();
        } else if (input == "assistance") {
            string query;
            cout << "Enter your query: ";
            getline(cin, query);
            hms.provideAssistance(query);
        } else {
            cout << "Invalid input. Please try again." << endl;
        }

        cout << "Do you have any other queries? (yes/no): ";
        getline(cin, input);

        if (input != "yes") {
            break;
        }
    }

    cout << "Thank you for using the Hospital Management System Chatbot. Have a great day!" << endl;

    return 0;
}
