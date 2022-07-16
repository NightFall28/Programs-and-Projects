#include <cstdio>
#include <string>
using std::string;

int main()
{
  enum state {
    normal,
    slash,
    commentType1,
    commentType2,
    endOfcomment,
    stringLiteral,
    backslash,
    beginOfchar,
    escapeChar,
    character

};

  state s = normal;
  char c;
  while (scanf("%c",&c) > 0){
   switch (s) {
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case normal:
       if(c == '/'){
            s = slash;
          }
       else if(c == '"'){
            s = stringLiteral;
            printf("%c",c);
          }
       else if(c == '\''){
            s = beginOfchar;
            printf("%c",c);
          }
       else{
            printf("%c",c);
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case slash:
       if(c == '/'){
            s = commentType1;
          }
       else if(c == '*'){
            s = commentType2;
          }
       else if(c != '*' && c != '/'){
            s = normal;
            printf("/");
            printf("%c",c);
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case commentType1:
       if(c == '\n'){
            s = normal;
            printf("%c",c);
          }
       else{
            s = commentType1;
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case commentType2:
       if(c == '*'){
            s = endOfcomment;
          }
       else{
            s = commentType2;
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case endOfcomment:
       if(c == '/'){
            s = normal;
          }
       else{
            s = commentType2;
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case stringLiteral:
       if(c == '"'){
            s = normal;
            printf("%c",c);
          }
       else if(c == '\\'){
            s = backslash;
            printf("%c",c);
          }
       else{
            printf("%c",c);
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case backslash:
       printf("%c",c);
       s = stringLiteral;
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case beginOfchar:
       if(c == '\\'){
            s = escapeChar;
            printf("%c",c);
          }
       else{
            s = character;
            printf("%c",c);
          }
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case escapeChar:
       printf("%c",c);
       s = character;
       break;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     case character:
       if(c == '\''){
            s = normal;
            printf("%c",c);
          }
       break;
   }
 }
	return 0;
}
