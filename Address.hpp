#ifndef ADDRESS_HPP
#define ADDRESS_HPP

// чтобы сравнивать строки без учета регистра
std::string to_lower(const std::string &str)
{
    std::string copy = str;
    for (auto &ch : copy)
        if(ch <= 'Z' && ch >= 'A')
                ch += 32;
    return copy;
}

class Address
{
public:
    Address() : apt(0), house(0) {}
    Address(const std::string &new_town, const std::string &new_street,
            const int &new_apt, const int &new_house)
    {
        town = new_town;
        street = new_street;
        apt = new_apt;
        house = new_house;
    }
    bool operator==(Address const &rhs) const
    {
        return to_lower(rhs.town) == to_lower(town) &&
               to_lower(rhs.street) == to_lower(street) &&
               rhs.apt == apt &&
               rhs.house == house;
    }
    // принадлежность городу
    bool inTown(std::string const &aTown) const
    {
        return std::equal(town.begin(), town.end(), aTown.begin(),
                          [](char a, char b) {
                              return tolower(a) == tolower(b);
                          });
    }
    // принадлежность улице
    bool inStreet(std::string const &aStreet) const
    {
        return std::equal(street.begin(), street.end(), aStreet.begin(),
                          [](char a, char b) {
                              return tolower(a) == tolower(b);
                          });
    }
    // является ли соседом
    bool isNeighs(Address const &rhs) const
    {
        if (!(to_lower(rhs.town) == to_lower(town) &&
              to_lower(rhs.street) == to_lower(street)))
            return false;
        return abs(rhs.apt - apt) <= 1;
    }
    // вывести всю информацию об одном адресе
    void display() const
    {
        std::cout << town << "\t" << street << "\t" << house << "\t" << apt;
    }

private:
    std::string town, street; // название города, улицы
    int apt, house;           // номер дома, квартиры
};

#endif