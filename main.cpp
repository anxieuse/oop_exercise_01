/*
Короткевич Л. В.
github.com/anxieuse
Создать класс Address для работы с адресами домов. Адрес должен состоять из строк с названием города и улицы и чисел с номером дома и квартиры. 
Реализовать операции сравнения адресов, а также операции проверки принадлежности адреса к улице и городу. 
В операциях не должен учитываться регистр строки. 
Так же необходимо сделать операцию, которая возвращает истину если два адреса находятся по соседству (на одной улице в одном городе и дома стоят подряд).
*/

#include <iostream>
#include <string>

#include "Address.hpp"
#include "Vector.hpp"

int main()
{
    std::string town, street;
    int apt, house, idToDel, id, id1, id2;
    Vector<Address> ads;

    int command_idx;
    bool input = true;
    std::cout << '\n'
              << " 1  - добавить адрес" << '\n'
              << " 2  - удалить адрес" << '\n'
              << " 3  - сравнить два адреса" << '\n'
              << " 4  - проверить принадлежность улице" << '\n'
              << " 5  - проверить принадлежность городу" << '\n'
              << " 6  - являются ли соседями" << '\n'
              << " 7  - вывести список адресов" << '\n'
              << " 8  - выйти\n"
              << '\n';
    while (input)
    {
        std::cin >> command_idx;
        switch (command_idx)
        {
            case 1:
            {
                std::cin >> town >> street >> apt >> house;
                printf("Адрес %s %s %d %d успешно добавлен в список\n", town.c_str(), street.c_str(), apt, house);
                ads.push_back({town, street, apt, house});
                break;
            }
            case 2:
            {
                std::cin >> idToDel;
                --idToDel;
                if (idToDel < ads.size() && idToDel >= 0)
                {
                    std::cout << "Адрес ";
                    ads[idToDel].display();
                    std::cout << " успешно удален из списка\n";
                    ads.erase(idToDel);
                }
                else
                {
                    std::cout << "Введен некорректный индекс\n";
                }
                break;
            }
            case 3:
            {
                std::cin >> id1 >> id2;
                if (ads[id1 - 1] == ads[id2 - 1])
                {
                    std::cout << "Адреса равны\n";
                }
                else
                {
                    std::cout << "Адреса НЕ равны\n";
                }
                break;
            }
            case 4:
            {
                std::cin >> id >> street;
                if (ads[id - 1].inStreet(street))
                {
                    printf("Адрес под номером %d действительно принадлежит улице %s\n", id, street.c_str());
                }
                else
                {
                    printf("Адрес под номером %d НЕ принадлежит улице %s\n", id, street.c_str());
                }
                break;
            }
            case 5:
            {
                std::cin >> id >> town;
                if (ads[id - 1].inTown(town))
                {
                    printf("Адрес под номером %d действительно принадлежит городу %s\n", id, town.c_str());
                }
                else
                {
                    printf("Адрес под номером %d НЕ принадлежит городу %s\n", id, town.c_str());
                }
                break;
            }
            case 6:
            {
                std::cin >> id1 >> id2;
                if (ads[id1 - 1].Address::isNeighs(ads[id2 - 1]))
                {
                    if (ads[id1 - 1] == ads[id2 - 1])
                        printf("Адреса совпадают\n");
                    else
                        printf("Адреса под номерами %d и %d являются соседними\n", id1, id2);
                }
                else
                {
                    printf("Адреса под номерами %d и %d НЕ являются соседними\n", id1, id2);
                }
                break;
            }
            case 7:
            {
                if (ads.size() == 0)
                {
                    std::cout << "Список адресов пуст\n";
                }
                else
                {
                    printf("\n№\tГород\tУлица\tДом\tКватира\n");
                    for (int i = 0; i < ads.size(); ++i)
                    {
                        std::cout << i + 1 << '\t';
                        // std::cout << &x - &ads[0] + 1 << '\t';
                        ads[i].Address::display();
                        std::cout << '\n';
                    }
                    std::cout << '\n';
                }
                break;
            }
            case 8:
            {
                input = false;
                break;
            }
        }
    }
}
