#include <iostream>
#include "WeatherData.h"
#include "Client.h"
#include <string>
#include <map>

enum MyEnum
{
    ONE = 1,
    TWO,
    THREE,
    ALL,
    EXIT,
    RM1,
    RM2,
    RM3,
    RM,
    KEEP
};
int main()
{
    int nStateChanged = 0;
    std::string cmd;
    bool flag = true;
    std::map<std::string, int> mp = {{"one", ONE},
                                  {"two", TWO},
                                  {"three", THREE},
                                  {"all", ALL},
                                  {"rm1", RM1},
                                  {"rm2", RM2},
                                  {"rm3", RM3},
                                  {"exit", EXIT},
                                  {"rm", RM},
                                  {"keep", KEEP} };

    WeatherData weatherStation;
    Client one(1);
    Client two(2);
    Client three(3);

    float temp, humidity, pressure;

    while (flag)
    {
        std::cout << "===================================================================" << std::endl;
        std::cout << "Register: one/two/three/all :: "
                  << "Remove  : rm1/rm2/rm3/rm " << std::endl;
        std::cout << "Command: ";

        nStateChanged++;
        std::cin >> cmd;

        switch (mp[cmd])
        {
        case ONE:
            weatherStation.registerObserver(&one);
            break;
        case TWO:
            weatherStation.registerObserver(&two);
            break;
        case THREE:
            weatherStation.registerObserver(&three);
            break;
        case ALL:
            weatherStation.registerObserver(&one);
            weatherStation.registerObserver(&two);
            weatherStation.registerObserver(&three);
            break;

        case RM1:
            weatherStation.removeObserver(&one);
            break;
        case RM2:
            weatherStation.removeObserver(&two);
            break;
        case RM3:
            weatherStation.removeObserver(&three);
            break;
        case EXIT:
            return 0;
            break;
        default:
            break;
        }

        std::cout << "[NumChanged - " << nStateChanged << "] - Enter Temperature, Humidity, Pressure << ";
        std::cin >> temp >> humidity >> pressure;

        weatherStation.setState(temp, humidity, pressure);
    }

    return 0;
}
