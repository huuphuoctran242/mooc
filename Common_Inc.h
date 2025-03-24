#ifndef _COMMON_INC_H
#define _COMMON_INC_H
#include<string>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <iostream>
enum Car_type{
    Toyota,
    Huyndai,
    Kia,
    Ford,
    Mazda,
    Mitsubishi,
    Vinfast,
    Honda,
    Mercesdes,
    BMW,
    Ferrari,
    GTA,
    Audi,
    Bugatti,
    Lamborghini,
    Unknown
};
enum ComparisonResult {
    SAME_ALL_INFORMATION = 1,
    SAME_ID = 2,
    SAME_PHONE_NUMBER = 3,
    NOT_EXIST = 0
};
#define STAT_NOT_REPAIR (0)
#define STAT_REPAIRING  (1)
#define STAT_REPAIRED   (2)
#define STAT_ARNORMAL   (3)



#endif