#include <string.h>
#include <stdio.h>

struct	s_builtin
{
	const char	*name;
	char		*fc;
};

static struct s_builtin *func(struct s_builtin *test)
{
	struct s_builtin	arr[] ={
		{ "env", NULL },
		{ "echo", NULL },
		{ "test", NULL },
		{ "cd", NULL },
	};
	test = arr;
	return (test);
}

int	main(void)
{
	int i = 0;
	struct s_builtin *test;

	test = func(test);
//	while (test[i].name != NULL)
//	{
//		printf("i = %d\n", i);
		printf("name = %s", test[i].name);
//		i++;
//	}
	return (0);
}
