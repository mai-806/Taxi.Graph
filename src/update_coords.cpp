#include <iostream>
#include <unistd.h>
#include <vector>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>


void sendHttpRequestWithCoords(double num1, double num2) {
    // Создание io_context
    boost::asio::io_context ioContext;

    // Создание resolver
    boost::asio::ip::tcp::resolver resolver(ioContext);

    // Разрешение хоста и порта
    auto const results = resolver.resolve("localhost", "8080");

    // Создание сокета
    boost::asio::ip::tcp::socket socket(ioContext);

    // Установка соединения
    boost::asio::connect(socket, results.begin(), results.end());

    // Создание запроса
    boost::beast::http::request<boost::beast::http::string_body> request;
    request.method(boost::beast::http::verb::post);
    request.target("/");
    request.set(boost::beast::http::field::host, "localhost");
    request.set(boost::beast::http::field::content_type, "application/json");

    // Создание тела запроса с двумя дробными числами
    std::string body = "{\"num1\": " + std::to_string(num1) + ", \"num2\": " + std::to_string(num2) + "}";
    request.body() = std::move(body);

    // Отправка запроса
    boost::beast::http::write(socket, request);

    // Получение и вывод ответа
    // boost::beast::flat_buffer buffer;
    // http::response<http::dynamic_body> response;
    // http::read(socket, buffer, response);
    // std::cout << "Ответ сервера: " << boost::beast::buffers_to_string(response.body().data()) << std::endl;

    // Закрытие соединения
    boost::system::error_code ec;
    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    if (ec && ec != boost::system::errc::not_connected) {
        std::cerr << "Ошибка при закрытии соединения: " << ec.message() << std::endl;
    }
}


void GettingCurrentCoordinates(std::vector<std::pair <double, double>>& node, std::vector<double>& times)
{
    std::vector<double> sum_time(1);
    sum_time[0] = 0;
    for (int i = 0; i < times.size(); ++i){
        sum_time.push_back(sum_time[i] + times[i]); // массив сумарного времени до каждой ноды
    }
    double current_time = 0;
    int i = 0;
    while (true){
        if (current_time >= sum_time[i]){
            sendHttpRequestWithCoords(node[i].first, node[i].second);
            std::cout << node[i].first<<" "<<node[i].second<< '\n';
            i += 1;
            if (i == sum_time.size())
            return void();
        }
        sleep(60);
        current_time += 60;
    }
}



// int main()
// {
//     std::vector<std::pair <double, double>> a = {{1.1, 1.1}, {2.2, 2.2}, {5.5, 5.5}, {4.4, 4.4}, {3.3, 3.3}, {2.2, 2.2}, {7.7, 7.7}};
//     std::vector<double> b = {118.2, 122, 131.22, 153, 142.2, 131.1};
//     GettingCurrentCoordinates(a, b);

//     return 0;
// }
 
