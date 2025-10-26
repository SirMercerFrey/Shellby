#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_rdr
{
	int type; // < = 0; > = 1; << = 2; >> = 3
	char			*filename;
	struct s_rdr	*next;
}					t_rdr;

typedef struct s_cmd
{
	char			**argv;
	char			*cmd_path;
	struct s_rdr	*redirs;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_cap
{
	int				tok;
	struct s_cmd	*next;
}					t_cap;

int					check_pipes(char **token);
int					check_redirections(char **token);
int					check_quotes(char **token);
int					all_checks(char **token);
void				exit_syntax(char **token);
void				remove_outer_quotes_inplace(char *str);
void				remove_quotes(char **argv);

size_t				get_len(char *line);
char				*extract_token(char **line);
void				free_tokens(char **token, int i);
char				**split_tokens(char *line);

void				write_prompt(void);
t_cmd				*prompt_loop_sub(char *line, char **envp);
void				prompt_loop(char **envp);

t_cmd				*create_node(void);
t_cap				*create_head(void);
void				add_arg(char ***argv, char *word);
void				parsing_loop(char **token, t_cmd *node, int *n);
t_cap				*parsing(char **token);
void				free_head_nodes(t_cap *head);

char				*extract_var(char *str);
char				*write_var(char *str, char *env, size_t i, size_t var_len);
char    *get_var(char *str, size_t i, char **envp);
void				check_var_quotes(char c, int *in_single_quote,
						int *in_double_quote);
void    put_env_str(char **str, char **envp);
void    put_env_arg(char **argv, char **envp);

void				print_banner_start(void);
void				print_banner_end(void);

char				*absolut_path(void);
int					isbuiltin(t_cmd *cmd);
void				exec_builtins(t_cmd *cmd);
void				exec_cmd(t_cmd *cmd, char **envp);
void				builtin_pwd(t_cmd *cmd);
void				builtin_cd(t_cmd *cmd);
char				*find_path(char *cmd, char **envp);
void				ft_free_split(char **tab);
int					ft_strcmp(char *s1, char *s2);

#endif
