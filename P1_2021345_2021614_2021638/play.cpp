#include "Neural_Net.h"
#include <vector>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;
//defining a topology 
//9 input layers
//3 hidden layers
//1 outpur layer
vector<uint32_t> topology = {9, 3, 1};
//0.1 learning rate entered at constructor
sp::SimpleNeuralNetwork NN(topology, 0.1);
string s, s2;
vector<string> s4;
vector<float> s5;
vector<float> s6;

vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};//the board of tic-tac-toe by 2D vector

float m = RAND_MAX, min_i;//minimum value of probability / index of value
int choise; //choise entered by user and AI
int row, column;
char turn = 'X'; //X == player & O == AI
bool draw = false;

void display()//fuction to display board
{
    system("CLS");

    cout << "PLAYER 1-[X] AI-[O]" << endl;
    cout << "   |   |   " << endl;
    cout << board[0][0] << "  | " << board[0][1] << " |  " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << board[1][0] << "  | " << board[1][1] << " |  " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << board[2][0] << "  | " << board[2][1] << " |  " << board[2][2] << endl;
    cout << "   |   |   " << endl;
}

void player_turn()//function through which game is played
{
    if (turn == 'X')
    {
        cout << "Player 1 [X] Turn: ";
        cin >> choise;
    }

    else
    {
        cout << "AI [O] Turn: ";

        vector<float> AI_board(9);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                    AI_board[i * 3 + j] = 1.0;

                else if (board[i][j] == 'O')
                    AI_board[i * 3 + j] = -1.0;

                else
                    AI_board[i * 3 + j] = 0.0;
            }

        float prob;
        m=RAND_MAX;
        for (int i = 0; i < 9; i++)
        {
            if (AI_board[i] == 0.0)
            {
                AI_board[i] = -1.0;

                NN.feedForword(AI_board);
                prob = NN._valueMatrices.back().at(0, 0);
                AI_board[i] = 0.0;

                if (prob < m)
                { 
                    m = prob;
                    min_i = i;
                    choise = min_i + 1;
                }
            }
        }
    }


    switch (choise)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "INVALID MOVE";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box alredy filled in please chose another !!" << endl;
        player_turn();  
    }

    display();
}

bool gameover()//function to check who is the winner
{
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main()
{

    ifstream input("tic-tac-toe.data");//importing data for all possibilities from file tic-tac-toe.data

    for (int i = 0; i < 958; i++)//file has 958 lines
    {
        getline(input, s);//reading  data from file storing into string s 
        stringstream s1(s);

        while (getline(s1, s2, ','))//further dividing it into string-stream s1 with respect to ,
            s4.push_back(s2);

        for (int i = 0; i < s4.size(); i++)//assigning values to vector characters
        {                                  //x=1 o=-1 b(blank)=0 negavtive=-1 positive=1
            if (s4[i] == "x")
                s5.push_back(1);

            else if (s4[i] == "o")
                s5.push_back(-1);

            else if (s4[i] == "b")
                s5.push_back(0);

            else if(s4[i]=="positive")
                s5.push_back(1);

            else if(s4[i]=="negative") 
                s5.push_back(-1);   
        }

        int num = s5.back();
        s6.push_back(num);//seperating last element for back propagation

        s5.pop_back();//removing last element from string

        NN.feedForword(s5);
        NN.backPropagate(s6);

        s5.clear();//clearing both vectors
        s6.clear();
    }

    input.close();//closing file

    while (gameover())
    {
        display();
        player_turn();
    }

    if (turn == 'X' && draw == false)
        cout << "AI wins"<<endl;

    else if (turn == 'O' && draw == false)
        cout << "Player 1 wins"<<endl;

    else if(draw == true)
        cout << "GAME DRAW"<<endl;

        system("pause");

    return 0;
}