
#include "../include/ReportManager.h"
#include <iostream>

using namespace std;

void ReportManager::showAvailableEvents(
    const vector<unique_ptr<Event>>& events,
    const RegistrationManager& registrations)
{
    cout << "\nEvents with Available Capacity:\n";

    for (const auto& event : events) {
        int count = registrations.countForEvent(event->getEventId());
        int available = event->getEventMaxCapacity() - count;

        if (available > 0) {
            cout << event->getEventName()
                 << " - Available spots: " << available << endl;
        }
    }
}

void ReportManager::showFullEvents(
    const vector<unique_ptr<Event>>& events,
    const RegistrationManager& registrations)
{
    cout << "\nFull Events:\n";

    for (const auto& event : events) {
        int count = registrations.countForEvent(event->getEventId());

        if (count >= event->getEventMaxCapacity()) {
            cout << event->getEventName() << endl;
        }
    }
}

void ReportManager::showRegistrationCounts(
    const vector<unique_ptr<Event>>& events,
    const RegistrationManager& registrations)
{
    cout << "\nRegistration Counts:\n";

    for (const auto& event : events) {
        cout << event->getEventName() << ": "
             << registrations.countForEvent(event->getEventId())
             << " registrations" << endl;
    }
}

void ReportManager::showMostPopularEvent(
    const vector<unique_ptr<Event>>& events,
    const RegistrationManager& registrations)
{
    if (events.empty()) {
        cout << "No events available.\n";
        return;
    }

    int highest = -1;
    string popularEvent;

    for (const auto& event : events) {
        int count = registrations.countForEvent(event->getEventId());

        if (count > highest) {
            highest = count;
            popularEvent = event->getEventName();
        }
    }

    cout << "\nMost Popular Event: " << popularEvent
         << " (" << highest << " registrations)" << endl;
}

