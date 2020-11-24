
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include "GameController.h"
#include "io.h"

using namespace::std;

void GameController::ReadBoard()
{
    auto board = std::ifstream("Board.txt");
    
    string s;
    std::getline(board,s);
    m_size = stoi(s);

    for (int i = 0; i < m_size; i++)
    {
        auto line = std::string();
        std::getline(board, line);
        m_board.push_back(line);
        for (size_t j = 0; j < m_size; j++)
        {
            Enemy e();
            Coin c();
 
            switch (m_board[i][j])
            {
            case '@' : // player
                m_player = Player(Vertex(i,j));
                break;
            case '%':
                e.setVertex((Vertex(i, j)));
                m_enemies.push_back(e);
                break;
            case '*':
                c =(Vertex(i, j));
                m_coins.push_back(c);
                break;
            }
        }
    }
}

void GameController::printBoard()
{
    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            cout << m_board[i][j];
    // put 
    if (m_board[m_player.getVertex().m_row][m_player.getVertex().m_col] == 'H')
        cout << 'S';
    else
        cout << '@';


}

void GameController::run()
{
    printBoard();
    for (int l = 1; l <= NUM_OF_LEVELS ; l++)
    {
        runLevel(l);
    }
    
    if (m_player.getLives() > 0)
        cout << "you win\n";
    else
        cout << "you Lose\n";
}

void GameController::runLevel(int level)
{
    system("cls");
    // cout >> "test1";
    printBoard();
    cout << "Point " << m_score << " Level " << m_level << endl;

    while (true)
    {
        movePlayer();

        moveEnemies();

        int r = checkConsequences();
        
        switch (r)
        {
        case 0:
            break;
        case 1:
            for (int i = 0; i < m_enemies.size(); i++) // reset enemies
            {
                m_enemies[i].restart();
            }
            break;
        case 2:
            return;
        }

        system("cls");
        // cout >> "test1";
        printBoard();
        cout << "Point " << m_score << " Level " << m_level << endl;
    }
}

int GameController::checkConsequences()
{
    for (int i = 0; i < m_coins.size(); i++)
    {
        if (m_player.getVertex().same(m_coins[i].getVertex()))
        {
            m_score += 2 * m_level;
            m_coins[i].picked();
        }
    }
    if (m_coins.empty())
    {
        m_score += 50 * m_level;
        return 2; // start the next level
    }
    return 0;

    for (int i = 0; i < m_enemies.size(); i++)
    {
        if (m_player.getVertex().same(m_enemies[i].getVertex()))
        {
            m_player.dead(); // if end of lives

            if (m_player.getLives() == 0)
            {
                exit(0);
            }
            return 1; // restart the level
        }
    }
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
                if (isValid(m_board[m_player.getVertex().m_row][m_player.getVertex().m_col-1]) && m_player.getVertex().m_col > 0) {
                    m_player.moveLeft();
                    b = true;
                }
                break;
            case KB_RIGHT:
                if (isValid(m_board[m_player.getVertex().m_row][m_player.getVertex().m_col+1]) && m_player.getVertex().m_col < m_board.size() -1){
                    m_player.moveRight();
                    b = true;
                }
                break;
            case KB_UP:
                if (isValid(m_board[m_player.getVertex().m_row-1][m_player.getVertex().m_col]) && m_player.getVertex().m_row > 0){
                    m_player.moveUp();
                    b = true;
                }
                break;
            case KB_DOWN:
                if (isValid(m_board[m_player.getVertex().m_row+1][m_player.getVertex().m_col]) && m_player.getVertex().m_row < m_board.size() -1){
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
    if (m_board[m_player.getVertex().m_row][m_player.getVertex().m_col] != '-' && m_board[m_player.getVertex().m_row][m_player.getVertex().m_col] != 'H')
        while (!isFloor(m_board[m_player.getVertex().m_row+1][m_player.getVertex().m_col]) && m_player.getVertex().m_row < m_board.size() - 1)
            m_player.moveDown();
}

void GameController::moveEnemies()
{
    for (int i = 0; i < m_enemies.size(); i++) // reset enemies
    {
       moveToPlayer (m_enemies[1]);
    }
}

void GameController::moveToPlayer(Enemy e)
{
    Vertex vP = m_player.getVertex();
    Vertex vE = e.getVertex();
    if (vP.sameRow (vE))
    {
        if (vP.isToTheRightOf(vE))
        {
            if (isValid(m_board[vE.m_row][vE.m_col + 1]))
                e.moveRight();
        }
        else
        {
            if (isValid(m_board[vE.m_row][vE.m_col - 1]))
                e.moveLeft();
        }
        return;
    }
    if (vP.sameCol(vE))
    {
        if (vP.isHigherThan (vE))
        {

        }
        else
        {

        }

        return;
    }
    if (vP.isHigherThan(vE))
    {
        if (vP.isToTheRightOf(vE)) // up & right
        {

            return;
        }
        else // up & left
        {

            return;
        }
    }
    else
    {
        if (vP.isToTheRightOf(vE)) // down & right
        {
            
            return;
        }
        else // down & left
        {
            
            return;
        }
    }
}

bool GameController::isFloor(char c)
{
    return (c == '#');
}

bool GameController::isValid(char c)
{
    return (!(c == '#'));
}



