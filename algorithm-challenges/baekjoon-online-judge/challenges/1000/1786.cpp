#include <iostream>
#include <string>
#include <vector>

using namespace std;

void kmpAlgorithm(const string& originalText, const string& targetText)
{
    int resultCount = 0;
    vector<int> resultPositions;
    vector<int> failureFunctionTable(targetText.size(), 0);
    unsigned int pointer = 0;

    for (auto i = 1u; i < targetText.size(); i++) {
        if (pointer > 0 && targetText[i] != targetText[pointer]) {
            pointer = failureFunctionTable[pointer - 1];
        }

        if (targetText[i] == targetText[pointer]) {
            failureFunctionTable[i] = ++pointer;
        }
    }

    pointer = 0;

    for (auto i = 0u; i < originalText.size(); i++) {
        if (pointer > 0 && originalText[i] != targetText[pointer]) {
            pointer = failureFunctionTable[pointer - 1];
        }

        if (originalText[i] == targetText[pointer]) {
            pointer++;

            if (pointer == targetText.size()) {
                resultCount++;
                resultPositions.push_back(i - targetText.size() + 2);
                pointer = failureFunctionTable[targetText.size() - 1];
            }
        }
    }

    cout << resultCount << "\n";

    for (int index : resultPositions) {
        cout << index << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string originalText;
    string targetText;

    getline(cin, originalText);
    getline(cin, targetText);

    kmpAlgorithm(originalText, targetText);

    return 0;
}
