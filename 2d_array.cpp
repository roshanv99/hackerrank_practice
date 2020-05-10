#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    vector<int> sums;
    int rows = arr.size();
    int col = arr[0].size();

    for (int i = 0; i<(rows-2);i++){
        
        for (int j = 0; j<(col-2);j++){
            int sum1 = 0;
            for(int k=0; k<3;k++){
                sum1 = sum1 + arr[i][j+k];
            }
             for(int k=0; k<3;k++){
                if(k ==1){
                sum1 = sum1 + arr[i+1][j+k];
                }
            }
             for(int k=0; k<3;k++){
                sum1 = sum1 + arr[i+2][j+k];
            }
            sums.push_back(sum1);
        }
        
    }
    //Getting the greatest:
    int max = sums[0];
    for(auto i = sums.begin(); i!=sums.end(); i++){
        if (*i > max){
            max = *i;
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
