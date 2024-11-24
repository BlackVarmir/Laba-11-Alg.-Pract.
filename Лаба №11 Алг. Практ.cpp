#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для генерації випадкових чисел у заданому діапазоні
int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Завдання 1: Видалити попередній і наступний елементи для кожного 0
void task1(vector<int>& arr) {
    vector<int> result;
    for (size_t i = 0; i < arr.size(); ++i) {
        if ((i > 0 && arr[i - 1] == 0) || (i < arr.size() - 1 && arr[i + 1] == 0) || arr[i] == 0) {
            continue;
        }
        result.push_back(arr[i]);
    }
    arr = result;
    cout << "Масив після видалення: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 2: Замінити значення елемента на суму всіх наступних
void task2(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = accumulate(arr.begin() + i + 1, arr.end(), 0);
    }
    cout << "Масив після заміни: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 3: Знайти порядкові номери та суму елементів з відрізка [-5, 5], відсортувати парні
void task3(vector<int>& arr) {
    int sum = 0;
    vector<int> evenIndices;

    cout << "Елементи з відрізка [-5, 5]: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] >= -5 && arr[i] <= 5) {
            cout << "a[" << i + 1 << "]=" << arr[i] << " ";
            sum += arr[i];
        }
        if (arr[i] % 2 == 0) {
            evenIndices.push_back(arr[i]);
        }
    }
    cout << "\nСума елементів з відрізка: " << sum << endl;

    sort(evenIndices.begin(), evenIndices.end());
    size_t evenIdx = 0;
    for (int& num : arr) {
        if (num % 2 == 0) {
            num = evenIndices[evenIdx++];
        }
    }

    cout << "Масив після сортування парних елементів: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 4: Середнє значення парних елементів та вставка 0 перед елементами > 10
void task4(vector<double>& arr) {
    double sum = 0;
    int count = 0;
    for (double num : arr) {
        if (static_cast<int>(num) % 2 == 0) {
            sum += num;
            ++count;
        }
    }
    double average = count > 0 ? sum / count : 0;
    cout << "Середнє значення парних елементів: " << average << endl;

    vector<double> result;
    for (double num : arr) {
        if (num > 10) {
            result.push_back(0);
        }
        result.push_back(num);
    }
    arr = result;

    cout << "Масив після вставки 0: ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 5: Сума 3-х найбільших чисел
void task5(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < 3 && i < arr.size(); ++i) {
        sum += arr[i];
    }
    cout << "Сума 3-х найбільших чисел: " << sum << endl;
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Видалити попередній і наступний елементи для кожного 0\n";
        cout << "2. Замінити значення елемента на суму всіх наступних\n";
        cout << "3. Знайти порядкові номери, суму з [-5, 5] і відсортувати парні\n";
        cout << "4. Середнє значення парних і вставка 0 перед елементами > 10\n";
        cout << "5. Сума 3-х найбільших чисел\n";
        cout << "0. Вихід\n";
        cout << "Виберіть пункт меню: ";
        cin >> choice;

        if (choice == 0) break;

        int n;
        cout << "Введіть розмір масиву: ";
        cin >> n;

        if (choice == 4) {
            vector<double> arr(n);
            for (int i = 0; i < n; ++i) {
                arr[i] = generateRandom(0, 20);
            }
            cout << "Масив: ";
            for (double num : arr) {
                cout << num << " ";
            }
            cout << endl;

            if (choice == 4) task4(arr);
        }
        else {
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                arr[i] = generateRandom(-10, 20);
            }
            cout << "Масив: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            switch (choice) {
            case 1:
                task1(arr);
                break;
            case 2:
                task2(arr);
                break;
            case 3:
                task3(arr);
                break;
            case 5:
                task5(arr);
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
            }
        }
    }

    return 0;
}
