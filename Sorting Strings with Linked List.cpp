#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;


/* doubly linked list node: */
struct node {
	string data;
	node* prev;
	node* next;
	node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};

void uniqueCase(node*& L);
void reverseCase(node*& L);

int main(int argc, char *argv[]) {
	/* define long options */
	static int unique=0, reverse=0;
	static struct option long_opts[] = {
		{"unique",   no_argument,       &unique,   'u'},
		{"reverse",  no_argument,       &reverse,  'r'},
		{0,0,0,0} // this denotes the end of our options.
	};
	/* process options */
	char c; /* holds an option */
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'u':
				unique = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case '?': /* this will catch unknown options. */
				return 1;
		}
	}
	/* NOTE: at this point, variables 'reverse' and 'unique' have been set
	 * according to the command line.  */
	/* TODO: finish writing this.  Maybe use while(getline(cin,line)) or
	 * similar to read all the lines from stdin. */

  //default sorting string in order from smallest to largest:
	string line;
	node* L = NULL;
	if(getline(cin,line)) L = new node(line); //first node
	node* end = L;
	node* smallest = L;
	while(getline(cin,line)){
	 node* L = new node(line,NULL,NULL);
		  if(smallest->data >= L->data){
				L->next = smallest;
				smallest->prev = L;
				smallest = L;
			}
			else if(L->data >= end->data){
			  L->prev = end;
				end->next = L;
				end = L;
			}
		  else{
			  for(node*search=end; search!=NULL; search=search->prev){
				  if(search->data < L->data){
					  node* temp = search->next;
						search->next = L;
						L->prev = search;
						L->next = temp;
						temp->prev = L;
						break;
					}
				}
			}
	}
	L = smallest;

	// -u unique case:
	if(unique==1 && reverse == 0){
		uniqueCase(L);
  }

	// -r reverse case:
	if(unique==0 && reverse == 1){
    reverseCase(L);
	}

	// -u and -r combined case:
	if(unique==1 && reverse==1){
		uniqueCase(L);
		reverseCase(L);
	}

	for (node* p = L; p; p = p->next) {
		cout << p->data << "\n";
	}
	return 0;
}

//unique case function:
void uniqueCase(node*& L)
{
	node *current, *locate, *temp;
   for(current = L; current != NULL; current = current->next){
		for(locate = current->next; locate != NULL; locate = locate->next){
			 if(current->data == locate->data){
				  temp = locate;
				  locate->prev->next = locate->next;
				  if(locate->next != NULL){
						  locate->next->prev = locate->prev;
						}
					delete temp;
				 }
		  }
		}
}

//reverse case function:
void reverseCase(node*& L)
{
	node*p = L;
		node* end = NULL;
		while(p!=NULL){
			end = p;
			p = p->next;
		}
	  L = end;
		node* current = L;
		while(current!=NULL){
		 node*temp = current->next;
		 current->next = current->prev;
		 current->prev = temp;
		 current = current->next;
	 }
}


