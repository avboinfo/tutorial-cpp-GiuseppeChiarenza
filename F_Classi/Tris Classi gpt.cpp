#include <iostream>
#include <vector>

class Game {
public:
    Game() {
        board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        player = 1;
        win = false;
    }

    void DrawBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool CheckWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) return true;
        return false;
    }

    void PlayGame() {
        int x, y;

        while (!win) {
            DrawBoard();
            std::cout << "Player " << player << ", enter coordinates x, y: ";
            std::cin >> x >> y;

            // Check for valid input
            if (x < 0 || x > 2 || y < 0 || y > 2) {
                std::cout << "Invalid coordinates. Please try again." << std::endl;
                continue;
            }

            // Check if the spot is already taken
            if (board[x][y] != 0) {
                std::cout << "This spot is already taken. Please try again." << std::endl;
                continue;
            }

            if (player == 1) {
                board[x][y] = 1;
                player = 2;
            } else {
                board[x][y] = 2;
                player = 1;
            }

            win = CheckWin();
        }

        std::cout << "Player " << (player == 1 ? 2 : 1) << " wins!" << std::endl;
    }

private:
    std::vector<std::vector<int>> board;
    int player;
    bool win;
};

int main() {
    Game game;
    game.PlayGame();
    return 0;
}
