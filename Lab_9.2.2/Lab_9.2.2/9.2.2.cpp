#include <iostream>

// ������ ��� ��������� ���������� ��� ��������
#define INFO_MSG() std::cout << "File: " << __FILE__ << "\nCompilation Date: " << __DATE__ << "\nCompilation Time: " << __TIME__ << "\n" \
                              << "Line of Code: " << __LINE__ << std::endl;

// ������ ��� ��������� ���������� ��� �������
#define ERROR_MSG(msg) std::cerr << "Error: " << msg << "\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\nDate: " << __DATE__ << "\nTime: " << __TIME__ << std::endl;

// ������ ��� ���������� ���� ������� ������� �����
#define SUM(...) Sum(__VA_ARGS__)

// ������� ��� ���������� ���� �����
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
        // ��������� ������ ��� ����������� ��� �������
        ERROR_MSG("Insufficient parameters!");
    }
    else {
        // ������� ���������� ���� ����� ����� ����
        int a = 5;
        double b = 10.5;
        float c = 3.2f;

        std::cout << "Sum of numbers: " << SUM(a, b, c) << std::endl;
    }

    return 0;
}
