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
void TV::print_info() const{
    std::cout << "Model: " << _model << " ";
    std::cout << "Producer: " << _producer._to_string() << " ";
    std::cout << "Resolution: " << _resolution.x << "x" << _resolution.y << " ";
    std::cout << "Brightness: " << _brightness << " ";
    std::cout << "Price: " << _price << "\n";
}

//bool TV::test() const {
//    int random_value = (rand() % 10000);
//    if (random_value > (_resolution.x + _resolution.y + int(_brightness))) {
//        return false;
//    }  else {
//        return true;
//    }
//}
bool TV::test() const {

    if (_resolution.x < 2000) {
        return false;
    }  else {
        return true;
    }
}
