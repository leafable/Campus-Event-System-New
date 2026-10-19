#include "System.h"

System::System() {
}

System::~System() {
}

int System::getSelection()
{
    int selection;
    cout << "Campus Event Management System" << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (c1majorselection < 1 || c1majorselection > numMajors) {
                cout << "Invalid selection." << endl;
                cout << "Major: ";
                cin >> c1majorselection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            c1major = majorList[c1majorselection - 1];

            int highestId = students.getStudentVector().at(0).getId();
            for (const auto& student : students.getStudentVector()) {
                if (highestId < student.getId()) {
                    highestId = student.getId();
                }
            }
            c1id = highestId + 1;

            // const auto& studentsVector = students.getStudentVector();
            // if (!studentsVector.empty()) {
            //     c1id = studentsVector.back().getId() + 1;
            // }
            // else {
            //     c1id = 100;
            // }

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c2selection < 1 || c2selection > 2) {
                cout << "Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin >> c2selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c2selection == 1) {
                cout << "1). Find student by name" << endl;
                cout << "2). Find student by ID" << endl;

                cout << endl << "Enter selection: ";
                cin >> c2selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c2selection < 1 || c2selection > 2) {
                    cout << "Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin >> c2selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c2selection == 1) {
                    cout << "Student name: ";
                    getline(cin, c2name);
                    students.displayStudent(c2name);
                    cout << endl;
                }
                else if (c2selection == 2) {
                    cout << "Student ID: ";
                    cin >> c2id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    students.displayStudent(c2id);
                    cout << endl;
                }
            }
            else if (c2selection == 2) {
                students.displayAllStudents();
                cout << endl;
            }
            break;
        }
        case 3: {
            string c3name{};
            string c3description{};
            string c3date{};
            int c3year{};
            int c3month{};
            int c3day{};
            string c3time{};
            int c3minute{};
            int c3hour{};
            string c3location{};
            int c3capacity{};
            string c3selection{};
            int c3id{};
            string c3organizer{};
            double c3length;

            int highestId = events.getEventsPointer()->at(0)->getEventId();
            for (const auto& event : *events.getEventsPointer()) {
                if (highestId < event->getEventId()) {
                    highestId = event->getEventId();
                }
            }
            c3id = highestId + 1;

            cout << "Event name: ";
            getline(cin, c3name);
            cout << "Event description: ";
            getline(cin, c3description);
            cout << "Date of event (yyyy-mm-dd): ";
            cin >> c3year;
            cin.ignore();
            cin >> c3month;
            cin.ignore();
            cin >> c3day;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3month > 12 || c3month < 1 || c3day < 1 || c3day > 31 || c3year > 9999 || c3year < 2000) {
                cout << "Error: Invalid date." << endl;
                cout << "Date of event (yyyy-mm-dd): ";
                cin >> c3year;
                cin.ignore();
                cin >> c3month;
                cin.ignore();
                cin >> c3day;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            c3date = to_string(c3year) + '-' + to_string(c3month) + '-' + to_string(c3day);

            cout << "Time (HH:MM): ";
            cin >> c3hour;
            cin.ignore();
            cin >> c3minute;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3hour > 24 || c3hour < 0 || c3minute > 59 || c3minute < 0) {
                cout << "Error: Invalid time." << endl;
                cout << "Time (HH:MM): ";
                cin >> c3hour;
                cin.ignore();
                cin >> c3minute;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            c3time = to_string(c3hour) + ':' + to_string(c3minute);

            cout << "Location: ";
            cin >> c3location;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Max capacity: ";
            cin >> c3capacity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3capacity < 1) {
                cout << "Error: Invalid capacity." << endl;
                cout << "Max capacity: ";
                cin >> c3capacity;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "List of organizers" << endl;
            int index{};
            for (const auto& organizer : *organizers.getOrganizersPointer()) {
                cout << ++index << "). " << organizer.getName() << endl;
            }

            cout << endl << "Select an organizer or type it in manually: ";
            getline(cin, c3selection);
            try {
                c3organizer = organizers.getOrganizersPointer()->at(stoi(c3selection)).getName();
            }
            catch (const exception &e) {
                c3organizer = c3selection;
            }

            cout << "Event duration (in minutes): ";
            cin >> c3length;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3length < 0) {
                cout << "Error: Invalid duration." << endl;
                cin >> c3length;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            c3length /= 60;

            unique_ptr<Event> newEvent = make_unique<Event>(c3id, c3name, c3description, c3date, c3time, c3location, c3capacity, c3organizer, to_string(c3length));
            events.createEvent(move(newEvent));

            break;
        }
        case 4: {
            int c4selection{};

            cout << "1). View specific event" << endl;
            cout << "2). View all events" << endl;
            cout << endl << "Enter selection: ";
            cin >> c4selection;

            while (c4selection < 1 || c4selection > 2) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin >> c4selection;
            }

            if (c4selection == 1) {
                cout << "1). Find by event name" << endl;
                cout << "2). Find by event ID" << endl;
            }
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            int studentID, eventID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter event ID: ";
            cin >> eventID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter event ID: ";
            cin >> eventID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            vector<int> studentIDs = registrations.getStudentIDsForEvent(eventID);
            if (studentIDs.empty())
                cout << "No students registered." << endl;
            for (int id : studentIDs)
                cout << "  - Student " << id << endl;
            break;
        }
        case 10: {
            int c10selection{};
            string c10name{};
            int c10id{};
            char c10association{};

            organizers.updateOrganizers(events);

            cout << "1). View specific organizer" << endl;
            cout << "2). View all organizers" << endl;
            cout << endl << "Enter selection: ";
            cin >> c10selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c10selection < 1 || c10selection > 2) {
                cout << "Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin >> c10selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c10selection == 1) {
                cout << "1). Find by organization name" << endl;
                cout << "2). Find by organization ID" << endl;
                cout << endl << "Enter selection: ";
                cin >> c10selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c10selection < 1 || c10selection > 2) {
                    cout << "Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin >> c10selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c10selection == 1) {
                    cout << "Organization name: ";
                    getline(cin, c10name);
                    organizers.displayOrganizer(c10name);
                }
                else if (c10selection == 2) {
                    cout << "Organization ID: ";
                    cin >> c10id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    c10name = organizers.findNameById(c10id);
                    organizers.displayOrganizer(c10id);
                }
                cout << endl << "Display associated events? (Y/N): ";
                cin >> c10association;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                c10association = toupper(c10association);

                while (c10association != 'Y' && c10association != 'N') {
                    cout << "Invalid selection." << endl;
                    cout << "Display associated events? (Y/N): ";
                    cin >> c10association;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    c10association = toupper(c10association);
                }

                if (c10association == 'Y') {
                    organizers.viewAssociatedEvents(c10name, events);
                }
            }
            else if (c10selection == 2) {
                organizers.displayAllOrganizers();

                cout << "Display associated events? (Y/N): ";
                cin >> c10association;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                c10association = toupper(c10association);

                while (c10association != 'Y' && c10association != 'N') {
                    cout << "Invalid selection." << endl;
                    cout << "Display associated events? (Y/N): ";
                    cin >> c10association;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    c10association = toupper(c10association);
                }

                if (c10association == toupper('Y')) {
                    cout << "Organization name: ";
                    getline(cin, c10name);
                    organizers.viewAssociatedEvents(c10name, events);
                }
            }
            break;
        }
        case 11: {
            cout << "1). View available events" << endl;
            cout << "2). View full events" << endl;
            cout << "3). View registration statistics" << endl;
            cout << "4). View most popular event(s)" << endl;

            cout << endl << "Enter selection: ";

            int c11selection;
            if (!(cin >> c11selection)) {
                cin.clear();
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
            break;
        }
    }
    if (selection != 0) {
        cout << "Press enter to continue...";
        cin.get();
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
