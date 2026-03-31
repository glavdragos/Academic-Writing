#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

vector<string> generateBinaryNumbers(int n, int m) 
{
    vector<string> numbers;
    srand(time(0));
    for (int i = 0; i < n; i++) 
    {
        string binary = "";
        for (int j = 0; j < m; j++) 
            binary += (rand() % 2) ? '1' : '0';
        numbers.push_back(binary);
    }
    return numbers;
}



double checkAlternatingPattern(const vector<string>& numbers) 
{
    int count = 0;
    for (const auto& num : numbers) 
    {
        bool ok = true;
        for (int i = 1; i < num.size(); i++) 
            if (num[i] == num[i - 1]) 
            {
                ok = false;
                break;
            }
        if (ok) count++;
    }
    return numbers.empty() ? 0 : count * 100.0 / numbers.size();
}


double checkOnlyOneType(const vector<string>& numbers) {
    int count = 0;

    for (const auto& num : numbers) {
        bool allZero = true, allOne = true;

        for (char c : num) {
            if (c != '0') allZero = false;
            if (c != '1') allOne = false;
        }

        if (allZero || allOne) count++;
    }

    return numbers.empty() ? 0 : count * 100.0 / numbers.size();
}


double checkEqualZerosOnes(const vector<string>& numbers) 
{
    int count = 0;
    for (const auto& num : numbers) 
    {
        int zeros = 0, ones = 0;
        for (char c : num) 
        {
            if (c == '0') zeros++;
            else ones++;
        }
        if (zeros == ones) count++;
    }
    return numbers.empty() ? 0 : count * 100.0 / numbers.size();
}


double checkHalfPattern(const vector<string>& numbers) 
{
    int count = 0;
    for (const auto& num : numbers) 
    {
        int n = num.size();
        if (n % 2 != 0) continue;
        int half = n / 2;
        bool firstOk = true, secondOk = true;
        for (int i = 1; i < half; i++) 
        {
            if (num[i] != num[0]) 
            {
                firstOk = false;
                break;
            }
        }
        for (int i = half + 1; i < n; i++) 
        {
            if (num[i] != num[half]) 
            {
                secondOk = false;
                break;
            }
        }
        if (firstOk && secondOk && num[0] != num[half]) 
            count++;
    }
    return numbers.empty() ? 0 : count * 100.0 / numbers.size();
}


double checkPalindrome(const vector<string>& numbers) 
{
    int count = 0;
    for (const auto& num : numbers) 
    {
        bool ok = true;
        for (int i = 0; i < num.size() / 2; i++) 
        {
            if (num[i] != num[num.size() - 1 - i]) 
            {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    }
    return numbers.empty() ? 0 : count * 100.0 / numbers.size();
}


double checkSameEnds(const vector<string>& numbers) 
{
    int count = 0;
    for (const auto& num : numbers) 
    {
        if (!num.empty() && num.front() == num.back())
            count++;
    }
    return numbers.empty() ? 0 : count * 100.0 / numbers.size();
}


int main() {
    int n, m;
    
    cout << "Enter number of binary numbers (n): ";
    cin >> n;
    cout << "Enter length of each binary number (m): ";
    cin >> m;
    
    vector<string> binaryNumbers = generateBinaryNumbers(n, m);
    
    cout << fixed << setprecision(2);
    cout << "\n--- Pattern Analysis ---\n";
    cout << "Alternating pattern (010101... or 101010...): " << checkAlternatingPattern(binaryNumbers) << "%\n";
    cout << "Only 0 or 1: " << checkOnlyOneType(binaryNumbers) << "%\n";
    cout << "Equal 0s and 1s: " << checkEqualZerosOnes(binaryNumbers) << "%\n";
    cout << "Palindrome: " << checkPalindrome(binaryNumbers) << "%\n";
    cout << "Same start and end: " << checkSameEnds(binaryNumbers) << "%\n";
    if (m % 2 == 0) {
        cout << "First/Second half opposite pattern: " << checkHalfPattern(binaryNumbers) << "%\n";
    } else {
        cout << "First/Second half opposite pattern: N/A (odd length)\n";
    }
    
    return 0;
}