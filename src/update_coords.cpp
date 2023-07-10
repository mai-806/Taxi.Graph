#include <iostream>
#include <unistd.h>
#include <vector>


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
            //здесь будет http запрос, отправляющий текущуюю координату в фронт (return node[i])
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
 
