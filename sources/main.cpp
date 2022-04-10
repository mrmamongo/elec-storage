#include <iostream>
#include "storage/TV_factory.h"
#include "storage/Fridge_factory.h"
#include <vector>

/*
 * Сгенерировать вектор телевизоров
 * модель - первые две буквы - из производителя капсом, следующие четыре цифры - случайные
 * производитель - случайный
 * разрешение - случайное из набора разрешений
 * яркость - произведение суммы разрешения на номер производителя
 * цена - сумма яркости, разрешения, умноженная на номер производителя
 *
 * все образцы протестировать и удалить образцы, не прошедшие тест
 */

int main() {
    int n;
    std::cin >> n;

    std::array<TV::resolution_t, 5> resolutions = {
            TV::resolution_t{.x = 1280, .y = 1024}, {.x = 1600, .y = 900}, {.x = 1920, .y = 1080},
            {.x = 2560, .y = 1440}, {.x = 4096, .y = 2160}
    };

    storage warehouse;
    TV_factory<resolutions.size()> tv_factory(resolutions, warehouse);
    fridge_factory f_factory(warehouse);

    for (int i = 0; i < n; ++i) {
        tv_factory.create_item();
        f_factory.create_item();
    }

    size_t total_warehouse = warehouse.size();

    for (auto tv: warehouse) {
        if (!tv->test(5000, 25000)) {
            warehouse.erase(std::remove(warehouse.begin(), warehouse.end(), tv), warehouse.end());
        }
    }

    int fridges = 0, tvs = 0;

    std::cout << "\nitems:\n";
    for (const auto &item: warehouse) {
        item->print_info(std::cout);
        if (item->get_type().operator el_type::_enumerated() == el_type::tv) {
            tvs++;
        } else {
            fridges++;
        }
    }

    std::cout << "\n\tIn total items: " << total_warehouse;
    std::cout << "\n\tValidated items: " << warehouse.size();
    std::cout << "\n\tNon validated items: " << total_warehouse - warehouse.size();

    std::cout << "\n\n\tValidated TVs: " << tvs;
    std::cout << "\n\tValidated Fridges: " << fridges;

    return 0;
}
