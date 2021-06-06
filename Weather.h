#ifndef WEATHER_PROJECT_WEATHER_H
#define WEATHER_PROJECT_WEATHER_H
#include <string>
#include <iostream>

class Weather
{
    // unique key
    int key;

    // temperature in fahrenheit
    double temperature, humidity, wind;
    std::string location, description;

public:

    Weather();
    /*
	** Header: Weather(Weather &weather)
	** Copy constructor
	** Pre:
	** Post: copy all the attributes to construct new Weather object
	** Return:
	*/
    Weather(Weather &weather);
    /*
	** Header: Weather(double temp, double humid, double wind, std::string loc)
	** Constructor
	** Pre:
	** Post: initialize attributes with given parameters
	** Return:
	*/
    Weather(double temp, double humid, double wind, std::string loc);
    /*
	** Header: Weather(double temp, double humid, double wind, std::string loc, std::string desc)
	** Constructor
	** Pre:
	** Post: initialize attributes with given parameters
	** Return:
	*/
    Weather(double temp, double humid, double wind, std::string loc, std::string desc);

    // getters

    /*
	** Header: getUniqueKey()
	** Returns unique key
	** Pre:
	** Post:
	** Return: int value of key
	*/
    int getUniqueKey();
    /*
	** Header: getTemperature(bool isFahrenheit)
	** Returns temperature
	** Pre:
	** Post:
	** Return: double value of temperature
	*/
    double getTemperature(bool isFahrenheit = true);
    /*
	** Header: getHumidity()
	** Returns humidity
	** Pre:
	** Post:
	** Return: double value of humidity
	*/
    double getHumidity();
    /*
	** Header: getWind()
	** Returns wind
	** Pre:
	** Post:
	** Return: double value of wind
	*/
    double getWind();
    /*
	** Header: getLocation()
	** Returns location
	** Pre:
	** Post:
	** Return: string value of location
	*/
    std::string getLocation();
    /*
	** Header: getDescription()
	** Returns description
	** Pre:
	** Post:
	** Return: string value of description
	*/
    std::string getDescription();

    // setters
    /*
	** Header: setUniqueKey(int key)
	** Sets int value of key
	** Pre: int value of key
	** Post:
	** Return:
	*/
    void setUniqueKey(int key);
    /*
	** Header: setTemperature(double temp, bool isFahrenheit)
	** Sets double value of temperature
	** Pre: double value of temperature, bool value of isFahrenheit
	** Post:
	** Return:
	*/
    void setTemperature(double temp, bool isFahrenheit = true);
    /*
	** Header: setHumidity(double humid)
	** Sets double value of humidity
	** Pre: double value of humidity
	** Post:
	** Return:
	*/
    void setHumidity(double humid);
    /*
	** Header: setWind(double wind)
	** Sets double value of wind
	** Pre: double value of wind
	** Post:
	** Return:
	*/
    void setWind(double d);
    /*
	** Header: setLocation(std::string loc)
	** Sets string value of location
	** Pre: string value of location
	** Post:
	** Return:
	*/
    void setLocation(std::string loc);
    /*
	** Header: setDescription(std::string desc)
	** Sets string value of description
	** Pre: string value of description
	** Post:
	** Return:
	*/
    void setDescription(std::string desc);

    // overloaded operators
    /*
	** Header: operator<<(std::ostream &out, Weather &weather)
	** Overloaded stream output operator
	** Pre: a reference of ostream, reference of Weather
	** Post:
	** Return: a reference of ostream
	*/
    friend std::ostream &operator<<(std::ostream &out, Weather &weather);
    /*
	** Header: operator>>(std::istream &in, Weather &weather)
	** Overloaded stream input operator
	** Pre: a reference of istream, reference of Weather
	** Post:
	** Return: a reference of istream
	*/
    friend std::istream &operator>>(std::istream &in, Weather &weather);
    /*
	** Header: operator<(const Weather &lhs, const Weather &rhs)
	** Overloaded comparison operator
	** Pre: a reference of Weather on the left, a reference of Weather on the right
	** Post:
	** Return: boolen value
	*/
    friend bool operator<(const Weather &lhs, const Weather &rhs);
    /*
	** Header: operator>(const Weather &lhs, const Weather &rhs)
	** Overloaded comparison operator
	** Pre: a reference of Weather on the left, a reference of Weather on the right
	** Post:
	** Return: boolen value
	*/
    friend bool operator>(const Weather &lhs, const Weather &rhs);
    /*
	** Header: operator<=(const Weather &lhs, const Weather &rhs)
	** Overloaded comparison operator
	** Pre: a reference of Weather on the left, a reference of Weather on the right
	** Post:
	** Return: boolen value
	*/
    friend bool operator<=(const Weather &lhs, const Weather &rhs);
    /*
	** Header: operator>=(const Weather &lhs, const Weather &rhs)
	** Overloaded comparison operator
	** Pre: a reference of Weather on the left, a reference of Weather on the right
	** Post:
	** Return: boolen value
	*/
    friend bool operator>=(const Weather &lhs, const Weather &rhs);
    /*
	** Header: operator==(const Weather &lhs, const Weather &rhs)
	** Overloaded comparison operator
	** Pre: a reference of Weather on the left, a reference of Weather on the right
	** Post:
	** Return: boolen value
	*/
    friend bool operator==(const Weather &lhs, const Weather &rhs);
    /*
	** Header: operator!=(const Weather &lhs, const Weather &rhs)
	** Overloaded comparison operator
	** Pre: a reference of Weather on the left, a reference of Weather on the right
	** Post:
	** Return: boolen value
	*/
    friend bool operator!=(const Weather &lhs, const Weather &rhs);
};
#endif //WEATHERPROJECT_WEATHER_H
