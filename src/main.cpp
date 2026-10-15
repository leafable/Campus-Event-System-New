#include <iostream>
#include <limits>
#include "../include/System.h"

using namespace std;

int getSelection();
void processSelection(int selection, System& system);

int main()
{
    System system;
    
    int selection{};

   do {
       selection = getSelection();
       processSelection(selection, system);
   }

    while (selection != 0);
    return 0;
}

int getSelection()
{
    int selection;
    cout << endl << "Campus Event Management System" << endl;
    cout << "1). Add Student" << endl;
    cout << "2). View Students" << endl;
    cout << "3). Create Event" << endl;
    cout << "4). View Events" << endl;
    cout << "5). Search Events" << endl;
    cout << "6). Register Student for Event" << endl;
    cout << "7). Cancel Registration" << endl;
    cout << "8). View Student Registrations" << endl;
    cout << "9). View Event Attendees" << endl;
    cout << "10). View Organizers" << endl;
    cout << "11). System Reports" << endl;
    cout << "0). Exit" << endl;

    cout << endl << "Enter selection: ";

    while (!(cin >> selection) || selection < 0 || selection > 11)
        {
            cout << "Invalid selection. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return selection;
}

void processSelection(int selection, System& system)
{
    switch (selection) {
        case 1: {
            string c1name{};
            string c1email{};
            string c1major{};
            int c1id{};
            int c1majorselection{};
            string majorList[] = {"Biology","Business","Chemistry",
                "Computer Science","Economics","Engineering",
                "English","Mathematics","Physics","Psychology"};
            // The size of the array in bytes divided by the number of bytes in a single element.
            const int numMajors = sizeof(majorList) / sizeof(majorList[0]);

            cout << "Student name: ";
            getline(cin, c1name);
            cout << "Student email: ";
            getline(cin, c1email);

            cout << "List of majors:" << endl;
            for (int i = 0; i < numMajors; i++) {
                cout << i + 1 << "). " << majorList[i] << endl;
            }
            cout << endl << "Major: ";
            cin >> c1majorselection;
            while (c1majorselection < 1 || c1majorselection > numMajors) {
                cout << "Invalid selection." << endl;
                cout << "Major: ";
                cin >> c1majorselection;
            }
            c1major = majorList[c1majorselection - 1];

            const auto& students = system.students.getStudentVector();
            if (!students.empty()) {
                c1id = students.back().getId() + 1;
            }
            else {
                c1id = 100;
            }

            if (!system.students.isDuplicateId(c1id)) {
                system.students.addStudent(c1id, c1name, c1email, c1major);
            }
            else {
                cerr << "Error: Duplicate student ID." << endl;
            }
            break;
        }
        case 2: {
            string c2name{};
            int c2id{};
            int c2selection{};

            cout << "1). View specific student" << endl;
            cout << "2). View all students" << endl;

            cout << endl << "Enter selection: ";
            cin >> c2selection;

            while (c2selection < 1 || c2selection > 2) {
                cout << "Invalid selection." << endl;
                cout << endl << "Enter selection: ";
            }

            if (c2selection == 1) {
                cout << "1). Find student by name" << endl;
                cout << "2). Find student by ID" << endl;

                cout << endl << "Enter selection: ";
                cin >> c2selection;

                while (c2selection < 1 || c2selection > 2) {
                    cout << "Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                }

                if (c2selection == 1) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Student name: ";
                    getline(cin, c2name);
                    system.students.displayStudent(c2name);
                }
                else if (c2selection == 2) {
                    cout << endl << "Student ID: ";
                    cin >> c2id;
                    system.students.displayStudent(c2id);
                }
            }
            else if (c2selection == 2) {
                system.students.displayAllStudents();
            }
            break;
        }
        case 3: {

        }
        break;

        case 4:
            break;
 
        case 5:
            break;

        case 6: {
            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter event ID: ";
            cin >> eventID;

            // addRegistration needs the event's max capacity, so look the event up first
            int maxCapacity = -1;
            for (const auto& e : *system.events.getEventsPointer())
            {
                if (e->getEventId() == eventID)
                {
                    maxCapacity = e->getEventMaxCapacity();
                }
            }
            if (maxCapacity == -1)
            {
                cout << "No event found with that ID.\n";
                break;
            }

            // the registration date, typed in by the user
            string date;
            cout << "Enter registration date (YYYY-MM-DD): ";
            cin >> date;

            if (system.registrations.addRegistration(Registration(studentID, eventID, date, true), maxCapacity))
                cout << "Student registered.\n";
            else if (system.registrations.isRegistered(studentID, eventID))
                cout << "Student is already registered for this event.\n";
            else
                cout << "This event is full.\n";
            break;
        }
        case 7: {
            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter event ID: ";
            cin >> eventID;
            cout << endl;

            if (system.registrations.cancelRegistration(studentID, eventID))
                cout << "Registration cancelled.\n";
            else
                cout << "No active registration found.\n";
            break;
        }
        case 8: {
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << endl;

            vector<int> eventIDs = system.registrations.getEventIDsForStudent(studentID);
            if (eventIDs.empty())
                cout << "No registrations found.\n";
            for (int id : eventIDs)
                cout << "  - Event " << id << "\n";
            break;
        }
        case 9: {
            int eventID;
            cout << "Enter event ID: ";
            cin >> eventID;
            cout << endl;

            vector<int> studentIDs = system.registrations.getStudentIDsForEvent(eventID);
            if (studentIDs.empty())
                cout << "No students registered.\n";
            for (int id : studentIDs)
                cout << "  - Student " << id << "\n";
                    break;
        }
        case 10: {
            break;
        }
        case 11: {
            cout << "1). Available Events\n";
            cout << "2). Full Events\n";
            cout << "3). Registration Counts\n";
            cout << "4). Most Popular Event\n";

            cout << "\nReport selection: ";

            int reportChoice;
            if (!(cin >> reportChoice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid report selection.\n";
                break;
            }

            const auto& eventList = *system.events.getEventsPointer();

            switch (reportChoice) {
                case 1:
                    system.reports.showAvailableEvents(eventList, system.registrations);
                    break;

                case 2:
                    system.reports.showFullEvents(eventList, system.registrations);
                    break;

                case 3:
                    system.reports.showRegistrationCounts(eventList, system.registrations);
                    break;

                case 4:
                    system.reports.showMostPopularEvent(eventList, system.registrations);
                    break;

                default:
                    cout << "Invalid report selection.\n";
            }
            break;
        }
        case 0:
            exit(0);
    }
}