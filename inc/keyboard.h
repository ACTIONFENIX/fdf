/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:52:20 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:52:22 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# define ESC 53
# define A 0
# define D 2
# define W 13
# define S 1
# define DOWN 125
# define UP 126
# define LEFT 123
# define RIGHT 124
# define Q 12
# define E 14
# define R 15
# define H 4
# define L 37
# define V 9
# define C 8
# define O 31
# define F 3
# define J 38
# define P 35
# define NUMPAD_PLUS 69
# define NUMPAD_MINUS 78
# define NUMPAD_ASTERISK 67
# define NUMPAD_SLASH 75

int key_hook(int key, void *param);

#endif
