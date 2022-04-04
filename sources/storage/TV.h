//
// Created by MrMam on 03.04.2022.
//

#ifndef DAN_TV_H
#define DAN_TV_H

#include <string>
#include <iostream>
#include <utility>
#include "i_electronic.h"

class TV : public i_electronics {
template <int _resolutions>
friend class TV_factory;

public:
    struct resolution_t {
        int x;
        int y;
    };

    TV(std::string model, producer_t producer, TV::resolution_t resolution, float brightness, float price):
    _resolution(resolution), _brightness(brightness), i_electronics(std::move(model), producer, price){};

    [[nodiscard]] bool test(int start = 0, int end = 15000) const override;
    void print_info(std::ostream& os) const override;
private:
    resolution_t _resolution;
    float _brightness;
};

#endif // DAN_TV_H