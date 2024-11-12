#include <iostream>

// Макрос для виведення інформації про програму
#define INFO_MSG() std::cout << "File: " << __FILE__ << "\nCompilation Date: " << __DATE__ << "\nCompilation Time: " << __TIME__ << "\n" \
                              << "Line of Code: " << __LINE__ << std::endl;

// Макрос для виведення повідомлень про помилки
#define ERROR_MSG(msg) std::cerr << "Error: " << msg << "\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\nDate: " << __DATE__ << "\nTime: " << __TIME__ << std::endl;

// Макрос для обчислення суми довільної кількості чисел
#define SUM(...) Sum(__VA_ARGS__)

// Функція для обчислення суми чисел
template<typename T>
T Sum(T value) {
    return value;
}

template<typename T, typename... Args>
T Sum(T first, Args... args) {
    return first + Sum(args...);
}

int main(int argc, char* argv[]) {
    INFO_MSG();

    if (argc < 2) {
        // Викликаємо макрос для повідомлення про помилку
        ERROR_MSG("Insufficient parameters!");
    }
    else {
        // Приклад обчислення суми чисел різних типів
        int a = 5;
        double b = 10.5;
        float c = 3.2f;

        std::cout << "Sum of numbers: " << SUM(a, b, c) << std::endl;
    }

    return 0;
}
