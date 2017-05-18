/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:59:49 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/18 18:59:50 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "bitmap.h"

static void	fill_bitmap_file_header(t_bitmap_file_header *h,
									int width, int height)
{
	h->bf_type[0] = 'B';
	h->bf_type[1] = 'M';
	h->bf_size = sizeof(t_bitmap_file_header) + sizeof(t_bitmap_info_header)
					+ sizeof(int) * (width * height);
	h->bf_reserved1 = 0;
	h->bf_reserved2 = 0;
	h->bf_off_bits = sizeof(t_bitmap_file_header)
						+ sizeof(t_bitmap_info_header);
}

static void	fill_bitmap_info_header(t_bitmap_info_header *h,
									int width, int height)
{
	h->bi_size = sizeof(t_bitmap_info_header);
	h->bi_width = width;
	h->bi_height = height;
	h->bi_planes = 0;
	h->bi_bit_count = 8;
	h->bi_compression = 0;
	h->bi_size_image = 0;
	h->bi_x_pels_per_meter = 0;
	h->bi_y_pels_per_meter = 0;
	h->bi_clr_used = 0;
	h->bi_clr_important = 0;
}

int			save_bitmap(char *file_name, int width, int height, int *image)
{
	int						fd;
	t_bitmap_file_header	bitmap_file_header;
	t_bitmap_info_header	bitmap_info_header;

	fill_bitmap_file_header(&bitmap_file_header, width, height);
	fill_bitmap_info_header(&bitmap_info_header, width, height);
	fd = open(file_name, O_WRONLY | O_CREAT);
	if (fd == -1)
		return (1);
	write(fd, &bitmap_file_header, sizeof(bitmap_file_header));
	write(fd, &bitmap_info_header, sizeof(bitmap_info_header));
	write(fd, image, sizeof(int) * width * height);
	close(fd);
	return (0);
}
