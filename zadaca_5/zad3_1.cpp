#include <iostream>
#include <cmath>

class BezierSpline {
private:
    double P0_x, P0_y, P1_x, P1_y, P2_x, P2_y, P3_x, P3_y;
public:
    BezierSpline(double P0x, double P0y, double P1x, double P1y, double P2x, double P2y, double P3x, double P3y) {
        P0_x = P0x; P0_y = P0y; P1_x = P1x; P1_y = P1y; P2_x = P2x; P2_y = P2y; P3_x = P3x; P3_y = P3y;
    }

    double GetPoint(double t) {
        double u = 1 - t;
        double x = pow(u, 3) * P0_x + 3 * t * pow(u, 2) * P1_x + 3 * pow(t, 2) * u * P2_x + pow(t, 3) * P3_x;
        double y = pow(u, 3) * P0_y + 3 * t * pow(u, 2) * P1_y + 3 * pow(t, 2) * u * P2_y + pow(t, 3) * P3_y;
        return sqrt(x*x + y*y); // vraćamo duljinu vektora
    }

    void SubdivideBezier(double t, BezierSpline& left, BezierSpline& right) {
        double P01_x = P0_x + t*(P1_x - P0_x);
        double P01_y = P0_y + t*(P1_y - P0_y);
        double P12_x = P1_x + t*(P2_x - P1_x);
        double P12_y = P1_y + t*(P2_y - P1_y);
        double P23_x = P2_x + t*(P3_x - P2_x);
        double P23_y = P2_y + t*(P3_y - P2_y);

        double P012_x = P01_x + t*(P12_x - P01_x);
        double P012_y = P01_y + t*(P12_y - P01_y);
        double P123_x = P12_x + t*(P23_x - P12_x);
        double P123_y = P12_y + t*(P23_y - P12_y);

        double P0123_x = P012_x + t*(P123_x - P012_x);
        double P0123_y = P012_y + t*(P123_y - P012_y);

        left = BezierSpline(P0_x, P0_y, P01_x, P01_y, P012_x, P012_y, P0123_x, P0123_y);
        right = BezierSpline(P0123_x, P0123_y, P123_x, P123_y, P23_x, P23_y, P3_x, P3_y);
    }
};

int main() {
    BezierSpline spline(0, 0, 2, 4, 6, 4, 8, 0);
    double t =
    double f_t = spline.GetPoint(t);
    BezierSpline left, right;
    spline.SubdivideBezier(t, left, right);
    std::cout << "Subdivided splines:\n";
    std::cout << "Left spline: P0=(" << left.P0_x << ", " << left.P0_y << "), P1=(" << left.P1_x << ", " << left.P1_y << "), P2=(" << left.P2_x << ", " << left.P2_y << "), P3=(" << left.P3_x << ", " << left.P3_y << ")\n";
    std::cout << "Right spline: P0=(" << right.P0_x << ", " << right.P0_y << "), P1=(" << right.P1_x << ", " << right.P1_y << "), P2=(" << right.P2_x << ", " << right.P2_y << "), P3=(" << right.P3_x << ", " << right.P3_y << ")\n";
    return 0;
}
