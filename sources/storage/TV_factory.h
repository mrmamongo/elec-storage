//
// Created by MrMam on 04.04.2022.
//

#ifndef DAN_TV_FACTORY_H
#define DAN_TV_FACTORY_H

#include <random>
#include <ctime>
#include <array>
#include "TV.h"
#include "i_elec_factory.h"


template <int _resolutions = 5>
class TV_factory: public i_elec_factory {
public:
    TV_factory(std::array<TV::resolution_t, _resolutions> resolutions, storage& _storage, range&& random_range = {0, RAND_MAX}):
    _res(resolutions), i_elec_factory(_storage, std::move(random_range)){}

    producer_t defineProducer() {
        return producer_t::_from_index(_dist(_rng) % 3 + 1);
    }
    std::string createModel(producer_t defined_producer) {
        return "tv_" + std::string(defined_producer._to_string()).substr(0, 2) + "_" + std::to_string(_dist(_rng) % 8999 + 1000 );
    }
    TV::resolution_t createResolution() {
        return _res[_dist(_rng) % _res.size()];
    };
    int createBrightness(producer_t defined_producer, TV::resolution_t defined_resolution) {
        return defined_resolution.x + defined_resolution.y * defined_producer;
    }

    i_electronics* _create_item() override {
        producer_t producer = defineProducer();
        std::string model = createModel(producer);
        TV::resolution_t resolution = createResolution();
        int brightness = createBrightness(producer, resolution);
        int price = (_dist(_rng) % 40000 + 10000);
        return new TV(model, producer, resolution, static_cast<float>(brightness), static_cast<float>(price));
    }

private:
    std::array<TV::resolution_t, _resolutions> _res;
};


#endif //DAN_TV_FACTORY_H
