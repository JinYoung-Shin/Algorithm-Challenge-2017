#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class vec {
    public:
    double x, y, size;
    
    vec(double x, double y) {
        this->x = x;
        this->y = y;
        this->size = sqrt(x*x + y*y);
    }
    
    void normalize() {
        x /= size;
        y /= size;
        size /= size;
    }
    void multiply(double k) {
        x *= k;
        y *= k;
        size *= k;
    }
};
int main() {
    ll R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    ll R2 = R*R;
    ll d2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    
    if (d2 >= R2) {//Fata's laptop is outside of flat
        cout << x1 << ' ' << y1 << ' ' << R << '\n';
        return 0;
    } else if (d2 == 0) {
        cout << x1 << ' ';
        printf("%.16lf %.16lf\n",((double)(y1) + (double)R/2) , ((double)R/2));
        return 0;
    }
    
    double d = sqrt(d2);
    double diameter = d + R;
    double radius = diameter/2;
    
    vec alpha(x1-x2, y1-y2);
    
    alpha.normalize();
    alpha.multiply(radius);
    
    printf("%.16lf %.16lf %.16lf\n", ((double)x2 + alpha.x), ((double)y2 + alpha.y) , radius);
    
	return 0;
}

