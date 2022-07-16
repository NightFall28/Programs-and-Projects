#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function

void towersOfhanoi(int n, int s, int e, int aux);

/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"start",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{0,0,0,0} // this denotes the end of our options.
	};
	// now process the options:
	char c; // to hold the option
	int opt_index = 0;
	short n=0,start=1,end=2; /* to store inputs to the towers function. */
	while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 's': // process option s
				start = atoi(optarg);
				break;
			case 'e': // process option e
				end = atoi(optarg);
				break;
			case 'n': // process option n
				n = atoi(optarg);
				break;
			case '?': // this will catch unknown options.
				// here is where you would yell at the user.
				// although, getopt will already print an error message.
				return 1;
		}
	}

	/* TODO: now that you have the options and arguments,
	 * solve the puzzle. */

	//Determining the number for the auxiliary peg:
	int aux;
	if(start==1 && end==2) aux =3;
	else if(start==1 && end==3) aux =2;
	else if(start==2 && end==1) aux =3;
	else if(start==2 && end==3) aux =1;
	else if(start==3 && end==1) aux =2;
  else if(start==3 && end==2) aux =1;

	towersOfhanoi(n,start,end,aux);

	return 0;
}

void towersOfhanoi(int n, int s, int e, int aux)
{

	if(n==1){
		  cout << s << "\t" << e << "\n";
		return;
		}

	towersOfhanoi(n-1,s,aux,e);
	cout << s << "\t" << e << "\n";
	towersOfhanoi(n-1,aux,e,s);

}

