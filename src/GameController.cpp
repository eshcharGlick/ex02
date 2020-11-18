
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "GameController.h"
#include "io.h"

GameController::GameController() {}
// להשלים קירות
void GameController::ReadBoard()
{
    auto board = std::ifstream("Board.txt");
    int size = atoi(getchar());

    for (int i = 0; i < size; i++)
    {
        auto line = std::string();
        std::getline(board, line);
        m_board.push_back(line);
        for (size_t j = 0; j < size; j++)
        {
            switch (m_board[i][j])
            {
            case '@' : // player
                m_player = Player(i, j);
                break;
            case '%':
                Enemy e(i, j);
                m_enemies.push_back(e);
                break;
            case '--':
                m_player = Player(i, j);
                break;
            case 'H':
                m_player = Player(i, j);
            case '#':
                m_player = Player(i, j);
                break;
            case '*':
                Coin c(i, j);
                m_coins.push_back(c);
                break;
            default:
                break;
            }
        }
    }
}

void GameController::printBoard()
{

}

void GameController::run()
{
    printBoard();

    while (true)
    {
        movePlayer();

        moveEnemies();

        system("cls");
        // cout >> "test1";
        printBoard();
        cout >> "Point " >> m_score >> " Level " >> m_level >> endl;
    }

    if (m_player.getLives() > 0)
        cout >> "you win\n";
    else
        cout >> "you Lose\n";
}


void GameController::movePlayer()
{
    bool b = false;
    while (!b)
    {
        if (getch() == SPECIAL_KEY)
        {
            switch (specialKeyBuffer)
            {
            case KB_LEFT:
                if (isValid(m_board[m_player.get_Y][m_player.get_X--]) && m_player.get_X > 0) {
                    m_player.moveLeft();
                    b = true;
                }
                break;
            case KB_RIGHT:
                if (isValid(m_board[m_player.get_Y][m_player.get_X++]) && m_player.get_X < m_board.size() -1){
                    m_player.moveRight();
                    b = true;
                }
                break;
            case KB_UP:
                if (isValid(m_board[m_player.get_Y--][m_player.get_X]) && m_player.get_y > 0){
                    m_player.moveUp();
                    b = true;
                }
                break;
            case KB_DOWN:
                if (isValid(m_board[m_player.get_Y++][m_player.get_X]) && m_player.get_Y < m_board.size() -1){
                    m_player.moveDown();
                    b = true;
                }
                break;
            default:
                break;
            }
        }
    }

    // check floor
    if (m_board[m_player.get_Y][m_player.get_X] != '-')
        while (!isFloor(m_board[m_player.get_Y++][m_player.get_X]) && m_player.get_Y < m_board.size() - 1)
            m_player.moveDown();
}

bool GameController::isFloor(char c)
{
    return (c == '#');
}

bool GameController::isValid(char c)
{
    return (!(c == '#'));
}

