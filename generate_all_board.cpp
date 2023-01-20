#include <vector>
#include <string>
#include <cstdio>
#include "types.h"

#define H 5
#define W 6

struct PDRandom {
	u32 x;
	PDRandom (u16 seed) : x(seed) {}
	u32 next() {
		return (x = x * 0x343FD + 0x269EC3) >> 16;
	}
};

std::vector<int> gen_board(u16 seed, int n_colors) {
	PDRandom rnd(seed);
	int board[16][16];
	for (int i = 0; i < 16; i++) for (int j = 0; j < 16; j++) board[i][j] = (rnd.next() * n_colors) >> 16;
	auto has_combo_one = [&] (int i, int j) {
		if (i >= 2 && board[i - 2][j] == board[i - 1][j] && board[i - 1][j] == board[i][j]) return true;
		if (j >= 2 && board[i][j - 2] == board[i][j - 1] && board[i][j - 1] == board[i][j]) return true;
		if (i + 2 < H && board[i + 2][j] == board[i + 1][j] && board[i + 1][j] == board[i][j]) return true;
		if (j + 2 < W && board[i][j + 2] == board[i][j + 1] && board[i][j + 1] == board[i][j]) return true;
		if (i >= 1 && i + 1 < H && board[i + 1][j] == board[i][j] && board[i][j] == board[i - 1][j]) return true;
		if (j >= 1 && j + 1 < W && board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1]) return true;
		return false;
	};
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) 
		for (int k = 0; k < n_colors && has_combo_one(i, j); k++) board[i][j] = k;
	std::vector<int> res;
	for (int i = H; i--; ) for (int j = 0; j < W; j++) res.push_back(board[i][j]);
	return res;
}

void write_all_boards(int n_colors) {
	std::string data;
	for (s32 i = 0; i < 65536; i++) {
		auto board = gen_board(i, n_colors);
		for (auto j : board) data.push_back('0' + j);
		data.push_back('\n');
	}
	
	char fname[32] = { 0 };
	snprintf(fname, 32, "all_boards_%d.txt", n_colors);
	FILE *fp = fopen(fname, "w");
	if (fp) {
		fprintf(fp, "%s", data.c_str());
		fclose(fp);
		fp = NULL;
	} else fprintf(stderr, "Failed to open %s\n", fname);
}

int main() {
	for (int i = 4; i <= 6; i++) write_all_boards(i);
	
	return 0;
}
