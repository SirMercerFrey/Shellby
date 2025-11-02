#include "minishell.h"

char	*extract_var(char *str)
{
	size_t	len;
	size_t	i;
	char	*var;

	if (*str == '?')
	{
		var = (char *)(malloc(sizeof(char) * 2));
		var[0] = '?';
		var[1] = '\0';
		return (var);
	}
	len = 1;
	while (str[len] && ft_isalnum(str[len]))
		++len;
	--len;
	var = (char *)(malloc(sizeof(char) * len + 1));
	if (!var)
		return (NULL);
	++str;
	i = 0;
	while (i < len)
		var[i++] = *str++;
	var[i] = '\0';
	return (var);
}

char	*ft_getenv(char *var, size_t var_len, t_shell *shell)
{
	size_t	i;
	char	*status;
	char	**envp;

	status = NULL;
	if (!ft_strcmp(var, "?"))
	{
		status = ft_itoa(shell->exit_status);
		return (status);
	}
	envp = shell->envp;
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], var, var_len) && envp[i][var_len] == '=')
			return (envp[i] + var_len + 1);
		++i;
	}
	return (NULL);
}


char	*write_var(char *str, char *env, size_t i, size_t var_len)
{
	char	*new_str;
	size_t	str_len;
	size_t	env_len;
	size_t	j;

	str_len = ft_strlen(str);
	env_len = ft_strlen(env);
	new_str = (char *)malloc(sizeof(char) * (str_len - var_len + env_len + 1));
	j = 0;
	while (j < i)
	{
		new_str[j] = str[j];
		++j;
	}
	while (*env)
		new_str[j++] = *env++;
	i = i + var_len + 1;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*get_var(char *str, size_t i, t_shell *shell)
{
	char	*new_str;
	char	*var;
	char	*env;
	size_t	var_len;

	var = extract_var(str + i);
	var_len = ft_strlen(var);
	env = ft_getenv(var, var_len, shell);
	if (!env)
		env = "";
	new_str = write_var(str, env, i, var_len);
	if (*var == '?')
		free(env);
	free(var);
	return (new_str);
}

void	check_var_quotes(char c, int *in_single_quote, int *in_double_quote)
{
	if (c == '\'' && !*in_double_quote)
		*in_single_quote = !*in_single_quote;
	else if (c == '"' && !*in_single_quote)
		*in_double_quote = !*in_double_quote;
}

void	put_env_str(char **str, t_shell *shell)
{
	char	*new_str;
	int		in_single_quote;
	int		in_double_quote;
	size_t	i;

	in_single_quote = 0;
	in_double_quote = 0;
	i = 0;
	while ((*str)[i])
	{
		check_var_quotes((*str)[i], &in_single_quote, &in_double_quote);
		if (!in_single_quote && (*str)[i] == '$')
		{
			new_str = get_var(*str, i, shell);
			free(*str);
			*str = new_str;
			i = 0;
			in_single_quote = 0;
			in_double_quote = 0;
			continue ;
		}
		++i;
	}
}

void	put_env_arg(char **argv, t_shell *shell)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		put_env_str(&argv[i], shell);
		++i;
	}
}

void ft_setenv(const char *key, const char *value, char ***envp)
{
    size_t i = 0;
    size_t j;
    size_t key_len = strlen(key);
    char *new_entry;
    char **new_env;

    new_entry = malloc(key_len + strlen(value) + 2);
    if (!new_entry)
        return;
    strcpy(new_entry, key);
    strcat(new_entry, "=");
    strcat(new_entry, value);
    printf("NEW ENTRY: %s\n", new_entry);
    while ((*envp)[i])
    {
		// printf("str1: %s, str2: %s\n", (*envp)[i], key);
        if (!strncmp((*envp)[i], key, key_len) && (*envp)[i][key_len] == '=')
        {
		    printf("FREE ZONE: %s\n", (*envp)[i]);
            // free((*envp)[i]);
            (*envp)[i] = new_entry;
            return;
        }
        i++;
    }
    new_env = malloc(sizeof(char *) * (i + 2));

    if (!new_env)
    {
        free(new_entry);
        return;
    }
    j = 0;
    while (j < i)
    {
        new_env[j] = (*envp)[j];
        j++;
    }

    new_env[i] = new_entry;
	printf("str1: %s\n", new_env[i]);
    new_env[i + 1] = NULL;
	printf("str2: %s\n", new_env[i + 1]);
	
    *envp = new_env;
    // free(*new_env);
}
