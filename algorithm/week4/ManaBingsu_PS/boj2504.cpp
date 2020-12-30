// ��ȣ�� ��
// https://www.acmicpc.net/problem/2504
// Memory	:	KB
// Time		:	ms

// �� Ǭ ����
// ������ �̿��Ѵٴ� ���� �����߽��ϴ�
// ��͸� ����Ͽ� �Լ��� ����ó�� ȣ���� �� �ִ� �Ϳ��� �����Ͽ�
// ���� ���� �̷��� ȣ���ϸ� ���� ������ ������ �� ����������? ���
// ������� ��Ʋ�� �Ҹ��Ͽ����ϴ�

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<int> indexes;
int memo[50];
int counter = 0;
int result = 0;

void recursion(int depth) {
	if (depth == str.size()) {
		return;
	}
	recursion(depth + 1);
	if (str[depth] == '(') {
		int index = depth + 1;
		int check = counter;
		int sum = 0;
		while (check >= 0) {
			if (memo[index] != 0) {
				index += 2 + (memo[index]);
			}
			if (str[index] == ')') {
				check--;
			}
			else {
				sum++;
			}
		}
		memo[depth - 1] = str[depth - 1] * sum;
		counter++;
	}
}

int main(){
	cin >> str;
	recursion(0);
	int index = 0;
	while (memo[index] != 0) {
		index++;
	}
	cout << memo[index] << "\n";
	return 0;
}
