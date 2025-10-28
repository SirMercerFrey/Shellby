#include "minishell.h"

/*static char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		++len;
	dup = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = s[i];
		++i;
	}
	return (dup);
}*/


// static int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }

// static int	ft_isalpha(int c)
// {
// 	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
// }

// static int	ft_isalnum(int c)
// {
// 	return (ft_isalpha(c) || ft_isdigit(c));
// }

// static size_t	ft_strlen(char *str)
// {
// 	char	*end;

// 	if (!str)
// 		return (0);
// 	end = str;
// 	while (*end)
// 		++end;
// 	return (end - str);
// }

// static int	ft_strncmp(char *s1, char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (n > i)
// 	{
// 		if ((unsigned char)s1[i] != (unsigned char)s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		if (!s1[i])
// 			break ;
// 		++i;
// 	}
// 	return (0);
// }

char	*extract_var(char *str)
{
	size_t	len;
	size_t	i;
	char	*var;

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

char	*ft_getenv(char *var, size_t var_len, char **envp)
{
	size_t	i;

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

char	*get_var(char *str, size_t i, char **envp)
{
	char	*new_str;
	char	*var;
	char	*env;
	size_t	var_len;

	var = extract_var(str + i);
	var_len = ft_strlen(var);
	env = ft_getenv(var, var_len, envp);
	free(var);
	if (!env)
		env = "";
	new_str = write_var(str, env, i, var_len);
	return (new_str);
}

void	check_var_quotes(char c, int *in_single_quote, int *in_double_quote)
{
	if (c == '\'' && !*in_double_quote)
		*in_single_quote = !*in_single_quote;
	else if (c == '"' && !*in_single_quote)
		*in_double_quote = !*in_double_quote;
}

void	put_env_str(char **str, char **envp)
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
			new_str = get_var(*str, i, envp);
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

void	put_env_arg(char **argv, char **envp)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		put_env_str(&argv[i], envp);
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


/*int		main(void)
{
	char	**argv ;
	char	str2[] = "\"Hello $USER, you 're now at $PWD on the $HOSTNAME machine.\"";
	char	str[] = "echo";
	char	str1[] = "-n";
	size_t	i;

	argv = (char **)(malloc(sizeof(char *) * 4));
	
	argv[0] = ft_strdup(str);
	argv[1] = ft_strdup(str1);
	argv[2] = ft_strdup(str2);
	argv[3] = NULL;
	i = 0;
	while (argv[i])
		printf("%s\n", argv[i++]);
	put_env_arg(argv);
	i = 0;
	while (argv[i])
		printf("%s\n", argv[i++]);
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	return (0);
}*/
