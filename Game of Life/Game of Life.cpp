#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
#include <string>

//Name: Junhui Huang


//global vector given
vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //0
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //1
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //2
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //3
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //4
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //5
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}, //6
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}, //7
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0}, //8
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}  //9
};

const int Ten = 10; //total rows
const int Twenty = 20; //total columns
const char alive = 'O' , dead = '.'; //cell display

//Functions:
int numLiveNghbrs(int r, int c);
bool aliveNextGen(int r, int c);


int main(int argc, char *argv[])
{

	if (argc == 1){
			for (int i = 0; i < Ten; i++){
			for (int j = 0; j < Twenty; j++){
					if(world[i][j] == false){
						   cout << dead;
						} else if (world[i][j] == true){
							 cout << alive;
							}
				}
			cout << "\n";
		}
	}
	else {

		int nGen = atoi(argv[1]);

	//keep looping until it gets to the n-th generation
	for (int h = 1; h <= nGen; h++){
	vector<vector<bool>> future(world); /* make future a copy of world. */


	//update the cell each generation:
	for (int p=0; p<Ten; p++){
			for (int q=0; q<Twenty; q++){
					future[p][q] = aliveNextGen(p,q);
				}
		}

	//copy next generation (future) to world
	world = future;
	}

	//printing the final result (the world after n-th generation):
	for (int i = 0; i < Ten; i++){
			for (int j = 0; j < Twenty; j++){
					if(world[i][j] == false){
						   cout << dead;
						} else if (world[i][j] == true){
							 cout << alive;
							}
				}
			cout << "\n";
		}
	}
	return 0;
}


int numLiveNghbrs(int r, int c) // r = row, c = column
{
	int count = 0; //keep track of the number of neighbor cell alive around one cell (r,c)
	for (int i = -1; i < 2; i++){
			for(int j = -1; j < 2; j++){
					if (world[(r+i+Ten)%Ten][(c+j+Twenty)%Twenty] == true){
							count++;
						}
				}
		}
	if(world[r][c]==true){
		count = count - 1;
	}

return count;
}


bool aliveNextGen(int r, int c)
{
	int numNghbrs = numLiveNghbrs(r,c);
	if(world[r][c] == true){
	return numNghbrs == 2 || numNghbrs == 3; //living cell has exactly 2 or 3 neighbors - stay alive
												    //living cell has less than 2 or more than 3 neighbors - die
		                        //which mean if it is not equal to 2 or 3, it dies
		} else {
				return numNghbrs == 3;//dead cell has exactly 3 neighbors - revive
															//if not, dead cell remains dead
			}
}
