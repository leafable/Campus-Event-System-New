#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/FileManager.h"
#include "../include/AcademicEvent.h"
#include "../include/CareerEvent.h"
#include "../include/ClubEvent.h"
#include "../include/EventSystem.h"
#include "../include/Registration.h"
#include "../include/RegistrationManager.h"
#include "../include/SocialEvent.h"
#include "../include/StudentManagement.h"
#include "../include/OrganizerManagement.h"


using namespace std;

FileManager::FileManager(StudentManagement& stm, EventSystem& evs, OrganizerManagement& orgs, RegistrationManager& regm) {
    readStudents(stm);
    readEvents(evs);
    readOrganizers(orgs);
    readRegistrations(regm);
}

void FileManager::readStudents(StudentManagement& sm) {

    // open the students.txt file
    std::ifstream enrolled("data/students.txt");

    //initialize counter variable to track line read
    int i = 0;


    string line;

    //read all the lines in the file
    while (getline(enrolled, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string name, email, major, tempId;
        int id;

        //store all CSV in the line to variables
        getline(ss, tempId, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, major);

        //Check if current row is missing a data member
        if (email.empty() && !getline(ss, major, ',')) {
            cerr << "Error! There is data missing from line " << i << endl;
            continue;
        }

        //convert tempId to int id and catch errors
        try {
            id = stoi(tempId);
        } catch (const exception &e) {
            cerr << "Error reading ID. Skipped line: " << i << endl;
            continue;
        }

        sm.addStudent(id, name, email, major);
    }

    enrolled.close();
}

void FileManager::writeStudents(StudentManagement& sm) {

    ofstream enrolled("data/students.txt");

    // std::vector<Student>* stuPtr = sm.getStudentsPointer();
    //
    // if (stuPtr != nullptr) {
    //     for (const Student& s : *stuPtr) {
    //         enrolled << s.id << "," << s.name << "," << s.email << "," << s.major << '\n';
    //     }
    // }

    for (const Student& s : sm.getStudentVector()) {
        enrolled << s.id << "," << s.name << "," << s.email << "," << s.major << '\n';
    }

    enrolled.close();
}

void FileManager::readEvents(EventSystem& es) {
    // open the events.txt file
    std::ifstream eventFile("data/events.txt");

    //initialize counter variable to track line read
    int i = 0;

    string line; //string to hold line text

    //read all the lines in the file
    while (getline(eventFile, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string tempId, name, description, date, location, org, start, maxcap, length;
        int imaxcap, id;

        //store all CSV in the line to variables
        getline(ss, tempId, ',');
        getline(ss, name, ',');
        getline(ss, description, ',');
        getline(ss, date, ',');
        getline(ss, start, ',');
        getline(ss, location, ',');
        getline(ss, maxcap, ',');
        getline(ss, org, ',');
        getline(ss, length, ',');

        // if (!getline(ss, length, ',')) {
        //     cerr << "Missing data in line: " << i << endl;
        //     continue;
        // }

        //convert numerical strings to proper data types
        try {
            imaxcap = stoi(maxcap);
            id = stoi(tempId);
        } catch (const exception &e) {
            cerr << "Error reading numerical values. Skipped line: " << i << endl;
            continue;
        }

        if (description == "Academic Event") {
            string department, speaker;
            getline(ss, department, ',');
            getline(ss, speaker, ',');

            //creates AcademicEvent object and stores it in an event unique ptr then adds to EventSystem
            std::unique_ptr<Event> my_event = std::make_unique<AcademicEvent>(id, name, description, date, start, location,
                imaxcap, org, length, department, speaker);
            es.createEvent(std::move(my_event));
        }
        else if (description == "Career Event") {
            string company, recruiter;
            getline(ss, company, ',');
            getline(ss, recruiter, ',');

            //creates CareerEvent object and stores it in an event unique ptr then adds to EventSystem
            std::unique_ptr<Event> my_event = std::make_unique<CareerEvent>(id, name, description, date, start, location,
                imaxcap, org, length, company, recruiter);
            es.createEvent(std::move(my_event));
        }
        else if (description == "Club Event") {
            string club;
            getline(ss, club, ',');

            //creates ClubEvent object and stores it in an event unique ptr then adds to EventSystem
            std::unique_ptr<Event> my_event = std::make_unique<ClubEvent>(id, name, description, date, start, location,
                imaxcap, org, length, club);
            es.createEvent(std::move(my_event));
        }
        else if (description == "Social Event") {
            string tempBool;
            getline(ss, tempBool, ',');
            bool fancy = stoi(tempBool); //converts string to integer then boolean

            //creates Social Event object and stores it in an event unique ptr then adds to EventSystem
            std::unique_ptr<Event> my_event = std::make_unique<SocialEvent>(id, name, description, date, start, location,
                imaxcap, org, length, fancy);
            es.createEvent(std::move(my_event));

        }
        else {
            cerr << "Error reading event type. Skipped line: " << i << endl;
        }

    } //end of reading file loop

    //close the file stream
    eventFile.close();
}

void FileManager::writeEvents(EventSystem& es) {
    ofstream events("data/events.txt");

    const vector<unique_ptr<Event>> *eventsPtr = es.getEventsPointer();

    if (eventsPtr != nullptr) {
        for (const unique_ptr<Event>& e : *eventsPtr) {

            events <<  e->getEventId() << "," <<  e->getEventName() << "," << e->getEventDescription() << ","
            << e->getEventDate() << "," << e->getEventTime() << "," <<  e->getEventLocation() << ","
            << e->getEventMaxCapacity() << "," << e->getOrganizer();

            // Determine type of event and write event specific data
            if (e->getEventDescription() == "Academic Event")
            {
                auto* ePtr = dynamic_cast<AcademicEvent*>(e.get());
                events << "," << ePtr->getDepartment() << "," << ePtr->getSpeaker() << endl;
            }
            else if (e->getEventDescription() == "Career Event")
            {
                auto* ePtr = dynamic_cast<CareerEvent*>(e.get());
                events << "," << ePtr->getCompanyName() << "," << ePtr->getRecruiterName() << endl;
            }
            else if (e->getEventDescription() == "Club Event")
            {
                auto* ePtr = dynamic_cast<ClubEvent*>(e.get());
                events << "," << ePtr->getClub() << '\n';
            }
            else if (e->getEventDescription() == "Social Event")
            {
                auto* ePtr = dynamic_cast<SocialEvent*>(e.get());
                events << "," << ePtr->getIfFancy() << '\n';
            }
        }
    }

    events.close();
}

void FileManager::readOrganizers(OrganizerManagement& org) {

    // open the students.txt file
    std::ifstream organizer("data/organizers.txt");

    //initialize counter variable to track line read
    int i = 0;

    string line;

    getline(organizer, line);

    //read all the lines in the file
    while (getline(organizer, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string name, email, dept, tempId;
        int id;

        //store all CSV in the line to variables
        getline(ss, tempId, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, dept, ',');

        //Check if current row is missing a data member
        if (tempId.empty() || name.empty() || email.empty() || dept.empty()) {
            cerr << "Error! There is data missing from line " << i << endl;
            continue;
        }



        //convert tempId to int id and catch errors
        try {
            id = stoi(tempId);
        } catch (const exception &e) {
            cerr << "Error reading ID. Skipped line: " << i << endl;
            continue;
        }

        org.addOrganizer(name, id, email, dept);
    }

    organizer.close();

}

void FileManager::writeOrganizers(OrganizerManagement& org) {

    //open txt file to save organizers
    ofstream orgFile("data/organizers.txt");

    //get a pointer to the vector holding the organizers
    const vector<Organizer> *orgPtr = org.getOrganizersPointer();

    if (orgPtr != nullptr) {
        for (const Organizer& o : *orgPtr) {
            orgFile << o.getOrganizerId() << "," << o.getName() << "," << o.getEmail() << "," << o.getDepartment() << '\n';
        }
    }

    // for (const Organizer& s : org.getStudentVector()) {
    //     orgFile << o.id << "," << o.name << "," << o.email << "," << o.dept << '\n';
    // }

    orgFile.close();
}

void FileManager::readRegistrations(RegistrationManager& rm) {

    // open the registrations.txt file
    std::ifstream registration("data/registrations.txt");

    //initialize counter variable to track line read
    int i = 0;


    string line;

    //read all the lines in the file
    while (getline(registration, line)) {
        ++i; //we have read the first line

        //create a string stream to grab line
        stringstream ss(line);

        //declare all holding variables
        string tempSId, tempEId, regDate, stat;
        int SId, EId;
        bool status;

        //store all CSV in the line to variables
        getline(ss, tempSId, ',');
        getline(ss, tempEId, ',');
        getline(ss, regDate, ',');
        getline(ss, stat, ',');

        //Check if current row is missing a data member
        // if (status.empty() && !getline(ss, major, ',')) {
        //     cerr << "Error! There is data missing from line " << i << endl;
        //     continue;
        // }



        //convert temp string IDs to int IDs and catch errors
        try {
            SId = stoi(tempSId);
            EId = stoi(tempEId);
            status = stoi(stat);
        } catch (const exception &e) {
            cerr << "Error reading IDs. Skipped line: " << i << endl;
            continue;
        }

        rm.loadRegistration(Registration(SId, EId, regDate, status));
    }

    registration.close();
}

void FileManager::writeRegistrations(RegistrationManager& rm) {

    //open txt file to save registrations
    ofstream regFile("data/registrations.txt");

    //get a pointer to the vector holding the organizers
    // std::vector<Registration>* regPtr = rm.getOrganizerPointer();
    //
    // if (regPtr != nullptr) {
    //     for (const Registration& r : *regPtr) {
    //         regFile << r.studentID << "," << r.eventID << "," << o.email << "," << o.dept << '\n';
    //     }
    // }

    for (const Registration& r : rm.getAllRegistrations()) {
        regFile << r.getStudentID() << "," << r.getEventID() << "," << r.getRegistrationDate() << "," << r.getStatus() << '\n';
    }

    regFile.close();;
}

void FileManager::saveData(StudentManagement& stm, EventSystem& evs, OrganizerManagement& orgs, RegistrationManager& regm) {
    writeStudents(stm);
    writeEvents(evs);
    writeOrganizers(orgs);
    writeRegistrations(regm);
}