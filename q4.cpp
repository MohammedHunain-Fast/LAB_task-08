#include <iostream>

class TrafficSystem {
private:
    int cars;
    int waitTime;
public:
    TrafficSystem(int c, int w = 0) : cars(c), waitTime(w) {}

    TrafficSystem operator+(int moreCars) const {
        return TrafficSystem(cars + moreCars, waitTime);
    }

    TrafficSystem operator-(int fewerCars) const {
        return TrafficSystem(cars - fewerCars, waitTime);
    }

    TrafficSystem operator*(int factor) const {
        return TrafficSystem(cars, waitTime * factor);
    }

    bool operator==(const TrafficSystem& other) const {
        return cars == other.cars;
    }

    void display() const {
        std::cout << cars << " " << waitTime << std::endl;
    }
};

int main() {
    TrafficSystem intersection(50, 5);
    
    TrafficSystem worseTraffic = intersection + 20;
    worseTraffic.display();

    TrafficSystem betterTraffic = worseTraffic - 15;
    betterTraffic.display();

    TrafficSystem signalFailure = intersection * 2;
    signalFailure.display();

    TrafficSystem roadA(100, 10);
    TrafficSystem roadB(100, 15);
    std::cout << (roadA == roadB) << std::endl;

    return 0;
}
