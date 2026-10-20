#include "System.h"

#include <iomanip>

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
    cin >> selection;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (selection < 0 || selection > 11) {
        cout << "Error: Invalid selection." << endl;
        cout << "Enter selection: ";
        cin.clear();
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

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
                cin.clear();
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
            cout << "3). Return" << endl;

            cout << endl << "Enter selection: ";
            cin >> c2selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c2selection < 1 || c2selection > 3) {
                cout << "Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c2selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c2selection == 1) {
                cout << "1). Find student by name" << endl;
                cout << "2). Find student by ID" << endl;
                cout << "3). Return" << endl;

                cout << endl << "Enter selection: ";
                cin >> c2selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c2selection < 1 || c2selection > 3) {
                    cout << "Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
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
                else if (c2selection == 3) {
                    return;
                }
            }
            else if (c2selection == 2) {
                students.displayAllStudents();
                cout << endl;
            }
            else if (c2selection == 3) {
                break;
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
            stringstream ss;

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
                cin.clear();
                cin >> c3year;
                cin.ignore();
                cin >> c3month;
                cin.ignore();
                cin >> c3day;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            ss << c3year << '-' << setfill('0') << setw(2) << c3month << '-' << setw(2) << c3day;
            c3date = ss.str();

            cout << "Time (HH:MM): ";
            cin >> c3hour;
            cin.ignore();
            cin >> c3minute;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3hour > 24 || c3hour < 0 || c3minute > 59 || c3minute < 0) {
                cout << "Error: Invalid time." << endl;
                cout << "Time (HH:MM): ";
                cin.clear();
                cin >> c3hour;
                cin.ignore();
                cin >> c3minute;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            ss.str("");
            ss << setfill('0') << setw(2) << c3hour << ':' << setw(2) << c3minute;
            c3time = ss.str();

            cout << "Location: ";
            cin >> c3location;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Max capacity: ";
            cin >> c3capacity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3capacity < 1) {
                cout << "Error: Invalid capacity." << endl;
                cout << "Max capacity: ";
                cin.clear();
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
                c3organizer = organizers.getOrganizersPointer()->at(stoi(c3selection) - 1).getName();
            }
            catch (const exception &e) {
                c3organizer = c3selection;
            }

            cout << "Event duration (in minutes): ";
            cin >> c3length;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c3length < 0) {
                cout << "Error: Invalid duration." << endl;
                cin.clear();
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
            string c4name{};
            int c4id{};

            cout << "1). View specific event" << endl;
            cout << "2). View all events" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c4selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c4selection < 1 || c4selection > 3) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c4selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c4selection == 1) {
                cout << "1). Find by event name" << endl;
                cout << "2). Find by event ID" << endl;
                cout << "3). Return" << endl;

                cout << endl << "Enter selection: ";
                cin >> c4selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c4selection < 1 || c4selection > 3) {
                    cout << "Error: Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c4selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c4selection == 1) {
                    cout << "Event name: ";
                    getline(cin, c4name);
                    events.displayEvent(events.findEventByName(c4name));
                    cout << endl;
                }
                else if (c4selection == 2) {
                    cout << "Event ID: ";
                    cin >> c4id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    events.displayEvent(events.findEventById(c4id));
                    cout << endl;
                }
                else if (c4selection == 3) {
                    break;
                }
            }
            else if (c4selection == 2) {
                events.displayAllEvents();
            }
            else if (c4selection == 3) {
                break;
            }
            break;
        }
        case 5: {
            int c5selection{};
            string c5name{};
            int c5id{};
            string c5description{};
            string c5date{};
            string c5time{};
            string c5location{};
            int c5capacity{};
            string c5organization{};
            string c5duration{};
            char c5continue{};

            cout << "1). Search by event name" << endl;
            cout << "2). Search by event ID" << endl;
            cout << "3). Search by description" << endl;
            cout << "4). Search by date" << endl;
            cout << "5). Search by time" << endl;
            cout << "6). Search by location" << endl;
            cout << "7). Search by capacity" << endl;
            cout << "8). Search by organization" << endl;
            cout << "9). Search by event duration" << endl;

            cout << endl << "Enter selection: ";
            cin >> c5selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c5selection < 1 || c5selection > 9) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c5selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            do {
                switch (c5selection) {
                    case 1: {
                        cout << "Event name: ";
                        getline(cin, c5name);
                        if (events.findEventByName(c5name) != -1) {
                            events.displayEvent(events.findEventByName(c5name));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 2: {
                        cout << "Event ID: ";
                        cin >> c5id;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (events.findEventById(c5id) != -1) {
                            events.displayEvent(events.findEventById(c5id));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 3: {
                        cout << "Description: ";
                        getline(cin, c5description);
                        if (events.findEventByDescription(c5description) != -1) {
                            events.displayEvent(events.findEventByDescription(c5description));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 4: {
                        cout << "Date: ";
                        getline(cin, c5date);
                        if (events.findEventByDate(c5date) != -1) {
                            events.displayEvent(events.findEventByDate(c5date));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "Time: ";
                        getline(cin, c5time);
                        if (events.findEventByTime(c5time) != -1) {
                            events.displayEvent(events.findEventByTime(c5time));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 6: {
                        cout << "Location: ";
                        getline(cin, c5location);
                        if (events.findEventByLocation(c5location) != -1) {
                            events.displayEvent(events.findEventByLocation(c5location));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 7: {
                        cout << "Capacity: ";
                        cin >> c5capacity;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (events.findEventByCapacity(c5capacity) != -1) {
                            events.displayEvent(events.findEventByCapacity(c5capacity));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 8: {
                        cout << "Organization: ";
                        getline(cin, c5organization);
                        if (events.findEventByOrganization(c5organization) != -1) {
                            events.displayEvent(events.findEventByOrganization(c5organization));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                    case 9: {
                        cout << "Event length: ";
                        getline(cin, c5duration);
                        if (events.findEventByDuration(c5duration) != -1) {
                            events.displayEvent(events.findEventByDuration(c5duration));
                        }
                        else {
                            cout << "Event not found." << endl;
                        }
                        break;
                    }
                }
                cout << endl << "Search again? (Y/N): ";
                cin >> c5continue;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                c5continue = toupper(c5continue);

                while (c5continue != 'Y' && c5continue != 'N') {
                    cout << "Error: Invalid choice." << endl;
                    cout << endl << "Search again? (Y/N): ";
                    cin.clear();
                    cin >> c5continue;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            } while (c5continue == 'Y');

            break;
        }
        case 6: {
            int c6selection{};
            int c6studentId{};
            int c6eventId{};
            string c6studentName{};
            string c6eventName{};
            stringstream ss;
            int c6year{};
            int c6month{};
            int c6day{};
            string c6date{};
            int maxCapacity;

            cout << "1). Register using student name" << endl;
            cout << "2). Register using student ID" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c6selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c6selection < 1 || c6selection > 3) {
                cout << endl << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c6selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c6selection == 1) {
                cout << "Enter student name: ";
                getline(cin, c6studentName);
                if (students.findByName(c6studentName) != -1) {
                    c6studentId = students.getStudentVector().at(students.findByName(c6studentName)).getId();
                }
            }
            else if (c6selection == 2) {
                cout << "Enter student ID: ";
                cin >> c6studentId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (students.findById(c6studentId) != -1) {
                    c6studentName = students.getStudentVector().at(students.findById(c6studentId)).getName();
                }
            }
            else if (c6selection == 3) {
                break;
            }

            while (students.findById(c6studentId) == -1 || students.findByName(c6studentName) == -1) {
                cout << endl << "Error: Student does not exist." << endl;
                cout << "1). Register using student name" << endl;
                cout << "2). Register using student ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c6selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c6selection < 1 || c6selection > 3) {
                    cout << endl << "Error: Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c6selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c6selection == 1) {
                    cout << "Enter student name: ";
                    getline(cin, c6studentName);
                    if (students.findByName(c6studentName) != -1) {
                        c6studentId = students.getStudentVector().at(students.findByName(c6studentName)).getId();
                    }
                }
                else if (c6selection == 2) {
                    cout << "Enter student ID: ";
                    cin >> c6studentId;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (students.findById(c6studentId) != -1) {
                        c6studentName = students.getStudentVector().at(students.findById(c6studentId)).getName();
                    }
                }
                else if (c6selection == 3) {
                    break;
                }
            }

            cout << "1). Register using event name" << endl;
            cout << "2). Register using event ID" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c6selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c6selection < 1 || c6selection > 3) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c6selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c6selection == 1) {
                cout << "Enter event name: ";
                getline(cin, c6eventName);
                if (events.findEventByName(c6eventName) != -1) {
                    c6eventId = events.getEventsPointer()->at(events.findEventByName(c6eventName))->getEventId();
                }
            }
            else if (c6selection == 2) {
                cout << "Enter event ID: ";
                cin >> c6eventId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (events.findEventById(c6eventId) != -1) {
                    c6eventName = events.getEventsPointer()->at(events.findEventById(c6eventId))->getEventName();
                }
            }
            else if (c6selection == 3) {
                break;
            }

            while (events.findEventById(c6eventId) == -1 || events.findEventByName(c6eventName) == -1) {
                cout << "Error: Event does not exist." << endl;
                cout << "1). Register using event name" << endl;
                cout << "2). Register using event ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c6selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c6selection < 1 || c6selection > 3) {
                    cout << "Error: Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c6selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c6selection == 1) {
                    cout << "Enter event name: ";
                    getline(cin, c6eventName);
                    if (events.findEventByName(c6eventName) != -1) {
                        c6eventId = events.getEventsPointer()->at(events.findEventByName(c6eventName))->getEventId();
                    }
                }
                else if (c6selection == 2) {
                    cout << "Enter event ID: ";
                    cin >> c6eventId;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (events.findEventById(c6eventId) != -1) {
                        c6eventName = events.getEventsPointer()->at(events.findEventById(c6eventId))->getEventName();
                    }
                }
                else if (c6selection == 3) {
                    break;
                }
            }

            maxCapacity = -1;
            for (const auto& e : *events.getEventsPointer())
            {
                if (e->getEventId() == c6eventId)
                {
                    maxCapacity = e->getEventMaxCapacity();
                }
            }
            if (maxCapacity == -1)
            {
                cout << "No event found with that ID." << endl;
                break;
            }

            cout << "Date of event (yyyy-mm-dd): ";
            cin >> c6year;
            cin.ignore();
            cin >> c6month;
            cin.ignore();
            cin >> c6day;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c6month > 12 || c6month < 1 || c6day < 1 || c6day > 31 || c6year > 9999 || c6year < 2000) {
                cout << "Error: Invalid date." << endl;
                cin.clear();
                cin >> c6year;
                cin.ignore();
                cin >> c6month;
                cin.ignore();
                cin >> c6day;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            ss << c6year << '-' << setfill('0') << setw(2) << c6month << '-' << setw(2) << c6day;
            c6date = ss.str();

            if (registrations.addRegistration(Registration(c6studentId, c6eventId, c6date, true), maxCapacity))
                cout << "Student registered." << endl;
            else if (registrations.isRegistered(c6studentId, c6eventId))
                cout << "Student is already registered for this event." << endl;
            else
                cout << "This event is full." << endl;
            break;
        }
        case 7: {
            int c7selection{};
            int c7studentId{};
            int c7eventId{};
            string c7studentName{};
            string c7eventName{};
            char c7association{};

            cout << "1). Cancel registration using student name" << endl;
            cout << "2). Cancel registration using student ID" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c7selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c7selection < 1 || c7selection > 3) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c7selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c7selection == 1) {
                cout << "Enter student name: ";
                getline(cin, c7studentName);
                if (students.findByName(c7studentName) != -1) {
                    c7studentId = students.getStudentVector().at(students.findByName(c7studentName)).getId();
                }
            }
            else if (c7selection == 2) {
                cout << "Enter student ID: ";
                cin >> c7studentId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (students.findById(c7studentId) != -1) {
                    c7studentName = students.getStudentVector().at(students.findById(c7studentId)).getName();
                }
            }
            else if (c7selection == 3) {
                break;
            }

            while (students.findById(c7studentId) == -1 || students.findByName(c7studentName) == -1) {
                cout << "Error: Student does not exist." << endl;
                cout << "1). Cancel registration using student name" << endl;
                cout << "2). Cancel registration using student ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c7selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c7selection < 1 || c7selection > 3) {
                    cout << "Error: Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c7selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c7selection == 1) {
                    cout << "Enter student name: ";
                    getline(cin, c7studentName);
                    if (students.findByName(c7studentName) != -1) {
                        c7studentId = students.getStudentVector().at(students.findByName(c7studentName)).getId();
                    }
                }
                else if (c7selection == 2) {
                    cout << "Enter student ID: ";
                    cin >> c7studentId;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (students.findById(c7studentId) != -1) {
                        c7studentName = students.getStudentVector().at(students.findById(c7studentId)).getName();
                    }
                }
                else if (c7selection == 3) {
                    break;
                }
            }

            cout << endl << "Display associated events? (Y/N): ";
            cin >> c7association;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            c7association = toupper(c7association);

            while (c7association != 'Y' && c7association != 'N') {
                cout << "Invalid selection." << endl;
                cout << endl << "Display associated events? (Y/N): ";
                cin.clear();
                cin >> c7association;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                c7association = toupper(c7association);
            }

            if (c7association == 'Y') {
                organizers.viewAssociatedEvents(c7studentName, events);
            }

            cout << "1). Cancel registration using event name" << endl;
            cout << "2). Cancel registration using event ID" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c7selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c7selection < 1 || c7selection > 3) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c7selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c7selection == 1) {
                cout << "Enter event name: ";
                getline(cin, c7eventName);
                if (events.findEventByName(c7eventName) != -1) {
                    c7eventId = events.getEventsPointer()->at(events.findEventByName(c7eventName))->getEventId();
                }
            }
            else if (c7selection == 2) {
                cout << "Enter event ID: ";
                cin >> c7eventId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (events.findEventById(c7eventId) != -1) {
                    c7eventName = events.getEventsPointer()->at(events.findEventById(c7eventId))->getEventName();
                }
            }
            else if (c7selection == 3) {
                break;
            }

            while (events.findEventById(c7eventId) == -1 || events.findEventByName(c7eventName) == -1) {
                cout << "Error: Event does not exist." << endl;
                cout << "1). Cancel registration using event name" << endl;
                cout << "2). Cancel registration using event ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c7selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c7selection < 1 || c7selection > 3) {
                    cout << "Error: Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c7selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c7selection == 1) {
                    cout << "Enter event name: ";
                    getline(cin, c7eventName);
                    if (events.findEventByName(c7eventName) != -1) {
                        c7eventId = events.getEventsPointer()->at(events.findEventByName(c7eventName))->getEventId();
                    }
                }
                else if (c7selection == 2) {
                    cout << "Enter event ID: ";
                    cin >> c7eventId;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (events.findEventById(c7eventId) != -1) {
                        c7eventName = events.getEventsPointer()->at(events.findEventById(c7eventId))->getEventName();
                    }
                }
                else if (c7selection == 3) {
                    break;
                }
            }

            if (registrations.cancelRegistration(c7studentId, c7eventId))
                cout << "Registration cancelled." << endl;
            else
                cout << "No active registration found." << endl;
            break;
        }
        case 8: {
            int c8selection{};
            int c8studentId{};
            string c8studentName{};

            cout << "1). View registrations using student name" << endl;
            cout << "2). View registrations using student ID" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c8selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c8selection < 1 || c8selection > 3) {
                cout << "Error: Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c8selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c8selection == 1) {
                cout << "Enter student name: ";
                getline(cin, c8studentName);
                if (students.findByName(c8studentName) != -1) {
                    c8studentId = students.getStudentVector().at(students.findByName(c8studentName)).getId();
                }
            }
            else if (c8selection == 2) {
                cout << "Enter student ID: ";
                cin >> c8studentId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (students.findById(c8studentId) != -1) {
                    c8studentName = students.getStudentVector().at(students.findById(c8studentId)).getName();
                }
            }
            else if (c8selection == 3) {
                break;
            }

            while (students.findById(c8studentId) == -1 || students.findByName(c8studentName) == -1) {
                cout << "Error: Student does not exist." << endl;
                cout << "1). View registrations using student name" << endl;
                cout << "2). View registrations using student ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c8selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c8selection < 1 || c8selection > 3) {
                    cout << "Error: Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c8selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c8selection == 1) {
                    cout << "Enter student name: ";
                    getline(cin, c8studentName);
                    if (students.findByName(c8studentName) != -1) {
                        c8studentId = students.getStudentVector().at(students.findByName(c8studentName)).getId();
                    }
                }
                else if (c8selection == 2) {
                    cout << "Enter student ID: ";
                    cin >> c8studentId;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (students.findById(c8studentId) != -1) {
                        c8studentName = students.getStudentVector().at(students.findById(c8studentId)).getName();
                    }
                }
                else if (c8selection == 3) {
                    break;
                }
            }

            vector<int> eventIDs = registrations.getEventIDsForStudent(c8studentId);
            if (eventIDs.empty()) {
                cout << "No registrations found." << endl;
            }
            for (const auto& id : eventIDs) {
                events.displayEvent(events.findEventById(id));
                cout << endl;
            }
            break;
        }
        case 9: {
            int c9selection{};
            int c9eventId{};
            string c9eventName{};

            cout << "1). View attendees using event name" << endl;
            cout << "2). View attendees using event ID" << endl;
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c9selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c9selection < 1 || c9selection > 3) {
                cout << "Error: Invalid selection." << endl;
                cout << "1). View attendees using event name" << endl;
                cout << "2). View attendees using event ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c9selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c9selection == 1) {
                cout << "Enter event name: ";
                getline(cin, c9eventName);
                if (events.findEventByName(c9eventName) != -1) {
                    c9eventId = events.getEventsPointer()->at(events.findEventByName(c9eventName))->getEventId();
                }
            }
            else if (c9selection == 2) {
                cout << "Enter event ID: ";
                cin >> c9eventId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (events.findEventById(c9eventId) != -1) {
                    c9eventName = events.getEventsPointer()->at(events.findEventById(c9eventId))->getEventName();
                }
            }
            else if (c9selection == 3) {
                break;
            }

            vector<int> studentIDs = registrations.getStudentIDsForEvent(c9eventId);
            if (studentIDs.empty()) {
                cout << "No students registered." << endl;
            }
            for (const auto& id : studentIDs) {
                students.displayStudent(id);
                cout << endl;
            }
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
            cout << "3). Return" << endl;
            cout << endl << "Enter selection: ";
            cin >> c10selection;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (c10selection < 1 || c10selection > 3) {
                cout << "Invalid selection." << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c10selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (c10selection == 1) {
                cout << "1). Find by organization name" << endl;
                cout << "2). Find by organization ID" << endl;
                cout << "3). Return" << endl;
                cout << endl << "Enter selection: ";
                cin.clear();
                cin >> c10selection;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (c10selection < 1 || c10selection > 3) {
                    cout << "Invalid selection." << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c10selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (c10selection == 1) {
                    cout << "Organization name: ";
                    getline(cin, c10name);
                    if (organizers.findIndexByName(c10name) != -1) {
                        c10id = organizers.getOrganizersPointer()->at(organizers.findIndexByName(c10name)).getOrganizerId();
                    }
                }
                else if (c10selection == 2) {
                    cout << "Organization ID: ";
                    cin >> c10id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (organizers.findIndexById(c10id) != -1) {
                        c10name = organizers.getOrganizersPointer()->at(organizers.findIndexById(c10id)).getName();
                    }
                }
                else if (c10selection == 3) {
                    break;
                }

                while (organizers.findIndexById(c10id) == -1 || organizers.findIndexByName(c10name) == -1) {
                    cout << "Error: Organizer not found." << endl;
                    cout << "1). Find by organization name" << endl;
                    cout << "2). Find by organization ID" << endl;
                    cout << "3). Return" << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c10selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    while (c10selection < 1 || c10selection > 3) {
                        cout << "Invalid selection." << endl;
                        cout << endl << "Enter selection: ";
                        cin.clear();
                        cin >> c10selection;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (c10selection == 1) {
                        cout << "Organization name: ";
                        getline(cin, c10name);
                        if (organizers.findIndexByName(c10name) != -1) {
                            c10id = organizers.getOrganizersPointer()->at(organizers.findIndexByName(c10name)).getOrganizerId();
                        }                    }
                    else if (c10selection == 2) {
                        cout << "Organization ID: ";
                        cin >> c10id;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (organizers.findIndexById(c10id) != -1) {
                            c10name = organizers.getOrganizersPointer()->at(organizers.findIndexById(c10id)).getName();
                        }                    }
                    else if (c10selection == 3) {
                        break;
                    }
                }

                if (organizers.findIndexById(c10id) != -1) {
                    organizers.displayOrganizer(c10id);
                }

                cout << endl << "Display associated events? (Y/N): ";
                cin >> c10association;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                c10association = toupper(c10association);

                while (c10association != 'Y' && c10association != 'N') {
                    cout << "Invalid selection." << endl;
                    cout << endl << "Display associated events? (Y/N): ";
                    cin.clear();
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
                    cout << endl << "Display associated events? (Y/N): ";
                    cin.clear();
                    cin >> c10association;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    c10association = toupper(c10association);
                }

                if (c10association == toupper('Y')) {
                    cout << "1). Find by organization name" << endl;
                    cout << "2). Find by organization ID" << endl;
                    cout << "3). Return" << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c10selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    while (c10selection < 1 || c10selection > 3) {
                        cout << "Invalid selection." << endl;
                        cout << endl << "Enter selection: ";
                        cin.clear();
                        cin >> c10selection;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (c10selection == 1) {
                        cout << "Organization name: ";
                        getline(cin, c10name);
                    }
                    else if (c10selection == 2) {
                        cout << "Organization ID: ";
                        cin >> c10id;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else if (c10selection == 3) {
                        break;
                    }
                }

                while (organizers.findIndexById(c10id) == -1 || organizers.findIndexByName(c10name) == -1) {
                    cout << "Error: Organizer not found." << endl;
                    cout << "1). Find by organization name" << endl;
                    cout << "2). Find by organization ID" << endl;
                    cout << "3). Return" << endl;
                    cout << endl << "Enter selection: ";
                    cin.clear();
                    cin >> c10selection;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    while (c10selection < 1 || c10selection > 3) {
                        cout << "Invalid selection." << endl;
                        cout << endl << "Enter selection: ";
                        cin.clear();
                        cin >> c10selection;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (c10selection == 1) {
                        cout << "Organization name: ";
                        getline(cin, c10name);
                        c10id = organizers.getOrganizersPointer()->at(organizers.findIndexByName(c10name)).getOrganizerId();
                    }
                    else if (c10selection == 2) {
                        cout << "Organization ID: ";
                        cin >> c10id;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        c10name = organizers.getOrganizersPointer()->at(organizers.findIndexById(c10id)).getName();
                    }
                    else if (c10selection == 3) {
                        break;
                    }
                }
            }
            else if (c10selection == 3) {
                break;
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
    cin.clear();
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
