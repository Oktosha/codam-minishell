/** @file 
 * Module that takes commands and executes them.
 * Namespace prefix: "ex".
*/
#ifndef DEBUG_H
# define DEBUG_H

# include "tokenize.h"

typedef struct s_dbg_tk_result {
    t_tk_token  tokens[50];
    t_tk_status status;
} t_dbg_tk_result;

#endif
