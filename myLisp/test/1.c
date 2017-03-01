#include "mpc.h"
#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv)
{
  mpc_parser_t* StrA = mpc_new("stra");
  mpc_parser_t* StrB = mpc_new("strb");
  mpc_parser_t* StrAB = mpc_new("strab");
  mpc_parser_t* Str = mpc_new("str");

  mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      stra     : 'a';                                    \
      strb     : 'b';                                    \
      strab    : <stra>+ <strb>+;                           \
      str      : /^/ <strab>* /$/;                        \
    ",
    StrA, StrB, StrAB, Str);

  while (1) {

    char* input = readline("test 1> ");
    add_history(input);

    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Str, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }

  mpc_cleanup(4, StrA, StrB, StrAB, Str);

  return 0;
}
