//
// Created by MrMam on 04.04.2022.
//

#ifndef DAN_I_ELECTRONIC_H
#define DAN_I_ELECTRONIC_H

#include <string>
#include <utility>
#include "enums.h"

BETTER_ENUM(producer_t, uint8_t,
        samsung = 1,
        hp = 2,
        benq = 3,
        LG = 4
)

BETTER_ENUM(el_type, uint8_t,
            fridge = 1,
            tv = 2
            )

class i_electronics {
friend class i_elec_factory;
public:
    i_electronics(std::string&& model, producer_t producer, float price):
        _model(std::move(model)), _producer(producer), _price(price) {}


    [[nodiscard]] virtual bool test(int start, int end) const = 0;
    virtual void print_info(std::ostream& os) const = 0;
    virtual el_type get_type() const = 0;
protected:
    std::string _model;
    producer_t _producer;
    float _price;
};

#endif //DAN_I_ELECTRONIC_H
