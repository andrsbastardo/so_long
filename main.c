/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:38 by abastard          #+#    #+#             */
/*   Updated: 2025/01/22 07:08:48 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_parsemap	*mapinf;
    if (argc != 2 || ft_strncmpend(argv[1], ".ber", 4) == 0)
        return(-1);
    printf("init\n");
    mapinf = init_struct();
    printf("%s\n",argv[1]);
    parse_map(argv[1], &mapinf);
    return(1); 
}