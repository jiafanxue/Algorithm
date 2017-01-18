#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int** array = new int*[n];
	int** outarray = new int*[n];
	int** temparray = new int*[n];
	for(int i = 0; i < n; ++i) {
		array[i] = new int[n];
		outarray[i] = new int[n];
		temparray[i] = new int[n];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> array[i][j];
			temparray[i][j] = array[i][j];
			outarray[i][j] = 0;
		}
	}

	if(m == 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    cout << 0 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
        return 0;
    }

	while(--m) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				outarray[i][j] = 0;
                for(int k = 0; k < n; ++k) {
                	outarray[i][j] += array[i][k] * temparray[k][j]; 
                }
			}
		}
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temparray[i][j] = outarray[i][j];
            }
        }
	}

	for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << outarray[i][j] << " ";
        }
        cout << endl;
    }
	cout << endl;

	return 0;
}