// Operator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Drob {
    int chesl;
    int znam;
public:
    Drob() {
        chesl = 0;
        znam = 0;
    }
    Drob(int x, int y) {
        chesl = x;
        znam = y;

    }
    Drob operator +(const Drob& other) {
        Drob temp;
        temp.chesl = this->chesl * other.znam + other.chesl * znam;
        temp.znam = this->znam * other.znam;
        return temp;
    }
    Drob operator -(const Drob& other) {
        Drob temp;
        temp.chesl = this->chesl * other.znam - other.chesl * znam;
        temp.znam = this->znam * other.znam;
        return temp;
    }
    Drob operator *(const Drob& other) {
        Drob temp;
        temp.chesl = this->chesl * other.chesl;
        temp.znam = this->znam * other.znam;
        return temp;
    }
    Drob operator /(const Drob& other) {
        Drob temp;
        temp.chesl = this->chesl * other.znam;
        temp.znam = this->znam * other.chesl;
        return temp;
    }
    void OutPut() {
        cout << "Chesl: " << chesl << endl;
        cout << "Znam: " << znam << endl;
    }
   
};
class Date {
    int day;
    int month;
    int year;
public:
    Date() {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int x, int y, int a) {
        day = x;
        month = y;
        year = a;
    }
    bool Year() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    int Monthday() {
        if (month == 2) {
            return Year() ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }
    Date& operator+(int days) {

        day += days;
        for (; day > 30; month++) {
            day -= 30;
            if (month > 12) {
                year++;
                month -= 12;
            }
        }


        return *this;
    }
    Date operator-(const Date& other) {
        
            Date temp;
            int res;
            int x = year * 365 + month * 30 + day;
            int y = other.year * 365 + other.month * 30 + other.day;
            res = x - y;
            temp.year = res / 365;
            res %= 365;
            temp.month = res / 30;
            temp.day = res % 30;
            return temp;
        

        
    }
    void output() {
        cout <<"day" << ": " << day << endl;
        cout << "month " << ": " << month << endl;
        cout << "year " << ": " << year << endl;
    }
    
};
int main()
{
    //N1
    Drob A(7, 6);
    Drob B(4, 3);
    Drob C = A + B;
    cout << "Result << + " << endl;
    C.OutPut();
    Drob X = A - B;
    cout << "Result << - " << endl;
    X.OutPut();
    Drob I = A * B;
    cout << "Result << * " << endl;
    I.OutPut();
    Drob Y = A / B;
    cout << "Result << /" << endl;
    Y.OutPut();
   

    Date obj(2, 7, 2022);
    Date obj2(1, 7, 2023);
    obj = obj + 150;
    Date obj3;
    obj3 = obj - obj2; 
    cout << "Difference ";
    obj3.output();
   

}


