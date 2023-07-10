#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class Elem
{
private:
    double lat;
    double lon;
public:
    Elem() = default;
    ~Elem() = default;
    friend class Coordinates;
};

class Coordinates 
{
private:
    std::vector<Elem> coord;

public:
    Coordinates() = default;
    ~Coordinates() = default;

    void fillingCoord(const std::string &file);
};

#include "../src/Coordinates.cpp"

#endif //COORDINATES_HPP