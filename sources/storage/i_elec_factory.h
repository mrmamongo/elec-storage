//
// Created by MrMam on 04.04.2022.
//

#ifndef DAN_I_ELEC_FACTORY_H
#define DAN_I_ELEC_FACTORY_H

#include <list>
#include <random>
#include "i_electronic.h"

struct range {
    int start, end;
};

using storage = std::list<i_electronics*>;

class i_elec_factory {
public:
    explicit i_elec_factory(storage& storage, range&& random_range):
    _rng(_dev()), _dist(random_range.start, random_range.end), _storage(storage){}

    void emplace_back(i_electronics* item) {
        _storage.emplace_back(item);
    }

    i_electronics* create_item() {
        auto item = _create_item();
        emplace_back(item);
        return item;
    }

protected:
    virtual i_electronics* _create_item() = 0;

    storage& _storage;
    std::random_device _dev;
    std::mt19937 _rng;
    std::uniform_int_distribution<std::mt19937::result_type> _dist;
};

#endif //DAN_I_ELEC_FACTORY_H
