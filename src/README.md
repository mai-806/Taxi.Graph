# Taxi.Graph
### Алгоритм ценообразования, функция get_price.cpp
Разобьем нашу формулу цены на _Тариф_ и _Повышенный спрос_:
_Тариф * Повышенный спрос = Цена_
### Тариф
В тарифе мы будем учитывать:
-  цена за километр - траты на обслуживание машины на один километр.
-  цена за километр - заработок таксиста в минуту ( средней заработок таксиста в час в Москве равен 675 рублям )
- платная подача - складывается из километров до пассажира и минут, которые потратит таксист для подъезда к пассажиру
Пока что не будем учитывать повышения цены из-за _детский кресел_, _перевозки животных_ и т.д.
<img width="302" alt="image" src="https://github.com/mai-806/Taxi.Graph/assets/65921394/ca1f6a89-2aa5-4564-b473-c75b42beefd8">

### Повышенный спрос
Повышенным спросом будем называть _**коэффициент**_, который включается, когда много людей заказывают такси и водителей не хватает. Этот коэффициент должен привлекать водителей ехать в ту область, где много заказов, а какую-то часть клиентов, наоборот, заставлять отказываться от такси и ехать на городском транспорте. Тем самым такси гарантируется каждому вызвавшему клиенту и сбоев не будет.
Обычно этот коэффициент зависит от многих факторов, включая _погоду_, _сезонность_, или, например, _конец какого-нибудь концерта_ и т.д. Мы же будем учитывать _час-пик_, а именно утренний, вечерний, и ночной ( все едут с тусовок ).

<img width="452" alt="image" src="https://github.com/mai-806/Taxi.Graph/assets/65921394/74bb45cc-98f4-4909-857b-7c2f35f68f9e">



Также можно снижать стоимость, если есть возможность _экономить_ время таксиста:
- Просить высадиться рядом с домом, не заезжая во двор 
- Сделать тариф "вместе"
- Снижать стоимость, если такси, который вы вызвали, вот вот закончит заказ близко к вам 

и т.д.
Но это на будущее :)



### Алгоритм поиска ближайшего соседа (NNS), функция distance_utils.cpp

Основная идея алгоритма заключается в том, что для каждой точки или объекта из набора данных вычисляется расстояние до заданной точки или объекта, и затем выбирается точка или объект с наименьшим расстоянием.

1. Выбор заданной точки или объекта, для которого нужно найти ближайшего соседа.
2. Для каждой точки или объекта из набора данных вычисление расстояния до заданной точки или объекта.
3. Выбор точки или объекта с наименьшим расстоянием как ближайшего соседа.
4. Возврат найденного ближайшего соседа.



### Функция update_coords.cpp для обновления координат

Составление вектора Times, в котором каждый элемент - это время езды до соответствующей ноды ( по индексу )
Сравнивание времени работы программы с первом элементом из Times, если время работы больше, то выведем координаты первой ноды
Сравнивание будем делать раз в минуту ( можно поменять )
В функцию нужно передать все ноды маршрута, включая точку отправления и пункт назначения (важны координаты отправления в начале вектора, в алгоритме сразу присваивается время ноль этой ноде)
Функция завершается, когда достигли последней ноды.



### Функции Grah.hpp && Graph.cpp

Заполнение вектора списков со следующими свойствами ребра:
Для начала скажу, что каждый индекс вектора - нода, из которой входит ребро
А так же в списке хранятся:
Переменная size_t номера ноды, в которую зайдёт ребро
Переменная double длины ребра (в метрах)
Переменная int максимально допусимой скорости (км/ч)
Переменная int загруженности участка дороги(система десятибальная, где 0 - пустая дорога, а 10 - максимально загруженная, заполняется рандомным образом)
