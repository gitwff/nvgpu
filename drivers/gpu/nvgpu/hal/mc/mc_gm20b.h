/*
 * Copyright (c) 2014-2019, NVIDIA CORPORATION.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef NVGPU_MC_GM20B_H
#define NVGPU_MC_GM20B_H

#include <nvgpu/types.h>

#define MC_ENABLE_DELAY_US	20U
#define MC_RESET_DELAY_US	20U
#define MC_RESET_CE_DELAY_US	500U

struct gk20a;
enum nvgpu_unit;

u32  gm20b_mc_isr_nonstall(struct gk20a *g);
void gm20b_mc_enable(struct gk20a *g, u32 units);
void gm20b_mc_disable(struct gk20a *g, u32 units);
void gm20b_mc_reset(struct gk20a *g, u32 units);
u32  gm20b_mc_reset_mask(struct gk20a *g, enum nvgpu_unit unit);
bool gm20b_mc_is_enabled(struct gk20a *g, enum nvgpu_unit unit);

#ifdef CONFIG_NVGPU_HAL_NON_FUSA
void gm20b_mc_intr_mask(struct gk20a *g);
void gm20b_mc_intr_enable(struct gk20a *g);
void gm20b_mc_intr_pmu_unit_config(struct gk20a *g, bool enable);
void gm20b_mc_isr_stall(struct gk20a *g);
u32  gm20b_mc_intr_stall(struct gk20a *g);
void gm20b_mc_intr_stall_pause(struct gk20a *g);
void gm20b_mc_intr_stall_resume(struct gk20a *g);
u32  gm20b_mc_intr_nonstall(struct gk20a *g);
void gm20b_mc_intr_nonstall_pause(struct gk20a *g);
void gm20b_mc_intr_nonstall_resume(struct gk20a *g);
bool gm20b_mc_is_intr1_pending(struct gk20a *g,
		enum nvgpu_unit unit, u32 mc_intr_1);
void gm20b_mc_log_pending_intrs(struct gk20a *g);
void gm20b_mc_fb_reset(struct gk20a *g);
void gm20b_mc_ltc_isr(struct gk20a *g);

bool gm20b_mc_is_mmu_fault_pending(struct gk20a *g);
#endif

#endif /* NVGPU_MC_GM20B_H */
