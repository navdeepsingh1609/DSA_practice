#include <bits/stdc++.h>
using namespace std;

int minSwaps(int N, int M, vector<vector<int> >& A,
			vector<vector<int> >& B)
{
	int count01 = 0;
	int count10 = 0;
	for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				if (A[i][j] == 1)
					count10++;
				else
					count01++;
			}
		}
	}

	if (count01 == count10)
		return count01;
	else
		return -1;
}

int main()
{

	vector<vector<int> > A= {{ 1, 1, 0 }, { 0, 0, 1 }, { 0, 1, 0 }};
	vector<vector<int> > B= {{ 0, 0, 1 }, { 0, 1, 0 }, { 1, 1, 0 }};

	int N = A.size();
	int M = B[0].size();

	cout << minSwaps(N, M, A, B);
}
