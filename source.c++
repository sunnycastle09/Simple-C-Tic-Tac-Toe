#include<iostream>

void Line(int l);
void change(bool& y);
void winner(bool nums[9][2], bool turn);

int main()
{
    bool num[9][2] = {false};
    bool Xturn = true;
    int tmp, line = 0;

    std::cout << "123\n456\n789";
    for (int i = 0; i < 9; i++) {
        std::cout << "\n\n";
        std::cin >> tmp;
        if (num[tmp - 1][0]) {//여기 오류
            std::cout << "Enter again\n";
            i--;
            continue;
        }
        num[tmp - 1][0] = true;

        if (Xturn) {
            num[tmp - 1][1] = true;//X 턴이면 true
        }
        else {
            num[tmp - 1][1] = false;
        }

        for (int j = 0; j < 9; j++) {
            if (num[j][0]) {
                if (num[j][1]) {
                    Line(line);
                    std::cout << "X";
                }
                else {
                    Line(line);
                    std::cout << "O";
                }
            }
            else {
                Line(line);
                std::cout << "-";
            }
            line++;
        }
        winner(num, Xturn);
        change(Xturn);
    }
}

void Line(int l) {
    if (l % 3 == 0) {
        std::cout << "\n";
    }
}

void change(bool& x) {
    x = !x;
}

void winner(bool nums[9][2], bool turn) {
    int i = 0;
    while (i < 7) { // 123 456 789 (가로)
        if (nums[i][0] && nums[i + 1][0] && nums[i + 2][0]) {
            if ((nums[i][1] == nums[i + 1][1]) && (nums[i + 1][1] == nums[i + 2][1])) {
                std::cout << "\n\nWinner is " << (turn ? "X" : "O");
                exit(0);
            }
        }
        i += 3;
    }

    int k = 0;
    while (k < 3) { // 147 258 369 (세로)
        if (nums[k][0] && nums[k + 3][0] && nums[k + 6][0]) {
            if ((nums[k][1] == nums[k + 3][1]) && (nums[k + 3][1] == nums[k + 6][1])) {
                std::cout << "\n\nWinner is " << (turn ? "X" : "O");
                exit(0);
            }
        }
        k++;
    }

    // 대각선 159
    if (nums[0][0] && nums[4][0] && nums[8][0]) {
        if ((nums[0][1] == nums[4][1]) && (nums[4][1] == nums[8][1])) {
            std::cout << "\n\nWinner is " << (turn ? "X" : "O");
            exit(0);
        }
    }

    // 대각선 357
    if (nums[2][0] && nums[4][0] && nums[6][0]) {
        if ((nums[2][1] == nums[4][1]) && (nums[4][1] == nums[6][1])) {
            std::cout << "\n\nWinner is " << (turn ? "X" : "O");
            exit(0);
        }
    }
    std::cout<<"?";
}