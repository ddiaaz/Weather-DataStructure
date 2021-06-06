#include "Weather.h"
#include <iostream>
Weather::Weather()
{
    this->key = 0;
    this->temperature = 0.0;
    this->humidity = 0.0;
    this->wind = 0.0;
    this->location = "";
    this->description = "";
}

Weather::Weather(Weather &weather)
{
    this->key = weather.key;
    this->temperature = weather.temperature;
    this->humidity = weather.humidity;
    this->wind = weather.wind;
    this->location = weather.location;
    this->description = weather.description;
}

Weather::Weather(double temp, double humid, double wind, std::string loc)
{
    this->key = 0;
    this->temperature = temp;
    this->humidity = humid;
    this->wind = wind;
    this->location = loc;
    this->description = "";
}

Weather::Weather(double temp, double humid, double wind, std::string loc, std::string desc)
{
    this->key = 0;
    this->temperature = temp;
    this->humidity = humid;
    this->wind = wind;
    this->location = loc;
    this->description = desc;
}

int Weather::getUniqueKey()
{
    return this->key;
}

double Weather::getTemperature(bool isFahrenheit)
{
    if (isFahrenheit)
        return this->temperature;
    else
        return ((this->temperature - 32.0) * 5.0 / 9.0);
}

double Weather::getHumidity()
{
    return this->humidity;
}

double Weather::getWind()
{
    return this->wind;
}

std::string Weather::getLocation()
{
    return this->location;
}

std::string Weather::getDescription()
{
    return this->description;
}

void Weather::setUniqueKey(int key)
{
    this->key = key;
}

void Weather::setTemperature(double temp, bool isFahrenheit)
{
    if (isFahrenheit)
        this->temperature = temp;
    else
        this->temperature = (temp * 9.0 / 5.0 + 32);
}

void Weather::setHumidity(double humid)
{
    this->humidity = humid;
}

void Weather::setWind(double d)
{
    this->wind = d;
}

void Weather::setLocation(std::string loc)
{
    this->location = std::move(loc);
}

void Weather::setDescription(std::string desc)
{
    this->description = desc;
}

std::ostream &operator<<(std::ostream &out, Weather &weather)
{
    out << "[ Location: " << weather.getLocation() << " | "
        << "Temperature: " << weather.getTemperature() << " °F" << " | "
        << "Humidity: " << weather.getHumidity() << " %" << " | "
        << "Wind: " << weather.getWind() << " m/s | "
        <<"Key: "<<weather.getUniqueKey()<< "]\n";

    if (weather.description != "")
        out << "Description: " << weather.getDescription() << std::endl;

    return out;
}

std::istream &operator>>(std::istream &in, Weather &weather)
{
    std::string location;
    double temperature, humidity, wind;
    //int key;

    in >> temperature >> humidity >> wind;
    std::getline(in, location);

    weather.setLocation(location);
    weather.setTemperature(temperature);
    weather.setHumidity(humidity);
    weather.setWind(wind);
    weather.setUniqueKey( (int)(temperature+humidity+wind));

    return in;
}

bool operator<(const Weather &lhs, const Weather &rhs)
{
    double val1 = lhs.temperature + lhs.humidity + lhs.wind;
    double val2 = rhs.temperature + rhs.humidity + rhs.wind;
    return (val1 < val2);
}

bool operator>(const Weather &lhs, const Weather &rhs)
{
    double val1 = lhs.temperature + lhs.humidity + lhs.wind;
    double val2 = rhs.temperature + rhs.humidity + rhs.wind;
    return (val1 > val2);
}

bool operator<=(const Weather &lhs, const Weather &rhs)
{
    double val1 = lhs.temperature + lhs.humidity + lhs.wind;
    double val2 = rhs.temperature + rhs.humidity + rhs.wind;
    return (val1 <= val2);
}

bool operator>=(const Weather &lhs, const Weather &rhs)
{
    double val1 = lhs.temperature + lhs.humidity + lhs.wind;
    double val2 = rhs.temperature + rhs.humidity + rhs.wind;
    return (val1 >= val2);
}

bool operator==(const Weather &lhs, const Weather &rhs)
{
    double val1 = lhs.temperature + lhs.humidity + lhs.wind;
    double val2 = rhs.temperature + rhs.humidity + rhs.wind;
    return val1 == val2;
}

bool operator!=(const Weather &lhs, const Weather &rhs)
{
    double val1 = lhs.temperature + lhs.humidity + lhs.wind;
    double val2 = rhs.temperature + rhs.humidity + rhs.wind;
    return val1 != val2;
}
