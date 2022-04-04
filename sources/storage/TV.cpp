//
// Created by MrMam on 03.04.2022.
//

#include <random>
#include "TV.h"

void TV::print_info(std::ostream& os) const {
    os << "TV("
       << "Model: " << _model << " "
       << "Producer: " << _producer._to_string() << " "
       << "Resolution: " << _resolution.x << "x" << _resolution.y << " "
       << "Brightness: " << _brightness << " "
       << "Price: " << _price << " Address: " << this
       << ")\n";
}

bool TV::test(int start, int end) const {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    static std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return (static_cast<int>(dist(rng)) % 15000 > (_resolution.x + _resolution.y + static_cast<int>(_brightness)));
}

