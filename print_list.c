#include "print_list.h"

void	print_list(t_list **lst)
{
	t_list	*current;
	size_t	i;

	current = *lst;
	i = 0;
	while (current)
	{
		printf("Element nb %zu: %i\n", i, *(int *)current->content);
		i++;
		current = current->next;
	}
}