#include "System.h"

System::System() {
}

System::~System() {
    filemanager.saveData(students, events, organizers, registrations);
}