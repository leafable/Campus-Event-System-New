#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class StudentManagement;
class EventSystem;
class OrganizerManagement;
class RegistrationManager;

class FileManager {

    public:
    FileManager(StudentManagement& stm, EventSystem& evs, OrganizerManagement& orgs, RegistrationManager& regm);
    void readStudents(StudentManagement& sm);
    void writeStudents(StudentManagement& sm);
    void readEvents(EventSystem& es);
    void writeEvents(EventSystem& es);
    void readOrganizers(OrganizerManagement& org);
    void writeOrganizers(OrganizerManagement& org);
    void readRegistrations(RegistrationManager& rm);
    void writeRegistrations(RegistrationManager& rm);
    void saveData(StudentManagement& stm, EventSystem& evs, OrganizerManagement& orgs, RegistrationManager& regm);

    private:

};

#endif