/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:32:34 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/24 13:29:45 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

/* Implementation of linked list */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Vector with x and y coordinates */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/* Returns length of a string */
size_t		ft_strlen(const char *s);

/* Concatenates two strings ensuring it ends with \0 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/* Copies n - 1 bytes from a source string to a destination string */
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/* Compares two strings up to the n-th character */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* Reads a String, and, after ignoring spaces
with ft_isspace, saves the string into an integer */
int			ft_atoi(const char *nptr);

/* More restrictive version of ft_atoi */
int			ft_atoi2(const char *nptr, long *nbr);

/* Saves the given number as a string (char array) */
char		*ft_itoa(int n);

/* Replica of ft_itoa which works with unsigned numbers */
char		*ft_uitoa(unsigned int n);

/* Prints a character to the given file descriptor */
int			ft_putchar_fd(char c, int fd);

/* Writes n chars to the given file descriptor */
int			ft_putnchar_fd(char c, int fd, int n);

/* Prints a string followed by a new line \n to a given file descriptor */
int			ft_putendl_fd(char *s, int fd);

/* Prints number to the given file descriptor */
int			ft_putnbr_fd(int n, int fd);

/* Prints number in given base to the given file descriptor */
int			ft_putnbr_base_fd(long n, char *base, int fd);

/* Prints string to the given file descriptor */
int			ft_putstr_fd(char *s, int fd);

/* Writes n bytes from a string to the given file descriptor */
int			ft_putstrn_fd(char *s, int fd, int n);

/* Splits a string according to a given separator character */
char		**ft_split(char const *s, char c);

/* Concatenates two strings allocating enough space first */
char		*ft_strjoin(char const *s1, char const *s2);

/* Applies a function (mapping) to every element in a string */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Removes occurrences of characters in a string from the start
 * and end of another one */
char		*ft_strtrim(char const *s1, char const *set);

/* Copies from the n-th char of a string */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/* Writes n zeroes to the string s */
void		ft_bzero(void *s, size_t n);

/* Reserves x blocks of y bits of memory */
void		*ft_calloc(size_t nmemb, size_t size);

/* Returns 1 if the input is a number or a letter in the ASCII table */
int			ft_isalnum(int c);

/* Returns 1 if the input is a letter in the ASCII table */
int			ft_isalpha(int c);

/* Returns whether or not a value belongs to the ASCII table */
int			ft_isascii(int c);

/* Returns 1 if the input is a number in the ASCII table */
int			ft_isdigit(int c);

/* Returns whether a character is printable */
int			ft_isprint(int c);

/* Copies from one memory point to another, until the specified character
 * is copied or until n bytes are copied */
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);

/* Looks for a matching character inside a part of the memory */
void		*ft_memchr(const void *s, int c, size_t n);

/* Compares two parts of memory, returning 0 if they're the same,
 * or a nonzero value */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* Copies from one part of memory to another, ignoring possible overlaps*/
void		*ft_memcpy(void *dest, const void *src, size_t n);

/* Copies from one part of memory to another, preventing possible overlaps*/
void		*ft_memmove(void *dest, const void *src, size_t n);

/* Assigns a character n times to a part of the memory*/
void		*ft_memset(void *s, int c, size_t n);

/* Looks for a specific character inside a given string,
 * returning pointer to it*/
char		*ft_strchr(const char *s, int c);

/* Looks for a specific character inside a given string,
 * returning its index */
int			ft_strchr_i(const char *s, int c);

/* Looks for a given character in a string, reading it from back to front */
char		*ft_strrchr(const char *s, int c);

/* Saves enoug space and duplicates a string */
char		*ft_strdup(const char *s);

/* Tries to find a substring (needle) in a second string (haystack)
 * before the n-th char is reached */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/* Makes every uppercase character in a string lowercase */
int			ft_tolower(int c);

/* Makes every lowercase character in a string uppercase */
int			ft_toupper(int c);

/* Retrieves length of a number in a given base */
int			ft_nbrlen(long n, int base);

/* Returns max between two ints */
int			ft_max(int a, int b);

/* Returns min between two ints */
int			ft_min(int a, int b);

/* Joins two strings regardless if either one is NULL (similar to ft_strjoin) */
char		*ft_strenlarge(char *s1, char *s2);

/* Compares ends of two strings up to the n-th character */
int			ft_strrncmp(const char *s1, const char *s2, size_t n);

/* Returns number of matching chars in a string */
int			ft_countchar(char *s, char c);

/* Returns if a character is a form of space (space, tab, etc) */
int			ft_isspace(char c);

/* Allocates memory for a string of one char */
char		*ft_chartostr(char c);

/* Adds new node at the end of the linked list */
void		ft_lstadd_back(t_list **lst, t_list *newnode);

/* Adds new node at the beginning of the linked list */
void		ft_lstadd_front(t_list **lst, t_list *newnode);

/* Deletes a given element and every element after that */
void		ft_lstclear(t_list **lst, void (*del)(void*));

/* Deletes, frees, and applies function del to content of a given node */
void		ft_lstdelone(t_list *lst, void (*del)(void*));

/* Applies a function to the content of every node of the linked list */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Retrieves last node of the list */
t_list		*ft_lstlast(t_list *lst);

/* Applies function to a copy of the list, freeing when necessary */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Creates new node allocating with malloc */
t_list		*ft_lstnew(void *content);

/* Returns number of elements of linked list */
int			ft_lstsize(t_list *lst);

/* Returns sqare root of number as closest (rounded) int */
int			ft_sqrt(int nb);

/* Calculates the power of a number given a base with recursion */
int			ft_recursive_power(int nb, int power);

/* Returns value of the euclidean distance between two points */
int			ft_euclideandistance(t_vector src, t_vector dest);

/* Creates a new t_vector with the given x and y parameters	 */
t_vector	ft_newvector(int x, int y);

/* Frees all allocated memory from a matrix (array of arrays) */
void		ft_free_matrix(char ***m);

/* Allocates and fully duplicates a matrix (array of arrays) */
char		**ft_dup_matrix(char **m);

#endif
