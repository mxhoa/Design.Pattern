#ifndef OBSERVER_PATTERN_OBSERVER_HPP
#define OBSERVER_PATTERN_OBSERVER_HPP 

/**
 * @brief Interface for the Observer 
 * 
 */

class Observer
{
public:
    /**
     * @brief Update the state of this observer 
     * 
     * @param temp      - new temperature
     * @param humidity  - new humidity
     * @param pressure  - new pressure
     */
    virtual void update(float temp, float humidity, float pressure) = 0;
};


#endif 