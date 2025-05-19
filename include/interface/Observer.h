#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

// Interface for observer classes that respond to notifications
class Observer {
  public:
    // Called when an event occurs, receives a message describing the evnt
    virtual void notify(const std::string& message) = 0;

    // Virtual destructor for safe cleanup of derived classes
    virtual ~Observer() = default;
};

#endif //OBSERVER_H
