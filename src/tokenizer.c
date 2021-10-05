//#ifndef _TOKENIZER_

#define _TOKENIZER_

#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "history.h"

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */




int space_char(char c){

  if(c=='\t' || c==' '){
    return 1;
  }
  return 0;
}



/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  
    if(c=='\t' || c==' '|| c=='\0'){
      return 1; 
    }
    return 0;
}





/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */

char *word_start(char *str){
  // iterate until we read a char
  while(non_space_char(str[0])==0){
    str++;
  }
  return str;
}



/* Returns a pointer terminator char following *word */

char *word_terminator(char *str){
  // iterate until we reach ' ', '\t', or '\0'
  while(non_space_char(str[0])==1){
    str++;

  }
  return str;
}



/* Counts the number of words in the string argument. */

int count_words(char *str){
  int count = 0;

  while(1){
    // move to first char
    str = word_start(str);

    //check for space before the end
    if(str[1]== '\0'){
      break;
    }
    count++;

    //move to terminate char
    str =  word_terminator(str);

    //check end of word
    if(str[0] == '\0'){
      break;

    }
  } 

  printf("Numer of words: %d\n", count);
  return count;
}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  
  char *copy = malloc(len);
  int i =0;
  while(len !=0){
    copy[i] = inStr[i];
    i++;
    len--;


  }
  copy[i] = '\0';
  return copy;

}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str){
  //geting size and allocating memory

  int len = count_words(str);

  char **tokens = (char**)malloc((len+1)*sizeof(char*));



  for(int i = 0; i < len; i++){
    //size of word

    short size = *word_terminator(str) - *word_start(str);

    //if at last word

    if(i == len-1){

      tokens[i] = copy_str(str, size-1);

      tokens[i+1] = 0;

    }

    tokens[i] = copy_str(str, size);

    str = word_terminator(str);

    str = word_start(str);

  }

  // print_tokens(tokens);

  return tokens;


}
/* Prints all tokens. */

void print_tokens(char **tokens)
{

  while (*tokens)

    {

      printf("[%s],",*tokens);

      *tokens++;

    }

  printf("\n");

}



void free_tokens(char **tokens)

{

  while (*tokens++)

    {

      free(*tokens);

    }

  

}


/* Frees all tokens and the vector containing themx. */





