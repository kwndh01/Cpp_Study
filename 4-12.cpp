#include <iostream>
using namespace std;

class Circle {
    int radius;
    string name;
public:
    void setCircle(string name, int radius);
    double getArea();
    string getName();
};

void Circle::setCircle(string name, int radius) {
    this->name = name;
    this->radius = radius;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

string Circle::getName() {
    return name;
}

class CircleManager {
    Circle *p;
    int size;
public:
    CircleManager(int size);
    ~CircleManager();
    void searchByName();
    void searchByArea();
};

CircleManager::CircleManager(int size) {
    this->size = size;
    p = new Circle[size];
    for(int i=0; i<size; i++) {
        string name;
        int radius;
        cout << "원 " << i+1 << "의 이름과 반지름 >> ";
        cin >> name >> radius;
        p[i].setCircle(name, radius);
    }
}

CircleManager::~CircleManager() {
    delete [] p;
}

void CircleManager::searchByName() {
    string name;
    cout << "검색하고자 하는 원의 이름 >> ";
    cin >> name;
    for(int i=0; i<size; i++) {
        if(p[i].getName() == name) {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
        }
    }
}

void CircleManager::searchByArea() {
    double minimum;
    cout << "최소 면적을 입력하세요 >> ";
    cin >> minimum;
    cout << minimum << "보다 큰 원을 검색합니다." <<endl;
    for(int i=0; i<size; i++) {
        if(p[i].getArea() > minimum) {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
        }
    }
    cout << endl;
}

int main() {
    int count;
    cout << "원의 개수 >> ";
    cin >> count;
    CircleManager Cir(count);
    Cir.searchByName();
    Cir.searchByArea();
    return 0;
}
