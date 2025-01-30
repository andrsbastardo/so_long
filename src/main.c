/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:38 by abastard          #+#    #+#             */
/*   Updated: 2025/01/28 17:04:53 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_parsemap	*mapinf;
    int parse;
    
    if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == 0)
        return(0);
    mapinf = init_struct();
    parse = parse_map(argv[1], &mapinf);
    if(!parse)
        return(0);
    
    
    return(0);
}