#include <iostream>
#include <string>

std::string Sum(std::string& num1, std::string& num2) {
    std::string result = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    return result;
}
std::string Sub(std::string& num1, std::string& num2) {
    std::string result = "";
    bool isNegative = false;
    if (num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2)) {
        std::string temp = num1;
        num1 = num2;
        num2 = temp;
        isNegative = true;
    }
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int borrow = 0;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = std::to_string(diff) + result;
    }
    result.erase(0, result.find_first_not_of('0'));

    if (isNegative) {
        result = '-' + result;
    }

    return result;
}

int main() {
    std::string num1, num2;
    std::cout << "First number   >> ";
    std::cin >> num1;
    std::cout << "Second number  >> ";
    std::cin >> num2;

    std::string result = Sum(num1, num2);
    std::cout << "Sum            >> " << result << std::endl;
    std::string result2 = Sub(num1, num2);
    std::cout << "Sub            >> " << result2 << std::endl;
    return 0;
}
