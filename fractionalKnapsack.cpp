#include <iostream>
using namespace std;

class FractionalKnapsack {
    private:
        int n;
        float capacity;
        float w[20], p[20], x[20], pw[20];
    public:
        void input() {
            cout << "Enter total objects: ";
            cin >> n;
            cout << "Enter capacity: ";
            cin >> capacity;
            cout << "Enter the items with weight and profit\n";
            for (int i = 0; i < n; i++) {
                cout << "w" << i << "=";
                cin >> w[i];
                cout << "p" << i << "=";
                cin >> p[i];
                pw[i] = p[i] / w[i];
            }
        }

        void sortItems() {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - 1 - i; j++) {
                    if (pw[j] < pw[j + 1]) {
                        swap(pw[j], pw[j + 1]);
                        swap(w[j], w[j + 1]);
                        swap(p[j], p[j + 1]);
                    }
                }
            }
        }

        void setKnapsack() {
            for (int i = 0; i < n; i++) {
                x[i] = 0.0;
            }
        }
        
        void addItem(){
        	for (int i = 0; i < n; i++) {
                if (w[i] <= capacity) {
                    capacity = capacity - w[i];
                    x[i] = 1.0;
                } else {
                    x[i] = capacity / w[i];
                    capacity = 0;
                }
            }
		}

        void display() {
            float xp = 0, xw = 0;
            for (int i = 0; i < n; i++) {
                xp += x[i] * p[i];
                xw += x[i] * w[i];
            }
            cout << "Maximum Profit = " << xp << endl;
            cout << "Total weight: " << xw << endl;
        }
};

int main() {
    FractionalKnapsack fk;
    fk.input();
    fk.sortItems();
    fk.setKnapsack();
    fk.addItem();
    fk.display();
    return 0;
}
