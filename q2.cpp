#include <iostream>

class BallsFaced;

class Runs {
private:
    int runs;
public:
    Runs(int r) : runs(r) {}
    friend double calculateStrikeRate(Runs r, BallsFaced b);
};

class BallsFaced {
private:
    int balls;
public:
    BallsFaced(int b) : balls(b) {}
    friend double calculateStrikeRate(Runs r, BallsFaced b);
};

double calculateStrikeRate(Runs r, BallsFaced b) {
    return (static_cast<double>(r.runs) / b.balls) * 100.0;
}

int main() {
    Runs r(85);
    BallsFaced b(60);
    
    std::cout << calculateStrikeRate(r, b) << std::endl;
    
    return 0;
}
