//
// Created by MrMam on 03.04.2022.
//

#include "TV.h"

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
void TV::print_info(std::ostream& os) const {
    os << "Model: " << _model << " ";
    os << "Producer: " << _producer._to_string() << " ";
    os << "Resolution: " << _resolution.x << "x" << _resolution.y << " ";
    os << "Brightness: " << _brightness << " ";
    os << "Price: " << _price << "\n";
}

bool TV::test() const {
    int random_value = (rand() % 15000);
    if (random_value > (_resolution.x + _resolution.y + int(_brightness))) {
        return false;
    }  else {
        return true;
    }
}

