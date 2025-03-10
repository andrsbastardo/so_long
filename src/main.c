/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:38 by abastard          #+#    #+#             */
/*   Updated: 2025/02/17 21:11:31 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_parsemap	*mapinf;
    int parse;
    
    if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == 0)
        return(1);
    mapinf = init_struct();
    parse = parse_map(argv[1], &mapinf);
    if (!parse)
        return(0);
    if (!start_game(mapinf))
        return(1);
    return(0);
}
