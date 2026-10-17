#include "System.h"

System::System() {
}

System::~System() {
}

int System::getSelection()
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

void System::processSelection(int selection)
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

            const auto& studentsVector = students.getStudentVector();
            if (!studentsVector.empty()) {
                c1id = studentsVector.back().getId() + 1;
            }
            else {
                c1id = 100;
            }

            if (!students.isDuplicateId(c1id)) {
                students.addStudent(c1id, c1name, c1email, c1major);
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
                    students.displayStudent(c2name);
                }
                else if (c2selection == 2) {
                    cout << endl << "Student ID: ";
                    cin >> c2id;
                    students.displayStudent(c2id);
                }
            }
            else if (c2selection == 2) {
                students.displayAllStudents();
            }
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter event ID: ";
            cin >> eventID;

            // addRegistration needs the event's max capacity, so look the event up first
            int maxCapacity = -1;
            for (const auto& e : *events.getEventsPointer())
            {
                if (e->getEventId() == eventID)
                {
                    maxCapacity = e->getEventMaxCapacity();
                }
            }
            if (maxCapacity == -1)
            {
                cout << "No event found with that ID." << endl;
                break;
            }

            // the registration date, typed in by the user
            string date;
            cout << "Enter registration date (YYYY-MM-DD): ";
            cin >> date;

            if (registrations.addRegistration(Registration(studentID, eventID, date, true), maxCapacity))
                cout << "Student registered." << endl;
            else if (registrations.isRegistered(studentID, eventID))
                cout << "Student is already registered for this event." << endl;
            else
                cout << "This event is full." << endl;
            break;
        }
        case 7: {
            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter event ID: ";
            cin >> eventID;
            cout << endl;

            if (registrations.cancelRegistration(studentID, eventID))
                cout << "Registration cancelled." << endl;
            else
                cout << "No active registration found." << endl;
            break;
        }
        case 8: {
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << endl;

            vector<int> eventIDs = registrations.getEventIDsForStudent(studentID);
            if (eventIDs.empty())
                cout << "No registrations found." << endl;
            for (int id : eventIDs)
                cout << "  - Event " << id << endl;
            break;
        }
        case 9: {
            int eventID;
            cout << "Enter event ID: ";
            cin >> eventID;
            cout << endl;

            vector<int> studentIDs = registrations.getStudentIDsForEvent(eventID);
            if (studentIDs.empty())
                cout << "No students registered." << endl;
            for (int id : studentIDs)
                cout << "  - Student " << id << endl;
            break;
        }
        case 10: {
            
            break;
        }
        case 11: {
            cout << "1). Available Events" << endl;
            cout << "2). Full Events" << endl;
            cout << "3). Registration Counts" << endl;
            cout << "4). Most Popular Event" << endl;

            cout << endl << "Enter selection: ";

            int c11selection;
            if (!(cin >> c11selection)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid report selection." << endl;
                break;
            }

            const auto& eventList = *events.getEventsPointer();

            switch (c11selection) {
                case 1:
                    reports.showAvailableEvents(eventList, registrations);
                    break;

                case 2:
                    reports.showFullEvents(eventList, registrations);
                    break;

                case 3:
                    reports.showRegistrationCounts(eventList, registrations);
                    break;

                case 4:
                    reports.showMostPopularEvent(eventList, registrations);
                    break;

                default:
                    cerr << "Error: Invalid report selection." << endl;
            }
            break;
        }
        case 0: {
            cout << "Exiting program..." << endl;
            exit(0);
            break;
        }
    }
}

void System::runSystem() {
    int selection{};

    do {
        selection = getSelection();
        processSelection(selection);
    }

    while (selection != 0);
}

void System::closeSystem() {
    filemanager.saveData(students, events, organizers, registrations);
}
