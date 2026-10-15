
#pragma once
#include <vector>
#include <memory>
#include "Event.h"
#include "RegistrationManager.h"

using namespace std;

class ReportManager {
public:
    void showAvailableEvents(const vector<unique_ptr<Event>>& events,
                             const RegistrationManager& registrations);

    void showFullEvents(const vector<unique_ptr<Event>>& events,
                        const RegistrationManager& registrations);

    void showRegistrationCounts(const vector<unique_ptr<Event>>& events,
                                const RegistrationManager& registrations);

    void showMostPopularEvent(const vector<unique_ptr<Event>>& events,
                              const RegistrationManager& registrations);
};

