#include <iostream>
#include <string>
#include <vector>

using namespace std;

string plainText = "the quick brown fox jumps over the lazy dog";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char finalMapper[26] = { 0, };
    vector<string> encryptedTexts;
    string encryptedText;

    while (getline(cin, encryptedText)) {
        encryptedTexts.push_back(encryptedText);

        if (encryptedText.size() != plainText.size() || encryptedText[0] == ' ') {
            continue;
        }

        char mapper[26] = { 0, };
        bool checker = true;

        for (int i = 0; i < encryptedText.size(); i++) {
            char character = encryptedText[i];
            int index = character - 97;

            if (character == ' ') {
                if (plainText[i] != ' ') {
                    checker = false;
                    break;
                }

                continue;
            }

            if (mapper[index] == 0) {
                mapper[index] = plainText[i];
            }
            else {
                if (mapper[index] != plainText[i]) {
                    checker = false;
                    break;
                }
            }
        }

        if (checker) {
            for (int i = 0; i < 26; i++) {
                finalMapper[i] = mapper[i];
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (finalMapper[i] == 0) {
            cout << "No solution." << "\n";
            return 0;
        }
    }

    for (int i = 0; i < encryptedTexts.size(); i++) {
        string decryptedText = "";

        for (int j = 0; j < encryptedTexts[i].size(); j++) {
            char character = encryptedTexts[i][j];
            int index = encryptedTexts[i][j] - 97;

            if (index >= 0 && index < 26) {
                decryptedText.push_back(finalMapper[index]);
            }
            else {
                decryptedText.push_back(character);
            }
        }

        cout << decryptedText << "\n";
    }

    return 0;
}
