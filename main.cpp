#include <iostream>
#include <TV.h>
#include <vector>

namespace {
    std::vector <TV::resolution_t> res {
        {.x = 1280, .y = 1024},
        {.x = 1600, .y = 900},
        {.x = 1920, .y = 1080},
        {.x = 2560, .y = 1440},
        {.x = 4096, .y = 2160}
    };
}

producer_t defineProducer () {
    int random_value = (rand() % 3 + 1);
    auto out_producer = producer_t::_from_index(random_value);
    return out_producer;
}

std::string createModel (producer_t defined_producer) {
    std::string out_model;
    auto producer = defined_producer._to_string();
    out_model += char(producer[0]);
    out_model += char(producer[1]);
    int random_numbers = (rand() % 9999 + 1000);
    out_model += std::to_string(random_numbers);
    return out_model;
}

TV::resolution_t createResolution() {
    int random_value = rand() % res.size();

    return res[random_value];
};

int createBrightness (producer_t defined_producer, TV::resolution_t defined_resolution ) {
    int sum_res = defined_resolution.x + defined_resolution.y;
    return sum_res *defined_producer;
}




TV createTV () {
    producer_t producer = defineProducer();
    std::string model = createModel(producer);
    TV::resolution_t resolution = createResolution();
    int brightness = createBrightness(producer, resolution);
    int price = (rand() % 40000 + 10000);

    return TV(model,producer,  resolution, brightness, price);
}








//}

/*
 * Сгенерировать вектор телевизоров
 * модель: первые две буквы - из производителя капсом, следующие четыре цифры - случайные
 * производитель: случайный
 * разрешение: случайное из набора разрешений
 * яркость: произведение суммы разрешения на номер производителя
 * цена: сумма яркости, разрешения, умноженная на номер производителя
 *
 * все образцы протестировать и удалить образцы, не прошедшие тест
 */

int main() {
    srand(time(NULL));
    int n;
    std::cin >> n;
    std::vector<TV> TVs;
    std::vector<TV> validated_tvs;
    for (int i = 0; i < n; ++i) {
        TV pushing = createTV();
        TVs.push_back(pushing);

    }
    for (int i = 0; i < n; ++i) {
        TVs[i].print_info();
    }
    for (int i = 0; i < n; ++i) {
        if (TVs[i].test()) {
            validated_tvs.push_back(TVs[i]);
        }
    }
//    for (int i = 0; i < n; ++i) {
//        validated_tvs[i].print_info();
//    }
//
    std::cout << "\n" << "In total TVs: " << TVs.size();
    std::cout << "\n" << "Validated TVs: " << validated_tvs.size();
    std::cout << "\n" << "Non validated TVs: " << TVs.size() - validated_tvs.size();
    return 0;

}

// TV(model={}, producer={}, resolution={{}x{}}, brightness={}, price={})
