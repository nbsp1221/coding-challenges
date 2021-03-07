#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CountryInfo {
public:
    int countryNumber;
    int goldMedalCount;
    int silverMedalCount;
    int bronzeMedalCount;

    bool checkScoreSame(const CountryInfo& countryInfo) {
        return this->goldMedalCount == countryInfo.goldMedalCount
            && this->silverMedalCount == countryInfo.silverMedalCount
            && this->bronzeMedalCount == countryInfo.bronzeMedalCount;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<CountryInfo> countryInfoes;
    int countryRank = 0;

    for (int i = 0; i < n; i++) {
        CountryInfo countryInfo;
        cin >> countryInfo.countryNumber >> countryInfo.goldMedalCount >> countryInfo.silverMedalCount >> countryInfo.bronzeMedalCount;

        countryInfoes.push_back(countryInfo);
    }

    sort(countryInfoes.begin(), countryInfoes.end(), [](CountryInfo left, CountryInfo right) -> bool {
        if (left.goldMedalCount != right.goldMedalCount) return left.goldMedalCount > right.goldMedalCount;
        if (left.silverMedalCount != right.silverMedalCount) return left.silverMedalCount > right.silverMedalCount;
        return left.bronzeMedalCount > right.bronzeMedalCount;
    });

    for (int i = 0; i < n; i++) {
        if (countryInfoes[i].countryNumber == k) {
            countryRank = i + 1;
            break;
        }
    }

    while (k >= 2 && countryInfoes[countryRank - 1].checkScoreSame(countryInfoes[countryRank - 2])) {
        countryRank--;
    }

    cout << countryRank << "\n";
    return 0;
}
