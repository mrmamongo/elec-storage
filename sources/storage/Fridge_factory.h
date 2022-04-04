//
// Created by MrMam on 05.04.2022.
//

#ifndef DAN_FRIDGE_FACTORY_H
#define DAN_FRIDGE_FACTORY_H

#include "Fridge.h"
#include "i_elec_factory.h"

class fridge_factory: public i_elec_factory {
public:
    fridge_factory(storage& _storage, range&& random_range = {0, RAND_MAX}):
    i_elec_factory(_storage, std::move(random_range)){}

    producer_t defineProducer() {
        return producer_t::_from_index(_dist(_rng) % 3 + 1);
    }
    std::string createModel(producer_t defined_producer) {
        return "fr_" + std::string(defined_producer._to_string()).substr(0, 2) + "_" + std::to_string(_dist(_rng) % 8999 + 1000 );
    }

    float createVolume(producer_t defined_producer) {
        return static_cast<float>(defined_producer._to_integral()) *
               static_cast<float>(_dist(_rng) % 100);
    }

    float createPower(producer_t defined_producer) {
        return static_cast<float>(defined_producer._to_integral()) *
               static_cast<float>(_dist(_rng) % 750 + 250);
    }

    i_electronics* _create_item() override {
        producer_t producer = defineProducer();
        std::string model = createModel(producer);
        float volume = createVolume(producer);
        float power = createPower(producer);
        int price = static_cast<float>(_dist(_rng) % 40000 + 10000);
        return new fridge(model, producer, volume, power, static_cast<float>(price));
    }
};

#endif //DAN_FRIDGE_FACTORY_H
