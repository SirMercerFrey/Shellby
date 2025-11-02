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

typedef struct	s_rdr
{
	int				type; // < = 0; > = 1; << = 2; >> = 3
	char			*filename;
	struct s_rdr	*next;
} t_rdr;
	
typedef struct	s_cmd
{
	char			**argv;
	char			*cmd_path;
	struct s_rdr	*redirs;
	struct s_cmd	*next;
} t_cmd;

typedef struct	s_cap
{
	int				tok;
	struct s_cmd	*next;
} t_cap;

typedef struct	s_shell
{
	t_cap			*cap;
	char			**envp;
	int				exit_status;
} t_shell;

//prodrome
t_shell	*create_shell(char **envp);
void    free_shell(t_shell *shell);
char    **copy_envp(char **envp);
size_t  envp_len(char **envp);

//checking
int		check_pipes(char **token);
int		check_redirections(char **token);
int		check_quotes(char **token);
int		all_checks(char **token);
void	exit_syntax(char **token);

//quotes
void	remove_outer_quotes_inplace(char *str);
void	remove_quotes(char **argv);

//lexing
size_t	get_len(char *line);
char	*extract_token(char **line);
void	free_tokens(char **token, int i);
char	**split_tokens(char *line);

//chars_check
int     metachars(char c);
int     quotes(char c);
int     spaces(char c);
int     is_redir(char c);
int are_redir(char *str);

//core
char	*get_prompt(void);
void	prompt_loop_sub(char *line, t_shell *shell);
void	prompt_loop(t_shell *shell);

//parsing
t_cap	*parsing(char **token);
void	parsing_loop(char **token, t_cmd *node, int *n);
void	add_arg(char ***argv, char *word);
void    handle_direction(char **token, t_cmd *node, int *n);


//parsing_utils
t_cmd	*create_node(void);
t_cap	*create_head(void);
t_rdr   *create_redir(void);
void    free_redirs(t_rdr *tmp);
void	free_head_nodes(t_cap *head);

//environnement
char    *extract_var(char *str);
char	*ft_getenv(char *var, size_t var_len, t_shell *shell);
char    *write_var(char *str, char *env, size_t i, size_t var_len);
char    *get_var(char *str, size_t i, t_shell *shell);
void    check_var_quotes(char c, int *in_single_quote, int *in_double_quote);
void    put_env_str(char **str, t_shell *shell);
void    put_env_arg(char **argv, t_shell *shell);
void ft_setenv(const char *key, const char *value, char ***envp);

//print_banner
void	print_banner_start(void);
void	print_banner_end(void);

//libft_utils
int     ft_strcmp(char *s1, char *s2);

//core_bis
int isbuiltin(t_shell *shell);
void    exec_builtins(t_shell *shell);
void    exec_cmd(t_shell *shell);
void ft_free_split(char **split);

//built-ins
void builtin_pwd(t_cmd *cmd);
void builtin_export(t_cmd *cmd, t_shell *shell);
void    builtin_cd(t_cmd *cmd, t_shell *shell);
void builtin_unset(t_cmd *cmd, char ***envp);
void builtin_env(char ***envp);

//path_check
char    *check_direct_path(char *cmd);
char    *get_path_variable(char **envp);
char    *search_in_paths(char *cmd, char **paths);
char    *find_path(char *cmd, char **envp);
char *absolut_path(void);

#endif
