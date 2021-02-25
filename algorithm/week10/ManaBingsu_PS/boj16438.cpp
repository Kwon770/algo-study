// ������ ������
// https://www.acmicpc.net/problem/16438
// Memory	: 	2016	KB
// Time		: 	0		ms

/*
	�ٽ� �˰����� �����Ͽ�����
	���� �� ���� ���� ���̵� �������� �ʾ�
	https://sejinik.tistory.com/144 �� �����Ͽ����ϴ�.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt;

char monkeys[7][120];

void f(int sIdx, int eIdx, int depth) {
	if (depth >= 7 || sIdx >= eIdx)
		return;

	cnt = max(cnt, depth);
	int cIdx = (sIdx + eIdx) / 2;
	for (int i = sIdx; i <= eIdx; i++) {
		if (i <= cIdx)
			monkeys[depth][i] = 'A';
		else
			monkeys[depth][i] = 'B';
	}

	f(sIdx, cIdx, depth + 1);
	f(cIdx + 1, eIdx, depth + 1);
}

int main() {
	cin >> N;
	f(1, N, 0);
	for (int i = 0; i <= cnt; i++) {
		for (int j = 1; j <= N; j++) {
			if (monkeys[i][j] == '\0')
				monkeys[i][j] = j % 2 == 0 ? 'A' : 'B';
			cout << monkeys[i][j];
		}
		cout << "\n";
	}
	// 	�� ��ġ�� �ߺ��ǵ� �ȴٴ�...
	while (cnt != 6) {
		for (int i = 0; i < N; i++) {
			if (i & 1)
				cout << 'A';
			else
				cout << 'B';
		}
		cout << "\n";
		cnt++;
	}
	return 0;
}