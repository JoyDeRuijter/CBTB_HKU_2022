#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

template<typename T>
void printCompleteVector(vector<T> list, bool extraWhitespace)
{
    for(int i =0; i < list.size(); i++)
        cout << list[i] << ", ";
    cout << endl;

    if(extraWhitespace)
        cout << endl;
}

bool isBeforePurple(string a)
{
    if (a.compare("purple") < 0)
        return true;
    else
        return false;
}

void removeDuplicates(vector<string>& v)
{
    sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

string isEven (double number)
{
    int newNumber = (int)number;
    if(newNumber % 2 == 0)
        return "even";
    else
        return "uneven";
}



int main() {
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    {
        vector<string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        sort(colours.begin(), colours.end());
        vector<string> coloursPartBefore, coloursPartAfter;
        for(int i =0; i < colours.size(); i++)
        {
            if(isBeforePurple(colours[i]))
                coloursPartBefore.push_back(colours[i]);
            else
                coloursPartAfter.push_back(colours[i]);
        }
        printCompleteVector(coloursPartBefore, false);
        printCompleteVector(coloursPartAfter, false);
        cout << endl;
    }

    // 2) alle elementen UPPERCASE te maken.
    {
        vector<string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        for (auto& colour : colours) {
            for (auto& c : colour) {
                c = ::toupper(c);
            }
        }
        printCompleteVector(colours, true);
    }

    // 3) alle dubbele te verwijderen
    {
        vector<string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };     
        removeDuplicates(colours);
        printCompleteVector(colours, true);
    }

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) alle negatieve elementen te verwijderen
    {
        vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        auto toRemove = remove_if(numbers.begin(), numbers.end(), [](const int i) {return i < 0; });
        numbers.erase(toRemove, numbers.end());
        printCompleteVector(numbers, true);
    }

    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    {
        vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        vector<bool> evenOrOdd;
        for(int i = 0; i < numbers.size(); i++)
        {
            cout << numbers[i] << " = " << isEven(numbers[i]) << ", ";
        }
        cout << endl;
        cout << endl;
    }

    // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    {
        vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        double sum = 0.0;
        double median = 0.0;
        double product = 0.0;

        for(int i =0; i < numbers.size(); i++)
        {
            sum += numbers[i];
            if(product == 0)
                product = numbers[i];
            else
                product *= numbers[i];
        }
        median = sum / numbers.size();

        cout << "sum: " << sum << ", median: " << median << ", product: " << product;
        cout << endl;
    }

    return 0;
}
