#include <string.h>
#include <stdlib.h>
#include "debug.h"

/**
 * @brief appends addition to store. Old store is freed, new store is allocated
 * @warning 't pass a string you can't free as store!
 * @note no changes (no free or anything) done to addition
 * @note addition must be a valid string (not NULL)
*/
static void	l_dbg_append(char **store, char *addition)
{
	if (*store == NULL)
	{
		*store = strdup(addition);
		return;
	}
	char *new_str = malloc((strlen(*store) + strlen(addition) + 1) * sizeof(char));
	memcpy(new_str, *store, strlen(*store));
	memcpy(new_str + strlen(*store), addition, strlen(addition));
	free(*store);
	*store = new_str;
}

static char	*l_dbg_create_common_string_for_tk_tokens(t_dbg_dummy_tk_token *tk_token_dummies)
{
	char *s = NULL;
	int cnt = 0;
	while (tk_token_dummies[cnt].data != NULL)
	{
		l_dbg_append(&s, tk_token_dummies[cnt].data);
		cnt += 1;
	}
	return s;
}

t_dbg_tk_token_sequence	dbg_create_tk_token_sequence(t_dbg_dummy_tk_token *tk_token_dummies)
{
	t_dbg_tk_token_sequence	seq = {NULL, NULL};
	seq.s = l_dbg_create_common_string_for_tk_tokens(tk_token_dummies);
	int cnt = 0;
	char *s = seq.s;
	while (tk_token_dummies[cnt].data != NULL)
	{
		t_tk_token	*token = malloc(sizeof(t_tk_token));
		token->data = s;
		token->length = strlen(tk_token_dummies[cnt].data);
		token->type = tk_token_dummies[cnt].type;
		li_new_stack(&(seq.tokens), token);
		s += strlen(tk_token_dummies[cnt].data);
	}
	return seq;
}

void	dbg_clear_tk_token_sequence(t_dbg_tk_token_sequence *seq)
{
	free(seq->s);
	tk_token_free(seq->tokens);
	seq->s = NULL;
	seq->tokens = NULL;
}

int	dbg_are_tk_tokens_equal(t_tk_token *a, t_tk_token *b)
{
	
}