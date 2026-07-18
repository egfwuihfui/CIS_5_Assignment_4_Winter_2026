#include <iostream>
#include <iomanip>
using namespace std;

// Pass by const array (read-only, no modification allowed)
int calculateSum(const int ary[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ary[i];
    }
    return sum;
}

// Pass by value -- sum and size are copies, originals unaffected
double calculateAverage(int sum, int size)
{
    double average = static_cast<double>(sum) / size;
    return average;
}

// Pass by pointer/reference -- modifies the original array directly
void addBonus(int ary[], int size, int bonus)
{
    for (int i = 0; i < size; i++)
    {
        ary[i] += bonus;
        cout << ary[i] << " ";
    }
    cout << endl;
}

// Pass by pointer -- read-only, uses dereferencing
int findMinimum(const int* ary, int size)
{
    int mini = *ary;
    for (int i = 0; i < size; i++)
    {
        if (*(ary + i) < mini)
        {
            mini = *(ary + i);
        }
    }
    return mini;
}

// Pass by const array (read-only, no modification allowed)
int countHighPerformers(const int ary[], int size)
{
    int highPerformers = 0;
    for (int i = 0; i < size; i++)
    {
        if (ary[i] >= 80)
        {
            highPerformers += 1;
        }
    }
    return highPerformers;
}

int main()
{
    int ary[10] = {75, 88, 62, 95, 50, 82, 70, 91, 45, 78};
    int size = 10;
    int bonus = 10;

    cout << "Original scores: ";
    for (int i = 0; i < size; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;

    cout << "Sum: ";
    int sum = calculateSum(ary, size);
    cout << sum << endl;

    double average = calculateAverage(sum, size);
    cout << "Average: " << fixed << setprecision(2) << average << endl;

    cout << "Scores after +10 bonus: ";
    addBonus(ary, size, bonus);

    int mini = findMinimum(ary, size);
    cout << "Minimum score: " << mini << endl;

    int highPerformers = countHighPerformers(ary, size);
    cout << "High performers (>=80): " << highPerformers << endl;

    return 0;
}