// #include <iostream>
#include <ctime>

// using namespace std;

//Константы цен за минуту и за километр!
// int price_km = 13;
// int price_minute = 11;

float getRushHourCoefficient()
{
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime); // Получаем текущее локальное время
    localTime->tm_hour += 3; // Добавляем 3 часа к текущему времени
    int hour = localTime->tm_hour; // Часы
    int minute = localTime->tm_min; // Минуты

    float coefficient = 1.0; // Коэффициент по умолчанию

    if (hour >= 8 && hour <= 10)
    {
        if (minute == 0 && hour == 8)
            coefficient = 1.3;
            
        else if (minute < 30 && hour == 8)
            coefficient = 1.2;
            
        else if (minute == 30 && hour == 8)
            coefficient = 1.4;
            
        else if (minute > 30 && hour == 8)
            coefficient = 1.35;
            
        else if (minute == 0 && hour == 9)
            coefficient = 1.4;
            
        else if (minute < 30 && hour == 9)
            coefficient = 1.25;
            
        else if (minute == 30 && hour == 9)
            coefficient = 1.3;
            
        else if (minute > 30 && hour == 9)
            coefficient = 1.15;
            
        else if (minute == 0 && hour == 10)
            coefficient = 1.25;
            
    }
    else if ((hour >= 17 && hour <= 19))
    {
        if (minute == 0 && hour == 17)
            coefficient = 1.3;
            
        else if (minute < 30 && hour == 17)
            coefficient = 1.2;
            
        else if (minute == 30 && hour == 17)
            coefficient = 1.3;
            
        else if (minute > 30 && hour == 17)
            coefficient = 1.25;
            
        else if (minute == 0 && hour == 18)
            coefficient = 1.4;
            
        else if (minute < 30 && hour == 18)
            coefficient = 1.30;
            
        else if (minute == 30 && hour == 18)
            coefficient = 1.35;
            
        else if (minute > 30 && hour == 18)
            coefficient = 1.25;
            
        else if (minute == 0 && hour == 19)
            coefficient = 1.3;
            
        else if (minute < 15 && hour == 19)
            coefficient = 1.15;
    }
    else if (hour >= 23 || hour == 0){
        coefficient = 1.25;
    }

    return coefficient;
}

float pricing(int minutes_to_client, int km_to_client, int minutes_to_destination, int km_to_destination, int price_for_minute, int price_for_km)
{
    int tariff = 0;
    tariff += minutes_to_client * price_for_minute + km_to_client * price_for_km; // стоимость работы таксиста, когда он едет к клиенту
    tariff += minutes_to_destination * price_for_minute + km_to_destination * price_for_km; // стоимость работы таксиста, когда он везет клиента в пункт назначения
    
    
    float coefficient = getRushHourCoefficient();
    int price = tariff * coefficient; // округляем
    
    return price;
}

// int main(){
//     int price_km = 13;
//     int price_minute = 11;
//     cout<<pricing(5, 3, 30, 20, price_minute, price_km);
// }

