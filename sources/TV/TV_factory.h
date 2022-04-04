//
// Created by MrMam on 04.04.2022.
//

#ifndef DAN_TV_FACTORY_H
#define DAN_TV_FACTORY_H

#include <TV.h>
#include <random>
#include <array>

template <int _resolutions>
class TV_factory {
public:
    TV_factory(std::array<TV::resolution_t, _resolutions>&& res, int start = 0, int end = RAND_MAX):
            _res(res), _dev(), _rng(_dev()), _dist(start, end) {}

    inline producer_t defineProducer() {
        return producer_t::_from_index((_dist(_rng) % 3 + 1));
    }

    inline std::string createModel(producer_t defined_producer) {
        return std::string(defined_producer._to_string()).substr(0, 2) + std::to_string(_dist(_rng) % 9999 + 1000);
    }

    inline TV::resolution_t createResolution() {
        return _res[_dist(_rng) % _res.size()];
    };

    inline int createBrightness(producer_t defined_producer, TV::resolution_t defined_resolution) {
        return defined_producer * defined_resolution.x + defined_resolution.y;
    }

    TV createTV() {
        producer_t producer = defineProducer();
        std::string model = createModel(producer);
        TV::resolution_t resolution = createResolution();
        int brightness = createBrightness(producer, resolution);
        int price = (_dist(_rng) % 40000 + 10000);
        return {model, producer, resolution, static_cast<float>(brightness), static_cast<float>(price)};
    }

private:
    std::random_device _dev;
    std::mt19937 _rng;
    std::uniform_int_distribution<std::mt19937::result_type> _dist;
    std::array<TV::resolution_t, 5> _res;
};

#endif //DAN_TV_FACTORY_H
