//
// Created by MrMam on 04.04.2022.
//

#ifndef DAN_FRIDGE_H
#define DAN_FRIDGE_H


#include <string>
#include <iostream>
#include <utility>
#include "i_electronic.h"

class fridge : public i_electronics {
    template <int _resolutions>
    friend class TV_factory;

public:
    fridge(std::string model, producer_t producer, float volume, float power, float price):
            _volume(volume), _power(power), i_electronics(std::move(model), producer, price){};

    [[nodiscard]] bool test(int start, int end) const override;
    void print_info(std::ostream& os) const override;
private:
    float _volume;
    float _power;
};

#endif //DAN_FRIDGE_H
