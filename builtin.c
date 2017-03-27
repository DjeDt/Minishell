#include <string.h>
#include <stdio.h>

struct	s_builtin
{
	const char	*name;
	char		*ft;
};

static struct s_builtin	func(void)
{
	struct s_builtin	arr[] = {
		{ "env", NULL },
		{ "echo", NULL},
		{ "test", NULL}
	};

	return (arr);
}

int	main(void)
{
	struct s_builtin test;

	test = func();
	printf("%s", test.name);
	return (0);
}







