/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:28:46 by avallois          #+#    #+#             */
/*   Updated: 2018/06/22 13:58:12 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 4

typedef struct	s_pm
{
	char		**cmd;

	int			nb_i;
	int			ste;
	int			*a;
	int			*b;
	int			med;
	int			alen;
	int			blen;
}				t_pm;

void			ft_free_stacks(t_pm *s);
void			ft_error(void);
void			ft_isint(char *str, t_pm *s);
void			ft_isduplicate(int n, t_pm *s);
int				count_numbers(char *argv[]);
void			place_first_elt(t_pm *s, int *sort_done);
int				swap_and_place(t_pm *s);
int				take_and_place(t_pm *s, int *sort_done, int i);
void			place_all_elts(t_pm *s, int *sort_done);
void			sort_short_lists(t_pm *s);
void			try_simple_skills(t_pm *s);
void			put_instructions_v(t_pm *s, int index, int shots);
void			quicksort(int *tab, int first, int last);
void			ft_pusha(t_pm *s);
void			run_algo(t_pm *s);
t_pm			*fill_struct(t_pm *s, char *a[]);
void			simule_insert_a(t_pm *s, int *min, int *index, int n);
void			init_s(t_pm **s, int count);
void			init_f(void (*f[13])(t_pm *s, char list, int print));
void			run_checker(t_pm *s);
void			cmd_p(t_pm *s, char list, int print);
void			cmd_r(t_pm *s, char list, int print);
void			cmd_s(t_pm *s, char list, int print);
void			cmd_rr(t_pm *s, char list, int print);
int				ft_isascending(int *stack, int max);
int				get_mediane(int *a, int alen);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
long			ft_long_atoi(const char *str);
int				ft_inttab_cmp(int *a, int alen, int *b, int blen);
int				*copy_inttab(int *a, int alen);
void			swap_int(int *a, int *b);
int				ft_isdigit(int c);
int				pos_str_tab(char *haystack, char **needle);
int				get_next_line(const int fd, char **line);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin_f(char const *s1, char const *s2, int j);
void			ft_putinttab(int *tab, int size, char *sp);
int				*ft_intnew(size_t size, int value);
void			ft_putchar(char c);
void			ft_putnbr(int n);
size_t			ft_strlen(const char *str);
void			ft_putstr(char const *s);
int				ft_strcmp(const char *s1, const char *s2);
void			print_infos(t_pm *s, int print);

#endif
