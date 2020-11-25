#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int candidates[3];
    int minPackagePrice = 1000;
    int minPiecePrice = 1000;

    for (int i = 0; i < m; i++) {
        int packagePrice, piecePrice;
        cin >> packagePrice >> piecePrice;

        minPackagePrice = min(minPackagePrice, packagePrice);
        minPiecePrice = min(minPiecePrice, piecePrice);
    }

    candidates[0] = (int)ceil((double)n / (double)6) * minPackagePrice;
    candidates[1] = (n / 6) * minPackagePrice + (n % 6) * minPiecePrice;
    candidates[2] = n * minPiecePrice;

    cout << *min_element(candidates, candidates + 3) << "\n";
    return 0;
}