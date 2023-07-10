#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

// namespace http = boost::beast::http;

std::vector<std::pair<double, double>> extractCoordsFromRequest(const boost::beast::http::request<boost::beast::http::string_body>& request) {
    std::vector<std::pair<double, double>> numbers;

    // Разбор строки запроса для извлечения параметров
    std::string query = request.target().to_string();
    std::size_t pos = query.find('?');
    if (pos != std::string::npos) {
        query = query.substr(pos + 1);

        // Разбиение параметров на пары ключ-значение
        std::istringstream iss(query);
        std::string param;
        while (std::getline(iss, param, '&')) {
            std::size_t equalsPos = param.find('=');
            if (equalsPos != std::string::npos) {
                std::string key = param.substr(0, equalsPos);
                std::string value = param.substr(equalsPos + 1);

                // Преобразование значения в double и добавление в вектор
                try {
                    double number = std::stod(value);
                    numbers.emplace_back(number, number);
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка при преобразовании значения: " << e.what() << std::endl;
                }
            }
        }
    }

    return numbers;
}


// int main() {
//     // Пример HTTP-запроса с числами в строке запроса
//     boost::beast::http::request<boost::beast::http::string_body> request;
//     request.method(boost::beast::http::verb::get);
//     request.target("/?num1=1.23&num2=4.56&num3=7.89&num4=0.12");

//     // Обработка HTTP-запроса
//     // Извлечение чисел из запроса
//     std::vector<std::pair<double, double>> numbers = extractCoordsFromRequest(request);

//     // Вывод чисел
//     for (const auto& pair : numbers) {
//         std::cout << pair.first << ", " << pair.second << std::endl;
//     }

//     return 0;
// }
