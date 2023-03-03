#include <iostream>
#include <cmath>

class BezierSpline {
private:
    double P0_x, P0_y, P1_x, P1_y, P2_x, P2_y, P3_x, P3_y;
public:
    BezierSpline(double P0x, double P0y, double P1x, double P1y, double P2x, double P2y, double P3x, double P3y) {
        P0_x = P0x;
        P0_y = P0y;
        P1_x = P1x;
        P1_y = P1y;
        P2_x = P2x;
        P2_y = P2y;
        P3_x = P3x;
        P3_y = P3y;
    }

    double GetPoint(double t) {
        double q1_x = P0_x + t * (P1_x - P0_x);
        double q1_y = P0_y + t * (P1_y - P0_y);
        double q2_x = P1_x + t * (P2_x - P1_x);
        double q2_y = P1_y + t * (P2_y - P1_y);
        double q3_x = P2_x + t * (P3_x - P2_x);
        double q3_y = P2_y + t * (P3_y - P2_y);
        double r1_x = q1_x + t * (q2_x - q1_x);
        double r1_y = q1_y + t * (q2_y - q1_y);
        double r2_x = q2_x + t * (q3_x - q2_x);
        double r2_y = q2_y + t * (q3_y - q2_y);
        double b_x = r1_x + t * (r2_x - r1_x);
        double b_y = r1_y + t * (r2_y - r1_y);
        return sqrt(pow(b_x, 2) + pow(b_y, 2));
    }
};

int main() {
    // kreiraj novi BezierSpline objekt sa zadanim kontrolnim točkama
    BezierSpline spline(0, 0, 2, 4, 6, 4, 8, 0);

    // izračunaj vrijednost splajna u točki t=0.5
    double t = 0.5;
    double point = spline.GetPoint(t);

    std::cout << "Vrijednost Bezierovog splajna u tocki t=" << t << " je " << point << std::endl;

    return 0;
}
