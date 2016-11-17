//http://blog.naver.com/jjuncoder/220804386705
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> table;

void solve(int start_y, int start_x, int end_y, int end_x) {
	//크기가 1짜리 까지 오면 기저문.
	if (start_y == end_y - 1) {
		printf("%c", table[start_y][start_x]);
		return;
	}
	char comp = table[start_y][start_x];
	int mid_y = (end_y + start_y) / 2, mid_x = (end_x + start_x) / 2;
	//다른게 하나라도 있으면 분할정복
	for (int i = start_y; i < end_y; i++){
		for (int j = start_x; j < end_x; j++){
			if (comp != table[i][j]) {
				printf("(");
				//왼쪽 위
				solve(start_y, start_x, mid_y, mid_x);
				//오른쪽 위
				solve(start_y, mid_x, mid_y, end_x);
				//왼쪽 아래
				solve(mid_y, start_x, end_y, mid_x);
				//오른쪽 아래
				solve(mid_y, mid_x, end_y, end_x);
				printf(")");
				return;
			}
		}
	}
	//다른게 하나도 없으면 바로 출력하고 끝낸다.
	printf("%c", table[start_y][start_x]);
	return;
}

std::vector<std::string> decode(const std::string& quad_tree, int N){
	std::vector<std::string> result(N, std::string('N',N));
	int NsubL = N, NsubR = N;
	int depth = 1;
	int start_x=0, start_y=0, end_x=N, end_y=N;
	for (const auto& c : quad_tree){
		switch (c){
		case '(':
			depth++;
			break;
		case ')':
			depth--;
			break;
		case '0':
		case '1':
			//TODO : !!!
			break;
		}
	}
	return result;
}

int main() {
	int n;
	string input;
	std::streambuf * cinbuf = cin.rdbuf();
	std::ifstream file("../div_and_conq_quad_tree/input.txt");
	if (!file.good()){
		std::cerr << "Cannot open the file" << std::endl;
		return 0;
	}
	cin.set_rdbuf(file.rdbuf());

	std::getline(cin, input);
	n = std::stoi(input);
	for (int i = 0; i < n; i++) {
		std::getline(cin, input);
		table.push_back(input);
	}
	solve(0, 0, n, n);
	return 0;
}
