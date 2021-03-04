// �𳯸��� ������ �ӿ��� �� ������ �������ž�
// https://www.acmicpc.net/problem/17951
// Memory	: 2288		KB
// Time		: 28		ms

#include <iostream>
#include <algorithm>
#define SIZE 100000

using namespace std;

/// <summary>
/// ���� �׷� �� �ּ��� ������ ���´ٴ� ����
/// ��� �׷��� �ּ� ���� �̻��� ���´ٴ� �Ͱ� ����.
/// ���� �̺�Ž���� ���� 0 ~ 20 * N ��������
/// �ִ��� ū �ּ� ������ ã�ƾ� �Ѵ�.
/// </summary>


int main() {
	int N, K;
	int input[SIZE];
	cin >> N >> K;
	for (int i = 0; i < N; cin >> input[i], i++);
	int left = 0, right = 20 * N;
	int mid = (left + right) / 2;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		int groupNum = 0, counter = 0;
		for (int i = 0; i < N; i++) {
			counter += input[i];
			if (counter >= mid) {
				groupNum++;
				counter = 0;
			}
		}
		if (groupNum >= K)
			left = mid;
		else
			right = mid;
	}
	cout << left << "\n";
	return 0;
}