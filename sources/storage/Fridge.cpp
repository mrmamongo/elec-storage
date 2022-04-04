//
// Created by MrMam on 04.04.2022.
//

#include "Fridge.h"
#include <random>

bool fridge::test(int start, int end) const {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    static std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return (_power * _volume) > float(dist(rng) % 15000 + 4000);
}

void fridge::print_info(std::ostream& os) const {
    os << "Fridge("
       << "Model: " << _model << " "
       << "Producer: " << _producer._to_string() << " "
       << "Volume: " << _volume << " "
       << "Power: " << _power << " "
       << "Price: " << _price << " Address: " << this
       << ")\n";
}
