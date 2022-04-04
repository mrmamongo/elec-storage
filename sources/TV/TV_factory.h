//
// Created by MrMam on 04.04.2022.
//

#ifndef DAN_TV_FACTORY_H
#define DAN_TV_FACTORY_H

#include <random>
#include <ctime>
#include <array>
#include <TV.h>

struct range {
    int start, end;
};

template <int _resolutions = 5>
class TV_factory {
public:
    TV_factory(std::array<TV::resolution_t, _resolutions> resolutions, range&& random_range = {0, RAND_MAX}): _res(resolutions), _rnd(_dev()), _dist(random_range.start, random_range.end){}

    producer_t defineProducer() {
        int random_value = (_dist(_rnd) % 3 + 1);
        auto out_producer = producer_t::_from_index(random_value);
        return out_producer;
    }

    std::string createModel(producer_t defined_producer) {
        std::string out_model;
        auto producer = defined_producer._to_string();
        out_model += char(producer[0]);
        out_model += char(producer[1]);
        int random_numbers = (_dist(_rnd) % 9999 + 1000);
        out_model += std::to_string(random_numbers);
        return out_model;
    }

    TV::resolution_t createResolution() {
        int random_value = _dist(_rnd) % _res.size();

        return _res[random_value];
    };

    int createBrightness(producer_t defined_producer, TV::resolution_t defined_resolution) {
        int sum_res = defined_resolution.x + defined_resolution.y;
        return sum_res * defined_producer;
    }

    TV createTV() {
        producer_t producer = defineProducer();
        std::string model = createModel(producer);
        TV::resolution_t resolution = createResolution();
        int brightness = createBrightness(producer, resolution);
        int price = (_dist(_rnd) % 40000 + 10000);

        return {model, producer, resolution, static_cast<float>(brightness), static_cast<float>(price)};
    }

private:
    std::array<TV::resolution_t, _resolutions> _res;
    std::random_device _dev;
    std::mt19937 _rnd;
    std::uniform_int_distribution<std::mt19937::result_type> _dist;
};


#endif //DAN_TV_FACTORY_H
