// Name: Polly Sobeck
// Quiz: Random Testing
// Date: 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//int r = rand() % 20;

char inputChar()
{
    //TODO: rewrite this function
    int r = (rand() % 94) + 32;
    char c = r;
    return c;
}

char *inputString()
{
    //TODO: rewrite this function
    int asciiValues[] = {
        101, // 'e'
        114, // 'r' 
        115, // 's'
        116  // 't'
    };

    char *s;
    char c[6];
    for (int i = 0; i < 5; i++) {
        int r = rand() % 4;
        c[i] = asciiValues[r];
    }
    c[5] = '\0';
    s = c;
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();

    s = inputString();

    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
