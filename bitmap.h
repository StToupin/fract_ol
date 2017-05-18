/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:55:34 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/18 18:55:35 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include <stdint.h>

# pragma pack(push, 1)

typedef struct	s_bitmap_file_header
{
	char			bf_type[2];
	uint32_t		bf_size;
	uint16_t		bf_reserved1;
	uint16_t		bf_reserved2;
	uint32_t		bf_off_bits;
}				t_bitmap_file_header;

# pragma pack(pop)

# pragma pack(push, 1)

typedef struct	s_bitmap_info_header
{
	uint32_t		bi_size;
	uint32_t		bi_width;
	uint32_t		bi_height;
	uint16_t		bi_planes;
	uint16_t		bi_bit_count;
	uint32_t		bi_compression;
	uint32_t		bi_size_image;
	uint32_t		bi_x_pels_per_meter;
	uint32_t		bi_y_pels_per_meter;
	uint32_t		bi_clr_used;
	uint32_t		bi_clr_important;
}				t_bitmap_info_header;

# pragma pack(pop)

int				save_bitmap(char *file_name, int width, int height, int *image);

#endif
