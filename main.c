/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:38 by abastard          #+#    #+#             */
/*   Updated: 2025/01/25 15:42:11 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_parsemap	*mapinf;
    int cosa;
    
    if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == 0)
        return(0);
    mapinf = init_struct();
    cosa = parse_map(argv[1], &mapinf);
    if(!cosa)
        return(0);
    return(0);
}