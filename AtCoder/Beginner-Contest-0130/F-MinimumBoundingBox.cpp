#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

const int INF = 2e9;

struct Point {
    int x, y;
    Point(int _x, int _y) : x{_x}, y{_y} {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Point> up, down, left, right;
    for (int i = 0; i < n; ++i) {
        int x, y;
        char d;
        std::cin >> x >> y >> d;
        switch (d) {
            case 'U': up.emplace_back(x, y);    break;
            case 'D': down.emplace_back(x, y);  break;
            case 'L': left.emplace_back(x, y);  break;
            case 'R': right.emplace_back(x, y); break;
        }
    }
    int lx = INF, rx = -INF, ly = INF, ry = -INF;
    for (Point& p : up)    { lx = std::min(lx, p.x); rx = std::max(rx, p.x); }
    for (Point& p : down)  { lx = std::min(lx, p.x); rx = std::max(rx, p.x); }
    for (Point& p : left)  { ly = std::min(ly, p.y); ry = std::max(ry, p.y); }
    for (Point& p : right) { ly = std::min(ly, p.y); ry = std::max(ry, p.y); }
    auto sortByX = [](const Point& p1, const Point& p2) {
        return p1.x < p2.x;
    };
    auto sortByY = [](const Point& p1, const Point& p2) {
        return p1.y < p2.y;
    };
    std::sort(up.begin(), up.end(), sortByY);
    std::sort(down.begin(), down.end(), sortByY);
    std::sort(left.begin(), left.end(), sortByX);
    std::sort(right.begin(), right.end(), sortByX);
    std::vector<double> times = { 0.0 };
    if (!up.empty() && !down.empty()) {
        times.push_back((down.back().y - up.back().y) / 2.0);
        times.push_back((down[0].y - up[0].y) / 2.0);
    }
    if (!left.empty() && !right.empty()) {
        times.push_back((left.back().x - right.back().x) / 2.0);
        times.push_back((left[0].x - right[0].x) / 2.0);
    }
    if (rx != -INF && !right.empty()) times.push_back(rx - right.back().x);
    if (rx != -INF && !left.empty())  times.push_back(left.back().x - rx);
    if (lx != INF  && !left.empty())  times.push_back(left[0].x - lx);
    if (lx != INF  && !right.empty()) times.push_back(lx - right[0].x);
    if (ry != -INF && !up.empty())    times.push_back(ry - up.back().y);
    if (ry != -INF && !down.empty())  times.push_back(down.back().y - ry);
    if (ly != INF  && !down.empty())  times.push_back(down[0].y - ly);
    if (ly != INF  && !up.empty())    times.push_back(ly - up[0].y);
    double res = 1e100;
    for (double t : times) {
        if (t < 0.0) continue;
        double minX = INF, minY = INF, maxX = -INF, maxY = -INF;
        for (Point p : up) {
            minX = std::min(minX, (double) p.x);
            maxX = std::max(maxX, (double) p.x);
            minY = std::min(minY, p.y + t);
            maxY = std::max(maxY, p.y + t);
        }
        for (Point p : down) {
            minX = std::min(minX, (double) p.x);
            maxX = std::max(maxX, (double) p.x);
            minY = std::min(minY, p.y - t);
            maxY = std::max(maxY, p.y - t);
        }
        for (Point p : right) {
            minX = std::min(minX, p.x + t);
            maxX = std::max(maxX, p.x + t);
            minY = std::min(minY, (double) p.y);
            maxY = std::max(maxY, (double) p.y);
        }
        for (Point p : left) {
            minX = std::min(minX, p.x - t);
            maxX = std::max(maxX, p.x - t);
            minY = std::min(minY, (double) p.y);
            maxY = std::max(maxY, (double) p.y);
        }
        res = std::min(res, (maxX - minX) * (maxY - minY));
    }
    std::cout << std::fixed << std::setprecision(2) << res << '\n';
}
