//
// Created by MrMam on 03.04.2022.
//

#include "TV.h"
#include <random>

TV::resolution_t TV::get_resolution() const {
    return _resolution;
}
std::string TV::get_model() const {
    return _model;
}

float TV::get_brightness() const {
    return _brightness;
}
float TV::get_price() const {
    return _price;
}
void TV::print_info() const{
    std::cout << "Model: " << _model << " ";
    std::cout << "Producer: " << _producer._to_string() << " ";
    std::cout << "Resolution: " << _resolution.x << "x" << _resolution.y << " ";
    std::cout << "Brightness: " << _brightness << " ";
    std::cout << "Price: " << _price << "\n";
}

bool TV::test(int start, int end) const {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    static std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    if (dist(rng) > (_resolution.x + _resolution.y + int(_brightness))) {
        return false;
    }  else {
        return true;
    }
}
