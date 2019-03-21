#ifndef OBSERVER_PATTERN_SUBJECT_HPP
#define OBSERVER_PATTERN_SUBJECT_HPP 

#include "Observer.h"


class Subject
{
public:
    /**
     * @brief Register an observer
     * 
     * @param observer the observer object to be registered
     */
    virtual void registerObserver(Observer *observer) = 0;

    /**
     * @brief Unregister an observer
     * 
     * @param observer the observer object to be unregistered
     */
    virtual void removeObserver(Observer *observer) = 0;

    /**
     * @brief Notify all the registered observers when a change happens
     * 
     */
    virtual void notifyObservers() = 0;
};

#endif 