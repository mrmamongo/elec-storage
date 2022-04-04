#include <array>
#include <TV.h>
#include <TV_factory.h>
#include <vector>
#include <iostream>



/*
 * Сгенерировать вектор телевизоров
 * модель: первые две буквы - из производителя капсом, следующие четыре цифры - случайные
 * производитель: случайный
 * разрешение: случайное из набора разрешений
 * яркость: произведение суммы разрешения на номер производителя
 * цена: случайное число в пределах [10_000 - 50_000]
 *
 * все образцы протестировать и удалить образцы, не прошедшие тест
 */

int main() {
    int n;
    std::cin >> n;
    std::array<TV::resolution_t, 5> resolutions = {
            TV::resolution_t
            {.x = 1280, .y = 1024},
            {.x = 1600, .y = 900},
            {.x = 1920, .y = 1080},
            {.x = 2560, .y = 1440},
            {.x = 4096, .y = 2160}
    };

    TV_factory<5> factory(std::move(resolutions));
    std::vector<TV> TVs;
    TVs.reserve(n);
    for (int i = 0; i < n; ++i) {
        TVs.emplace_back(factory.createTV());
    }
    size_t total_TVs = TVs.size();

    for (const auto& tv: TVs) {
        if (!tv.test()) {
            TVs.erase(std::remove_if(TVs.begin(), TVs.end(), [&tv](const auto &rhs) {
                return tv.get_model() == rhs.get_model();
            }), TVs.end());
        }
    }

    std::cout << "Validated TVs:\n";
    for (const auto& tv: TVs) {
        tv.print_info();
    }

    std::cout << "\n\t* In total TVs: " << total_TVs;
    std::cout << "\n\t* Validated TVs: " << TVs.size();
    std::cout << "\n\t* Non validated TVs: " << total_TVs - TVs.size();
    return 0;
}
