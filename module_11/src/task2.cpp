#include <iostream>

std::string shareEmail(std::string email, bool flag) {
    std::string temp;

    if (flag) {
        for (int i = 0; i < email.length(); i++) {
            if(email[i] == '@') {
                return temp;
            }
            temp += email[i];
        }
        return temp;
    }

    int i = email.rfind('@');

    if (i < 0) {
        return "";
    }

    for(; i < email.length(); ++i) {
        temp += email[i];
    }
    return temp;
}

bool isValidEmail(std::string leftPart, std::string rightPart) {
    if(leftPart.empty() || leftPart.length() > 64) {
        std::cerr << "Long left part" << std::endl;
        return false;
    }

    if(rightPart.empty() || rightPart.length() > 63) {
        std::cerr << "Long right part" << std::endl;
        return false;
    }

    if(leftPart[0] == '.') {
        std::cerr << "First simb ." << std::endl;
        return false;
    }

    if(rightPart[0] != '@') {
        std::cerr << "@ not found" << std::endl;
        return false;
    }

    if(rightPart[rightPart.length() - 1] == '.') {
        std::cerr << ". last symb" << std::endl;
        return false;
    }

    for(int i = 0; i < leftPart.length() - 1; ++i) {
        bool symbol = leftPart[i] >= 'A' && leftPart[i] <= 'Z' || leftPart[i] >= 'a' && leftPart[i] <= 'z';
        bool numb = leftPart[i] >= '0' && leftPart[i] <= '9';
        bool sign = leftPart[i] == '!' || leftPart[i] >= '#' &&  leftPart[i] <= '`';
        bool operSign = leftPart[i] == '*' || leftPart[i] == '+' || leftPart[i] == '-' || leftPart[i] == '/';
        bool other = leftPart[i] == '=' || leftPart[i] == '?' || leftPart[i] == '^'
            || leftPart[i] == '{' || leftPart[i] == '|' || leftPart[i] == '}' || leftPart[i] == '~';

        if(!symbol && !numb && !sign && !operSign && !other) {
            std::cerr << "Left part not conditional" << std::endl;
            return false;
        }

        if(leftPart[i] == '.' && leftPart[i + 1] == '.') {
            return false;
        }
    }

    for(int i = 1; i < rightPart.length() - 1; ++i) {
        bool symbol = rightPart[i] >= 'A' && rightPart[i] <= 'Z' || rightPart[i] >= 'a' && rightPart[i] <= 'z';
        bool numb = rightPart[i] >= '0' && rightPart[i] <= '9';
        bool other = rightPart[i] == '-' || rightPart[i] == '.';

        if (!symbol && !numb && !other) {
            std::cerr << "Right part not conditinal" << std::endl;
            return false;
        }

        if(rightPart[i] == '.' && rightPart[i + 1] == '.') {
            return false;
        }
    }

    return true;
}

void task2()
{
    std::string email;

    std::cout << "Enter email: ";
    std::cin >> email;

    std::string left = shareEmail(email, true);
    std::string right = shareEmail(email, false);

    if(left.length() + right.length() == email.length()
        && isValidEmail(left, right)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}