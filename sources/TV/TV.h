//
// Created by MrMam on 03.04.2022.
//

#ifndef DAN_TV_H
#define DAN_TV_H

#include <string>
#include <iostream>
#include <enums.h>


BETTER_ENUM(producer_t, uint8_t,
            samsung = 1,
            hp = 2,
            benq = 3,
            LG = 4
)

// model, producer, resolution, price
class TV {
    template <int _resolutions>
    friend class TV_factory;

public:
    struct resolution_t {
        int x;
        int y;
    };
    TV(std::string model, producer_t producer, TV::resolution_t resolution,
       float brightness, float price):_model(model), _producer(producer),
       _resolution(resolution), _brightness(brightness), _price(price){};


    bool test() const;
    void print_info(std::ostream& os = std::cout) const;
    resolution_t get_resolution() const;
    std::string get_model() const;
    producer_t get_producer() const {
        return _producer;
    }
    float get_brightness() const;
    float get_price() const;
private:
    std::string _model;
    producer_t _producer;
    resolution_t _resolution;
    float _brightness;
    float _price;
};

#endif // DAN_TV_H