#include <iostream>

bool isValid(std::string ip) {
    if(ip.length() > 15) {
        return false;
    }

    if(ip[0] < '1' || ip[0] > '9' || ip[ip.length() - 1] < '0' || ip[ip.length() - 1] > '9') {
        return false;
    }

    std::string temp;

    for(int i = 0; i < ip.length(); i++) {
        if(ip[i] == '.') {
            if (ip[i + 1] == '.') {
                return false;
            }
            for(int j = 0; j < temp.length(); j++) {
                if(temp.length() > 1 && temp[0] == '0') {
                    return false;
                }
            }

            if(std::stoi(temp.c_str()) > 255) {
                return false;
            }

            temp.clear();
            continue;
        }

        if(temp.length() > 3) {
            return false;
        }

        temp += ip[i];
    }


    return true;
}

void task3()
{
    std::string ip;

    std::cout << "Enter the IP address: ";
    std::cin >> ip;

    if(isValid(ip)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
}