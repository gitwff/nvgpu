/*
 * Copyright (C) 2017 NVIDIA Corporation.  All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "debug_cde.h"
#include "gk20a/platform_gk20a.h"

#include <linux/debugfs.h>


static ssize_t gk20a_cde_reload_write(struct file *file,
	const char __user *userbuf, size_t count, loff_t *ppos)
{
	struct gk20a *g = file->private_data;
	gk20a_cde_reload(g);
	return count;
}

static const struct file_operations gk20a_cde_reload_fops = {
	.open		= simple_open,
	.write		= gk20a_cde_reload_write,
};

void gk20a_cde_debugfs_init(struct gk20a *g)
{
	struct gk20a_platform *platform = dev_get_drvdata(dev_from_gk20a(g));

	if (!platform->has_cde)
		return;

	debugfs_create_u32("cde_parameter", S_IWUSR | S_IRUGO,
			   platform->debugfs, &g->cde_app.shader_parameter);
	debugfs_create_u32("cde_ctx_count", S_IWUSR | S_IRUGO,
			   platform->debugfs, &g->cde_app.ctx_count);
	debugfs_create_u32("cde_ctx_usecount", S_IWUSR | S_IRUGO,
			   platform->debugfs, &g->cde_app.ctx_usecount);
	debugfs_create_u32("cde_ctx_count_top", S_IWUSR | S_IRUGO,
			   platform->debugfs, &g->cde_app.ctx_count_top);
	debugfs_create_file("reload_cde_firmware", S_IWUSR, platform->debugfs,
			    g, &gk20a_cde_reload_fops);
}
