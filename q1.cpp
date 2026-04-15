#include <iostream>

class Time;

class Speed {
private:
    double speed;
public:
    Speed(double s) : speed(s) {}
    friend double calculateDistance(Speed s, Time t);
};

class Time {
private:
    double time;
public:
    Time(double t) : time(t) {}
    friend double calculateDistance(Speed s, Time t);
};

double calculateDistance(Speed s, Time t) {
    return s.speed * t.time;
}

int main() {
    Speed s(60.0);
    Time t(2.0);
    
    std::cout << calculateDistance(s, t) << std::endl;
    
    return 0;
}
